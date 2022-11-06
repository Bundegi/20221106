#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
using namespace std;
vector<vector<int>> Array(101);
vector<vector<int>> room(101, vector<int>(5001, 5001));
//1389backjun 무지성 첫번째 제출했는데 맞은 케이스..
bool room1[101] = { 0, };
int N, M;
void init() { for (int i = 1; i < 101; i++) room1[i] = 0; }
void Kebin(int Su,int Search,int top, int memSu) {
	int flag = 1;
	for (int j = 0; j < Array[Su].size(); j++) {
		room1[Su] = 1;
		if (flag == 1) {
			for (int i = 0; i < Array[Su].size(); i++) {
				if (Array[Su][i] == Search) {
					if (room[memSu][Search] > top)
						room[memSu][Search] = top;
					init();
					return;
				}
			}
			flag = 0;
		}
		if (room1[Array[Su][j]] == 1) continue;
		else if (room[memSu][Search] <= top + 1) {
			init();
			return;
		}
		else if (Array[Su][j] != memSu) {
			Kebin(Array[Su][j], Search, top + 1, memSu);
		}
	}
}
int main() { 
	fast;
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		Array[a].push_back(b);
		Array[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(Array[i].begin(), Array[i].end());
		Array[i].erase(unique(Array[i].begin(), Array[i].end()), Array[i].end());
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j||room[i][j]!=5001) continue;
			Kebin(i, j,1,i);
			room[j][i] = room[i][j];
		}
	}
	int minimum = 5001,mini=0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			sum += room[i][j];
		}
		if (minimum > sum) {
			mini = i;
			minimum = sum;
		}
	}
	cout << mini;
}
