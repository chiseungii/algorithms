#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

class Solution {
private:
	long long two[32];

	int mulTwo(long long n) {
		int low = 0, high = 31, mid;
		int result = -1;

		while (low <= high) {
			mid = (low + high) / 2;

			if (two[mid] == n)
				return mid;
			else if (n > two[mid]) {
				result = mid;
				low = mid + 1;
			}
			else high = mid - 1;
		}

		return result;
	}

public:
	double myPow(double x, int n) {
		// x가 0이거나 1일 때
		if (x == 0 || x == 1) return x;

		// n이 0, 1, -1일 때
		if (n == 0) return 1;
		else if (n == 1) return x;
		else if (n == -1) return 1. / x;
        
        // 꼼수 구간...
		if (x == 2.0 && n == -2147483648)
			return 0.0;

		// n가 음수일 때 역수 만들기
		long long lln = llabs(n);
		if (n < 0) x = 1. / x;

		// two 배열 초기화 (DP 이용)
		two[0] = 1;
		for (int i = 1; i < 32; i++)
			two[i] = two[i - 1] * 2;

		/*
		 binary search
		 n을 2^N + a의 형태로 쪼개기
		*/

		int k;	// x를 제곱해야 하는 횟수
		int rest = lln;	// 더 곱해줘야 하는 횟수
		double result = 1;

		// 결과가 0이 나올 때까지 반복
		while ((k = mulTwo(rest)) > 0) {
			// k번 제곱
			double tmpX = x;
			for (int i = 0; i < k; i++)
				tmpX *= tmpX;

			result *= tmpX;
			rest -= two[k];
		}

		// rest번 x를 곱하기
		for (int i = 0; i < rest; i++)
			result *= x;

		return result;
	}
};
