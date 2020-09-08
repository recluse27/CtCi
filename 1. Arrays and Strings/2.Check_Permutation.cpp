// Given two strings,write a method to decide if one is a permutation of the other.

#include <iostream>

using namespace std;

bool check_perm(string s1, string s2)
{
    if (s1.length() != s2.length())
        return (true);
    
    const int ht_length = 93;
    int ht[ht_length] = {0}; // can change to char array = size / 4

    for (int i = 0; i < s1.length(); i++)
    {
        ht[int(s1[i]) - 33] += 1;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        ht[int(s2[i]) - 33] -= 1;
    }

    for (int i = 0; i < ht_length; i++)
    {
        if (ht[i] != 0)
            return (true);
    }

    return (false);
}

bool check_perm_2(string s1, string s2)
{
    if (s1.length() != s2.length())
        return (true);

    sort(s1.begin(), s1.end()); // O(nlogn) sort from <algorithm>
    sort(s2.begin(), s2.end()); // O(nlogn) sort from <algorithm>

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            return (true);
    }

    return (false);
}

int main()
{
    string test1 = "!2380954{sgklnxzv}122";
    string test2 = "!2380954{sgklnxzv}1221";
    cout << check_perm(test1, test2) << endl;

    cout << check_perm(test1, test2) << endl;

    return 0;
}