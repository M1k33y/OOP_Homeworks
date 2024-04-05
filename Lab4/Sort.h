#pragma once



class Sort
{
	int* v;
	int lg;
	void QuickSort(int* v, int st, int dr,bool ascendent);
	int Partitionare(int* v, int st, int dr,bool ascendent);

	// add data members
public:
	Sort(int nr, int min, int max);
	Sort(int *a);
	Sort(int* a, int nr);
	Sort(int nr, ...);
	Sort(char* c);
	// add constuctors

	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
};