/*4)	Прочитайте во встроенный массив С содержимое текстового файлы, 
скопируйте данные в вектор одной строкой кода (без циклов и алгоритмов STL)*/

#include <iostream>
#include <vector>
#include <fstream>

#define SIZE 6

using namespace std;


int main()
{
	int arr[SIZE];

	ifstream myfile("array.txt");          //opening the file.
	if (myfile.is_open()) {                     //if the file is open

		while (!myfile.eof()) {                 //while the end of file is NOT reached

			// Push items into a vector
			int current_number = 0;
			int i = 0;
			while (myfile >> current_number) {
				arr[i++] = current_number;
			}

			// Close the file.
			myfile.close();

		}

		// Display the numbers read:
		cout << "Array: ";
		for (int count = 0; count < SIZE; count++) {
			cout << arr[count] << " ";
		}

		cout << endl;
		cout << "Vector: ";

		vector<int> vect(arr, arr + SIZE);

		for (int i = 0; i < vect.size(); i++)
		{
			cout << vect[i] << " ";
		}


	} else {
		cout << "Error!";
		_exit(0);
	}

}
