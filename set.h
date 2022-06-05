#pragma once
#include <iostream>
using namespace std;
class Set
{
private:

	int sizeArrSet;// размер массива множеств
	int* arrSet;	// указатель массив множеств

public:
	Set(int size) : sizeArrSet{ size }
	{
		if (size == 0)
		{
			arrSet = nullptr;
		}
		else
		{
			arrSet = new int[size];
			

		}
		
	}
	
	Set(int size, int* arr) : sizeArrSet{ size }, arrSet{ new int [sizeArrSet] {} }
	{
		for (int i = 0; i < sizeArrSet; i++)
		{
			this->arrSet[i] = arr[i];
		}
	}
	

	Set() : Set(0) {}

	~Set()
	{
		delete[]arrSet;
		cout << "отработал деструктор";
	}

	friend ostream& operator << (ostream& output, const Set& set)
	{
		for (int i = 0; i < set.sizeArrSet; i++)
		{
			output << set.arrSet[i] << " ";
		}
		return output;
	}

	friend istream& operator>>(istream& input, Set& set)
	{
		for (int i{ 0 }; i < set.sizeArrSet; ++i)
		{
			input >> set.arrSet[i];
		}
		return input;
	}

	Set& add(const int c)
	{
		int* temp = new int[sizeArrSet+1];
		for (int i = 0; i < sizeArrSet; i++)
		{
			if (arrSet[i] = c)
			{
				return;
			}
			temp[i] = arrSet[i];
		}
		temp[sizeArrSet] = c;
		delete[]arrSet;
		arrSet = temp;
		sizeArrSet = ++sizeArrSet;
	}

};

