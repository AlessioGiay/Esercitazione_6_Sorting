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
	void heapify(vector<T>& v, int n, int i)
	{
		int max = i;
		int sinistro = 2 * i + 1;
		int destro = 2 * i + 2;

		if (sinistro < n && v[sinistro] > v[max])
		{
			max = sinistro;
		}

		if (destro < n && v[destro] > v[max])
		{
			max = destro;
		}

		if (max != i)
		{
			swap(v[i], v[max]);
			heapify(v, n, max);
		}
	}

	template<typename T>
	void HeapSort(vector<T>& v)
	{
		int n = v.size();

		for (int i = n / 2 - 1; i >= 0; --i)
		{
			heapify(v, n, i);
		}

		for (int i = n - 1; i > 0; --i)
		{
			swap(v[0], v[i]);
			heapify(v, i, 0);
		}
	}
}