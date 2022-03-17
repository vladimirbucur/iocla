#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* delete_first(char *s, char *pattern) {
	char *s1 = malloc((strlen(s) + 1) * sizeof(char));
	strcpy(s1, s);
	char *p1 = strtok(s, pattern);
	char *p2 = strstr(s1, pattern) + strlen(pattern);
	char *aux = malloc((strlen(p1) + strlen(p2) + 2) * sizeof(char));
	strcpy(aux, p1);
	strcat(aux,p2);

	free(s1);

	return aux;
}

int main(){
	char s[] = "Ana are mere";
	char *pattern = "re";

	char *p = delete_first(s, pattern);
	printf("%s\n", p);
	free(p);

	return 0;
}
