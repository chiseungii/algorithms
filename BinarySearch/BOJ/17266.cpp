#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

// h 높이로 다 밝히는 게 가능한지?
bool possible(vector<int> locates, int h, int n) {
	int bright = 0;

	for (int locate : locates) {
		// locate - h가 bright가 안 되면 false
		if (locate - h > bright) return false;
		bright = locate + h;
	}

	if (bright < n) return false;
	return true;
}

int main() {
	int N; cin >> N;	// 굴다리 길이
	int M; cin >> M;	// 가로등 개수
	vector<int> locates;	// 가로등 위치

	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		locates.push_back(x);
	}

	/*
	 1 ~ N 중에서 가능한 높이를 binary search
	*/

	int low = 1, high = N, mid;
	int result = N + 1;

	while (low <= high) {
		mid = (low + high) / 2;

		if (possible(locates, mid, N)) {
			result = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}

	cout << result << endl;
}
