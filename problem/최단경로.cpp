//https://www.acmicpc.net/problem/1753
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 987654321
vector< vector<pair<int, int> > >adj;
int n, m, start;
int u, v, w;
void dijkstra(){
	priority_queue<pair<int, int> > pq;
	vector<int> dist(n + 1, MAX);
	dist[start] = 0;
	pq.push(make_pair(0, start));
	int cost, newCost;
	while (!pq.empty()){
		cost = -pq.top().first;
		u = pq.top().second;
		pq.pop();
		if (dist[u] < cost) { continue; }

		for (int i = 0; i<adj[u].size(); i++){
			v = adj[u][i].first;
			w = adj[u][i].second;
			newCost = cost + w;
			if (dist[v] > newCost){
				dist[v] = newCost;
				pq.push(make_pair(-newCost, v));
			}
		}
	}

	for (int i = 1; i <= n; i++){
		if (start == i){
			printf("0\n");
		}
		else{
			if (dist[i] == MAX){
				printf("INF\n");
			}
			else{
				printf("%d\n", dist[i]);
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &start);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	dijkstra();
	return 0;
}