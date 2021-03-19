#include <stdio.h>
#include <queue>
#define MAX 101
using namespace std;

int adj[MAX][MAX]={0,}; //i번 공정과 j번 공정의 연결 여부 (1:true,0:false)
int indegree[MAX]={0,}; //해당공정 전에 선행되어야 하는 공정 수 
int time[MAX]={0,}; //time[i] : i번 공정을 완료하기까지 소요되는 최소 시간

int solution(int n[],int r[][100],int goal,int N,int R){

    queue <int> q;

    for(int i=0;i<R;i++){
        int u=r[i][0];
        int v=r[i][1];
        adj[u][v]=1;
        indegree[v]++;
    }//입력 값으로 연결여부와 내차수 초기화 

    for(int i=1;i<=N;i++){
        if(indegree[i]==0){//선행 공정이 없는(indegree==1) 공정들을 큐에 삽입
            time[i]=n[i-1];//인덱스 통일 (n의 0번 인덱스에 1번 공정 소요시간이 저장됨-> 그걸 time의 1번 인덱스에 저장)
            q.push(i);
        }
    }

    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=1;i<=N;i++){
            if(adj[p][i]==1){
                time[i]=max(time[i],time[p]+n[i-1]);
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
    }
	return time[goal];
}


int main() {
    
    int N;//공정 수
    int R;//관계 수
    int n[100] = {0};//공정 별 소요시간
    int r[100][100] = {0};//공정간 관계
    int goal, answer;//목표 공정, 결과
   
    scanf("%d %d", &N, &R);

    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }
	
    for (int k = 0; k < R; k++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &r[k][j]);
        }
    }

    scanf("%d", &goal);
    answer = solution(n, r, goal, N, R);
    printf("%d\n", answer);
}