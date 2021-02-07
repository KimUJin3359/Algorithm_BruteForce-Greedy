#include <stdio.h>
#pragma warning (disable:4996)

int *ft_intcpy(int *dest, int *src, int len)
{
	int i = 0;

	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int main()
{
	int *arr;
	int *buf;
	int res;
	int *index;
	int rep;	//number of number
	int len;	//permutation length
	int flag = 1;

	scanf("%d %d", &rep, &len);
	arr = new int[rep];
	buf = new int[rep];
	index = new int[len];
	for (int i = 0; i < rep; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < len; i++)
		index[i] = 0;
	while (flag)
	{
		int print = 1;

		ft_intcpy(buf, arr, rep);
		res = 0;
		for (int i = 0; i < len; i++)
		{
			if (buf[index[i]] != -1)
			{
				res *= 10;
				res += buf[index[i]];
				buf[index[i]] = -1;
			}
			else
			{
				print = 0;
				break;
			}
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
		if (print)
			printf("%d ", res);
	}
	delete index;
	delete arr;
	return (0);
}