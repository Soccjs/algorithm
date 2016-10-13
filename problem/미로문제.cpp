//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int r, c;
void dijkstra(vector< vector<int> > miro) {
	vector< vector<int> > visited(r + 2, vector<int>(c + 2, false));
	vector< vector<int> > dist(r + 2, vector<int>(c + 2, 0));
	priority_queue<pair<int, pair<int,int> > > pq;

	dist[1][1] = 1;
	visited[1][1] = true;
	pq.push(make_pair(-1, make_pair(1,1)));

	int cost, x, y, new_cost;
	while (!pq.empty()){
		cost = -pq.top().first;
		x = pq.top().second.first;
		y = pq.top().second.second;
		pq.pop();

		if (cost > dist[x][y]){
			continue;
		}

		visited[x][y] = true;

		new_cost = cost + 1;
		if (!visited[x + 1][y] && miro[x + 1][y] > 0){
			if (dist[x + 1][y] < cost + 1){
				dist[x + 1][y] = cost + 1;
				pq.push(make_pair(-new_cost, make_pair(x + 1, y)));
			}
		}
		if (!visited[x - 1][y] && miro[x - 1][y] > 0){
			if (dist[x - 1][y] < cost + 1){
				dist[x - 1][y] = cost + 1;
				pq.push(make_pair(-new_cost, make_pair(x - 1, y)));
			}
		}
		if (!visited[x][y + 1] && miro[x][y + 1] > 0){
			if (dist[x][y + 1] < cost + 1){
				dist[x][y + 1] = cost + 1;
				pq.push(make_pair(-new_cost, make_pair(x, y + 1)));
			}
		}
		if (!visited[x][y - 1] && miro[x][y - 1] > 0){
			if (dist[x][y - 1] < cost + 1){
				dist[x][y - 1] = cost + 1;
				pq.push(make_pair(-new_cost, make_pair(x, y - 1)));
			}
		}
	}

	cout << dist[r][c] << endl;
}

int main(void) {
	string input;
	cin >> r >> c;
	vector< vector<int> > miro(r + 2, vector<int>(c + 2, -1));

	for (int i = 1; i <= r; i++){
		cin >> input;
		for (int j = 1; j <= c; j++){
			miro[i][j] = input[j - 1] - '0';
		}
	}

	dijkstra(miro);
	return 0;
}