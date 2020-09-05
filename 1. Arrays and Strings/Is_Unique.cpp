// Implement an algorithm to determine if a string has all unique characters. (1)
// What if you cannot use additional data structures? (2)

#include <iostream>

using namespace std;

bool is_unique_1(string s)
{
    int ht[93] = {0}; // can change to char array = size / 4

    for (int i; i < s.length(); i++)
    {
        ht[int(s[i]) - 33] += 1;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (ht[int(s[i]) - 33] > 1)
            return (false);
    }

    return (true);
}

bool is_unique_2(string s)
{
    sort(s.begin(), s.end()); // O(nlogn) sort from <algorithm>

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
            return (false);
    }

    return (true);
}

int main()
{
    string test = "!2380954{sgklnxzv}12";
    cout << is_unique_1(test) << endl;

    cout << is_unique_2(test) << endl;

    return 0;
}