#include <bits/stdc++.h>
using namespace std;
void calc_digits(int n, vector<int> &digits){
    while(n){
        digits.push_back(n%10);
        n = n/10;
    }
    reverse(digits.begin(), digits.end());
}
void calc_rem_val(vector<int> &digits, int *val){
    int temp = 0;
    for(int i=1;i<digits.size();i++)
        temp = (temp*10)+digits[i];
    *val = temp+1;
}
int calc_num(int sum, int *freq, int curr_num, int n){
    if(curr_num > n)
        return 0;
    if(*freq == sum)
        return curr_num;
    int temp = 0, ret_val;
    // cout << "Here\n";
    for(int i=0;i<10;i++){
        temp = (curr_num*10)+i;
        // cout << temp << ' ';
        ret_val = calc_num(sum, &(++(*freq)), temp, n);
        if(!ret_val){
            --(*freq);
            continue;
        } else if(ret_val != -1){
            return ret_val;
        }   
    }
    return -1;
}
int findKthNumber(int n, int k) {
    if(n < 10)
        return k;
    vector<int> digits;
    int num = 1, ten_pow = 1, all_ones, rem_val, sum = 0, freq = 1;
    calc_digits(n, digits);
    calc_rem_val(digits, &rem_val);
    for(int i=0;i<digits.size()-1;i++)
        ten_pow *= 10;
    all_ones = (ten_pow-1)/9;
    ten_pow = ten_pow;
    for(int i=1;i<11;i++){
        if(num<digits[0]){
            if(sum + all_ones + ten_pow >= k)
                break;
            sum += all_ones + ten_pow;
        } else if(num == digits[0]){
            if(sum + all_ones + rem_val >= k)
                break;
            sum += all_ones + rem_val;
        } else{
            if(sum + all_ones >= k)
                break;
            sum += all_ones;
        }
        num++;
    }
    return calc_num(k-sum, &freq, num, n);
}
int main(){
    int n, k;
    cin >> n >> k;
    cout << findKthNumber(n, k) << endl;
    return 0;
}