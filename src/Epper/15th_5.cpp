//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
// 	string str="";
// 	string answer="";
// 	scanf("%s",str.c_str());

// 	if(str[0]=='1') answer.push_back('1');
// 	printf("string : %s\n",str.c_str());
// 	printf("string length : %d \n",str.length());
// 	int cnt=0;
// 	for(int i=0;i<str.length();i++){
// 		printf("for문안");
// 		if(i!=0 && str[i]==str[i-1]){
// 			cnt++;
// 			printf("같음 \n");
// 		}
// 		else{
// 			cnt=0;
// 		}
// 	}
// 	printf("answer : %s ",answer.c_str());
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
	answer[index]=0;
	
	printf("%s",answer);
	
	return 0;
}