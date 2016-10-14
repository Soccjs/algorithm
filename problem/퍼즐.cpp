//https://www.acmicpc.net/problem/1525
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

#define FOR(i,s,n) for(int i=s;i<n;i++)

vector< vector<char> > puzzle(5, vector<char>(5, '9'));
map<string, int> M;
pair<map<string, int>::iterator, bool> chk;
string goal = "123456780";
int X[9] = { 1, 1, 1, 2, 2, 2, 3, 3, 3 };
int Y[9] = { 1, 2, 3, 1, 2, 3, 1, 2, 3 };

void input(){
	FOR(i, 1, 4){
		FOR(j, 1, 4){
			cin >> puzzle[i][j];
		}
	}
}

string make_string(vector< vector<char> > s){
	string result = "";
	FOR(i, 1, 4){
		FOR(j, 1, 4){
			result += s[i][j];
		}
	}
	return result;
}
void swap(char *a, char *b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

bool go_puzzle(){
	string state = make_string(puzzle);
	if (state == goal){
		cout << 0 << endl;
		return true;
	}
	priority_queue< pair<int,string> > que;
	int zero, x, y, k, cost, nextCost;
	string nextState = "";
	M.insert(make_pair(state, true));
	que.push(make_pair(0, state));
	while (!que.empty()){
		cost = -que.top().first;
		state = que.top().second;
		if (state == goal){
			cout << cost << endl;
			return true;
		}
		k = 0;
		FOR(i, 1, 4){
			FOR(j, 1, 4){
				if (state[k] == '0'){
					zero = k;
				}
				puzzle[i][j] = state[k++];
			}
		}

		x = X[zero];
		y = Y[zero];
		que.pop();

		nextCost = cost + 1;
		if (x - 1 >= 1){
			swap(puzzle[x][y], puzzle[x - 1][y]);
			nextState = make_string(puzzle);
			swap(puzzle[x][y], puzzle[x - 1][y]);
			chk = M.insert(make_pair(nextState, true));
			if (chk.second){
				que.push(make_pair(-nextCost, nextState));
			}
		}
		if (x + 1 <= 3){
			swap(puzzle[x][y], puzzle[x + 1][y]);
			nextState = make_string(puzzle);
			swap(puzzle[x][y], puzzle[x + 1][y]);
			chk = M.insert(make_pair(nextState, true));
			if (chk.second){
				que.push(make_pair(-nextCost, nextState));
			}
		}
		if (y - 1 >= 1){
			swap(puzzle[x][y], puzzle[x][y - 1]);
			nextState = make_string(puzzle);
			swap(puzzle[x][y], puzzle[x][y - 1]);
			chk = M.insert(make_pair(nextState, true));
			if (chk.second){
				que.push(make_pair(-nextCost, nextState));
			}
		}
		if (y + 1 <= 3){
			swap(puzzle[x][y], puzzle[x][y + 1]);
			nextState = make_string(puzzle);
			swap(puzzle[x][y], puzzle[x][y + 1]);
			chk = M.insert(make_pair(nextState, true));
			if (chk.second){
				que.push(make_pair(-nextCost, nextState));
			}
		}
	}
	return false;
}
int main(){

	input();
	
	if (!go_puzzle()){
		cout << -1 << endl;
	}
}