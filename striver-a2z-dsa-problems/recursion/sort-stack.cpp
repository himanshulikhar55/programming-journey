#include<bits/stdc++.h>
using namespace std;
void insertDesc(stack<int> &s, int ele){
    if(s.empty() || s.top() < ele)
        s.push(ele);
    else{
        int top = s.top();
        s.pop();
        insertDesc(s, ele);
        s.push(top);
    }
}
stack<int> sortStack(stack<int> &s){
    if(!s.empty()){
        int top = s.top();
        s.pop();
        sortStack(s);
        insertDesc(s,top);
    }
    return s;
}
int main(){
    int n, temp;
    cin >> n;
    stack<int> s;
    for(int i=0;i<n;i++){
        cin >> temp;
        s.push(temp);
    }
    s = sortStack(s);
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
    return 0;
}