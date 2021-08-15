/*6)	Напишите функцию void fillRandom(double* array, int size) заполняющую массив случайными значениями в 
интервале от -1.0 до 1.0. Заполните с помощью заданной функции вектора размером 5,10,25,50,100 и отсортируйте 
его содержимое (с помощью любого разработанного ранее алгоритма модифицированного для сортировки действительных чисел) */

#include <iostream>
#include <vector>
#include <chrono>

#define SIZE 6

using namespace std;
using namespace std::chrono;

void fillRandom(double* array, int size);

void fillRandomVector(vector<double>& vec, int size);

double randNumber(double minNum, double maxNum);

void bubble_sort_with_at(vector<double>& vec);

void print_sort_time(vector<double>& vec, int size);

int main()
{
	double arr[SIZE];

	fillRandom(arr, SIZE);

	vector<double> vec5;
	vector<double> vec10;
	vector<double> vec25;
	vector<double> vec50;
	vector<double> vec100;

	fillRandomVector(vec5, 5);
	fillRandomVector(vec10, 10);
	fillRandomVector(vec25, 25);
	fillRandomVector(vec50, 50);
	fillRandomVector(vec100, 100);

	print_sort_time(vec5, 5);
	print_sort_time(vec10, 10);
	print_sort_time(vec25, 25);
	print_sort_time(vec50, 50);
	print_sort_time(vec100, 100);

}

void fillRandom(double* array, int size) {

	for (long i = 0; i < size; i++) {
		array[i] = randNumber(-1.0, 1.0);
	}

}

void fillRandomVector(vector<double>& vec, int size) {

	for (long i = 0; i < size; i++) {
		vec.push_back(randNumber(-1.0, 1.0));
	}

}

double randNumber(double minNum, double maxNum) {
	double f = (double)rand() / RAND_MAX;
	return minNum + f * (maxNum - minNum);
}

void bubble_sort_with_at(vector<double>& vec) {
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

void print_sort_time(vector<double>& vec, int size) {
	auto start = high_resolution_clock::now();
	bubble_sort_with_at(vec);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time sort vector " << size << " elements: " << duration.count() << " microseconds" << endl;
}
