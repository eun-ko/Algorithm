//https://programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int solution(string name) 
{
    int answer = 0;//이동 횟수
    string initial_name;
    
    for(int i = 0; i < name.size(); i++)
    {
        //주어진 이름의 길이만큼 A를 이어붙여서 초기세팅을 해줌
        initial_name += "A";
    }
    
    int current_index = 0;
    while(true)
    {   
        answer += min(name[current_index] - 'A', 'Z' - name[current_index] + 1);
        //조이스틱을 윗방향 또는 아랫방향으로 움직였을때의 최소값을 answer에 더해나감
        // 아래방향으로 움직여야될때는 한번을 더 더해줌 (왜냐면, z에서 바로가는게 아니라 a에서 z로 가는것도 한번 더 더해줘야되므로)
        initial_name[current_index] = name[current_index];
        //nowIdx에 해당하는 알파벳문자는 조이스틱으로 바꿔놓기 완료!

        if(initial_name == name)
        {
            return answer;
        }
        
        // 1. 왼쪽 이동 횟수 구하기
        int left_index = current_index;
        int left_cnt = 0; //왼쪽이동횟수
        
        while(initial_name[left_index] == name[left_index])
        {//문자가 같을 경우에는, 알파벳을 바꿀 필요가없으므로 커서를 계속 이동시킨다.
            left_index--;
            left_cnt++;
            
            // 왼쪽으로 이동시에 범위를 벗어나는 경우
            if(left_index == -1)
            {
                //첫번째 문자의 커서위치에서 왼쪽으로 이동하는경우, 마지막 문자위치로 커서를 옮겨줘야함.
                left_index = name.size()-1;
            }
        }
        
        // 2. 오른쪽 이동 횟수 구하기
        int right_index = current_index;
        int right_cnt = 0; //오른쪽이동횟수
        
        while(initial_name[right_index] == name[right_index])
        {//문자가 같을 경우에는, 알파벳을 바꿀 필요가없으므로 커서를 계속 이동시킨다.
            right_index++;
            right_cnt++;
            
            // 오른쪽으로 이동시에 범위를 벗어나는 경우
            if(right_index == name.size())
            {
                //마지막 문자의 커서위치에서 오른쪽으로 이동하는경우, 첫번째 문자위치로 커서를 옮겨줘야함
                right_index = 0;
            }      
        }
    
        // 3. 왼쪽, 오른쪽 중 횟수가 최소인 방향을 선택
        if(left_cnt < right_cnt)
        {// 왼쪽이 최소일경우
            answer += left_cnt;
            current_index = left_index;
        }
        else
        {// 오른쪽이 최소일경우
            answer += right_cnt;
            current_index = right_index;
        }
    }
}
