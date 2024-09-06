#include<bits/stdc++.h>
using namespace std;
bool common_colour(vector<string> &colour, int x, int y){
    return colour[x][0] == colour[y][0] ||
           colour[x][0] == colour[y][1] ||
           colour[x][1] == colour[y][0] ||
           colour[x][1] == colour[y][1];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        vector<string> colour = vector<string>(n+1);
        for(int i=1;i<=n;i++)
            cin >> colour[i];
        for(int i=0;i<q;i++){
            int x, y;
            cin >> x >> y;
            if(common_colour(colour, x, y)){
               cout << abs(x-y) << '\n';
            } else {
                int min_cost = -1;
                if(x > y){
                    for(int i=y+1;i<x;i++){
                        if(i!=x && i!=y){
                            if(common_colour(colour, x, i) && common_colour(colour, y, i)){
                                min_cost = abs(x-i) + abs(y-i);
                                break;
                            }
                        }
                    }
                    if(min_cost!=-1){
                        cout << min_cost << '\n';
                        continue;
                    }
                    for(int i=1;i<y;i++){
                        if(i!=x && i!=y){
                            if(common_colour(colour, x, i) && common_colour(colour, y, i)){
                                min_cost = abs(x-i) + abs(y-i);
                                break;
                            }
                        }
                    }
                    if(min_cost!=-1){
                        cout << min_cost << '\n';
                        continue;
                    }
                    for(int i=x+1;i<=n;i++){
                        if(i!=x && i!=y){
                            if(common_colour(colour, x, i) && common_colour(colour, y, i)){
                                min_cost = abs(x-i) + abs(y-i);
                                break;
                            }
                        }
                    }
                    cout << min_cost << '\n';
                }
                else {
                    for(int i=1;i<=n;i++){
                        if(i!=x && i!=y){
                            if(common_colour(colour, x, i) && common_colour(colour, y, i)){
                                min_cost = abs(x-i) + abs(y-i);
                                break;
                            }
                        }
                    }
                    cout << min_cost << '\n';
                }
            }
        }
        
    }
    return 0;
}