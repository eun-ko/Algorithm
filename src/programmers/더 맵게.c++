//https://programmers.co.kr/learn/courses/30/lessons/42626

#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    int answer=0;
    priority_queue< int,vector<int>,greater<int> > pq;

    for(int s : scoville){
        pq.push(s);
    }

    while(pq.top()<K){
        if(pq.size()==1) return -1;

        int first=pq.top(); //최소값
        pq.pop();

        int second=pq.top();//두번째 최소
        pq.pop();

        int mixed = first+second*2;
        pq.push(mixed);

        answer++;
    }
    return answer;
}