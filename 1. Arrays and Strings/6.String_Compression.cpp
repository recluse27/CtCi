// Implement a method to perform basic string compression using the counts of repeated characters.
// For example, the string aabcccccaaa would become a2blc5a3. 
// If the "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include <iostream>

using namespace std;

string compressString(string str)
{
    string res = "";

    for (int i = 0; i < str.length();)
    {
        int n = 1;
        while ((str[i] == str[i + n]) && ((i + n) < str.length()))
            n++;
        res += str[i] + to_string(n);
        i += n;
    }

    if (res.length() < str.length())
        return (res);
    return (str);
}

int main()
{
    string test = "aabcccccaaa";
    cout << compressString(test) << endl;

    return 0;
}