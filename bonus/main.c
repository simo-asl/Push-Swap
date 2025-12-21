#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	scanf("%d", &i);
	char *s = malloc(100);
	if (i == 10)
		free(s);
	else
	{
		printf("Dkhlti number ghalet!!!\n");
		exit(1);
	}
	free(s);
}
