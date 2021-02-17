//https://programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
 using namespace std;
 

bool isPrime(int n) {
    if (n < 2) return false;
    // 에라토스테네스의 체
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}
 
 
int solution(string numbers) {
    
    int answer = 0;
    
    vector<char> v;  // 종이 조각의 각 숫자 저장
    vector<int> total_cases;   // 종이 조각으로 만들 수 있는 모든 수
    
    
    for (int i = 0; i < numbers.size(); i++) 
        v.push_back(numbers[i]);

    sort(v.begin(), v.end()); //오름차순 정렬
 
    do {
        string temp = "";
        // 만들 수 있는 모든 숫자 total_cases에 저장
        for (int i = 0; i < v.size(); i++) {
            temp.push_back(v[i]);
            total_cases.push_back(stoi(temp)); //int형으로 바꿔서 저장
        }
    } while (next_permutation(v.begin(), v.end()));
 
    
    sort(total_cases.begin(), total_cases.end());
    
    total_cases.erase(unique(total_cases.begin(), total_cases.end()), total_cases.end()); //중복값 제거
    
    for (int i = 0; i < total_cases.size(); i++)
        if (isPrime(total_cases[i]))
            answer++;
 
    return answer;
}

