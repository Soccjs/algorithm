//https://www.acmicpc.net/problem/1254
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1004][1004] = {};
string reverse(string a, string b) {
	int i;
	for (i = 0; i<a.size(); i++){
		b.push_back(a[a.size() - i - 1]);
	}
	return b;
}
int main() {
	string a = "", b = "";
	int i = 0, j = 0, k = 0, M = 0;

	cin >> a;

	b = reverse(a, b);

	for (i = 0; i<a.size(); i++){
		for (j = 0; j<b.size(); j++){
			if (a[i] == b[j]) {
				dp[j + 1][i + 1] = dp[j][i] + 1;
				if (i == a.size() - 1) {
					M = max(M, dp[j + 1][i + 1]);
				}
			}
		}
	}
	
	cout << 2 * a.size() - M << endl;
}