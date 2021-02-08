#include "AgapiaToCCode.h"
#include "ExecutionBlackbox.h"
#include "InputTypes.h"

#include "Includes.h"


void CITIRE(InputBlock* pNorth, InputBlock* pWest, InputBlock* pSouth, InputBlock* pEast)
{
	// Local variables declaration: 
	int& perminversea = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[0])->GetValueRef();
	int& chunksizea = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[1])->GetValueRef();
	int& npermsizea = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[2])->GetValueRef();
	int& strallcontenta = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[0])->m_InputItems[3])->GetValueRef();
	int& perminverseb = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[1])->m_InputItems[0])->GetValueRef();
	int& chunksizeb = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[1])->m_InputItems[1])->GetValueRef();
	int& npermsizeb = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[1])->m_InputItems[2])->GetValueRef();
	int& strallcontentb = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[1])->m_InputItems[3])->GetValueRef();
	int& perminversec = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[2])->m_InputItems[0])->GetValueRef();
	int& chunksizec = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[2])->m_InputItems[1])->GetValueRef();
	int& npermsizec = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[2])->m_InputItems[2])->GetValueRef();
	int& strallcontentc = ((IntDataItem*)((SimpleProcessItem*)pEast->m_InputsInBlock[2])->m_InputItems[3])->GetValueRef();


	// User code: 
	std::string strLine;
	std::string strEncrypted;
	std::string strDecrypted;
	std::ifstream permutationTextFileRead("permutationParallel.txt");
	std::ifstream encryptedTextFileRead("encryptedTextParallel.txt");
	std::vector<int> arrPermutation;
		
		int nPermutationSize = 0;
		permutationTextFileRead >> nPermutationSize;
		for (int i = 0; i < nPermutationSize; ++i)
		{
			int nPermutationElement;
			permutationTextFileRead >> nPermutationElement;
			arrPermutation.push_back(nPermutationElement);
		}
		permutationTextFileRead.close();
		if (encryptedTextFileRead.is_open())
			{
			while (getline(encryptedTextFileRead, strLine))
			{
			strEncrypted.append(strLine.begin(), strLine.end());
			}
			encryptedTextFileRead.close();
			}
	
	std::vector<int> arrInverse;
		for (size_t i = 0; i < arrPermutation.size(); i++)
		{
			for (size_t j = 0; j < arrPermutation.size(); j++)
			{
				if (arrPermutation[j] == i)
				{
					arrInverse.push_back(j);
					break;
				}
			}
		}
	
		int nTextSize =(int)strEncrypted.size();
		nPermutationSize = (int)arrPermutation.size();
		int* perminverse= new int[nPermutationSize];
		for (int i = 0; i < nPermutationSize; ++i)
		{
			perminverse[i] = arrInverse[i];
		}
	
	perminversea = (int)perminverse;
	perminverseb = (int)perminverse;
	perminversec = (int)perminverse;
	int chunkSize = nPermutationSize / 3;
	chunksizea = (int)chunkSize;
	chunksizeb = (int)chunkSize;
	chunksizec = (int)chunkSize;
	npermsizea = (int)nPermutationSize;
	npermsizeb = (int)nPermutationSize;
	npermsizec = (int)nPermutationSize;
	
	char * cstrAllContent = new char[strEncrypted.size() + 1];
	std::copy(strEncrypted.begin(), strEncrypted.end(), cstrAllContent);
	cstrAllContent[strEncrypted.size()] = '\0'; 
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
	std::ofstream encryptedTextFile("DecryptedTextParallel.txt");
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
	for (int i = localsizeb ; i < 2*localsizeb; ++i)
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
	
	char * cstrLocalEncrypted = new char[nLocalChunkSize + 1];
	std::copy(strEncryptedChunk.begin(), strEncryptedChunk.end(), cstrLocalEncrypted);
	cstrLocalEncrypted[nLocalChunkSize] = '\0'; 
	localc = (int)cstrLocalEncrypted;
	
	

}


void InitializeAgapiaToCFunctions()
{
ExecutionBlackbox::Get()->AddAgapiaToCFunction("CITIRE", &CITIRE);
ExecutionBlackbox::Get()->AddAgapiaToCFunction("SCRIERE", &SCRIERE);
ExecutionBlackbox::Get()->AddAgapiaToCFunction("SLAVEA", &SLAVEA);
ExecutionBlackbox::Get()->AddAgapiaToCFunction("SLAVEB", &SLAVEB);
ExecutionBlackbox::Get()->AddAgapiaToCFunction("SLAVEC", &SLAVEC);
}
