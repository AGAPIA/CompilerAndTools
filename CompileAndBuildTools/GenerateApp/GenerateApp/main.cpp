// TODO: all files opened/created should use temp subdir
//       test lib/include/linker tool

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <list>
#include <string>
#include <assert.h>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

#ifdef _WIN32
#include <Windows.h>
#include <io.h>
#include <direct.h>

inline int access(const char *pathname, int mode)
{
	return _access(pathname, mode);
}
#endif


#ifdef unix
#include <unistd.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

#define fprintf_s fprintf
#define sprintf_s snprintf

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int BOOL;
typedef unsigned int DWORD;
typedef char* LPTSTR;

const BOOL FALSE = 0;
const BOOL TRUE = 1;

inline BOOL CopyFile(const char *fileName, const char *destName, BOOL failIfExists)
{
	int destFileFlag = O_WRONLY | O_CREAT;
	if(failIfExists == TRUE)
		destFileFlag |= O_EXCL;
	int destFileMode = S_IRWXU | S_IRWXG | S_IRWXO;


	int sourceFile = open(fileName, O_RDONLY);
	assert(sourceFile != -1);

	struct stat sourceStat;
    fstat(sourceFile, &sourceStat);

	int destFile = open(destName, destFileFlag, destFileMode);

	if(destFile == -1)
		return FALSE;

	sendfile(destFile, sourceFile, 0, sourceStat.st_size);

	close(sourceFile);
	close(destFile);
	return TRUE;
}

inline int _mkdir(const char *path)
{
 	return mkdir(path, S_IRWXU | S_IRWXG | S_IRWXO);
}

inline void GetCurrentDirectory(DWORD bufferLength, LPTSTR buffer)
{
	getcwd(buffer, bufferLength);
}



#endif



// COMMENT THIS BEFORE RELEASE
#define GENERATE_EXE_EACH_TIME_BEFORE_CODEGEN

char* gStrAgapiaCompilerSlnPath = NULL;

#define CURRDIRPATH_LEN		4096
char gCurrentDirPath[CURRDIRPATH_LEN];

#if _WIN32
#define PATH_TOAGAPIATOCPPFILECODE_FROM_SLNROOT "\\Compiler\\AgapiaToCCode.cpp"
#define PATH_TO_RELEASEEXE_ITER_FROM_SLNROOT	"\\IterativeRelease\\Compiler.exe"
#define PATH_TO_DEBUGEXE_ITER_FROM_SLNROOT		"\\IterativeDebug\\Compiler.exe"
#define PATH_TO_RELEASEEXE_DISTRI_FROM_SLNROOT	"\\DistributedRelease_Compiler\\Compiler.exe"
#define PATH_TO_DEBUGEXE_DISTRI_FROM_SLNROOT		"\\DistributedDebug_Compiler\\Compiler.exe"
#define PATH_TO_MODULEANALYZER_TOOL_FROM_AGAPIAPATH	"\\ModulesAnalyzer\\Release\\ModulesAnalyzer.exe"
#else

#define PATH_TOAGAPIATOCPPFILECODE_FROM_SLNROOT "/Compiler/AgapiaToCCode.cpp"
#define PATH_TO_RELEASEEXE_ITER_FROM_SLNROOT	"/build/Compiler/Compiler"
#define PATH_TO_DEBUGEXE_ITER_FROM_SLNROOT		"/build/Compiler/Compiler"
#define PATH_TO_RELEASEEXE_DISTRI_FROM_SLNROOT	"/build/Compiler/Compiler"
#define PATH_TO_DEBUGEXE_DISTRI_FROM_SLNROOT		"/build/Compiler/Compiler"
#define PATH_TO_MODULEANALYZER_TOOL_FROM_AGAPIAPATH	"/linux_bin/ModulesAnalyzer"
#endif

#define FILENAME_OF_TRANSFORMED_AGAPIA_FILE			"agapia_transf.txt"
#define GENERATED_MODULE_FILES_NAME					"generatedModules.txt"

#define INCLUDES_FILE_NAME							"Includes.h"

bool isDistributedRun = false;
bool isDebug = false;

//Modify Compiler CMakeLists.txt to include the files and directories given in Def.txt
void ModifyCMakeLists(std::string CMakeListsPath) {
    // Types of lines found in Def.txt
    const auto NONE = 0;
    const auto INCLUDE_FILE = 1;
    const auto ADDITIONAL_INCLUDE_DIRECTORY = 2;
    const auto ADDITIONAL_LIBRARY_DIRECTORY = 3;
    const auto ADDITIONAL_LINKER_LIB_DLL_ETC = 4;
    const auto ADDITIONAL_SOURCE_FILE = 5;

    // open CMakeLists.txt in append mode (all data will be written to the end of the file)
    std::ofstream g(CMakeListsPath, std::ios::app);
    auto CurrentLineType = NONE;
    std::ifstream f("Def.txt");
    std::string line;
    while (std::getline(f, line)) {
        // if we find a line that starts with %, the current line type changes
        if(line[0] == '%')
            CurrentLineType++;
        // we do nothing for lines of type NONE, INCLUDE_FILE or undefined (default case)
        // todo: add more cases
        else switch(CurrentLineType) {
            case ADDITIONAL_SOURCE_FILE:
                g << "add_executable(${PROJECT_NAME} " << line << ")\n";
                break;
            default:
                break;
        }
    }
}

// Get the path of the MSBuild.exe path in the buffer given as parameter
// Returns false if failed, true if succeeded
bool GetMSBuildPath(char* buff)
{
	const char* path = getenv("AGAPIA_MSBUILDPATH");
	if (path == NULL)
	{
		printf("Can't find the environment variable AGAPIA_MSBUILDPATH\n");
		return false;
	}

	strcpy(buff, path);
	if (access(buff, 0) == -1)
	{
		printf("The MSBUILD.exe can't be found. Check the location specified in the environment variable %s again: current value %s", "AGAPIA_MSBUILDPATH", path);
		return false;
	}

	return true;
}

void Cleanup();

const auto copyOptions = fs::copy_options::overwrite_existing;

BOOL CopyFileHelper(const char* filename, const char* buffDest)
{
	try {
		return static_cast<BOOL>(fs::copy_file(filename, buffDest, copyOptions));
	} catch (fs::filesystem_error& e) {
		printf("Could not copy %s: %s\n", filename, e.what());
		exit(0);
	}
}

void AnalyzeModules()
{
	int res = 0;

	char tempPath[CURRDIRPATH_LEN];
	char tempDest[CURRDIRPATH_LEN];
	// Generate the agapia_transf.txt from agapia.txt
	sprintf(tempPath, "%s%s", gStrAgapiaCompilerSlnPath, PATH_TO_MODULEANALYZER_TOOL_FROM_AGAPIAPATH);
	// printf("%s", tempPath);
	res = system(tempPath);
	if (res != 0)
	{
		// Internal error in tool ?
		if (res < 0)	
		{
			printf("Internal errors occurred while processing your file. Please solve the above errors and re-run\n");
			exit(-1);
		}
		else 
		{
			printf("Didn't file the tool where it should be: %s\n", tempPath);
			exit(-1);
		}							
	}


	// Copy the agapia_transf.txt instead of agapia.txt if succeeded
	FILE* f = fopen("temp/" GENERATED_MODULE_FILES_NAME, "r");
	if (f == NULL)
	{
		printf("Couldn't file the module filename generated by the analyze modules tool !!! Report this error please\n");
		exit(-1);
	}

	while(!feof(f))
	{
		fscanf(f, "%s\n", tempPath);
		sprintf(tempDest, "%s/Compiler/temp/%s", gStrAgapiaCompilerSlnPath, tempPath);

		// Modules are created in temp subdir...
		char tempPath2[CURRDIRPATH_LEN];
		sprintf_s(tempPath2, CURRDIRPATH_LEN, "temp/%s", tempPath);

		CopyFileHelper(tempPath2, tempDest);

		// TODO should verify if we are not copying to the same dir...
		//remove(tempPath);
	}

	// Copy and delete the agapia_transf file
	sprintf(tempDest, "%s/Compiler/temp/%s", gStrAgapiaCompilerSlnPath, FILENAME_OF_TRANSFORMED_AGAPIA_FILE);
	res = CopyFileHelper("temp/" FILENAME_OF_TRANSFORMED_AGAPIA_FILE, tempDest);
	if (res == 0)
	{
		printf("Error: Couldn't copy the agapia_transf.txt file.\n");
		exit(0);
	}

	// TODO should verify if we are not copying to the same dir...
	remove(GENERATED_MODULE_FILES_NAME);

	fclose(f);
}

void DoStep1(int argc, char* argv[])
{
	_mkdir("temp");
	if (argc < 4)
	{
		printf("Step1: Error, you should give at least the agapia.txt - the file with AGAPIA module coordination, the type of execution and Def.txt file\n");
		exit(-1);
	}

	/*
	;
	wprintf(L"%ls\n", buff);
	*/

	// Test if we need a distributed or iterative executable
	if (strstr(argv[1], "exectype=iterative"))
	{
		isDistributedRun = false;

		if (strstr(argv[1], "debug"))
		{
			isDebug = true;
		}
	}
	else if (strstr(argv[1], "exectype=distributed"))
	{
		isDistributedRun = true;
		if (strstr(argv[1], "debug"))
		{
			isDebug = true;
		}
	}
	else
	{
		printf("Step1: Error, the first parameter must be either exectype=iterative or exectype=distributed .\n");
		exit(-1);
	}

	// Verify if the second argument is "Def.txt"
	if (strcmp(argv[2], "Def.txt"))
	{
		printf("Error: the second parameter of GenerateApp must be \"Def.txt\" file\n");
		exit(-1);
	}
	else
	{
		FILE *fOutputInclude = fopen("temp/Includes.h", "w");

		// Parse the file and create the "Includes.h"
		FILE* fDef = fopen("Def.txt", "r");
		if (!fDef)
		{
			printf("Error: Can't find the Def.txt file!!!\n");
			exit(-1);
		}

		char lineBuff[1024];
		fgets(lineBuff, 1024, fDef);
		if (lineBuff[0] != '%')
		{
			printf("Error: Def line in Def.txt should begin with 'percent' on the first column\n");
			exit(-1);
		}

		while(!feof(fDef))
		{
			fgets(lineBuff, 1024, fDef);			
			if (lineBuff[0] == '%')
				break;

			fprintf(fOutputInclude, "%s\n", lineBuff);
		}

		fclose(fOutputInclude);
		fclose(fDef);
	}

	
	// Verify if the third argument is agapia.txt and do the necessary actions
	if (strcmp(argv[3], "agapia.txt"))
	{
		printf("Error: the second parameter of GenerateApp must be \"agapia.txt\" file\n");
		exit(-1);
	}

	// Analyze the modules and copy the generated files to compiler path
	AnalyzeModules();

	// Collect all files that need to be copied from here to sln
	std::list<std::pair<std::string,bool>> listOfFilesToBeCopied;
	listOfFilesToBeCopied.push_back(std::make_pair(std::string(INCLUDES_FILE_NAME), true));
	for (int i = 3; i < argc; i++)
	{
		listOfFilesToBeCopied.push_back(std::make_pair(std::string(argv[i]), false));
	}
	//---

	// Copy some files to the sln dir
	char buffDest[CURRDIRPATH_LEN];
	char temp[CURRDIRPATH_LEN];
	for (std::list<std::pair<std::string,bool>>::iterator it = listOfFilesToBeCopied.begin(); it != listOfFilesToBeCopied.end(); it++) 
	{
		const std::pair<std::string, bool>& fileInfo = *it;
		const char* fileName = fileInfo.first.c_str();
		const bool	isTemp = fileInfo.second;
		sprintf(buffDest, "%s/Compiler/%s", gStrAgapiaCompilerSlnPath, fileName);

		// TODO !!! CHECK IF FILE EXIST AND IF THE ATTRIBUTE OF THE FILE IS NOT READ ONLY
		//printf("Copying file %s to %s\n", argv[i], buffDest);


		if (isTemp)
		{
			sprintf_s(temp, CURRDIRPATH_LEN, "temp/%s", fileName);
		}
		else
		{
			sprintf_s(temp, CURRDIRPATH_LEN, "%s", fileName);
		}

		CopyFileHelper(temp, buffDest);
	}

	// Remove the "Includes.h" file
	//remove("Includes.h");

	// Reset the AgapiaToCCode.cpp file
	const char* AGAPITOCCODE_FILE_TEXT = "#include \"AgapiaToCCode.h\"\n void InitializeAgapiaToCFunctions(){}";
	char pathTo_AgapiaToCCode[CURRDIRPATH_LEN];
	sprintf_s(pathTo_AgapiaToCCode, CURRDIRPATH_LEN, "%s" PATH_TOAGAPIATOCPPFILECODE_FROM_SLNROOT, gStrAgapiaCompilerSlnPath);
	FILE *f = fopen(pathTo_AgapiaToCCode, "w");
	fprintf_s(f, "%s", AGAPITOCCODE_FILE_TEXT);
	fclose(f);

	// Modify the CMakeLists file
	//--------------------------------------------------------------------------------------------------------------------------------------------
	// Save the CMakeLists file
	sprintf(buffDest, "%s/Compiler/CMakeLists_copy.txt", gStrAgapiaCompilerSlnPath);
	sprintf(temp, "%s/Compiler/CMakeLists.txt", gStrAgapiaCompilerSlnPath);
	BOOL resC = CopyFileHelper(temp, buffDest);
	if (resC != TRUE)
	{
		printf("Error: can't copy the CMakeLists.txt file from %s\n", buffDest);
		exit(0);
	}

	ModifyCMakeLists(temp);

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//printf("Step 2 ends\n");
}

void CopyGeneratedCodeFile()
{
	char strCompilerExePath[CURRDIRPATH_LEN];
	char strCompilerDestPath[CURRDIRPATH_LEN];
	sprintf_s(strCompilerExePath, CURRDIRPATH_LEN, "%s" PATH_TOAGAPIATOCPPFILECODE_FROM_SLNROOT, gStrAgapiaCompilerSlnPath);
	sprintf_s(strCompilerDestPath, CURRDIRPATH_LEN, "%s/temp/AgapiaToCCode.cpp", gCurrentDirPath);
	BOOL bRes = CopyFileHelper(strCompilerExePath, strCompilerDestPath);
	if (bRes != TRUE)
	{
		printf("Failed to copy the AgapiaToCCode.cpp. You can open the executable but you can't debug errors...\n");
	}
}

void DoStep3()
{
	// const char* MSBULD_PARAMS = " /verbosity:quiet /maxcpucount:4 /nologo /consoleloggerparameters:Summary"; //"/verbosity:quiet /maxcpucount /nodeReuse:True /nologo /consoleloggerparameters:Summary";
	// const char* CONFIGURATION_DISTRIBUTED = (isDebug == false? " /property:Configuration=DistributedRelease" : " /property:Configuration=DistributedDebug");
	// const char* CONFIGURATION_ITERATIVE = (isDebug == false ? " /property:Configuration=IterativeRelease" : " /property:Configuration=IterativeDebug");

	//printf("Step 3 begin\n");

	// char buff[CURRDIRPATH_LEN];
	// if (!GetMSBuildPath(buff))
	// {
	// 	printf("Cannot get the path to .NetFramework. Verify if you have the following file: %s. If not, then install .NET framework 4.0\n", buff);
	// 	exit(0);
	// }

	// char msBuildCommand[CURRDIRPATH_LEN*2];
	// sprintf_s(msBuildCommand, CURRDIRPATH_LEN*2, "\"\"%s\"  \"%s/Compiler.sln\"\"", buff, gStrAgapiaCompilerSlnPath);

	// // Check if we run either the distributed or iterative version
	// if (isDistributedRun)
	// {
	// 	strcat(msBuildCommand, CONFIGURATION_DISTRIBUTED);
	// }
	// else
	// {
	// 	strcat(msBuildCommand, CONFIGURATION_ITERATIVE);
	// }	
	// strcat(msBuildCommand, MSBULD_PARAMS);


	//printf("The build command is: %s\n", msBuildCommand);
	
	// Tries 2 times just to be sure
	// int nrTries = 0;
	// int res = 0;
	// do {
	// 	nrTries++;
	// 	res = system(msBuildCommand);	// TODO here more
	// 	if (res)
	// 	{			
	// 		if (nrTries == 1)
	// 		{
	// 			printf ("------ Failed first time !!!! Trying one more time !!! ------\n");
	// 		}
	// 		else
	// 		{
	// 			printf("Couldn't execute the msbuild command over Compiler.sln :(\n");
	// 			CopyGeneratedCodeFile();
				
	// 			Cleanup();
	// 			exit(0);
	// 		}
	// 	}	
	// }while(res != 0 && nrTries < 2);
	char temp[CURRDIRPATH_LEN];
	sprintf(temp, "cmake -S %s -B %s/build", gStrAgapiaCompilerSlnPath, gStrAgapiaCompilerSlnPath);
	system(temp);
	sprintf(temp, "cmake --build %s/build", gStrAgapiaCompilerSlnPath);
	system(temp);
}

void DoStep2()
{	
	char strCompilerExePath[CURRDIRPATH_LEN];
	if (!isDistributedRun)
	{
		const char *localPathToExeFile = isDebug ? PATH_TO_DEBUGEXE_ITER_FROM_SLNROOT : PATH_TO_RELEASEEXE_ITER_FROM_SLNROOT;
		sprintf_s(strCompilerExePath, CURRDIRPATH_LEN, "%s%s", gStrAgapiaCompilerSlnPath, localPathToExeFile);
	}
	else
	{
		const char *localPathToExeFile = isDebug ? PATH_TO_DEBUGEXE_DISTRI_FROM_SLNROOT : PATH_TO_RELEASEEXE_DISTRI_FROM_SLNROOT;
		sprintf_s(strCompilerExePath, CURRDIRPATH_LEN, "%s%s", gStrAgapiaCompilerSlnPath, localPathToExeFile);
	}

	// Add the generate argument to the executable
	strcat(strCompilerExePath, " g");
	// printf("Running compiler from: %s\n", strCompilerExePath);
	int res = system(strCompilerExePath);
	if (res)
	{
		printf("Failed to execute and generate the C code\n");
		exit(0);
	}
}

void DoStep4()
{
	char strCompilerExePath[CURRDIRPATH_LEN];

	if (!isDistributedRun)
	{
		const char *localPathToExeFile = isDebug ? PATH_TO_DEBUGEXE_ITER_FROM_SLNROOT : PATH_TO_RELEASEEXE_ITER_FROM_SLNROOT;
		sprintf_s(strCompilerExePath, CURRDIRPATH_LEN, "%s%s", gStrAgapiaCompilerSlnPath, localPathToExeFile);
	}
	else
	{
		const char *localPathToExeFile = isDebug ? PATH_TO_DEBUGEXE_DISTRI_FROM_SLNROOT : PATH_TO_RELEASEEXE_DISTRI_FROM_SLNROOT;
		sprintf_s(strCompilerExePath, CURRDIRPATH_LEN, "%s%s", gStrAgapiaCompilerSlnPath, localPathToExeFile);
	}

	char strCompilerDestPath[CURRDIRPATH_LEN];
	#ifdef _WIN32
	sprintf_s(strCompilerDestPath, CURRDIRPATH_LEN, "%s/AgapiaProgram.exe", gCurrentDirPath);
	#else
	sprintf_s(strCompilerDestPath, CURRDIRPATH_LEN, "%s/AgapiaProgram", gCurrentDirPath);
	#endif

	BOOL bRes = CopyFileHelper(strCompilerExePath, strCompilerDestPath);
	if (bRes != TRUE)
	{
		printf("Failed to copy the final executable :(\n");
		return ;
	}
	printf("Final executable copied. You can now use your AGAPIA program\n");
	CopyGeneratedCodeFile();

	// Copy the AgapiaToCCode.cpp file for debugging
}

void Cleanup()
{
	//remove(FILENAME_OF_TRANSFORMED_AGAPIA_FILE);

	// Revert the Compiler.vxproj file back from Compiler_copy.vxproj
	char buffDest[CURRDIRPATH_LEN];
	char temp[CURRDIRPATH_LEN];
	sprintf(buffDest, "%s/Compiler/Compiler.vcxproj", gStrAgapiaCompilerSlnPath);
	sprintf(temp, "%s/Compiler/Compiler_copy.vcxproj", gStrAgapiaCompilerSlnPath);
	BOOL resC = CopyFileHelper(temp, buffDest);
	if (resC != TRUE)
	{
		printf("Error: can't copy the Compiler.vcxproj file from %s\n", buffDest);
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	gStrAgapiaCompilerSlnPath = getenv("AGAPIAPATH");
	if (gStrAgapiaCompilerSlnPath == NULL || strlen(gStrAgapiaCompilerSlnPath) == 0)
	{
		printf("AGAPIAPATH environment variable was not defined. Please define it\n");
		exit(0);
	}

	GetCurrentDirectory(CURRDIRPATH_LEN, gCurrentDirPath);

	// 1. Copy all files specified in the argument list from the current dir, to the AGAPIA folder
	//    Reset the AgapiatoCCode.cpp file to make sure that is ok
	DoStep1(argc, argv);

	// The compiler should have been created at this point
	//--// Make sure that the exe is created
#ifdef GENERATE_EXE_EACH_TIME_BEFORE_CODEGEN
	DoStep3();
#endif

	// 2. Execute the Compiler.exe to create the AgapiaToCCode.cpp file.
	DoStep2();
	
	// 3. Execute the msbuild to rebuild the project with the new generated code
	DoStep3();

	// 4. Copy the new generated exe from Release to the current folder
	DoStep4();

	Cleanup();

	return 0;
}
