#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

long long N;	// 정수 N
long long graph[5001][5001];
long long check[5001];

void BFS() {
	queue<long long> q;
	q.push(1);
	check[1] = 0;

	while (!q.empty()) {
		long long tmp = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (i == tmp) continue;
			if (graph[tmp][i] && check[i] == -1) {
				q.push(i);
				check[i] = check[tmp] + graph[tmp][i];
			}
		}
	}
}

int main() {
	cin >> N;

	for (long long i = 0; i < N - 1; i++) {
		long long A, B, C; cin >> A >> B >> C;
		graph[A][B] = graph[B][A] = C;
	}

	// init check
	for (long long i = 1; i <= N; i++) check[i] = -1;

	BFS();

	// max값 출력
	long long max = check[1];
	for (long long i = 2; i <= N; i++)
		if (check[i] > max)
			max = check[i];

	cout << max << endl;
}
