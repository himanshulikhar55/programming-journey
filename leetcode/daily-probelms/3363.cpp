/**
There is a game dungeon comprised of n x n rooms arranged in a grid.

You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).

The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):

    The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
    The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
    The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.

When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.

Return the maximum number of fruits the children can collect from the dungeon.
*/

#include <bits/stdc++.h>

std::vector<std::vector<int>> dir1 = {{1,1}};              // (0,0)
std::vector<std::vector<int>> dir2 = {{-1,1},{0,1},{1,1}}; // (n-1,0)
std::vector<std::vector<int>> dir3 = {{1,-1},{1,0},{1,1}}; // (0,n-1)
int ans = 0, n;
bool allReached(int pos[3][2], int n){
    for(int i=0;i<3;i++){
        if(pos[i][0] != (n-1) || pos[i][1] != (n-1))
            return false;
    }
    return true;
}

bool isValid(int pos[2]){
    if(pos[0] >=0 && pos[1] <= (n-1))
        return true;
    return false;
}

bool equal(int pos1[2], int pos2[2]){
    if(pos1[0] == pos2[0] && pos1[1] == pos2[1])
        return true;
    return false;
}

int solve(std::vector<std::vector<int>>& fruits, int pos[3][2], int currFruitCount, int hopCount){
    if(hopCount == n)
        return;
    if(allReached(pos, n)){
        ans = std::max(ans, currFruitCount);
        return;
    }
    for(int i=0;i<1;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                int pos1[2] = {pos[0][0] + dir1[i][0], pos[0][1] + dir1[i][1]};
                if(!isValid(pos1))
                    continue;
                int pos2[2] = {pos[1][0] + dir2[j][0], pos[1][1] + dir2[j][1]};
                if(!isValid(pos2))
                    continue;
                int pos3[2] = {pos[2][0] + dir3[k][0], pos[2][1] + dir3[k][1]};
                if(!isValid(pos3))
                    continue;
                if(equal(pos1, pos2)) {
                    if(equal(pos2, pos3))
                        currFruitCount += fruits[pos1[0]][pos1[1]];
                    else if(equal(pos1, pos3))
                        currFruitCount += fruits[pos1[0]][pos1[1]] + fruits[pos2[0]][pos2[1]];
                    else
                        currFruitCount += fruits[pos1[0]][pos1[1]] + fruits[pos2[0]][pos2[1]] + fruits[pos2[0]][pos2[1]];
                }
                else {
                    if(equal(pos1, pos3))
                        currFruitCount += fruits[pos1[0]][pos1[1]] + fruits[pos2[0]][pos2[1]];
                    else if(equal(pos2, pos3))
                        currFruitCount += fruits[pos1[0]][pos1[1]] + fruits[pos2[0]][pos2[1]];
                    else
                        currFruitCount += fruits[pos1[0]][pos1[1]] + fruits[pos2[0]][pos2[1]] + fruits[pos2[0]][pos2[1]];
                }
            }
        }
    }
}

int maxCollectedFruits(std::vector<std::vector<int>>& fruits) {
    n = fruits.size();
    int pos[3][2] = {{0,0},{n-1,0},{0,n-1}};
    solve(fruits, pos, 0, 1);
    return ans;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> fruits = std::vector<std::vector<int>>(n, std::vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin >> fruits[i][j];
        }
    }

    return 0;
}