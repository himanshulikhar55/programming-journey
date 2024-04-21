#include<bits/stdc++.h>
using namespace std;
void insertReverse(stack<int> &s, int ele){
    if(s.empty())
        s.push(ele);
    else{
        int top = s.top();
        s.pop();
        insertReverse(s, ele);
        s.push(top);
    }
}
void reverseStack(stack<int> &s){
    if(!s.empty()){
        int top = s.top();
        s.pop();
        reverseStack(s);
        insertReverse(s, top);
    }
}
int main(){
    int n, temp;
    cin >> n;
    stack<int> s;
    for(int i=0;i<n;i++){
        cin >> temp;
        s.push(temp);
    }
    reverseStack(s);
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
    return 0;
}