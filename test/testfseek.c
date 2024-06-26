#include <stdio.h>

int main(void)
{
	char c;
	printf("Hiya\n");
	scanf("%c", &c);

	size_t fs1 = fseek(stdin, 0, SEEK_END);
	size_t fs2 = ftell(stdin);

	printf("fseek is %lu and ftell is %lu\n", fs1, fs2);

	return 0;
}
