#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary 
{
	template<typename T>
	
	void  BubbleSort(vector<T>& v)
	{
		const unsigned int n = v.size();
		
		for(size_t i = 0; i < n-1; i++)
		{
			for(size_t j = i+1; j < n; j++)
			{
				if(v[j] < v[i])
				{
					const T tmp = v[i];
					v[i] = v[j];
					v[j] = tmp;
				}
			}
		}
	}

	template<typename T>
	
	void HeapSort(vector<T>& v)
	{
		unsigned int n = v.size();
		
		while(n)
		{
			for(size_t son = 1; son < n; son++)
			{
				unsigned int father = (son-1)/2;
				
				while(v[father] < v[son])
				{
					const T tmp = v[son];
					v[son] = v[father];
					v[father] = tmp;
					
					if(father!=0)
					{
						son = father;
						father = (son-1)/2;
					}
				}
			}
			
			T tmp = v[n-1];
			v[n-1] = v[0];
			v[0] = tmp;
			
			n--;
		}
	}			
}