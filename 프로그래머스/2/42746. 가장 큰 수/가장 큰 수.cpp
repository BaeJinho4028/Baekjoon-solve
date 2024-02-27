#include <bits/stdc++.h>

using namespace std;

bool cmp(string& a, string& b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    for(auto n : numbers)
        v.push_back(to_string(n));
    sort(v.begin(), v.end(), cmp);
    
    for(auto s : v)
        answer += s;
    if(answer[0] == '0') return "0";
    
    return answer;
}