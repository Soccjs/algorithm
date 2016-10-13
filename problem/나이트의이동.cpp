//https://www.acmicpc.net/problem/7562
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, chess_size;
pair<int, int> s, d;

void dijkstra(){
	vector< vector<int> > dist(chess_size, vector<int>(chess_size, 0));
	vector< vector<bool> > visit(chess_size, vector<bool>(chess_size, false));
	priority_queue<pair<int, pair<int, int> > > pq;

	pq.push(make_pair(0, make_pair(s.first, s.second)));
	visit[s.first][s.second] = true;
	dist[s.first][s.second] = 0;

	int cost, x, y, nextCost;
	while (!pq.empty()){
		cost = -pq.top().first;
		x = pq.top().second.first;
		y = pq.top().second.second;
		pq.pop();
		if (dist[x][y] < cost){ continue; }

		visit[x][y] = true;

		nextCost = cost + 1;
		if (x - 2 >= 0 && y - 1 >= 0){
			if (!visit[x - 2][y - 1] && dist[x - 2][y - 1]==0) {
				dist[x - 2][y - 1] = nextCost;
				pq.push(make_pair(-nextCost, make_pair(x - 2, y - 1)));
			}
		}
		if (x - 1 >= 0 && y - 2 >= 0){
			if (!visit[x - 1][y - 2] && dist[x - 1][y - 2] == 0) {
				dist[x - 1][y - 2] = nextCost;
				pq.push(make_pair(-nextCost, make_pair(x - 1, y - 2)));
			}
		}
		if (x - 2 >= 0 && y + 1 < chess_size){
			if (!visit[x - 2][y + 1] && dist[x - 2][y + 1] == 0) {
				dist[x - 2][y + 1] = nextCost;
				pq.push(make_pair(-nextCost, make_pair(x - 2, y + 1)));
			}
		}
		if (x - 1 >= 0 && y + 2 < chess_size){
			if (!visit[x - 1][y + 2] && dist[x - 1][y + 2] == 0) {
				dist[x - 1][y + 2] = nextCost;
				pq.push(make_pair(-nextCost, make_pair(x - 1, y + 2)));
			}
		}
		if (x + 1 < chess_size && y - 2 >= 0){
			if (!visit[x + 1][y - 2] && dist[x + 1][y - 2] == 0) {
				dist[x + 1][y - 2] = nextCost;
				pq.push(make_pair(-nextCost, make_pair(x + 1, y - 2)));
			}
		}
		if (x + 2 < chess_size && y - 1 >= 0){
			if (!visit[x + 2][y - 1] && dist[x + 2][y - 1] == 0) {
				dist[x + 2][y - 1] = nextCost;
				pq.push(make_pair(-nextCost, make_pair(x + 2, y - 1)));
			}
		}
		if (x + 2 < chess_size && y + 1 < chess_size){
			if (!visit[x + 2][y + 1] && dist[x + 2][y + 1] == 0) {
				dist[x + 2][y + 1] = nextCost;
				pq.push(make_pair(-nextCost, make_pair(x + 2, y + 1)));
			}
		}
		if (x + 1 < chess_size && y + 2 < chess_size){
			if (!visit[x + 1][y + 2] && dist[x + 1][y + 2] == 0) {
				dist[x + 1][y + 2] = nextCost;
				pq.push(make_pair(-nextCost, make_pair(x + 1, y + 2)));
			}
		}
	}
	cout << dist[d.first][d.second] << endl;
}

int main() {
	cin >> n; 
	
	while (n--){
		cin >> chess_size;
		cin >> s.first >> s.second;
		cin >> d.first >> d.second;
		dijkstra();
	}
	return 0;
}