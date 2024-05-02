#include<bits/stdc++.h>
using namespace std;
/*
    Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

    Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has
    a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the
    number of your content children and output the maximum number.

    Constraints:

    1 <= g.length <= 3 * 10^4
    0 <= s.length <= 3 * 10^4
    1 <= g[i], s[j] <= 2^31 - 1
*/

int findContentChildren(vector<int>& greeds, vector<int>& sizes) {
    int ans=0;
    sort(greeds.begin(), greeds.end());
    sort(sizes.begin(), sizes.end());
    int j=0, n = greeds.size(), m = sizes.size();
    for(int i=0; i<n && j<m; i++, j++){
        while(j<m && greeds[i] > sizes[j])
            ++j;
        if(j<m)
            ++ans;
    }
    return ans;
}

int main(){
    int n, m;
    cout << "Enter the greeds:\n";
    cin >> n;
    vector<int> greeds = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> greeds[i];
    cout << "Enter the cookie sizes:\n";
    cin >> m;
    vector<int> sizes = vector<int>(m);
    for(int i=0;i<m;i++)
        cin >> sizes[i];
    cout << "The max number of children that can be content is: " << findContentChildren(greeds, sizes) << '\n';
    return 0;
}