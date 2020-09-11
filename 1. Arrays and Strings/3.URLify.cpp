// Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters,and that you are given the "true" length of the string. (Note: If implementing in Java,please use a character array so that you can perform this operation in place.)

#include <iostream>

using namespace std;

string urlify(string s, int len)
{
    string str = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
            str += "%20";
        else if (s[i] != ' ')
            str += s[i];
    }    

    return (str);
}

int main()
{
    string test = "Mr John Smith";
    cout << urlify(test, 13) << endl;

    return 0;
}