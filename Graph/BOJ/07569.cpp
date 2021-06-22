#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
using namespace std;

int N, M, H;	// 세로, 가로, 높이
int boxes[100][100][100];	// 박스들
int check[100][100][100];	// 방문 체크 & 일수 체크

// 이동 방향: 위, 아래, 왼, 오, 앞, 뒤 순서
int dh[6] = { -1, 1, 0, 0, 0, 0 };
int di[6] = { 0, 0, 0, 0, -1, 1 };
int dj[6] = { 0, 0, -1, 1, 0, 0 };

typedef struct indexes {
	int k, i, j;
} idx;

queue<idx> q;

void BFS() {
	while (!q.empty()) {
		idx tmp = q.front();
		q.pop();

		for (int d = 0; d < 6; d++) {
			int move_k = tmp.k + dh[d];
			int move_i = tmp.i + di[d];
			int move_j = tmp.j + dj[d];

			// index 범위 벗어나는지 확인
			if (move_k < 0 || move_k >= H) continue;
			if (move_i < 0 || move_i >= N) continue;
			if (move_j < 0 || move_j >= M) continue;

			// 안 익은 토마토가 있고 방문 안 했으면 체크
			if (boxes[move_k][move_i][move_j] == 0 &&
				check[move_k][move_i][move_j] == -1) {
				q.push(idx({ move_k,move_i,move_j }));
				check[move_k][move_i][move_j] = check[tmp.k][tmp.i][tmp.j] + 1;
				boxes[move_k][move_i][move_j] = 1;
			}
		}
	}
}

int main() {
	cin >> M >> N >> H;

	for (int k = H - 1; k >= 0; k--)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> boxes[k][i][j];

	// init check
	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				check[k][i][j] = -1;

	// 익은 토마토 찾으면 q에 넣기
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (boxes[k][i][j] == 1) {
					q.push(idx({ k, i, j }));
					check[k][i][j] = 0;
				}
			}
		}
	}

	// BFS 돌리기
	BFS();

	// 안 익은 토마토 있는지 확인
	bool noTomato = false;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (boxes[k][i][j] == 0) {
					noTomato = true;
					break;
				}
			}
			if (noTomato) break;
		}
		if (noTomato) break;
	}

	// 안 익은 토마토 있으면 -1 출력
	if (noTomato) cout << -1 << endl;
	// 아니면 제일 큰 값 찾기
	else {
		int max_check = -1;
		for (int k = 0; k < H; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					if (check[k][i][j] > max_check)
						max_check = check[k][i][j];

		cout << max_check << endl;
	}
}
