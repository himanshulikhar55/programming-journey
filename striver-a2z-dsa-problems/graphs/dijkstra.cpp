#include<bits/stdc++.h>
using namespace std;
vector <int> dijkstraUsingPQ(int v, vector<vector<int>> adj[], int s) {
    // Code here
    vector<int> minDist = vector<int>(v, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
    
    minDist[s] = 0;
    minHeap.push({0, s});
    
    while(!minHeap.empty()){
        int vertex = minHeap.top().second;
        int currDist = minHeap.top().first;
        
        minHeap.pop();
        
        int len = adj[vertex].size();
        for(int i=0;i<len;i++){
            
            int currVer = adj[vertex][i][0];
            int edgeWt = adj[vertex][i][1];
            
            if(minDist[currVer] > currDist + edgeWt){
                minDist[currVer] = currDist+edgeWt;
                minHeap.push({minDist[currVer], currVer});
            }
        }
    }
    return minDist;
}

vector<int> dijkstraUsingSet(vector<vector<int>> &edge, int V, int edges, int s){
    set<pair<int, int>> st;
    vector<vector<vector<int>>> adjList = vector<vector<vector<int>>>(V);

    for(auto it : edge){
        adjList[it[0]].push_back({it[1], it[2]});
        adjList[it[1]].push_back({it[0], it[2]});
    }
    vector<int> minDist(V, INT_MAX);
    // Mark the Distance of source to 0
    minDist[s] = 0;
    st.insert({0, s});
    while(!st.empty()){
        auto it = *(st.begin());
        int dis = it.first;
        int currNode = it.second;
        st.erase(it);
        for(auto it : adjList[currNode]){
            int edgeWt = it[1];
            int destNode = it[0];
            if(dis + edgeWt < minDist[destNode]){
                if(minDist[destNode] != INT_MAX){
                    //remove the existing dist
                    st.erase({minDist[destNode], destNode});
                }
                minDist[destNode] = dis + edgeWt;
                st.insert({minDist[destNode], destNode});
            }
        }
    }
    return minDist;
}