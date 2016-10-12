//https://www.acmicpc.net/problem/2579
#include<iostream>
#include<algorithm>

#define MAX 303
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR_RANGE(i,s,n) for(int i=s;i<n;i++)

using namespace std;

int stair[MAX];		//계단 점수
int one_step[MAX];	//1칸씩
int two_step[MAX];	//2칸씩
int main(){
	int n;
	cin >> n;
	FOR(i, n){
		cin >> stair[i+2];
	}

	FOR_RANGE(i,2, n + 2){
		one_step[i] = two_step[i-1] + stair[i];	//한 칸씩 움직이는 조건은 연속 두칸을 움직이면 결국 점프를 해야함(즉 직전에 점프를 할 경우)
		two_step[i] = max(two_step[i-2], one_step[i-2]) + stair[i];	//두 번 연속 점프를 하거나, 한칸 움직이고 점프를 하거나.
	}
	cout << max(one_step[n + 1], two_step[n + 1]) << endl;
}