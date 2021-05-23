//https://programmers.co.kr/learn/courses/30/lessons/42888

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
using namespace std;
 
string token_string(const string& s, int& i){
    string temp = "";
    for( ; i < s.size(); i++){
        if(s[i] == ' '){ i++; return temp; }
        temp += s[i];
    }
    return temp;
}
 
vector<string> solution(vector<string> record) {
    unordered_map<string, string> m;
    vector<pair<char, string> > v;
    vector<string> answer;
    
    for(int i = 0; i < record.size(); i++){
        string uid = "";  string nickname = "";
        if(record[i][0] == 'E'){
            int index = 6;
            uid = token_string(record[i], index);
            nickname = token_string(record[i], index);
            v.emplace_back(make_pair('E', uid));
            m[uid] = nickname;
        }else if(record[i][0] == 'L'){
            int index = 6;
            uid = token_string(record[i], index);
            v.emplace_back(make_pair('L', uid));
        }else{
            int index = 7;
            uid = token_string(record[i], index);
            nickname = token_string(record[i], index);
            m[uid] = nickname;
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        string temp = "";
        if(v[i].first == 'E')
            temp = m[v[i].second] + "님이 들어왔습니다.";
        else
            temp = m[v[i].second] + "님이 나갔습니다.";
        answer.emplace_back(temp);
    }
    
    return answer;
}
