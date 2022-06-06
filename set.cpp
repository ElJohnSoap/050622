#include "set.h"

void answer(bool a) //cout в ответ
{
	if (a)
		cout << "Является\n";
	else
		cout << "Не является\n";
}
int inputInt()
{
	int a;
	cin >> a;
	return a;
}

const Set operator+(const Set& set1, const Set& set2)
{
	Set temp(set1);
	for (int i = 0; i < set2.sizeArrSet; i++)
	{
		temp.add(set2.arrSet[i]);
	}
	return temp;
}

const Set operator+(const Set& set1, int a)
{
	Set temp(set1);
	temp.add(a);
	return temp;
}

ostream& operator<<(ostream& output, const Set& set)
{
	if (set.arrSet != nullptr)
	{
		for (int i = 0; i < set.sizeArrSet; i++)
		{
			output << set.arrSet[i] << " ";
		}
		cout << endl;
	}
	else output << "\nArray nullptr\n";
	return output;
}

istream& operator>>(istream& input, Set& set)
{	
	int a;
	input >> a;
	set.add(a);
	return input;
}

Set& Set::add(const int c)
{
	int* temp = new int[sizeArrSet + 1];
	for (int i = 0; i < sizeArrSet; i++)
	{
		if (arrSet[i] == c)
		{
			return *this;
		}
		temp[i] = arrSet[i];
	}
	temp[sizeArrSet] = c;
	delete[]arrSet;
	arrSet = temp;
	sizeArrSet = sizeArrSet + 1;
		
	return *this;
}

Set& Set::del()
{
	int c = inputInt();
	int* temp = new int[sizeArrSet-1];
	for (int i = 0, j = 0; i < sizeArrSet; i++, j++)
	{
		if (arrSet[i] == c)
		{
			++i;
		}
		temp[j] = arrSet[i];
	}
	delete[]arrSet;
	arrSet = temp;
	sizeArrSet = sizeArrSet - 1;

	return *this;
}

Set& Set::setMembershipCheck()
{
	int a = inputInt();
	bool unic = false;
	for (int i = 0; i < sizeArrSet; i++)
	{
		if (arrSet[i] == a)
		{
			unic = true;
			answer(unic);
			return *this;
		}
	}
	answer(unic);
	return *this;
}

const Set& Set::operator=(const Set& set1)
{
	{
		if (&set1 != this)
		{
			if (sizeArrSet != set1.sizeArrSet)
			{
				delete[] arrSet;
				sizeArrSet = set1.sizeArrSet;
				arrSet = new int[sizeArrSet];
			}
			for (int i = 0; i < sizeArrSet; ++i)
			{
				arrSet[i] = set1.arrSet[i];
			}
		}
		return *this;
	}
}

bool Set::operator==(const Set& set1) const
{
	{
		if (sizeArrSet != set1.sizeArrSet)
		{
			return false;
		}
		for (int i{ 0 }; i < sizeArrSet; ++i) {
			if (arrSet[i] != set1.arrSet[i]) {
				return false;
			}
		}
		return true;
	}
}
