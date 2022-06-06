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
		cout << "\nотработал конструктор 1\n" << this << endl;
		
	}
	
	Set(int size, int* arr) : sizeArrSet{ size }, arrSet{ new int [sizeArrSet] {} }
	{
		bool unic = true;
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] == arr[j])
				{
					unic = false;
				}
			}
			if (unic == false)
				break;
		}
		if (unic)
		{
			for (int i = 0; i < sizeArrSet; i++)
			{
				arrSet[i] = arr[i];
			}
		}
		else
		{
			arrSet = nullptr;
			cout << "\nМножество не создано, элементы не уникальны\n";
		}
		cout << "\nотработал конструктор 2\n" << this << endl;
	}
	

	Set() : Set(0) { cout << "\nотработал конструктор 3\n" << this << endl; }

	~Set()
	{
		delete[]arrSet;
		cout << "\nотработал деструктор\n" << this << endl;
	}

	Set (const Set& set) : arrSet{ new int[set.sizeArrSet] }, sizeArrSet {set.sizeArrSet} //конструктор копирования
	{
		for (int i{ 0 }; i < sizeArrSet; ++i)
		{
			arrSet[i] = set.arrSet[i];
		}
	}
	friend ostream& operator << (ostream& output, const Set& set);//перегрузка cout
	
	friend istream& operator>>(istream& input, Set& set);//перегрузка cin

	Set& add(const int c); //добавление элемента

	Set& del();

	friend int inputInt();
	
	Set& setMembershipCheck();// проверка на принадлежность множеству

	friend const Set operator+(const Set& set1, const Set& set2);//сложение объектов
	friend const Set operator+(const Set& set1, int a);//объект с интом
	const Set& operator=(const Set& set1);// присваивание
	bool operator==(const Set& set1) const;
	

};

