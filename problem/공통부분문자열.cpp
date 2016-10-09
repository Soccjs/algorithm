//https://www.acmicpc.net/problem/5582
#include <iostream>
#include <string>

using namespace std; 

#define FOR(i,n)  for (i=0; i<(n); i++) 

int dp[4001][4001] = { 0 };

int main () {
	string a, b;
	int i = 0, j = 0, M = 0;
	cin >> a >> b;
	
	FOR(i, a.size()){
		FOR(j, b.size()){
			if (a[i] == b[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
				if (dp[i + 1][j + 1] > M) {
					M = dp[i + 1][j + 1];
				}
			}
			else {
				dp[i + 1][j + 1] = 0;
			}
		}
	}
	cout << M << endl;
}
