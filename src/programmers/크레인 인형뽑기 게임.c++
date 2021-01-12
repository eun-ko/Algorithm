//https://programmers.co.kr/learn/courses/30/lessons/64061
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
  int answer = 0;
  int board_size = board.size();
  int move_cnt = moves.size();
  int doll;
  stack<int> s;
  for (int i = 0; i < move_cnt; i++)
  {
    for (int j = 0; j < board_size; j++)
    {
      if (board[j][moves[i] - 1]) //인형 존재할때 , -1해줘야 배열 인덱스랑 맞음
      {
        doll = board[j][moves[i] - 1];
        if (!s.empty()) //바구니가 비어있지 않을때
        {
          if (doll == s.top()) //바구니 맨 위의 인형과 크레인으로 집을 인형이 같다면
          {
            answer += 2;
            s.pop();
          }
          else
            s.push(doll);
        }
        else
          s.push(doll);
        board[j][moves[i] - 1] = 0; //바구니에 넣은 인형은 board 값 초기화
        break;                      //해당 열에서 인형뽑았으면 행탐색 종료 !!!!
      }
    }
  }
  return answer;
}