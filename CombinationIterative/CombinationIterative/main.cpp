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
	index[0] = 0;
	for (int i = 1; i < len; i++)
		index[i] = index[i - 1] + 1;
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
			if (index[i] >= rep - (len - 1 - i))
			{
				index[i - 1]++;
				for (int j = i ; j < len; j++)
					index[j] = index[j - 1] + 1;
			}
		}
		if (index[0] == rep - len + 1)
			flag = 0;
		printf("%d ", res);
	}
	delete index;
	delete arr;
	return (0);
}