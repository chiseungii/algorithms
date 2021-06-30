#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

short R, C;	// R * C
char cage[250][250];	// 목장

// 4방향 상, 하, 좌, 우
short di[4] = { -1, 1, 0, 0 };
short dj[4] = { 0, 0, -1, 1 };

pair<short, short> BFS(short start_i, short start_j) {
	queue<pair<short, short>> q;
	q.push(make_pair(start_i, start_j));

	short lamb = 0, wolf = 0;

	// 동물 카운트
	if (cage[start_i][start_j] == 'v') wolf++;
	else if (cage[start_i][start_j] == 'k') lamb++;

	cage[start_i][start_j] = '-';

	while (!q.empty()) {
		short tmp_i = q.front().first;
		short tmp_j = q.front().second;
		q.pop();

		for (short i = 0; i < 4; i++) {
			short move_i = tmp_i + di[i];
			short move_j = tmp_j + dj[i];

			// index 범위 체크
			if (move_i < 0 || move_i >= R) continue;
			if (move_j < 0 || move_j >= C) continue;

			if (cage[move_i][move_j] != '#' && cage[move_i][move_j] != '-') {
				q.push(make_pair(move_i, move_j));
				if (cage[move_i][move_j] == 'v') wolf++;
				else if (cage[move_i][move_j] == 'k') lamb++;
				cage[move_i][move_j] = '-';
			}
		}
	}

	if (lamb > wolf) wolf = 0;
	else lamb = 0;

	return { lamb, wolf };
}

int main() {
	cin >> R >> C;

	for (short i = 0; i < R; i++)
		for (short j = 0; j < C; j++)
			cin >> cage[i][j];

	// BFS
	pair<short, short> animals = { 0, 0 };	// 양 수, 늑대 수
	for (short i = 0; i < R; i++) {
		for (short j = 0; j < C; j++) {
			if (cage[i][j] != '#' && cage[i][j] != '-') {
				pair<short, short> tmp = BFS(i, j);
				animals.first += tmp.first;
				animals.second += tmp.second;
			}
		}
	}

	cout << animals.first << ' ' << animals.second << endl;
}
