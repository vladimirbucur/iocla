#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
	int l = 0;
	const char *p = str;
	while (*p) {
		l++;
		p++;
	}
	return l;
}
//  i + 2^i
void equality_check(const char *str)
{
	int i=0;
	int l = my_strlen(str);
	while (*(str+i)) {
		if ( *(str + i) ^ ((*(str + i) + (1 << *(str + i)) % l)))
			printf("%p\n",str+i);
		i++;
	} 
}

int main(void)
{
	char str[256];
	scanf("%s", str);
	int l = my_strlen(str);
	printf("%d\n", l);
	equality_check(str);
	return 0;
}

