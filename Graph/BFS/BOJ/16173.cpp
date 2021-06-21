#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
using namespace std;

int N;	// N * N
int board[3][3];	// 게임 구역

bool BFS() {
	char check[3][3];	// 방문 체크용

	// init check
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			check[i][j] = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = 1;

	while (!q.empty()) {
		// 현재 위치
		pair<int, int> tmp = q.front();
		int i = tmp.first, j = tmp.second;
		q.pop();
		check[i][j] = 1;

		// 마지막에 도달했으면 리턴
		if (i == N - 1 && j == N - 1) return true;

		// 오른쪽으로 이동
		int move_i = i;
		int move_j = j + board[i][j];
		if (move_j < N && !check[move_i][move_j]) q.push(make_pair(move_i, move_j));

		// 아래로 이동
		move_i = i + board[i][j];
		move_j = j;
		if (move_i < N && !check[move_i][move_j]) q.push(make_pair(move_i, move_j));
	}

	return false;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	if (BFS()) cout << "HaruHaru\n";
	else cout << "Hing\n";
}
