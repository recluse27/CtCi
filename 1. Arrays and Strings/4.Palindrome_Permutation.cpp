// Given a string, write a function to check if it is a permutation of a palin­ drome.
// A palindrome is a word or phrase that is the same forwards and backwards.
// A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

/*
 * Solution Philosophy:
 * For a string to be pallindrome, it should be able to spelled backward and forward the same.
 * Therefore the chars in string should fit one of the two possibilities:
 *  - Each char appear even number of times in the string ( even length string )
 *  - Each char should appear even number of times, except just one char ( odd length string )
 * 
 * We won't care about the case of the letter
 */

#include <iostream>

using namespace std;

int getCharIndex(char c)
{
    int idx = -1;
    if (c >= 'a' && c <= 'z')
        idx = c - 'a';

    else if (c >= 'A' && c <= 'Z')
        idx = c - 'A';
    return idx;
}

void countFrequency(string str, int *frequency)
{
    int idx;
    for (int i = 0; i < str.length(); i++)
    {
        idx = getCharIndex(str[i]);
        if (idx != -1)
            ++frequency[idx];
    }
}

bool isPermutationOfPallindrome1(string str)
{
    int frequency[26] = {0};
    countFrequency(str, frequency);

    /*
     * We will check here that letter frequencies are all even or all even except one odd.
     */
    bool oddAppeared = false;

    for (int i = 0 ; i < 26; ++i) {
        if (frequency[i] % 2  && oddAppeared)
            return false;
        else if (frequency[i] % 2 && !oddAppeared)
            oddAppeared = true;
    }
    return true;
}

bool isPermutationOfPallindrome2(string str)
{
    int oddCount = 0;
    int frequency[26] = {0};
    int idx = 0;
    for (int i = 0; i < str.length(); i++)
    {
        idx = getCharIndex(str[i]);
        if (idx != -1)
        {
            ++frequency[idx];
            if (frequency[idx] % 2)
                ++oddCount;
            else
                --oddCount;
        }
    }
    return (oddCount <= 1);
}

int main()
{
    string test = "Maman";
    cout << isPermutationOfPallindrome1(test) << endl;
    cout << isPermutationOfPallindrome2(test) << endl;

    return 0;
}
