//https://www.acmicpc.net/problem/1238
#include<iostream>
#include<vector>
#include<algorithm>
#define Max 1001
using namespace std;

int d[Max][Max]; // Cost Table. d[v1][v2] : Minimum cost of path v1 -> v2
int via[Max][Max]; // Via Table.
void doFloyd(int N)
{
    // Initialize
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            d[i][j] = via[i][j]; // k = 0
        }
    }

    // Do Floyd-Warshall Algorithm
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    via[i][j] = k;
                }
            }
        }
    }
}

int main() {
	int N,M,X;
	int from,to,cost,i,j;
	cin >> N >> M >> X;
	
	for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            via[i][j] = 10000001;
			d[i][j] = NULL;
        }
    }
	
	for (i=0;i<M;i++) {
		cin >> from >> to >> cost;
		via[from][to] = cost;
	}
	

	doFloyd(N);

	for (i=1;i<=N;i++) {
		for(j=1;j<=N;j++){
			cout<<d[i][j]<<" ";
		}cout<<endl;
	}

	int result[Max]={0};
	for (i=1;i<=N;i++) { 
		if (i!=X){
			result[i] = d[i][X] + d[X][i];
		}
			cout<<i<< " "<<result[i]<<endl;
	}

	
	cout<< *max_element(result+1, result+N+1)<<endl;
}


