/*
1)	Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя оператор operator[].

2)	Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя метод at().

3)	Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя для 
доступа к содержимому вектора только итераторы. Для работы с итераторами допустимо использовать только 
операторы получения текущего элемента и перехода в следующему (подсказка, можно сохранять копию итератора 
указывающего на некоторый элемент).
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>

#define SIZE 100

using namespace std;
using namespace std::chrono;


void bubble_sort(vector<int>& vec);

void bubble_sort_with_at(vector<int>& vec);

void bubble_sort_iterator(vector<int>& vec);

void bubble_sort_standart(vector<int>& vec);

int main()
{
	vector<int> vec;
	vector<int> vec_copy;

	for (long i = 0; i < SIZE; i++) {
		vec.push_back(rand());
	}

	vec_copy = vec;

	// Сотрировка с []
	auto start = high_resolution_clock::now();
	bubble_sort(vec_copy);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time sort with []: " << duration.count() << " microseconds" << endl;


	vec_copy = vec;

	// Сортировка с at()
	start = high_resolution_clock::now();
	bubble_sort_with_at(vec_copy);
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);
	cout << "Time sort with at(): " << duration.count() << " microseconds" << endl;


	vec_copy = vec;

	// Сортировка через iterator
	start = high_resolution_clock::now();
	bubble_sort_iterator(vec_copy);
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);
	cout << "Time sort with iterator: " << duration.count() << " microseconds" << endl;

	// сортировка через sort()
	vec_copy = vec;

	start = high_resolution_clock::now();
	bubble_sort_standart(vec_copy);
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);
	cout << "Time sort standart algorithm sort: " << duration.count() << " microseconds" << endl;

}

void bubble_sort(vector<int>& vec) {
	int r;

	// Сортировка массива пузырьком
	for (int i = 0; i < vec.size() - 1; i++) {
		for (int j = 0; j < vec.size() - i - 1; j++) {
			if (vec[j] > vec[j + 1]) {
				// меняем элементы местами
				r = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = r;
			}
		}
	}
}

void bubble_sort_with_at(vector<int>& vec) {
	int r;

	// Сортировка массива пузырьком
	for (int i = 0; i < vec.size() - 1; i++) {
		for (int j = 0; j < vec.size() - i - 1; j++) {
			if (vec.at(j) > vec.at(j + 1)) {
				// меняем элементы местами
				r = vec.at(j);
				vec.at(j) = vec.at(j + 1);
				vec.at(j + 1) = r;
			}
		}
	}
}

void bubble_sort_iterator(vector<int>& vec) {
	vector<int>::iterator begin = vec.begin();
	vector<int>::iterator end = vec.end();

	for (vector<int>::iterator i = begin; i != end; ++i)
		for (vector<int>::iterator j = begin; j < i; ++j)
			if (*i < *j)
				iter_swap(i, j);
}

void bubble_sort_standart(vector<int>& vec) {
	sort(vec.begin(), vec.end());
}