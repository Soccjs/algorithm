//https://www.acmicpc.net/problem/11726
#include <iostream>

using namespace std;

int main() {
	int n, i = 2;
	int dp[1001] = {0};
	dp[0] = 1;
	dp[1] = 1;

	cin >> n;
	
	for (i = 2; i <= n; i++){
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	
	cout << dp[n] << endl;
}