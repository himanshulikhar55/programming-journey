#include <bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int end) {
        if(start > end)
            return minBitFlips(end, start);
        int count = 0;
        while(end){
            if((end ^ start) == 0)
                break;
            end = end >> 1;
            count++;
        }
        return count;
    }
int main(){
    int start, end;
    cin >> start >> end;
    cout << minBitFlips(start, end) << endl;
    return 0;
}   