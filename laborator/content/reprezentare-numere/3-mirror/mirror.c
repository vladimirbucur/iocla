#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mirror(char *s)
{
	char *aux = malloc((strlen(s)+1) * sizeof(char));
	strcpy(aux, s);
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		*(s + i) = *(aux + (len - i - 1));
	free(aux);
}

int main()
{
	char str[256];
	scanf("%s", str);
	mirror(str);
	printf("%s\n", str);
	return 0;
}

