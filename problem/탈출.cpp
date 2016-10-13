//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int r, c;
pair<int, int> s, d;
vector< pair<int, int> > waterInfo;
priority_queue < pair<int, pair<int, int> > > waterQ;
priority_queue < pair<int, pair<int, int> > > pq;

void dijkstra(vector< vector<int> > miro) {
	vector< vector<int> > dist(r + 2, vector<int>(c + 2, 0));
	vector< vector<int> > waterDist(r + 2, vector<int>(c + 2, 0));
	vector< vector<bool> > visited(r + 2, vector<bool>(c + 2, false));
	vector< vector<bool> > waterVisited(r + 2, vector<bool>(c + 2, false));



	//물 부터.
	int cost, x, y, nextCost;
	//add water's index  in waterQ
	for (int i = 0; i < waterInfo.size(); i++){
		x = waterInfo[i].first;
		y = waterInfo[i].second;
		waterQ.push(make_pair(0, make_pair(x, y)));
		waterVisited[x][y] = true;
		waterDist[x][y] = 1;
	}
	
	while (!waterQ.empty()){
		cost = -waterQ.top().first;
		x = waterQ.top().second.first;
		y = waterQ.top().second.second;
		waterQ.pop();
		
		if (waterDist[x][y] < cost){
			continue;
		}
		waterVisited[x][y] = true;
		
		nextCost = cost + 1;
		if (miro[x + 1][y] == 1 && !waterVisited[x + 1][y]){
			if (waterDist[x + 1][y] < nextCost){
				waterDist[x + 1][y] = nextCost;
				waterQ.push(make_pair(-nextCost, make_pair(x + 1, y)));
			}
		}
		if (miro[x - 1][y] == 1 && !waterVisited[x - 1][y]){
			if (waterDist[x - 1][y] < nextCost){
				waterDist[x - 1][y] = nextCost;
				waterQ.push(make_pair(-nextCost, make_pair(x - 1, y)));
			}
		}
		if (miro[x][y + 1] == 1 && !waterVisited[x][y + 1]){
			if (waterDist[x][y + 1] < nextCost){
				waterDist[x][y + 1] = nextCost;
				waterQ.push(make_pair(-nextCost, make_pair(x, y + 1)));
			}
		}
		if (miro[x][y - 1] == 1 && !waterVisited[x][y - 1]){
			if (waterDist[x][y - 1] < nextCost){
				waterDist[x][y - 1] = nextCost;
				waterQ.push(make_pair(-nextCost, make_pair(x, y - 1)));
			}
		}
	}
	waterDist[d.first][d.second] = 10000;
	
	//고슴도치
	pq.push(make_pair(0, make_pair(s.first, s.second)));
	dist[s.first][s.second] = 0;
	visited[s.first][s.second] = true;

	while (!pq.empty()){
		cost = -pq.top().first;
		x = pq.top().second.first;
		y = pq.top().second.second;
		pq.pop();
		if (dist[x][y] > cost){ continue; }

		visited[x][y] = true;

		nextCost = cost + 1;
		if ((miro[x + 1][y] == 1 || miro[x + 1][y] == 10000) && !visited[x + 1][y]){
			if (dist[x + 1][y] < nextCost) {
				if (waterDist[x + 1][y] == 0){
					dist[x + 1][y] = nextCost;
					pq.push(make_pair(-nextCost, make_pair(x + 1, y)));
				}
				else{
					if (nextCost < waterDist[x + 1][y]){
						dist[x + 1][y] = nextCost;
						pq.push(make_pair(-nextCost, make_pair(x + 1, y)));
					}
				}
			}
		}
		if ((miro[x - 1][y] == 1 || miro[x - 1][y] == 10000) && !visited[x - 1][y]){
			if (dist[x - 1][y] < nextCost) {
				if (waterDist[x - 1][y] == 0){
					dist[x - 1][y] = nextCost;
					pq.push(make_pair(-nextCost, make_pair(x - 1, y)));
				}
				else{
					if (nextCost < waterDist[x - 1][y]){
						dist[x - 1][y] = nextCost;
						pq.push(make_pair(-nextCost, make_pair(x - 1, y)));
					}
				}
			}
		}
		if ((miro[x][y + 1] == 1 || miro[x][y + 1] == 10000) && !visited[x][y + 1]){
			if (dist[x][y + 1] < nextCost) {
				if (waterDist[x][y + 1] == 0){
					dist[x][y + 1] = nextCost;
					pq.push(make_pair(-nextCost, make_pair(x, y + 1)));
				}
				else{
					if (nextCost < waterDist[x][y + 1]){
						dist[x][y + 1] = nextCost;
						pq.push(make_pair(-nextCost, make_pair(x, y + 1)));
					}
				}
			}
		}
		if ((miro[x][y - 1] == 1 || miro[x][y - 1] == 10000) && !visited[x][y - 1]){
			if (dist[x][y - 1] < nextCost) {
				if (waterDist[x][y - 1] == 0){
					dist[x][y - 1] = nextCost;
					pq.push(make_pair(-nextCost, make_pair(x, y - 1)));
				}
				else{
					if (nextCost < waterDist[x][y - 1]){
						dist[x][y - 1] = nextCost;
						pq.push(make_pair(-nextCost, make_pair(x, y - 1)));
					}
				}
			}
		}
	}
	
	if (dist[d.first][d.second] != 0){
		cout << dist[d.first][d.second] << endl;
	}
	else{
		cout << "KAKTUS" << endl;
	}
}

int main(void) {
	string input;
	cin >> r >> c;
	vector< vector<int> > miro(r + 2, vector<int>(c + 2, -1));
	for (int i = 1; i <= r; i++){
		cin >> input;
		for (int j = 1; j <= c; j++){
			if (input[j - 1] == 'S'){
				miro[i][j] = 1;
				s = make_pair(i, j);
			}
			else if (input[j - 1] == 'D'){
				miro[i][j] = 10000;
				d = make_pair(i, j);
			}
			else if (input[j - 1] == '*'){
				waterInfo.push_back(make_pair(i, j));
			}
			else if (input[j - 1] == 'X'){
				miro[i][j] = -1;
			}
			else{
				miro[i][j] = 1;
			}
		}
	}

	if (r == 1 && c == 1){
		cout << "KAKTUS" << endl;
		return 0;
	}
	
	dijkstra(miro);
	
	return 0;
}