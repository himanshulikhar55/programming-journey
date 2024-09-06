#include <bits/stdc++.h>

using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    set<pair<int, int>> obstacle_set;
        for (const vector<int>& obstacle : obstacles)
            obstacle_set.insert({obstacle[0], obstacle[1]});

        int x = 0, y = 0, max_dist = 0, dir = 0;
        // dir 0: straight
        // dir 1: left
        // dir 2: down
        // dir 3: right
        for(int i=0;i<commands.size();i++){
            if(commands[i] < 0){
                if(commands[i] == -1)
                    dir = (4+dir-1)%4;
                else
                    dir = (4+dir+1)%4;
            } else {
                if(dir == 0){
                    for(int j=1;j<=commands[i];j++){
                        if(obstacle_set.count({x, y+1}) == 0){
                            y++;
                            max_dist = max(max_dist, ((x*x) + (y*y)));
                        } else {
                            break;
                        }
                    }
                } else if(dir == 1){
                    for(int j=1;j<=commands[i];j++){
                        if(obstacle_set.count({x-1, y}) == 0){
                            x--;
                            max_dist = max(max_dist, ((x*x) + (y*y)));
                        } else {
                            break;
                        }
                    }
                } else if(dir == 2){
                    for(int j=1;j<=commands[i];j++){
                        if(obstacle_set.count({x, y-1}) == 0){
                            y--;
                            max_dist = max(max_dist, ((x*x) + (y*y)));
                        } else {
                            break;
                        }
                    }
                } else{
                    for(int j=1;j<=commands[i];j++){
                        if(obstacle_set.count({x+1, y}) == 0){
                            x++;
                            max_dist = max(max_dist, ((x*x) + (y*y)));
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return max_dist;
}

int main() {
    // Your code here
    int n, m;
    cin >> n;
    vector<int> commands(n);
    for (int i = 0; i < n; i++) {
        cin >> commands[i];
    }
    cin >> m;
    vector<vector<int>> obstacles(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> obstacles[i][0] >> obstacles[i][1];
    }
    int max_distance = robotSim(commands, obstacles);
    cout << max_distance << endl;
    return 0;
}