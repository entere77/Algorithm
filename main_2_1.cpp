#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10000

int list[MAX_SIZE];
int get_max(int low, int high) {
	int mid, max1, max2;
	//아래를 완성하시오.
	if (low == high) return low;
	else {
		mid = (low + high) / 2;
		max1 = get_max(low, mid);
		max2 = get_max(mid + 1, high);
		if (list[max1] < list[max2]) return max2;
		else return max1;
	}
}
int main(void)
{
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 1000;
	int max = get_max(0, MAX_SIZE - 1);
	printf("최대값: %d\n", list[max]);

	return 0;
}
/*아래에 알고리즘의 분석 및 차수를 쓰시오.
순환식 T(n) 안에 get_max가 2번 있으므로 a=2
low부터 mid, mid+1부터 high까지 n/2 이므로 b=2
조건문은 단위연산이고 f(n)은 단위연산 이므로 f(n)=1이다.
따라서 T(n) = 2T(n/2) + 1 이므로,
따라서 마스터 정리 1번에 의해서 T(n) = 쎄타(n)이다.
*/