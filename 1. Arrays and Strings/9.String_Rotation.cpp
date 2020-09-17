// Assume you have a method isSubstringwhich checks if one word is a substring of another.
// Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one 
// call to isSubstring (e.g.,"waterbottle" is a rotation of"erbottlewat").

#include <iostream>

using namespace std;

bool isRotation(string s1, string s2 )
{
	size_t len1 = s1.length();
	size_t len2 = s2.length();
	if (len1 == 0 || len1 != len2)
		return false;
    
	string concatS1 = s1 + s1;
	
    if (concatS1.find(s2) != string::npos)
		return true;
	else
		return false;
}

int main()
{
    string test1 = "waterbottle";
    string test2 = "erbottlewat";

    cout << isRotation(test1, test2) << endl;

	return 0;
}