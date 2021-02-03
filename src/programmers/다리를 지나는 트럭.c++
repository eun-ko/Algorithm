//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int time = 0;
    queue<int> q;
    int truck_sum=0;//다리를 지나고 있는 트럭의 무게합 저장
    
    for(int i=0;i<truck_weights.size();i++){
        
        int current_truck=truck_weights[i];
       
        while(true){

            if(q.empty()){
                q.push(current_truck);
                truck_sum+=current_truck;
                time++;//큐에 push할때는 time도 증가시켜주기
                break; //새로운 트럭을 큐에 넣었을때는 while문 빠져나가게
            }

            else if(q.size()==bridge_length){
                truck_sum-=q.front();
                q.pop();
            }

            else{

                if(current_truck+truck_sum>weight){
                    q.push(0);
                    time++;
                }

                else{
                    q.push(current_truck);
                    truck_sum+=current_truck;
                    time++;
                    break;
                }
            }
        }
    }
    return time+bridge_length;
}