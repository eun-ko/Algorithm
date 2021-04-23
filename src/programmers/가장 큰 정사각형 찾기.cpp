//https://programmers.co.kr/learn/courses/30/lessons/60058

#include <algorithm>
#include <vector>
using namespace std;

int solution(vector< vector<int> > board)
{
    int answer = board[0][0]; 
    
    for(int i = 1; i < board.size(); i++){
        for(int j = 1; j < board.size() ; j++){
            if(board[i][j] == 1){ //현재 위치가 1일때만 정사각형을 만들 수 있으므로 그때 실행
                board[i][j] = min(board[i][j - 1], board[i - 1][j]); //왼쪽, 위
                board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1; //북서쪽 대각선
                //이렇게 갱신된 board[i][j]는 [i][j]위치가 정사각형의 최우측하단이 될 때, 만들 수 있는 정사각형 한변의 길이가 됨
                answer = max(answer, board[i][j]);
            }
        }
    }
    return answer * answer;
}