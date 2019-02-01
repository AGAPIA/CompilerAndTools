#include "AgapiaToCCode.h"
#include "ExecutionBlackbox.h"
#include "InputTypes.h"

#include "Includes.h"


void CITIRE(InputBlock* pNorth, InputBlock* pWest, InputBlock* pSouth, InputBlock* pEast)
{
	// Local variables declaration: 
	int& ppermutationa = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[0])->GetValueRef();
	int& chunksizea = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[1])->GetValueRef();
	int& npermsizea = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[2])->GetValueRef();
	int& strallcontenta = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[3])->GetValueRef();
	int& ppermutationb = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[1])->m_InputItems[0])->GetValueRef();
	int& chunksizeb = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[1])->m_InputItems[1])->GetValueRef();
	int& npermsizeb = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[1])->m_InputItems[2])->GetValueRef();
	int& strallcontentb = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[1])->m_InputItems[3])->GetValueRef();
	int& ppermutationc = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[2])->m_InputItems[0])->GetValueRef();
	int& chunksizec = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[2])->m_InputItems[1])->GetValueRef();
	int& npermsizec = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[2])->m_InputItems[2])->GetValueRef();
	int& strallcontentc = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[2])->m_InputItems[3])->GetValueRef();


	// User code: 
		std::ifstream testTextFile("clearText.txt");
		std::ofstream permutationTextFileWrite("permutationParallel.txt");	
		std::string strAllContent,strLine, strEncrypted;
	       	std::vector<int> arrPermutation;
	
		if (testTextFile.is_open())
		{
			while (getline(testTextFile, strLine))
			{
				strAllContent.append(strLine.begin(), strLine.end());
			}
			testTextFile.close();
		}
		else
		{
			std::cout << "Failed to open file";
			return;
		}
		std::srand(unsigned(std::time(0)));
		for (size_t i = 0; i < strAllContent.size(); ++i)
		{
			arrPermutation.push_back(i);
		}
	
		std::random_shuffle(arrPermutation.begin(), arrPermutation.end());
	
		permutationTextFileWrite << arrPermutation.size() << " ";
		for (size_t i = 0; i < arrPermutation.size(); ++i)
		{
			permutationTextFileWrite << arrPermutation[i] << " ";
		}
		permutationTextFileWrite.close();
	
		int nTextSize = (int)strAllContent.size();
		int nPermutationSize = (int)arrPermutation.size();
	
		int* ppermutation = new int[nPermutationSize];
		for (int i = 0; i < nPermutationSize; ++i)
		{
			ppermutation[i] = arrPermutation[i];
		}
	
	ppermutationa = (int)ppermutation;
	ppermutationb = (int)ppermutation;
	ppermutationc = (int)ppermutation;
	int chunkSize = nPermutationSize / 3;
	chunksizea = (int)chunkSize;
	chunksizeb = (int)chunkSize;
	chunksizec = (int)chunkSize;
	npermsizea = (int)nPermutationSize;
	npermsizeb = (int)nPermutationSize;
	npermsizec = (int)nPermutationSize;
	
	char * cstrAllContent = new char[strAllContent.size() + 1];
	std::copy(strAllContent.begin(), strAllContent.end(), cstrAllContent);
	cstrAllContent[strAllContent.size()] = '\0'; 
	strallcontenta = (int)cstrAllContent;
	strallcontentb = (int)cstrAllContent;
	strallcontentc = (int)cstrAllContent;
	
	

}




void SCRIERE(InputBlock* pNorth, InputBlock* pWest, InputBlock* pSouth, InputBlock* pEast)
{
	// Local variables declaration: 
	int& locala = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[0])->GetValueRef();
	int& localb = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[1])->m_InputItems[0])->GetValueRef();
	int& localc = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[2])->m_InputItems[0])->GetValueRef();


	// User code: 
	std::string strFinalEncrypted;
	std::string strLocalStringA((char*)locala);
	std::string strLocalStringB((char*)localb);
	std::string strLocalStringC((char*)localc);
	strFinalEncrypted.append(strLocalStringA.begin(), strLocalStringA.end());
	strFinalEncrypted.append(strLocalStringB.begin(), strLocalStringB.end());
	strFinalEncrypted.append(strLocalStringC.begin(), strLocalStringC.end());
	std::ofstream encryptedTextFile("encryptedTextParallel.txt");
	encryptedTextFile<<strFinalEncrypted;
	encryptedTextFile.close();
	
	

}




void SLAVEA(InputBlock* pNorth, InputBlock* pWest, InputBlock* pSouth, InputBlock* pEast)
{
	// Local variables declaration: 
	int& perm = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[0])->GetValueRef();
	int& chunksizea = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[1])->GetValueRef();
	int& npermsizea = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[2])->GetValueRef();
	int& strallcontenta = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[3])->GetValueRef();
	int& locala = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[0])->GetValueRef();


	// User code: 
	std::string strEncryptedChunk;
	int*pPermutation=(int*)perm;
	std::string strText((char*)strallcontenta);
	int localsizea= chunksizea;
	for (int i = 0; i < localsizea; ++i)
		{
			strEncryptedChunk.append(strText.begin() + pPermutation[i], strText.begin() + pPermutation[i] + 1);
		}
	
	char * cstrLocalEncrypted = new char[localsizea + 1];
	std::copy(strEncryptedChunk.begin(), strEncryptedChunk.end(), cstrLocalEncrypted);
	cstrLocalEncrypted[localsizea] = '\0'; 
	locala = (int)cstrLocalEncrypted;
	
	
	

}




void SLAVEB(InputBlock* pNorth, InputBlock* pWest, InputBlock* pSouth, InputBlock* pEast)
{
	// Local variables declaration: 
	int& perm = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[0])->GetValueRef();
	int& chunksizeb = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[1])->GetValueRef();
	int& npermsizeb = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[2])->GetValueRef();
	int& strallcontentb = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[3])->GetValueRef();
	int& localb = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[0])->GetValueRef();


	// User code: 
	std::string strEncryptedChunk;
	int*pPermutation=(int*)perm;
	std::string strText((char*)strallcontentb);
	int localsizeb= chunksizeb;
	for (int i = localsizeb; i < 2*localsizeb; ++i)
		{
			strEncryptedChunk.append(strText.begin() + pPermutation[i], strText.begin() + pPermutation[i] + 1);
		}
	
	char * cstrLocalEncrypted = new char[localsizeb + 1];
	std::copy(strEncryptedChunk.begin(), strEncryptedChunk.end(), cstrLocalEncrypted);
	cstrLocalEncrypted[localsizeb] = '\0'; 
	localb = (int)cstrLocalEncrypted;
	
	
	

}




void SLAVEC(InputBlock* pNorth, InputBlock* pWest, InputBlock* pSouth, InputBlock* pEast)
{
	// Local variables declaration: 
	int& perm = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[0])->GetValueRef();
	int& chunksizec = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[1])->GetValueRef();
	int& npermsizec = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[2])->GetValueRef();
	int& strallcontentc = ((IntDataItem*)((SimpleProcessItem*)pWest->m_InputsInBlock[0])->m_InputItems[3])->GetValueRef();
	int& localc = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[0])->GetValueRef();


	// User code: 
	std::string strEncryptedChunk;
	int*pPermutation=(int*)perm;
	std::string strText((char*)strallcontentc);
	int localsizec= chunksizec;
	int last=npermsizec;
	int nLocalChunkSize = last - 2*localsizec;
	for (int i = 2*localsizec; i < last ; ++i)
				{
					strEncryptedChunk.append(strText.begin() + pPermutation[i], strText.begin() + pPermutation[i] + 1);
				}
	
	char * cstrLocalEncryptec = new char[nLocalChunkSize + 1];
	std::copy(strEncryptedChunk.begin(), strEncryptedChunk.end(), cstrLocalEncryptec);
	cstrLocalEncryptec[nLocalChunkSize] = '\0'; 
	localc = (int)cstrLocalEncryptec;
	
	

}


void InitializeAgapiaToCFunctions()
{
ExecutionBlackbox::Get()->AddAgapiaToCFunction("CITIRE", &CITIRE);
ExecutionBlackbox::Get()->AddAgapiaToCFunction("SCRIERE", &SCRIERE);
ExecutionBlackbox::Get()->AddAgapiaToCFunction("SLAVEA", &SLAVEA);
ExecutionBlackbox::Get()->AddAgapiaToCFunction("SLAVEB", &SLAVEB);
ExecutionBlackbox::Get()->AddAgapiaToCFunction("SLAVEC", &SLAVEC);
}
