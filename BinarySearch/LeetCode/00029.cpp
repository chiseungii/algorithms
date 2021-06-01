#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

#define MIN_INT -2147483648
#define MAX_INT 2147483647

class Solution {
public:
	int divide(int dividend, int divisor) {
		// int 범위 벗어나는 경우
		if (dividend == MIN_INT && divisor == -1)
			return MAX_INT;

		// divisor가 1, -1인 경우
		if (divisor == 1) return dividend;
		else if (divisor == -1) return -dividend;

		bool positive;	// 결과 양수인지?

		if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
			positive = true;
		else positive = false;

		/*
		 몫을 이분 탐색으로 찾아내기
		*/

		// int 범위 벗어나는 경우 때문에 long long으로 선언
		long long low = 0, high = llabs(dividend), mid;
		int result;
		divisor = abs(divisor);
		long long tmp;	// 중간 계산을 위한 변수

		while (low <= high) {
			mid = (low + high) / 2;
			tmp = divisor * mid;

			// 몫을 찾은 경우
			if (tmp == llabs(dividend))
				return positive ? mid : -mid;
			// dividend보다 큰 경우
			else if (tmp > llabs(dividend))
				high = mid - 1;
			// dividend보다 작은 경우
			else {
				result = mid;
				low = mid + 1;
			}
		}

		return positive ? result : -result;
	}
};
