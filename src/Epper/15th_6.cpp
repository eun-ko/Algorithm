#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

vector<char> input;
int answer,n=0;
stack<int> s;

int calc(int n){
	int result;
	int op1,op2;
    for(int i=0;i<n;i++){
        if(input[i]>='0' && input[i]<='9')			
			s.push(input[i]-'0');
        else{
            switch(input[i]){
                case '+':
                    op1=s.top();s.pop();
					op2=s.top();s.pop();
                    result=op2+op1;
					s.push(result);
                    break;
                case '-':
                    op1=s.top();s.pop();
					op2=s.top();s.pop();
                    result=op2-op1;
					s.push(result);
                    break;
                case '*':
                    op1=s.top();s.pop();
				    op2=s.top();s.pop();
                    result=op2*op1;
					s.push(result);
                    break;
                case '/':
                    op1=s.top();s.pop();
					op2=s.top();s.pop();
                    result=op2/op1;
					s.push(result);
                    break;

            }
        }
    }
    return result;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char c;
        scanf(" %c",&c);
        input.push_back(c);
    }
    answer=calc(n);
    printf("%d",answer);
	return 0;
}