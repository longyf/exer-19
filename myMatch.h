#ifndef my_match_h
#define my_match_h
#include <iostream>
using namespace std;
bool myMatchCore(char *str, char *pattern);

bool myMatch(char *str, char *pattern) {
	if (str == nullptr || pattern == nullptr)
		return false;

	return myMatchCore(str, pattern);
}

bool myMatchCore(char *str, char *pattern) {
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*') {
		if (*str == *pattern || (*str != '\0' && *pattern == '.')) {
			return myMatchCore(str + 1, pattern + 2)
				|| myMatchCore(str + 1, pattern)
				|| myMatchCore(str, pattern + 2);
		}
		else {
			return myMatchCore(str, pattern + 2);
		}
	}

	if (*str == *pattern || (*str != '\0' && *pattern == '.')) {
		myMatchCore(str + 1, pattern + 1);
	}

	return false;
}
#endif
