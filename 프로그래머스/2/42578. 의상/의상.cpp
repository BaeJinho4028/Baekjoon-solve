#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> ma;
    
    for(auto a : clothes){
        ma[a[1]]++;
    }
    
    for(auto b : ma){
        answer *= (b.second+1);
    }
    
    return answer - 1;
}