/*5)	Напишите программу, сохраняющую в векторе числа, полученные из стандартного ввода 
(окончанием ввода является число 0). Удалите все элементы, которые делятся на 2 (не используете стандартные алгоритмы STL), 
если последнее число 1. Если последнее число 2, добавьте после каждого числа которое делится на 3 три единицы.*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;

	int number;

	cout << "Input numbers to vector: " << endl;

	cin >> number;

	while (number != 0)
	{
		vec.push_back(number);
		cin >> number;
	}

	if (vec.back() == 1)
	{
		for (vector<int>::iterator i = vec.begin(); i != vec.end(); ) {
			if (*i % 2 == 0)
			{
				i = vec.erase(i);
			}
			else
			{
				++i;
			}
		}
	}

	if (vec.back() == 2)
	{
		for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++) {
			if (*i % 3 == 0)
			{
				i = vec.insert(i + 1, 3, 1);
			}
		}
	}

	cout << endl;

	for (vector<int>::iterator i = vec.begin(); i < vec.end(); i++) {
		cout << *i << " ";
	}
}