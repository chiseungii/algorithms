#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

vector<pair<string, int>> names;	// <칭호, 상한선>

string binarySearch(int power) {
	if (power <= names[0].second) return names[0].first;

	int low = 0, high = names.size() - 1, mid;
	string result;

	while (low <= high) {
		mid = (low + high) / 2;

		if (power == names[mid].second)
			return names[mid].first;
		else if (power < names[mid].second) {
			result = names[mid].first;
			high = mid - 1;
		}
		else low = mid + 1;
	}

	return result;
}

int main() {
	int N; scanf("%d", &N);	// 칭호 개수
	int M; scanf("%d", &M);	// 캐릭터 개수

	char buf[20]; int n;

	for (int i = 0; i < N; i++) {
		scanf("%s %d", buf, &n);
		string s = buf;
		names.push_back(make_pair(s, n));
	}

	/*
	 names의 어느 자리에 들어가야 할 지 binary search
	*/

	for (int i = 0; i < M; i++) {
		int power; scanf("%d", &power);
		printf("%s\n", binarySearch(power).c_str());
	}
}
