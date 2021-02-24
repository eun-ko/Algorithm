//https://programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int solution(string name) 
{
    int answer = 0;
    string start;
    
    for(int i = 0; i < name.size(); i++)
    {
        start += "A";
    }
    
    int current_index = 0;
    while(true)
    {   
        answer += min(name[current_index] - 'A', 'Z' - name[current_index] + 1);
        start[current_index] = name[current_index];
        
        if(start == name)
        {
            return answer;
        }
        
        int left_index = current_index;
        int left_cnt = 0; //왼쪽이동횟수
        
        while(start[left_index] == name[left_index])
        {
            left_index--;
            left_cnt++;
            
            // 범위를 벗어나는 경우
            if(left_index == -1)
            {
                left_index = name.size()-1;
            }
        }
        
        int right_index = current_index;
        int right_cnt = 0; //오른쪽이동횟수
        
        while(start[right_index] == name[right_index])
        {
            right_index++;
            right_cnt++;
            
            // 범위를 벗어나는 경우
            if(right_index == name.size())
            {
                right_index = 0;
            }      
        }
    
        // 왼쪽이 최소일경우
        if(left_cnt < right_cnt)
        {
            answer += left_cnt;
            current_index = left_index;
        }
        // 오른쪽이 최소일경우
        else
        {
            answer += right_cnt;
            current_index = right_index;
        }
    }
}
