#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>             
#include <cstdlib>  
#include <string>
#include <string.h>
#include <assert.h>



std::vector<int> inversePermutation(std::vector<int>& arrPermutation)
{
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

	return arrInverse;
}


	