//https://programmers.co.kr/learn/courses/30/lessons/42895

#include <vector>
#include <unordered_set>
using namespace std;

int get_Ns(int N, int idx) { 
    int result = N;
    for (int i = 1; i <= idx; i++) {
        result = result * 10 + N; 
    } 
    return result; 
    // N, NN, NNN과 같은 형태...
}
int solution(int N, int number) { 
    if (N == number) return 1; 

    vector< unordered_set<int> > DP(8); //set 대신 정렬할 필요없는 unordered_set 사용
    DP[0].insert(N);

    for (int k = 1; k < 8; k++) { 
        DP[k].insert(get_Ns(N, k)); 

        for (int i = 0; i < k; i++) { 

            for (int j = 0; j < k; j++) { 
                if (i + j + 1 != k) 
                    continue; 

                for (int a : DP[i]) { 
                    for (int b : DP[j]) { 
                        DP[k].insert(a + b); 
                        DP[k].insert(a * b); 
                        //검사가 필요한 연산들
                        if (a - b > 0) 
                            DP[k].insert(a - b); //음수 존재하면 안됨
                        if (a / b > 0)
                            DP[k].insert(a / b); //0 존재하면 안됨
                    } 
                } 
            } 
          
        if (DP[k].find(number)!=DP[k].end()) 
            return k + 1; 
    } 
    return -1; 
}

