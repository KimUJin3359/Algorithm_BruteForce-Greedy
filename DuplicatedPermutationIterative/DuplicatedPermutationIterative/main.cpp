#include <stdio.h>
#pragma warning (disable:4996)

int main()
{
	int *arr;
	int res;
	int *index;
	int rep;	//number of number
	int len;	//permutation length
	int flag = 1;

	scanf("%d %d", &rep, &len);
	arr = new int[rep];
	index = new int[len];
	for (int i = 0; i < rep; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < len; i++)
		index[i] = 0;
	while (flag)
	{
		res = 0;
		for (int i = 0; i < len; i++)
		{
			res *= 10;
			res += arr[index[i]];
		}
		index[len - 1]++;
		for (int i = len - 1; i > 0; i--)
		{
			if (index[i] == rep)
			{
				index[i - 1]++;
				index[i] = 0;
			}
		}
		if (index[0] == rep)
			flag = 0;
		printf("%d", res);
		if (flag)
			printf(", ");
	}
	delete index;
	delete arr;
	return (0);
}