#include <stdio.h>

int main()
{
	int dot[10000] = { 0 };
	int start, end, num;
	int length = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &start, &end);
		for (int i = start; i < end; i++)
			dot[i] = 1;
	}
	for (int i = 1; i < 10000; i++)
	{
		if (dot[i] == 1)
			length++;
	}

	printf("%d", length);
}