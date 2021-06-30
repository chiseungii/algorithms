#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

int N;	// 전체 문자의 수
int M;	// 가능한 문자쌍의 수
int a, b;
vector<int> graph[1001];

char check[1001];
int weight[1001];

int BFS() {
	// if (a == b) return 0;

	queue<int> q;
	q.push(a);
	check[a] = 1;
	weight[a] = 0;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		if (tmp == b) return weight[tmp];

		for (int i = 0; i < graph[tmp].size(); i++) {
			if (!check[graph[tmp][i]]) {
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = 1;
				weight[graph[tmp][i]] = weight[tmp] + 1;
			}
		}
	}

	return -1;
}

int main() {
	cin >> a >> b;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// init check
	for (int i = 1; i < 1000; i++) check[i] = 0;

	cout << BFS() << endl;
}
