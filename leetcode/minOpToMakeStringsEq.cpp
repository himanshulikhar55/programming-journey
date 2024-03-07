#include <bits/stdc++.h> 
using namespace std;
int minimumOperations(string &a, string &b)
{
    if (a.size() != b.size())
    {
        return -1;
    }
    int n = a.size();
    int count = 0;
    char c1, c2, c3, c4;
    for (int i = 0; i < n / 2; i++)
    {
        c1 = a[i];
        c2 = a[n - i - 1];
        c3 = b[i];
        c4 = b[n - i - 1];
        if ((c1 == c2 && c3 == c4) ||
            (c1 == c3 && c2 == c4) ||
            (c1 == c4 && c2 == c3))
        {
            continue;
        }
        else if (c1 == c3 ||
                 c1 == c4 ||
                 c2 == c3 ||
                 c2 == c4 ||
                 c3 == c4)
        {
            count++;
        }
        else
        {
            count += 2;
        }
    }
    if (n % 2 == 1 && a[n / 2] != b[n / 2])
    {
        count++;
    }
    return count;
}