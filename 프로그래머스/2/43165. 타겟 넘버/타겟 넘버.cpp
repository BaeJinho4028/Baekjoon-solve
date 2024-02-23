#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt;
int v[25];

void f(int cur, int num){
    if(cur == n){
        if(num == k) cnt++;
        return;
    }
    
    f(cur+1, num + v[cur]);
    f(cur+1, num - v[cur]);
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    k = target;
    
    for(int i=0; i<n; i++)
        v[i] = numbers[i];
    
    f(0, 0);
    
    int answer = cnt;
    
    return answer;
}