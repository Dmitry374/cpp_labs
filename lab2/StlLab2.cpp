#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <vector>

using namespace std;

void read_file(string&);
void print_string(string&);
void remove_not_whitespaces_symbols(string&); // ex2_a
void remove_extra_whitespaces(string&); // ex2_b
void remove_whitespaces_before_punct_symbols(string&); // ex2_c
void create_whitespaces_after_punct_symbols(string&); // ex2_d
void replase_big_words(string&); // ex2_e
vector<string> split_text_on_lines(string&); // Ex3

void print_vector(vector<string>& vec);

int main()
{
	vector<string> vec;
	string str;

	read_file(str);
	print_string(str);

	cout << "Ex2_a. Remove_not_whitespaces_symbols:" << endl;
	remove_not_whitespaces_symbols(str);
	print_string(str);

	cout << "Ex2_b. Remove extra whitespaces:" << endl;
	remove_extra_whitespaces(str);
	print_string(str);

	cout << "Ex2_c. Remove whitespaces before punctuation symbols:" << endl;
	remove_whitespaces_before_punct_symbols(str);
	print_string(str);

	cout << "Ex2_d. Create whitespaces after punctuation symbols:" << endl;
	create_whitespaces_after_punct_symbols(str);
	print_string(str);

	cout << "Ex2_e. Replase words 10 symbols and more on word 'Vau!!!':" << endl;
	replase_big_words(str);
	print_string(str);

	cout << "Ex3. Split text  on lines 40 chars length:" << endl;
	vec = split_text_on_lines(str);
	print_vector(vec);


}

void read_file(string& str) {
	ifstream myfile("text.txt");          //opening the file.

	myfile.seekg(0, ios::end);
	str.reserve(myfile.tellg());
	myfile.seekg(0, ios::beg);

	str.assign((istreambuf_iterator<char>(myfile)),
		istreambuf_iterator<char>());
}

void print_string(string& str) {
	cout << str << "\n" << endl;
}

void remove_not_whitespaces_symbols(string& str) {
	string not_whitespaces_symbols("\a\b\f\n\r\t\v");

	int pos = str.find_first_of(not_whitespaces_symbols);

	while (pos != string::npos) {  //npos – максимально возможное количество символов
		str[pos] = ' ';
		pos = str.find_first_of(not_whitespaces_symbols);
	}

}

void remove_extra_whitespaces(string& str) {
	int pos = str.find(' ');

	for (int i = pos; i < str.length(); i++) {

		while (str[i] == str[pos] && str[i + 1] == str[pos]) {
			str.erase(i + 1, 1);
		}

		pos = str.find(' ');

	}
}

void remove_whitespaces_before_punct_symbols(string& str) {
	int pos = str.find_first_of(".?!,:;–(\"");

	for (int i = str.find(' '); i < str.length(); i++) {
		while (str[i] == ' ' && str[i + 1] == str[pos]) {
			str.erase(i, 1);
		}

		pos = str.find_first_of(".?!,:;–(\"", i);

	}
}

void create_whitespaces_after_punct_symbols(string& str) {
	int pos = str.find_first_of(".?!,:;–(\"");

	for (int i = pos; i < str.length(); i++) {

		while (str[i] == str[pos] && str[i + 1] != ' ') {
			str.insert(i+1, " ");
		}

		pos = str.find_first_of(".?!,:;–(\"", i);

	}

}

void replase_big_words(string& str) {

	string word = "";
	string text = "";
	for (auto x : str)
	{
		if (!isalpha(x))
		{

			if (word.length() >= 10) {
				word = "Vau!!!";
			}

			text = text + word + " ";

			word = "";
		}
		else
		{
			word = word + x;
		}

	}

	str = text;

}

vector<string> split_text_on_lines(string& str) {

	vector<string> vec;

	int begin = 0;

	//Разбиение строки my_string на отдельные подстроки (элементы вектора my_vector) длиной не более 40 символов
	for (int end = begin + 40; end < str.length(); end += 40) {
		while (str[end] != ' ') { //Т.к. слова нельзя переносить по частям, ищем пробел для окончания подстроки
			end--;
		}
		//if(my_string[end] != ' ') {
			//end = my_string.rfind(' ', end+1);
		//}
		int line_len = end - begin;
		string line = str.substr(begin, line_len); //Формируем подстроку line из строки my_string
		vec.push_back(line); //Добавляем подстроку line в вектор my_vector
		begin = end;
	}

	return vec;
}

void print_vector(vector<string>& vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "\n";
	cout << endl << endl;
}