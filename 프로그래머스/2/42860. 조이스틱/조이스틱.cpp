#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    for(char c : name)
        answer += min(c - 'A', 'Z' + 1 - c);
    
    int n = name.length();
    int mn= n -1;
    int nxt = 0;
    for(int i=0; i<n; i++){
        nxt = i+1;
        while(nxt < n && name[nxt] == 'A') 
            nxt++;
        
        mn = min(mn, i + (n - nxt) + min(i, n - nxt));
    }
    answer += mn;
    
    return answer;
}