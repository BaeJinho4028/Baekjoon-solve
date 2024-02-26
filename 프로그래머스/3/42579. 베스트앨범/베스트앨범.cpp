#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> music;
    map<string, map<int,int>> mlist;
    
    for(int i=0; i < genres.size(); i++){
        music[genres[i]] += plays[i];
        mlist[genres[i]][i] = plays[i];
    }
    
    while(music.size() > 0){
        string genre = "";
        int mx = 0;
        
        for(auto m : music){
            if(mx < m.second){
                genre = m.first;
                mx = m.second;
            }
        }
        
        for(int i=0; i<2; i++){
            int tmp = 0, idx = -1;
            for(auto ml : mlist[genre]){
                if(tmp < ml.second){
                    idx = ml.first;
                    tmp = ml.second;
                }
            }
            if(idx == -1) break;
            answer.push_back(idx);
            mlist[genre].erase(idx);
        }
        music.erase(genre);
    }
    return answer;
}