#include <stdio.h>

int main(void)
{
	int v[] = {4, 1, 2, -17, 15, 22, 6, 2};
	int max;
	int i;
	int nr = sizeof(v)  / sizeof(v[0]);
	
	max = v[0];
	i = 1;

L:
	if(i == nr)
		goto out;
	if(max < v[i])
		max = v[i];
	i++;
	goto L;

out:	
	printf("%d", max);
}
