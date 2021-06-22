#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

int w, h;	// h * w
int maps[50][50];	// 지도
char check[50][50];	// 방문 체크용

// 위쪽 ~ 북서쪽 시계방향
int di[8] = { -1,-1,0,1,1,1,0,-1 };
int dj[8] = { 0,1,1,1,0,-1,-1,-1 };

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = 1;

	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();

		for (int d = 0; d < 8; d++) {
			int move_i = tmp.first + di[d];
			int move_j = tmp.second + dj[d];

			// index 범위 벗어나는지 확인
			if (move_i < 0 || move_i >= h) continue;
			if (move_j < 0 || move_j >= w) continue;

			if (maps[move_i][move_j] == 1 && !check[move_i][move_j]) {
				q.push(make_pair(move_i, move_j));
				check[move_i][move_j] = 1;
			}
		}
	}
}

int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> maps[i][j];

		// init check
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				check[i][j] = 0;

		// BFS
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (maps[i][j] == 1 && !check[i][j]) {
					cnt++;
					BFS(i, j);
				}
			}
		}

		cout << cnt << endl;
	}
}
