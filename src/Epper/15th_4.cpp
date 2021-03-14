#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	vector<int> numbers;
	int sum=0;
	int temp=0;

	for(int i=0;i<9;i++){
		int n;
		scanf("%d",&n);
		numbers.push_back(n);
		sum+=n;
	}

	for(int i=0;i<9;i++){
		temp=sum;
		temp-=numbers[i];
		int temp_t;
		//printf("numbers[i]:%d 뺐을때의 sum %d\n",numbers[i],temp);
		for(int j=i+1;j<9;j++){
			temp_t=temp;
			temp_t-=numbers[j];
			//printf("temp에서 numbers[j] : %d 빼줌 : %d\n",numbers[j],temp_t);
			if(temp_t==100){
				//printf("정답 !!!!!!!!! i:%d j:%d\n",numbers[i],numbers[j]);
				numbers.erase(numbers.begin()+i);
				numbers.erase(numbers.begin()+j-1);
				goto ANSWER;
			}
		}
	}

	ANSWER:
	for(auto i : numbers){
		printf("%d ",i);
	}
	return 0;
}