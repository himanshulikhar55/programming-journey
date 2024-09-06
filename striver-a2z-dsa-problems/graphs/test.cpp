#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, marks;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> marks;
        if(marks < 0 || marks > 100)
            cout << "INVALID ";
        else if(marks >= 90)
            cout << "AA ";
        else if(marks >= 80 && marks < 90)
            cout << "AB ";
        else if(marks >= 70 && marks < 80)
            cout << "BB ";
        else if( marks >= 60 && marks < 70)
            cout << "BC ";
        else if (marks >= 40 && marks<60)
            cout << "CC ";
        else
            cout << "F ";
    }
    return 0;
}