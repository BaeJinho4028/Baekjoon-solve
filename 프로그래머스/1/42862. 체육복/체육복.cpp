#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> s(n+5,0);
    
    for(int x : lost)
        s[x]--;
    
    for(int x : reserve)
        s[x]++;
    
    for(int i=1; i<=n; i++){
        if(s[i] == -1) {
            if(s[i-1] == 1){
                s[i-1]--;
                s[i]++;
            }
            else if(s[i+1] == 1){
                s[i+1]--;
                s[i]++;
            }
        }
            
        cout << s[i] << ' ';
        if(s[i] >= 0) answer++;
    }
    
    return answer;
}