#include <numeric>
#include <chrono>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace chrono;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cerr << "Scrivi: " << argv[0] << " dimensione\n";
	}
	
	const unsigned int size = stoi(argv[1]);
	const unsigned int Simulation = 25;
		
	vector<double> v(size);
	
	iota(v.begin(), v.end(), 1);
	random_shuffle(v.begin(), v.end());
	
	double BubbleTime = 0;
	for(size_t i = 0; i < Simulation; i++)
	{
		vector<double> copy = v;
		auto start = steady_clock::now();
		SortLibrary::BubbleSort(copy);
		auto end = steady_clock::now();
		
		BubbleTime += duration_cast<microseconds>(end - start).count();
	}
	
	BubbleTime /= Simulation;
	
	
	double HeapTime = 0;
	for(size_t i = 0; i < Simulation; i++)
	{
		vector<double> copy = v;
		auto start = steady_clock::now();
		SortLibrary::HeapSort(copy);
		auto end = steady_clock::now();
		
		HeapTime += duration_cast<microseconds>(end - start).count();
	}
	
	HeapTime /= Simulation;
	
	
	cout<< "BubbleSort: "<<BubbleTime<<" μs"<<endl;
	cout<< "HeapSort: "<<HeapTime<<" μs"<<endl;
	
	return 0;
}

