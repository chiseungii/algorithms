#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

#define MAX_BOOST 301

short N, M;	// N * M
short maps[301][301];	// 맵
short check[301][301];

int BFS() {
	queue<pair<short, short>> q;
	q.push(make_pair(1, 1));
	check[1][1] = 1;

	while (!q.empty()) {
		short tmp_i = q.front().first;
		short tmp_j = q.front().second;
		q.pop();

		if (tmp_i == N && tmp_j == M)
			return check[tmp_i][tmp_j] - 1;

		// 오른쪽
		for (short i = tmp_j + 1; i <= M && i <= tmp_j + maps[tmp_i][tmp_j]; i++) {
			if (check[tmp_i][tmp_j] + 1 < check[tmp_i][i]) {
				q.push(make_pair(tmp_i, i));
				check[tmp_i][i] = check[tmp_i][tmp_j] + 1;
			}
		}

		// 아래쪽
		for (short i = tmp_i + 1; i <= N && i <= tmp_i + maps[tmp_i][tmp_j]; i++) {
			if (check[tmp_i][tmp_j] + 1 < check[i][tmp_j]) {
				q.push(make_pair(i, tmp_j));
				check[i][tmp_j] = check[tmp_i][tmp_j] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (short i = 1; i <= N; i++)
		for (short j = 1; j <= M; j++)
			cin >> maps[i][j];

	// init check
	for (short i = 1; i <= N; i++)
		for (short j = 1; j <= M; j++)
			check[i][j] = MAX_BOOST;

	cout << BFS() << endl;
}
