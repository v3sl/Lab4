#include <iostream>
#include <vector>

using namespace std;

int my_atoi(const char* inputString) {
	int result = 0;
	for (int i = 0; inputString[i] != '\0'; i++) {
		if (inputString[i] > '0' && inputString[i] < '9')
			result = result * 10 + (inputString[i] - '0');
		else
			if (i == 0 && inputString[i] == '-')
				result = result;
			else
				break;
	}
	if (inputString[0] == '-')
		result = -result;
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
int CountLetters(char* arary_for_string_TASK2, char input) {
	int number_of_letters = 0;
	for (int i = 0; arary_for_string_TASK2[i] != input; i++) {
		if (arary_for_string_TASK2[i] == '.') {
			break;
		}
		else {
			number_of_letters++;
		}
	}
	return number_of_letters;
}

void find_words(char input,char* arary_for_string_TASK2, vector<int>& first_space, vector<int>& last_space) {
	first_space.push_back(0);
	for (int i = 0; arary_for_string_TASK2[i] != input; i++) {
		if (arary_for_string_TASK2[i] == ' ' || arary_for_string_TASK2[i] == '.') {
			first_space.push_back(i);
			last_space.push_back(i);
		}
	}
	last_space.push_back(CountLetters(arary_for_string_TASK2, input));
}

void result(char* arary_for_string_TASK2, vector<int>& first_space, vector<int>& last_space) {
	vector<int> result_vector;
	for (int i = 0; i < last_space.size(); i++)
		result_vector.push_back(find_the_most_frequent_element(first_space[i], last_space[i], arary_for_string_TASK2));
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
		cout << arary_for_string_TASK2[i];

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
	vector<int>first_space;
	vector<int>last_space;
	char* arary_for_string_TASK2 = new char[max_size];
	cout << "Enter some text" << endl;
	char input = NULL;
	for (int i = 0; input != '.'; i++) {
		cin.get(input);
		arary_for_string_TASK2[i] = input;
	}
	find_words(input, arary_for_string_TASK2, first_space, last_space);
	result(arary_for_string_TASK2, first_space, last_space);
	return 0;
}