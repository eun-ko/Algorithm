#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
 
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
 
int M,N,K;
int map[100][100]={0};
int visited[100][100]={0};
 
int dfs(int y,int x){

    int cnt=1;
    
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        
        /*
        if(ny<0 || ny>=M || nx<0 || nx>=N)
            continue;
        
        if(map[ny][nx] || visited[ny][nx])
            continue;
        */


        //직사각형 영역이 아니고 방문되지 않았으며 map범위 안에 있을때, 영역의 넓이 구하기
        if(map[ny][nx]==0 && visited[ny][nx]==0 && ny>=0 &&ny<M && nx>=0 && nx<N){
            visited[ny][nx]=1;
            cnt+=dfs(ny,nx);
        }
        
        /*
        visited[ny][nx]=1;
        cnt+=dfs(ny,nx);
        */
    }
    
    return cnt;
}
 
int main(){

    scanf("%d %d %d", &M,&N,&K);
    int x1,y1,x2,y2;

    for(int i=0;i<K;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int x=x1;x<x2;x++)
            for(int y=y1;y<y2;y++)
                map[y][x]=1; //직사각형 영역 표시
    }
    
    vector<int> area;
    
    for(int y=0;y<M;y++){
        for(int x=0;x<N;x++){
            if(!map[y][x] && !visited[y][x]){ //직사각형 내부가 아니고 방문되지 않았을경우
                visited[y][x]=1;
                area.push_back(dfs(y,x));
            }
        }
    }

    printf("%d\n", area.size());
    sort(area.begin(),area.end());
    for(int i=0;i<area.size();i++)
        printf("%d ",area[i]);
    printf("\n");
 
}
