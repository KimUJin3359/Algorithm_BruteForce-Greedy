#include <stdio.h>
#pragma warning (disable:4996)

int *arr;
int rep;	//number of number
int len;	//permutation length

void get_Permutation(int res, int cnt, int index)
{
	res *= 10;
	res += arr[index];
	if (cnt == len)
	{
		printf("%d ", res);
		return;
	}
	for (int i = 0; i < rep; i++)
		get_Permutation(res, cnt + 1, i);
}

int main()
{
	scanf("%d %d", &rep, &len);
	arr = new int[rep];
	for (int i = 0; i < rep; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < rep; i++)
		get_Permutation(0, 1, i);
	delete arr;
	return (0);
}