#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int idx = 0;
    for(int i=0; i<number.length()-k; i++){
        char mx = number[idx];
        for(int j=idx; j<= i+k; j++){
            if(mx < number[j]){
                mx = number[j];
                idx = j;
            }
        }
        idx++;
        answer += mx;
    }
    
    
    return answer;
}