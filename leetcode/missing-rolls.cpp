#include <bits/stdc++.h>

using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int rolls_mean = 0, m = rolls.size(), temp;
        int total = mean*(m+n);
        vector<int> ans;
        for(int i : rolls)
            rolls_mean += i;
        if(total > ((6*n) + rolls_mean) ||
           total  < n+rolls_mean)
           return ans;
        ans = vector<int>(n);
        int num = 6, x, rem_n=n, i=0, j=0, temp_rem_n;
        int rem_mean = total - rolls_mean;
        while(num > 0){
            j=0;
            x = rem_mean/num;
            temp = rem_mean - (x*num);
            if(x<rem_n){
                temp_rem_n = rem_n-x;
                if(temp < temp_rem_n){
                    while(temp < temp_rem_n){ // remaining value < num of ones req to fullfil the value
                        temp = temp+num;
                        temp_rem_n++;
                        x--;
                    }
                    for(;i<n && j<x;i++,j++)
                        ans[i] = num;
                    rem_mean = temp;
                    rem_n = temp_rem_n;
                    num--;
                    continue;
                }
            }
            for(;i<n && j<x;i++,j++)
                ans[i] = num;
            rem_n = rem_n-x;
            rem_mean = temp;
            num--;
        }
        return ans;
    }

int main(){
    int m, n;
    string line, temp;
    ifstream fin("input.txt");
    vector<int> rolls;
    // cout << "Enter the number of rolls: ";
    // fin >> m;
    // cout << "Enter the rolls: ";
    fin >> line;
    
    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());
    stringstream ss(line);
    while (getline(ss, temp, ',')) {
        rolls.push_back(std::stoi(temp)); // Convert string to integer and store
    }
    int mean;
    // cout << "Enter the mean: ";
    fin >> mean;
    // cout << "Enter n: ";
    fin >> n;
    vector<int> ans = missingRolls(rolls, mean, n);
    std::cout << "The missing rolls are: ";
    for(int i=0;i<ans.size();i++){
        std::cout << ans[i] << " ";
    }
    std::cout << '\n';
    return 0;
}