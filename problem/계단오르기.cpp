//https://www.acmicpc.net/problem/2579
#include<iostream>
#include<algorithm>

#define MAX 303
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR_RANGE(i,s,n) for(int i=s;i<n;i++)

using namespace std;

int stair[MAX];		//��� ����
int one_step[MAX];	//1ĭ��
int two_step[MAX];	//2ĭ��
int main(){
	int n;
	cin >> n;
	FOR(i, n){
		cin >> stair[i+2];
	}

	FOR_RANGE(i,2, n + 2){
		one_step[i] = two_step[i-1] + stair[i];	//�� ĭ�� �����̴� ������ ���� ��ĭ�� �����̸� �ᱹ ������ �ؾ���(�� ������ ������ �� ���)
		two_step[i] = max(two_step[i-2], one_step[i-2]) + stair[i];	//�� �� ���� ������ �ϰų�, ��ĭ �����̰� ������ �ϰų�.
	}
	cout << max(one_step[n + 1], two_step[n + 1]) << endl;
}