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
