#include <stdio.h>
#include <string.h>
int ft_printf(const char *format, ...);

int main()
{
	int x;
	int y;
	char *str = "%10.*s|%%|\n";


	printf("test format:%s\n", str);
	x = ft_printf(str, NULL, -5);
	y = printf(str, NULL, -5);
	printf("\nft_printf:%d\n", x);
	printf("printf:%d\n", y);
	if (x != y)
		printf("[KO]\n");
}