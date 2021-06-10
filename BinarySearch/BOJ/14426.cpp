#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

bool isHead(string src, string s) {
	// s가 src보다 길이가 길면 false
	if (s.length() > src.length()) return false;

	for (int i = 0; i < s.length(); i++)
		if (src[i] != s[i]) return false;

	return true;
}

int main() {
	int N; cin >> N;	// 집합 S에 포함된 문자열 개수
	int M; cin >> M;	// 검사해야 할 문자열 개수
	vector<string> S;	// 집합 S

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		S.push_back(s);
	}
	sort(S.begin(), S.end());	// S 정렬

	int cnt = 0;	// 접두사 개수 카운트

	for (int i = 0; i < M; i++) {
		string str; cin >> str;

		/*
		 집합 S에서 하나라도 겹치는 게 있는지 binary search
		*/

		int low = 0, high = N - 1, mid;

		while (low <= high) {
			mid = (low + high) / 2;

			if (isHead(S[mid], str)) {
				cnt++;
				break;
			}
			else if (str > S[mid]) low = mid + 1;
			else high = mid - 1;
		}
	}

	cout << cnt << endl;
}
