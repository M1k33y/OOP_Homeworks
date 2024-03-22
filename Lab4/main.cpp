// seminar4.poo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sort.h"

using namespace std;
int main()
{
	
	Sort v(7, 2, 100);
	v.Print();
	cout << "verificare constructor1" << endl;


	v.QuickSort();
	v.Print();
	cout << "verificare quicksort" << endl;


	int numere[] = { 3,6,1,2,5 };
	Sort a(numere);
	a.InsertSort();
	a.Print();
	cout << "verificare constructor2 si InsertSort" << endl;

	Sort b(numere, 4);
	b.BubbleSort();
	b.Print();
	cout << "verificare constructor3 si BubbleSort" << endl;

	Sort c(4, 10, 4, 8, 11);
	c.InsertSort();
	c.Print();
	cout << "verificare constructor4" << endl;

	char caract[] = "10,12,4,3,5,20";
	Sort d(caract);
	d.BubbleSort();
	d.Print();
	cout << "verificare constructor5" << endl;
	cout<<d.GetElementsCount()<<endl;
	cout << "verificare GetElementCount" << endl;
	cout << d.GetElementFromIndex(3) << endl;
	cout << "verificare GetElementFromIndex"<<endl;
	



}

