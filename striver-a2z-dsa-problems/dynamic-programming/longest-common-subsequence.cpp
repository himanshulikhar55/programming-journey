#include<string.h>
#include<iostream>
using namespace std;

int longestCommonSubsequence(string str1, string str2) {
    int len1 = str1.length(), len2 = str2.length();
    int **dp = (int **)malloc(sizeof(int *) * (len1+1));
    for(int i=0;i<=len1;i++)
        dp[i] = (int *)malloc(sizeof(int) * (len2+1));
    for(int i=0;i<=len1;i++)
        dp[i][0] = 0;
    for(int i=0;i<=len2;i++)
        dp[0][i] = 0;
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[len1][len2];
}

int main(){
    string str1, str2;
    cout << "Enter str1: ";
    cin >> str1;
    cout << "Enter str2: ";
    cin >> str2;
    cout << "The length of longest common subsequence is: " << longestCommonSubsequence(str1, str2) << '\n';
    return 0;
}