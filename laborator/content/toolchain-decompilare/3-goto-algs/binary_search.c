#include <stdio.h>

int main(void)
{
	int v[] =  {1, 2, 15, 51, 53, 66, 202, 7000};
	int dest = 15; /* 15 */
	int start = 0;
	int end = sizeof(v) / sizeof(int) - 1;

L:
	if (start > end)
		goto notfind;
	int m = start + (end - start) / 2;

	if (v[m] == dest) {
		printf("Element is present at index %d\n", m);
		return 0;
	}
		

	if (v[m] < dest)
		start = m + 1;
	else
		end = m - 1;
	goto L;

notfind:
	printf("Element is not present in array");
}
