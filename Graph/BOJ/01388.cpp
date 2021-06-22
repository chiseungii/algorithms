#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
using namespace std;

int N, M;	// N * M
char _floor[100][100];	// 방바닥

int cnt = 0;	// 전체 나무 조각 개수
char check[100][100];	// 방문 체크용

void DFS(int i, int j) {
	check[i][j] = 1;
	cnt++;

	// '-' 모양이면 오른쪽으로
	if (_floor[i][j] == '-') {
		for (int k = j + 1; k < M; k++) {
			if (_floor[i][k] == '-') check[i][k] = 1;
			else break;
		}
	}
	// '|' 모양이면 아래쪽으로
	else {
		for (int k = i + 1; k < N; k++) {
			if (_floor[k][j] == '|') check[k][j] = 1;
			else break;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> _floor[i][j];

	// init check
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			check[i][j] = 0;

	// DFS
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!check[i][j])
				DFS(i, j);

	cout << cnt << endl;
}
