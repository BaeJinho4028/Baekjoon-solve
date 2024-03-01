#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int st = 0, en = people.size() - 1;
    
    while(st <= en){
        if(people[st] + people[en] <= limit) st++;
        
        en--; answer++;
    }
    
    return answer;
}