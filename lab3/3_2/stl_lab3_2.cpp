/*a. Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать 
от 0 до 20 значений (обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)

b. Выводит содержимое списка в следующем порядке: первый элемент, последний элемент, 
второй элемент, предпоследний элемент, тритий элемент и т.д.

Например если список содержит:
1 2 3 4 5 6 7 8
то вывод будет иметь вид
1 8 2 7 3 6 4 5
*/

#include <iostream>
#include <cstdlib>
#include <list>
#include <ctime>

using namespace std;

typedef list<int> list_type;
list_type list_numbers;

int get_random_number();
void fill_random_list(list_type&, int);
void print_list(list_type&);
void print_list_elements(list_type&);

int main()
{
	// initialization random number generator
	srand(time(0));

	fill_random_list(list_numbers, 15);
    
	print_list(list_numbers);

	cout << "Print new list" << endl << endl;

	print_list_elements(list_numbers);
}

int get_random_number() {
	return (rand() % 20) + 1;
}

void fill_random_list(list_type& num_list, int size) {
	for (int i = 0; i < size; i++) {
		int num = get_random_number();
		num_list.push_back(num);
	}
}

void print_list(list_type& num_list) {
	for (list_type::iterator i = num_list.begin(); i != num_list.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
}

void print_list_elements(list_type& num_list) {
	auto iter1 = num_list.begin();
	auto iter2 = num_list.rbegin();

	for(; ; iter1++, iter2++) {
		if (*iter1 == *iter2) {
			cout << *iter1 << endl;
			break;
		}

		cout << *iter1 << " " << *iter2 << " ";
	}
}