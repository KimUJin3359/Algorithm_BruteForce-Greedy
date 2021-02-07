#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int test_n = 1;
	int test_c;

	scanf("%d", &test_c);
	while (test_n <= 10)
	{
		int num;
		double *x_point;
		double *weight;
		double left, mid, right;

		scanf("%d", &num);
		x_point = new double[num];
		weight = new double[num];
		for (int i = 0; i < num; i++)
			scanf("%lf", &x_point[i]);
		for (int i = 0; i < num; i++)
			scanf("%lf", &weight[i]);
		printf("#%d ", test_n);
		for (int i = 0; i < num - 1; i++)
		{
			int flag = 1;

			left = x_point[i];
			right = x_point[i + 1];
			while (flag)
			{
				double l_force = 0;
				double r_force = 0;

				mid = (left + right) / 2;
				for (int j = 0; j < num; j++)
				{
					if (j <= i)
						l_force += weight[j] / ((mid - x_point[j]) * (mid - x_point[j]));
					else
						r_force += weight[j] / ((mid - x_point[j]) * (mid - x_point[j]));
				}
				if (l_force > r_force)
				{
					left = mid + 0.000000000001;
					if (left > right)
						flag = 0;
				}
				else if (l_force < r_force)
				{
					right = mid - 0.000000000001;
					if (left > right)
						flag = 0;
				}
				else
					flag = 0;
			}
			printf("%.10lf ", mid);
		}
		printf("\n");
		delete x_point;
		delete weight;
		test_n++;
	}
}