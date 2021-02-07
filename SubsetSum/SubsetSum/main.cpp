#include <stdio.h>
#pragma warning (disable:4996)

void get_Combination(int *arr, bool *visit, int res, int index)
{
	if (visit[index] == true)
		return;
	res += arr[index];
	if (res == 0)
	{
		for (int i = 0; i < 10; i++)
			if (visit[i] == true)
				printf("%d ", arr[i]);
		printf("%d\n", arr[index]);
	}
	for (int i = index; i < 10; i++)
	{
		visit[index] = true;
		get_Combination(arr, visit, res, i);
		visit[index] = false;
	}
}

int main()
{
	int arr[] = { -1, 3, -9, 6, 7, -6, 1, 5, 4, -2 };
	bool visit[10] = { false, };
	for (int i = 0; i < 10; i++)
		get_Combination(arr, visit, 0, i);
	return (0);
}