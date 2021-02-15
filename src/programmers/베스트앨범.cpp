#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> answer;
    map<string, int> music;
    map< string, map<int, int> > album_with_music_num;
    
    for (int i = 0; i < genres.size(); i++) {
        music[genres[i]] += plays[i]; //장르별(key)로 재생된 횟수(value)를 map에 추가 (더해나가기)
        album_with_music_num [genres[i]] [i] = plays[i];//value에 고유 번호와 재생횟수 추가
    }
    
    while (music.size() > 0) {
        string genre;
        int max=0;
        //장르중에서 제일높은것 찾기
        for (auto m : music){
            if (max < m.second){
                max = m.second;
                genre = m.first;
                //printf("genres : %s %d\n",genre.c_str(),max);
            }
        }
        //printf("final genres : %s %d\n",genre.c_str(),max);
        //2곡을 넣어야하므로 2번반복
        for (int i = 0; i < 2; i++){
            int play_cnt = 0, music_num = -1;
            //해당 장르중에서 제일 재생횟수높은것 찾기
            for (auto m : album_with_music_num[genre]) {
                if (play_cnt < m.second) {
                    play_cnt = m.second;
                    music_num = m.first;
                    //printf("%d %d\n",music_num,play_cnt);
                }
            }
            //printf("final %s list : %d %d \n",genre.c_str(),music_num,play_cnt);
            if (music_num == -1) break;
            
            answer.push_back(music_num);
            album_with_music_num[genre].erase(music_num);
        }
        music.erase(genre);
    }
    return answer;
}
