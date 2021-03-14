#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	char str[10001]="";
	char answer[10001]="";
	int count=0;
	int index=0;
	scanf("%s",str);
	
    if(str[0]=='1') answer[index++]='1';
	
	for(int i=1;i<strlen(str);i++){
		if(str[i]!=str[i-1]){
			answer[index++]='A'+count;
			count=0;
		}
		else count++;
	}
	
	answer[index++]='A'+count;
	//맨 끝 문자 처리과정
	
	printf("%s",answer);
	
	return 0;
}