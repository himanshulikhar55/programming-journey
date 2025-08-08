#include <bits/stdc++.h>
using namespace std;
int countPalindromicSubsequence(string s)
{
    set<string> pals;
    int n = s.length();
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        vector<int> freq = vector<int>(26, 0);
        int fPos = 0, sPos = 0;
        while (fPos < n && s[fPos] != c)
            fPos++;
        if (fPos >= n - 2)
            continue;
        if (s[fPos + 1] == c)
        {
            sPos = fPos + 2;
            freq[c-'a']++;
        }
        else
        {
            sPos = fPos + 1;
        }
        while (sPos < n && s[sPos] != c)
        {
            freq[s[sPos]-'a']++;
            sPos++;
        }
        if (sPos < n)
        {
            int pos = c - 'a', i = 0;
            // freq[s[sPos]-'a']++;
            while (i < 26)
            {
                if (freq[i] > 0)
                {
                    string temp = string(3, '\0');
                    temp[0] = c;
                    temp[1] = (i + 'a');
                    temp[2] = c;
                    pals.insert(temp);
                    cout << temp << '\n';
                }
                i++;
            }
        }
    }
    return pals.size();
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << "The number of unqiue 3 len subseq are: " << countPalindromicSubsequence(s) << '\n';
}