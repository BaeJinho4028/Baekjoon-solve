#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    queue<int> q;
    
    for(auto a : arr){
        if(q.empty()){
            q.push(a);
        }
        else{
            if(q.front() == a) continue;
            answer.push_back(q.front());
            q.pop();
            q.push(a);
        }
    }
    answer.push_back(q.front());

    return answer;
}