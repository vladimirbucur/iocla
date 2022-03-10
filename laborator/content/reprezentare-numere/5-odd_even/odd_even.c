#include <stdio.h>
#include <stdlib.h>

void print_binary(int number, int nr_bits)
{
	for(int i = nr_bits; i >= 0; i--) {
		int c = number >> i;
	if( c & 1)
		printf("1");
	else
		printf("0");
	}
	printf("\n");
}

void check_parity(int *numbers, int n)
{
		for(int i = 0; i < n; i++)
		if((*(numbers + i) ^ 1 )== *(numbers +i) +1)
			print_binary(*(numbers + i), 8 * sizeof(int));
		else 
			printf("0x%x\n", *(numbers + i));
}

int main()
{
	int nr, *numbers;
	scanf("%d", &nr);
	numbers = malloc(nr * sizeof(int));
	for(int i = 0; i < nr; i++)
		scanf("%d", numbers+i);
	check_parity(numbers, nr);

	return 0;
}

