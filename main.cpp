#include <iostream>
#include "match.h"
using namespace std;
void test1() {
	cout<<"Test1."<<endl;
	char str[6] = {'a', 'b', 'c', 'c', 'c', '\0'};
	char pattern[5] = {'a', '.', 'c', '*', '\0'};
	if (match(str, pattern)) {
		cout<<"Matched."<<endl;
	}
	else {
		cout<<"Not matched."<<endl;
	}
}

void test2() {
	cout<<"Test2."<<endl;
	char str[6] = {'a', 'b', 'c', 'c', 'c', '\0'};
	char pattern[5] = {'a', '.', '*', '*', '\0'};
	if (match(str, pattern)) {
		cout<<"Matched."<<endl;
	}
	else {
		cout<<"Not matched."<<endl;
	}
}

void test3() {
	cout<<"Test3."<<endl;
	char str[6] = {'a', 'b', 'c', 'c', 'c', '\0'};
	char pattern[5] = {'*', '.', 'c', '*', '\0'};
	if (match(str, pattern)) {
		cout<<"Matched."<<endl;
	}
	else {
		cout<<"Not matched."<<endl;
	}
}

int main() {
	test1();
	test2();
	test3();
	return 0;
}


