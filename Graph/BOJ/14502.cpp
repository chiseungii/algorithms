#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

int N, M;	// N * M
short room[8][8];	// 연구소

// 4방향 상, 하, 좌, 우
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

int BFS(vector<pair<int, int>> virus) {
	// room copy
	short copy_room[8][8];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			copy_room[i][j] = room[i][j];

	queue<pair<int, int>> q;

	for (int i = 0; i < virus.size(); i++)
		q.push(virus[i]);

	while (!q.empty()) {
		int tmp_i = q.front().first;
		int tmp_j = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int move_i = tmp_i + di[i];
			int move_j = tmp_j + dj[i];

			// index 범위 체크
			if (move_i < 0 || move_i >= N) continue;
			if (move_j < 0 || move_j >= M) continue;

			if (copy_room[move_i][move_j] == 0) {
				q.push(make_pair(move_i, move_j));
				copy_room[move_i][move_j] = 2;
			}
		}
	}

	// 안전지역 카운트
	int cnt = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (copy_room[i][j] == 0) cnt++;

	return cnt;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> room[i][j];

	vector<pair<int, int>> empty_room;	// 빈 칸
	vector<pair<int, int>> virus_room;	// 바이러스

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (room[i][j] == 0)
				empty_room.push_back(make_pair(i, j));
			else if (room[i][j] == 2)
				virus_room.push_back(make_pair(i, j));
		}
	}

	// 브루트포스
	int max_room = 0;

	for (int i = 0; i < empty_room.size() - 2; i++) {
		room[empty_room[i].first][empty_room[i].second] = 1;

		for (int j = i + 1; j < empty_room.size() - 1; j++) {
			room[empty_room[j].first][empty_room[j].second] = 1;

			for (int k = j + 1; k < empty_room.size(); k++) {
				room[empty_room[k].first][empty_room[k].second] = 1;

				// BFS
				int cnt = BFS(virus_room);
				if (cnt > max_room) max_room = cnt;

				room[empty_room[k].first][empty_room[k].second] = 0;
			}

			room[empty_room[j].first][empty_room[j].second] = 0;
		}

		room[empty_room[i].first][empty_room[i].second] = 0;
	}

	cout << max_room << endl;
}
