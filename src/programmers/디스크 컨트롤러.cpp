//https://programmers.co.kr/learn/courses/30/lessons/42627

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//우선순위큐에서 우선순위를 재정의하는 compare 구조체, sort와 반대임
struct compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1]; // 정렬 기준이 첫번째 인자가 아닌 두번째 인자 기준임. 따라서 오름차순 정렬임.
    }
};
 
int solution(vector< vector<int> > jobs) {
    
    int total_time = 0;
    
    priority_queue< vector<int>, vector< vector<int> >, compare> pq; // 소요시간을 기준으로 오름차순 정렬
    
    int current_time = 0;   // 현재 시각
    int task_cnt = 0;   // 우선순위 큐에 들어간 작업의 개수 축적
    
    sort(jobs.begin(), jobs.end()); // 요청시점을 기준으로 오름차순 정렬
 
    while (task_cnt < jobs.size() || !pq.empty()) {
       
        if (task_cnt < jobs.size() && jobs[task_cnt][0] <= current_time) { //요청시간이 현재 소요된 시간보다 작을때 작업을 수행할 수 있음
            pq.push(jobs[task_cnt++]);//넣으면 소요시간이 적은 순으로 저장됨
            continue;
        }
 
        // 수행할 작업이 있는 경우
        if (!pq.empty()) {
            current_time += pq.top()[1]; //소요시간
            total_time += current_time - pq.top()[0]; //요청시점
            pq.pop();
        }
        // 수행할 작업이 없는 경우
        else {
            // 다음 작업이 들어오는 시각으로 변경
            current_time = jobs[task_cnt][0];
        }
    }  
 
    return total_time/jobs.size();  // 평균 시간 반환
}
