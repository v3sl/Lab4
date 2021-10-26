#pragma once
#include <cassert>
#include "functions.h"
#include <vector>

void test_atoi1() {
	char test[4] = {
		'1', '2', '3', '4'
	};
	int result = my_atoi(test);
	assert( result == 1234);
}

void test_atoi2() {
	char test[5] = {
		'-', '1', '2', '3', '4'
	};
	int result = my_atoi(test);
	assert(result == -1234);
}

void test_atoi3() {
	char test[5] = {
		'a', '1', '2', '3', '4'
	};
	int result = my_atoi(test);
	assert(result == 0);
}

void test_atoi4() {
	char test[6] = {
		'1', '1', '2', 'a', '4','5'
	};
	int result = my_atoi(test);
	assert(result == 112);
}

void test_find_the_most_frequent_element1() {
	char test[5] = {
		'a','a','a','b','b'
	};
	int result = find_the_most_frequent_element(0, 5, test);
	assert(result == 3);
}

void test_find_the_most_frequent_element2() {
	char test[5] = {
	};
	int result = find_the_most_frequent_element(0, 5, test);
	assert(result == 0);
}

void test_find_the_most_frequent_element3() {
	char test[6] = { 'a', 'a', 'a', 'b', 'b', 'b'
	};
	int result = find_the_most_frequent_element(0, 5, test);
	assert(result == 3);
}

void  test_CountLetters1() {
	char test[8] = { 'a','a', 'a', 'a', 'a', ' ', '4', '.'
	};
	int result = CountLetters(test, NULL);
	assert(result == 7);
}

void  test_CountLetters2() {
	char test[8] = { 'a','a', 'a', '.', 'a', ' ', '4', '.'
	};
	int result = CountLetters(test, NULL);
	assert(result == 3);
}

void run_tests() {
	test_atoi1();
	test_atoi2();
	test_atoi3();
	test_atoi4();
	test_find_the_most_frequent_element1();
	test_find_the_most_frequent_element2();
	test_find_the_most_frequent_element3();
	test_CountLetters1();
	test_CountLetters2();
}
