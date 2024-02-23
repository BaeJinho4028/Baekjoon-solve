#include <bits/stdc++.h>

using namespace std;

int d[105][105];

int solution(int m, int n, vector<vector<int>> puddles) {
    
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            d[i][j] = 1;
        }
    }
    
    for(auto p : puddles){
        d[p[1]][p[0]] = 0;
    }
    
    
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 && j == 1) continue;
            if(d[i][j] == 0) continue;
            
            d[i][j] = 0;
            if(i != 1) d[i][j] += d[i-1][j];
            if(j != 1) d[i][j] += d[i][j-1];
            d[i][j] %= 1000000007;
        }
    }
    
    int answer = d[n][m];
    return answer;
}