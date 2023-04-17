#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10000

int list[MAX_SIZE];
int get_max(int low, int high) {
	int mid, max1, max2;
	//�Ʒ��� �ϼ��Ͻÿ�.
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
	printf("�ִ밪: %d\n", list[max]);

	return 0;
}
/*�Ʒ��� �˰����� �м� �� ������ ���ÿ�.
��ȯ�� T(n) �ȿ� get_max�� 2�� �����Ƿ� a=2
low���� mid, mid+1���� high���� n/2 �̹Ƿ� b=2
���ǹ��� ���������̰� f(n)�� �������� �̹Ƿ� f(n)=1�̴�.
���� T(n) = 2T(n/2) + 1 �̹Ƿ�,
���� ������ ���� 1���� ���ؼ� T(n) = ��Ÿ(n)�̴�.
*/