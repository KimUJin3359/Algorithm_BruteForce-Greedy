#include <stdio.h>
#pragma warning (disable:4996)

int rep;	//number of number
int len;	//permutation length

void get_Combination(int *arr, int res, int cnt, int index)
{
	int temp;

	if (arr[index] == -1)
		return;
	else
		temp = arr[index];
	res *= 10;
	res += temp;
	if (cnt == len)
	{
		printf("%d ", res);
		return;
	}
	for (int i = index; i < rep; i++)
	{
		arr[index] = -1;
		get_Combination(arr, res, cnt + 1, i);
		arr[index] = temp;
	}
}

int main()
{
	int *arr;

	scanf("%d %d", &rep, &len);
	arr = new int[rep];
	for (int i = 0; i < rep; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < rep; i++)
		get_Combination(arr, 0, 1, i);
	delete arr;
	return (0);
}