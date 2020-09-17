//  There are three types of edits that can be performed on strings: insert a character, remove a character, 
// or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

#include <iostream>

using namespace std;

bool OneAway(string s1, string s2)
{
    int a_l, b_l;

    a_l = s1.length();
    b_l = s2.length();

    if (abs(a_l - b_l) < 2)
    {
        string a, b;

        a = s1.length() > s2.length() ? s1 : s2;
        b = s1.length() <= s2.length() ? s1 : s2;

        a_l = a.length();
        b_l = b.length();

        int i = 0;
        int j = 0;

        int mismatch = 0;

        while (i < a_l && j < b_l)
        {
            if (a[i] != b[j])
            {
                mismatch++;
                if (a_l > b_l)
                    i++;
                else
                {
                    i++;
                    j++;
                }
                
                if (mismatch > 1)
                    return (false);
            }
            else
            {
                i++;
                j++;
            }
        }
        return (true);
    }
    return (false);
}

int main()
{
    cout << OneAway("pale", "ple") << endl;
    cout << OneAway("pales", "pale") << endl;
    cout << OneAway("pale", "pales") << endl;
    cout << OneAway("pale", "bale") << endl;
    cout << OneAway("pale", "bake") << endl;
    cout << OneAway("pale", "pakle") << endl;

    return (0);
}
