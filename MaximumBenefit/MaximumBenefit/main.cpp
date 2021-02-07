#include <stdio.h>
#pragma warning (disable : 4996)

int	get_size(int num)
{
	int size = 0;
	long long n;

	if (num < 0 || num == 0)
		size++;
	if (num < 0)
		n = -num;
	else
		n = num;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char *ft_itoa(int num)
{
	char *str;
	long long n;
	int minus = 0;
	int size = get_size(num);
	int i = 0;

	str = new char[size + 1];
	if (num < 0)
	{
		n = -num;
		str[0] = '-';
		i++;
	}
	else
		n = num;
	str[size] = '\0';
	while (i < size)
	{
		str[--size] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

size_t	ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void ft_swap(char &a, char &b)
{
	char c = a;
	a = b;
	b = c;
}

int main()
{
	int test_c;
	int test_n = 1;
	int num, change;
	char *nums;

	scanf("%d", &test_c);
	while (test_n <= test_c)
	{
		char *isChanged;
		int change_num = 0;
		int size;

		scanf("%d %d", &num, &change);
		nums = ft_itoa(num);
		size = ft_strlen(nums);
		isChanged = new char[size];
		for (int i = 0; i < size; i++)
			isChanged[i] = -1;
		for (int i = 0; i < size - 1; i++)
		{
			char max_v = nums[i];
			int max_i = -1;
			for (int j = i + 1; j < size; j++)
			{
				if (max_v < nums[j])
				{
					max_v = nums[j];
					max_i = j;
				}
				else if (max_v == nums[j] && max_i != -1)
						max_i = j;
			}
			if (max_i != -1)
			{
				isChanged[max_i] = nums[max_i];
				ft_swap(nums[i], nums[max_i]);
				change_num++;
			}
			for (int j = 0; j < size; j++)
			{
				if (nums[i] == isChanged[j])
				{
					if (nums[max_i] < nums[j])
						ft_swap(nums[max_i], nums[j]);
				}
			}
			if (change_num == change)
				break;
		}
		if (change_num != change)
		{
			int flag = 1;

			for (int i = 0; i < ft_strlen(nums) - 1; i++)
				if (nums[i] == nums[i + 1])
					flag = 0;
			if (flag)
				for (int i = 0; i < (change - change_num); i++)
					ft_swap(nums[ft_strlen(nums) - 1], nums[ft_strlen(nums) - 2]);
		}
		printf("#%d %s\n", test_n, nums);
		test_n++;
		delete nums;
		delete isChanged;
	}
	return (0);
}