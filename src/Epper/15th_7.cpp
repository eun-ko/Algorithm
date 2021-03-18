#include <stdio.h>
#include <vector>
using namespace std;

int solution(vector<int> s, vector<int> e,int n) {

    int tmp,answer = 0;
    int e1 = -1, e2 = -1; 

	// sort(s.begin(),s.end());
	// sort(e.begin(),e.end()); //안됨
	
	 for(int i = 0 ; i < n ; i++) // 종료시간 오름차순으로 정렬
    {
       for(int j = 0 ; j < n - 1 ; j++) // 종료시간이 같을때는 시작시간 기준 오름차순으로
       {
          if((e[j] > e[j + 1]) || (e[j] == e[j + 1] && s[j] > s[j + 1]))
          { 
             tmp = s[j];
             s[j] = s[j + 1];
             s[j + 1] = tmp;
             tmp = e[j];
             e[j] = e[j + 1];
             e[j + 1] = tmp;
         }
      }
   }
	
    for(int i = 0 ; i < n ; i++)
    {
       if(e1 <= s[i])
       {
          e1 = e[i];
          answer++;
       }
      
      else if(e2 <= s[i])
      {
         e2 = e1; 
         e1 = e[i]; 
			answer++; 
      }
    }
    
    return answer; 
}

int main() {
		vector<int>s,e;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int temp=0;
			scanf("%d",&temp);
			s.push_back(temp);
		}
	for(int i=0;i<n;i++){
			int temp=0;
			scanf("%d",&temp);
			e.push_back(temp);
		}
	
    printf("%d",solution(s,e,n));
}