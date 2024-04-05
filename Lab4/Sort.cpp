#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Sort.h"
#include <cstdarg>


using namespace std;

Sort::Sort(int nr, int min, int max)
{
	v = (int*)malloc((nr + 1) * 4);

	srand(time(0));
	for (int i = 0; i < nr; i++)
		v[i] = rand() % (max - min+1) + min;

	this->lg = nr;

}
Sort::Sort(int *a)
{
	
	v = (int*)malloc(sizeof(a));
	
	//memcpy(v, a, sizeof(a));
	this->lg = sizeof(a) / 4;
	
	for (int i = 0; i < this->lg; i++)
		v[i] = a[i];
}
Sort::Sort(int* a, int nr)
{
	v = (int*)malloc((nr + 1) * 4);
	for (int i = 0; i < nr; i++)
		v[i] = a[i];
	this->lg = nr;

}
Sort::Sort(int nr, ...)
{
	va_list  args;
	va_start(args, nr);
	v = (int*)malloc((nr + 1) * 4);
	int k = 0;
	this->lg = nr;
	while (nr)
	{
		v[k++] = va_arg(args, int);

		nr--;

	}
	va_end(args);

}
Sort::Sort(char* c)
{
	int nr = 1;
	for (int i = 0; i < strlen(c); i++)
		if (c[i] == ',')
			nr++;
	v = (int*)(malloc((nr + 1) * 4));

	char* p;
	int k = 0;
	p = strtok(c, ",");
	while (p)
	{
		v[k++] = atoi(p);

		p = strtok(NULL, ",");
	}
	this->lg = k;
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < lg; i++)
		for (int j = i; j > 0; j--)
		{
			if (!ascendent)
			{
				if (v[j] > v[j - 1])
					swap(v[j], v[j - 1]);
				else
					break;
			}
			else
			{
				if (v[j] < v[j - 1])
					swap(v[j], v[j - 1]);
				else
					break;
			}

		}

}

void Sort::QuickSort(bool ascendent)
{
	
	QuickSort(v, 0, lg - 1,ascendent);


}
int Sort::Partitionare(int v[], int st, int dr,bool ascendent)
{

	int pivot = v[dr];
	
	int i = (st - 1);

	for (int j = st; j <= dr; j++)
	{
	
		if (v[j] < pivot &&ascendent ||(v[j]>pivot &&!ascendent))
		{
			
			i++;
			swap(v[i], v[j]);
		}

	}
	swap(v[i + 1], v[dr]);
	return (i + 1);
}

void Sort::QuickSort(int* v, int st, int dr,bool ascendent)
{

	if (st < dr) 
	{
		int p = Partitionare(v, st, dr,ascendent);
		
		QuickSort(v, st, p - 1,ascendent);
		QuickSort(v, p + 1, dr,ascendent);
	}
}

void Sort::BubbleSort(bool ascendent )
{
	for (int i = 0; i < lg; i++)
		for (int j = 0; j < lg - 1; j++)
				if (v[j] > v[j + 1] &&ascendent ||(!ascendent && v[j] < v[j + 1]))
				swap(v[j], v[j + 1]);

}
void Sort::Print()
{
	for (int i = 0; i < lg; i++)
		cout << v[i] << " ";
	cout << endl;
}
int Sort::GetElementsCount()
{
	return lg;

}
int Sort::GetElementFromIndex(int index)
{
	return v[index];
}