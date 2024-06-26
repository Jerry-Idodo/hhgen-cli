#include <stdio.h>
#include <string.h>

int main(void)
{
	char c;
	char buff[128];
	const int width = 16;

	printf("Hiya\n");
	memset(buff, 0, width);
	fgets(buff, width, stdin);
	buff[strcspn(buff, "\n")] = 0;

	sscanf(buff, "%c", &c);

	size_t fs1 = fseek(stdin, 0, SEEK_END);
	size_t fs2 = ftell(stdin);
	size_t fend = feof(stdin);

	printf("fseek is %lu, ftell is %lu and feof is %lu\n", fs1, fs2, fend);

	return 0;
}
