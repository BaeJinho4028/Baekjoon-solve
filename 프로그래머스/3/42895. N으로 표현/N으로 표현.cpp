#include <bits/stdc++.h>

using namespace std;

int solution(int n, int number) {
    int answer = -1;
    
    
    set<int> se[8];
    
    int sum =0;
    for(int i = 0; i < 8; i++){
        sum = 10 * sum + n;
        se[i].insert(sum);
    }
    
    for(int i=1; i<8; i++){
        for(int j=0; j<i; j++){
            for(auto x : se[j]){
                for(auto y : se[i-j-1]){
                    se[i].insert(x+y);
                    se[i].insert(x-y);
                    se[i].insert(x*y);
                    if(y) se[i].insert(x/y);
                }
            }
        }
    }
    
    for(int i=0; i<8; i++){
        if(se[i].find(number) != se[i].end()){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}