#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(char* s) {
	string str = s;
	bool limit = true;
	int len = str.length();
	if (len % 2 == 1)
		limit = false;
	for (int i = 0; i < str.length(); i++)
	{
		// check how many occurance for the given char.
		std::string::difference_type n = std::count(str.begin(), str.end(), str[i]);
		if (n % 2 == 1)
		{
			if (limit)
				return -1;
			limit = true;
		}
		// remove them and continue.
		str.erase(std::remove(str.begin(), str.end(), str[i]), str.end());
	}
}