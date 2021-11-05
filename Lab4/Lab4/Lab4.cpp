#include <iostream>
#include <vector>
#include "functions.h"
#include "Tests.h"

using namespace std;

const char g_endString('\0');

int my_atoi(const char* inputString) {
	int result = 0;
    char zero = '0';
    char nine =  '9';
    char minus = '-';
	for (int i = 0; inputString[i] != g_endString; i++) {
		if (inputString[i] > zero && inputString[i] < nine)
			result = result * 10 + (inputString[i] - zero);
		else
			if (i == 0 && inputString[i] == minus)
				result = result;
			else
				break;
	}
	if (inputString[0] == minus)
		result = -result;
	return result;
}

int find_the_most_frequent_element(int firstSpace, int lastSpace, const char* inputString) {
	int numberOfLettersInAlphabet = 26;
    vector<char> all_letters;
	vector<int> number_of_the_same_letters(numberOfLettersInAlphabet);
	int number_of_letters = 'a';
	for (int i = 0; i < numberOfLettersInAlphabet; i++) {
		all_letters.push_back(number_of_letters);
		number_of_letters++;
	}
	for (int & number_of_the_same_letter : number_of_the_same_letters)
		number_of_the_same_letter = 0;
	for (int i = firstSpace; i < lastSpace; i++) {
		for (int j = 0; j < numberOfLettersInAlphabet; j++) {
			if (inputString[i] == all_letters[j])
				number_of_the_same_letters[j]++;
		}
	}
	int max_result = INT_MIN;
	for (int number_of_the_same_letter : number_of_the_same_letters) {
		if (number_of_the_same_letter > max_result) {
			max_result = number_of_the_same_letter;
		}
	}
	return max_result;
}

int CountLetters(const char* array_for_string_TASK2, char input) {
	int number_of_letters = 0;
	for (int i = 0; array_for_string_TASK2[i] != input; i++) {
		if (array_for_string_TASK2[i] == '.') {
			break;
		}
		else {
			number_of_letters++;
		}
	}
	return number_of_letters;
}

void find_words(char input,char* array_for_string_TASK2, vector<int>& first_space, vector<int>& last_space) {
	first_space.push_back(0);
	for (int i = 0; array_for_string_TASK2[i] != input; i++) {
		if (array_for_string_TASK2[i] == ' ' || array_for_string_TASK2[i] == '.') {
			first_space.push_back(i);
			last_space.push_back(i);
		}
	}
	last_space.push_back(CountLetters(array_for_string_TASK2, input));
}

void result(char* array_for_string_TASK2, vector<int>& first_space, vector<int>& last_space) {
	vector<int> result_vector;
    result_vector.reserve(last_space.size());
for (int i = 0; i < last_space.size(); i++) {
        result_vector.push_back(find_the_most_frequent_element(first_space[i], last_space[i], array_for_string_TASK2));
    }
	int result = INT_MIN, for_i = 0;
	for (int i = 0; i < result_vector.size(); i++) {
		if (result_vector[i] > result) {
			result = result_vector[i];
			for_i = i;
		}
	}
	int for_the_first_spaces, for_the_last_spaces;
	for_the_first_spaces = first_space[for_i];
	for_the_last_spaces = last_space[for_i];
	for (int i = for_the_first_spaces; i < for_the_last_spaces; i++)
		cout << array_for_string_TASK2[i];

}

int main() {
	cout << "Enter the size of your string" << endl;
	int size;
	cin >> size;
	char* array_for_string_TASK1 = new char[size + 1];
	array_for_string_TASK1[size] = g_endString;
	cout << "Enter the elements of your string" << endl;
	for (int i = 0; i < size; i++)
		cin >> array_for_string_TASK1[i];
	cout << "TASK 1" << endl << my_atoi(array_for_string_TASK1) << endl;
	const int max_size = 300;
	vector<int>first_space;
	vector<int>last_space;
	char* array_for_string_TASK2 = new char[max_size];
	cout << "Enter some text" << endl;
	char input = NULL;
	for (int i = 0; input != '.'; i++) {
		cin.get(input);
		array_for_string_TASK2[i] = input;
	}
	find_words(input, array_for_string_TASK2, first_space, last_space);
	result(array_for_string_TASK2, first_space, last_space);
	run_tests();
	return 0;
}