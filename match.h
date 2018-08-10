#ifndef match_h
#define match_h
#include <iostream>
using namespace std;

bool matchCore(char *str, char *pattern);

bool match(char *str, char *pattern) {
	if (str == nullptr || pattern == nullptr)
		return false;

	return matchCore(str, pattern);
}

bool matchCore(char *str, char *pattern) {
	if (*str == '\0' && *pattern == '\0')
		//str和pattern同时到头了。
		return true;

	if (*str != '\0' && *pattern == '\0')
		//str没到头但是pattern到头了。
		return false;

	if (*(pattern + 1) == '*') {
		//pattern首字符的下一个字符是*
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			//首字符匹配上了，其中'.'可以和任意字符匹配。有三种策略：
			return matchCore(str + 1, pattern + 2) //str往前走一步，pattern往前走两步：这对应着a* = a的情况。
				|| matchCore(str + 1, pattern) //str往前走一步，pattern不走：这对应着a* = aaaa...a的情况
				|| matchCore(str, pattern + 2);//str不走，pattern往前走两步：这对应着a* = 的情况。
		else 
			//首字符没有匹配上，直接跳过pattern的前两个字符。
			return matchCore(str, pattern + 2);
	}
	//pattern首字符的下一个字符不是*
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		//首字符匹配上了，str和pattern都各往后走一步。
		return matchCore(str + 1, pattern + 1);

	return false;
}
#endif
