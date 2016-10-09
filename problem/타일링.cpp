//https://www.acmicpc.net/problem/1793
#include <iostream>
#include <string>

using namespace std;

string sum(string a, string b) {
	string result = "";
	int a_size = a.size();
	int b_size = b.size();
	if (a_size > b_size) {
		int diff = a_size - b_size;
		while (diff--){
			b.insert(0, 1, '0');
		}
	}
	else if (a_size < b_size) {
		int diff = b_size - a_size;
		while (diff--){
			a.insert(0, 1, '0');
		}
	}
	char r = NULL;
	int  c = 0;
	for (int i = a_size-1; i >=0; i--){
		char r = a[i] + b[i] - '0' - '0' + c;
		c = 0;
		if (r > 9) {
			r -= 10;
			c = 1;
		}
		result.insert(0, 1, r + '0');
	}
	if (c == 1){
		result.insert(0, 1, c + '0');
	}

	return result;
}

int main() {
	int n, i = 2;
	string dp[1001] = { "1","1","3","", };
	dp[0] = "1";
	dp[1] = "1";
	int Max = 1;
	while (cin >> n){
		if (Max >= n){
			cout << dp[n] << endl;
		}
		else{
			for (i = Max+1; i <= n; i++){
				dp[i] = sum(dp[i - 1], sum(dp[i-2], dp[i - 2]));//dp[n] = dp[n-1] + 2*dp[n-2]
			}	
			Max = n;
			cout << dp[n] << endl;
		}
	}
}