#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> v) {
    int answer = 0;
    
    int n = v.size();
    
    int mx = 0, my = 0;
    for(int i=0; i<n; i++){
        if(v[i][0] < v[i][1]) swap(v[i][0], v[i][1]);
        mx = max(mx, v[i][0]);
        my = max(my, v[i][1]);
    }
    
    answer = mx * my;
    
    return answer;
}