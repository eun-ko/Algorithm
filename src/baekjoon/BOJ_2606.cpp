#include <stdio.h>
#include <vector>
using namespace std;

vector<int> network[101];
int visited[101];
int cnt;

void dfs(int x){
    
    if(visited[x]==1){
        return;
    }
    
    visited[x]=1;
    cnt++;
    
    for(int i=0;i<network[x].size();i++){
        dfs(network[x][i]);
    }
    
}

int main(int argc, const char * argv[]) {

    int n;
    int k;
   
    scanf("%d",&n);
    scanf("%d",&k);
    
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        network[a].push_back(b);
        network[b].push_back(a);
    }
    
    dfs(1);
    
    printf("%d",cnt-1);

    return 0;
}
