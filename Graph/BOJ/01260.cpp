#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

int N, M, V;	// 정점 개수, 간선 개수, 시작 번호
char graph[1001][1001];	// 그래프
char check[1001];	// 방문 체크용

void DFS() {
	// init check
	for (int i = 1; i <= N; i++)
		check[i] = 0;

	stack<int> s;
	s.push(V);
	check[V] = 1;
	cout << V << ' ';

	while (!s.empty()) {
		int tmp = s.top();

		bool flag = false;
		for (int i = 1; i <= N; i++) {
			if (graph[tmp][i] && !check[i]) {
				s.push(i);
				check[i] = 1;
				flag = true;
				cout << i << ' ';
				break;
			}
		}

		if (!flag) s.pop();
	}
	cout << endl;
}

void BFS() {
	// init check
	for (int i = 1; i <= N; i++)
		check[i] = 0;

	queue<int> q;
	q.push(V);
	check[V] = 1;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << ' ';

		for (int i = 1; i <= N; i++) {
			if (graph[tmp][i] && !check[i]) {
				q.push(i);
				check[i] = 1;
			}
		}
	}
	cout << endl;
}

int main() {
	cin >> N >> M >> V;

	// init graph
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			graph[i][j] = 0;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	DFS();
	BFS();
}
