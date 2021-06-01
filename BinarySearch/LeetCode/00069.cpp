#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		// 0, 1일 땐 바로 리턴
		if (!x || x == 1) return x;

		/*
		 제곱해서 x가 되는 정수를
		 binary search로 찾음
		*/

		// mid * mid가 int 범위 벗어나서 long long으로 선언
		// high를 최대한 낮게 잡기 위해 /2
		long long low = 1, high = x / 2, mid;
		int result;

		while (low <= high) {
			mid = (low + high) / 2;

			// 제곱한 수가 x와 같거나 작으면 가능한 수
			if (mid * mid <= x) {
				result = mid;
				low = mid + 1;
			}
			// x보다 크면 불가능
			else high = mid - 1;
		}

		return result;
	}
};
