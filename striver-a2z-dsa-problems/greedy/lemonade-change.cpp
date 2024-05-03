#include<bits/stdc++.h>
using namespace std;
/*
    At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order
    specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct
    change to each customer so that the net transaction is that the customer pays $5.

    Note that you do not have any change in hand at first.

    Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the
    correct change, or false otherwise.

    Constraints:

    1 <= bills.length <= 10^5
    bills[i] is either 5, 10, or 20.
*/
bool lemonadeChange(vector<int>& bills) {
    int numOfFive = 0, numOfTen = 0, len = bills.size();
    for(int i=0; i<len; i++){
        if(bills[i] == 5){
            ++numOfFive;
        }else if(bills[i] == 10){
            if(numOfFive == 0)
                return false;
            --numOfFive;
            ++numOfTen;
        }else {
            if(numOfFive > 0 && numOfTen > 0){
                --numOfFive;
                --numOfTen;
            } else if(numOfFive > 2){
                numOfFive -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> bills = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> bills[i];
    if(lemonadeChange(bills))
        cout << "Yes, we can provide every customer with the correct change :)\n";
    else
        cout << "No, we cannot  provide every customer with the correct change :(\n";
    return 0;
}