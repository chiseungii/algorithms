#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

short n, m;	// n * m
short paper[500][500];	// 도화지

int cnt_pic = 0;	// 그림 개수 카운트
int max_pic = 0;	// 제일 큰 그림

// 4방향 상, 하, 좌, 우
short di[4] = { -1, 1, 0, 0 };
short dj[4] = { 0, 0, -1, 1 };

void BFS(int start_i, int start_j) {
	cnt_pic++;

	queue<pair<short, short>> q;
	q.push(make_pair(start_i, start_j));
	paper[start_i][start_j] = 2;
	int pic = 1;	// 그림 크기

	while (!q.empty()) {
		short tmp_i = q.front().first;
		short tmp_j = q.front().second;
		q.pop();

		for (short i = 0; i < 4; i++) {
			short move_i = tmp_i + di[i];
			short move_j = tmp_j + dj[i];

			// index 범위 체크
			if (move_i < 0 || move_i >= n) continue;
			if (move_j < 0 || move_j >= m) continue;

			if (paper[move_i][move_j] == 1) {
				q.push(make_pair(move_i, move_j));
				paper[move_i][move_j] = 2;
				pic++;
			}
		}
	}

	if (pic > max_pic) max_pic = pic;
}

int main() {
	cin >> n >> m;

	for (short i = 0; i < n; i++)
		for (short j = 0; j < m; j++)
			cin >> paper[i][j];

	// BFS
	for (short i = 0; i < n; i++)
		for (short j = 0; j < m; j++)
			if (paper[i][j] == 1)
				BFS(i, j);

	cout << cnt_pic << endl;
	cout << max_pic << endl;
}
