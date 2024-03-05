#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    queue<pair<int, int>> q;
    for(int i=0; i< priorities.size(); i++)
        q.push({priorities[i], i});
    
    sort(priorities.begin(), priorities.end(), greater<>());
    
    int cnt = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        if(cur.first != priorities[cnt]) q.push(cur);
        else {
            if(cur.second == location){
                return cnt + 1;
            }
            cnt++;
        }
    }
}