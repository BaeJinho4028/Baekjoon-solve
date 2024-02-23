#include <bits/stdc++.h>

using namespace std;

vector<int> adj[205];
bool vis[205];
int cnt;

void dfs(int x){
    vis[x] = true;
    for(int nxt : adj[x]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    for(int i=0; i<computers.size(); i++){
        for(int j=0; j<computers[i].size(); j++){
            if(computers[i][j]) adj[i].push_back(j);
        }
    }
    
    for(int i = 0; i<n; i++){
        if(vis[i]) continue;
        dfs(i);
        cnt++;
    }
    
    int answer = cnt;
    return answer;
}