//https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define FOR(i, n) for (int i = 0; i < n;i++)
using namespace std;


vector<int> graph[MAX];
vector<bool> visit_dfs(MAX, false);
vector<bool> visit_bfs(MAX, false);

int n, m, start;

void dfs(int now){
	visit_dfs[now] = true;
	cout << now << " ";
	
	sort(graph[now].begin(), graph[now].end());
	FOR(i, graph[now].size()){
		if (!visit_dfs[graph[now][i]]){
			dfs(graph[now][i]);
		}
	}
}
void bfs(int now){
	queue<int> store;
	store.push(now);

	while (!store.empty()){
		now = store.front();
		if (!visit_bfs[now]){
			visit_bfs[now] = true;
			cout << now << " ";
		}
		store.pop();

		FOR(i, graph[now].size()){
			sort(graph[now].begin(), graph[now].end());
			if (!visit_bfs[graph[now][i]]){
				store.push(graph[now][i]);
			}
		}
	}
}
int main() {
	int from, to;
	cin >> n >> m >> start;
	
	FOR(i,m){
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	dfs(start);
	cout << endl;
	bfs(start);
	cout << endl;
}
