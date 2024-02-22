#include <bits/stdc++.h>

using namespace std;

int d[505][505];

int solution(vector<vector<int>> t) {
    
    int n = t.size();
    d[0][0] = t[0][0];
    
    for(int i=1; i<n; i++){
        for(int j=0; j <=i; j++){
            if(j == 0) d[i][j] = d[i-1][j];
            else if(j == i) d[i][j] = d[i-1][j-1];
            else d[i][j] = max(d[i-1][j], d[i-1][j-1]);
            d[i][j] += t[i][j];
        }
    }
    int answer = 0;
    for(int i=0; i<n; i++){
        answer = max(answer, d[n-1][i]);
    }
    
    return answer;
}