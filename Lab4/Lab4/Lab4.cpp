#include <iostream>
#include <vector>

using namespace std;

int my_atoi(const char* inputString) {
	int result = 0;
	while (*inputString != '\0') {
		if (*inputString < '0' || *inputString > '9')
			break;
		else
			result = result * 10 + (*inputString++ - '0');
	}
	return result;
}

int find_the_most_frequent_element(int firstSpace, int lastSpace, char* inputString) {
	vector<char> all_letters;
	vector<int> number_of_the_same_letters(26);
	int number_of_letters = 'a';
	for (int i = 0; i < 26; i++) {
		all_letters.push_back(number_of_letters);
		number_of_letters++;
	}
	for (int i = 0; i < number_of_the_same_letters.size(); i++)
		number_of_the_same_letters[i] = 0;
	for (int i = firstSpace; i < lastSpace; i++) {
		for (int j = 0; j < 26; j++) {
			if (inputString[i] == all_letters[j])
				number_of_the_same_letters[j]++;
		}
	}
	int max_result = INT_MIN;
	for (int i = 0; i < number_of_the_same_letters.size(); i++) {
		if (number_of_the_same_letters[i] > max_result) {
			max_result = number_of_the_same_letters[i];
		}
	}
	return max_result;
}

int main() {
	cout << "Enter the size of your stirng" << endl;
	int size;
	cin >> size;
	char* arary_for_string_TASK1 = new char[size + 1];
	arary_for_string_TASK1[size] = '\0';
	cout << "Enter the elements of your string" << endl;
	for (int i = 0; i < size; i++)
		cin >> arary_for_string_TASK1[i];
	cout << "TASK 1" << endl << my_atoi(arary_for_string_TASK1) << endl;
	const int max_size = 300;
	char* arary_for_string_TASK2 = new char[max_size];
	cout << "Enter some text" << endl;
	char input = NULL;
	for (int i = 0; input != '.'; i++) {
		cin.get(input);
		arary_for_string_TASK2[i] = input;
	}
	int number_of_letters = 0;
	for (int i = 0; arary_for_string_TASK2[i] != input; i++) {
		if (arary_for_string_TASK2[i] == '.') {
			break;
		}
		else {
			number_of_letters++;
		}
	}
	number_of_letters++;
	vector<int>arr_for_the_first_space;
	vector<int>arr_for_the_last_space;
	arr_for_the_first_space.push_back(0);
	int last_space = 0, first_space = 0, g = 0;
	for (int i = 0; arary_for_string_TASK2[i] != input; i++) {
		if (arary_for_string_TASK2[i] == ' ' || arary_for_string_TASK2[i] == '.') {
			arr_for_the_first_space.push_back(i);
			arr_for_the_last_space.push_back(i);
		}
	}
	arr_for_the_last_space.push_back(number_of_letters - 1);
	vector<int> result_vector;
	for (int i = 0; i < arr_for_the_last_space.size(); i++)
		result_vector.push_back(find_the_most_frequent_element(arr_for_the_first_space[i], arr_for_the_last_space[i], arary_for_string_TASK2));
	int result = INT_MIN, for_i = 0;
	for (int i = 0; i < result_vector.size(); i++) {
		if (result_vector[i] > result) {
			result = result_vector[i];
			for_i = i;
		}
	}
	int for_the_first_spaces, for_the_last_spaces;
	for_the_first_spaces = arr_for_the_first_space[for_i];
	for_the_last_spaces = arr_for_the_last_space[for_i];
	for (int i = for_the_first_spaces; i < for_the_last_spaces; i++)
		cout << arary_for_string_TASK2[i];
	return 0;
}