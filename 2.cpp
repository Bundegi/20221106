#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
#define INF 10000
using namespace std;
int V;
void floy(int graph[101][101]) {
	int i, j, k;
	int dist[101][101];

	for (i = 1; i <= V; i++)
		for (j = 1; j <= V; j++)
			dist[i][j] = graph[i][j];

	for (k = 1; k <= V; k++) {
		for (i = 1; i <= V; i++) {
			for (j = 1; j <= V; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	int minimum = 5001, mini = 0;
	for (i = 1; i <= V; i++) {
		int sum = 0;
		for (j = 1; j <= V; j++) {
			sum += dist[i][j];
		}
		if (minimum > sum) {
			minimum = sum;
			mini = i;
		}
	}
	cout << mini;
}
int main() {
	fast;
	int graph[101][101];
	int from, to, n;

	cin >> V >> n;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}
	floy(graph);
}