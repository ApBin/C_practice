#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	char password[20] = { 0 };
	printf("请输入密码\n");
	scanf("%s", password);
	//getchar();
	int a = getchar();
	while (a = !'\n')
	{
		;
	}

	printf("请确认[y/n]\n");
	int ch = getchar();
	if (ch == 'y')
		printf("确认成功");
	else
		printf("确认失败");

		return 0;
}

int main()
{
	int i = 0;
	int j = 0;
	for (; i < 3; i++)
	{
		printf("j: %d\n", j);
		for (; j < 3; j++)
		{
			printf("i: %d\n", i);
		}
	}
	return 0;
}

int main()
{
	int i = 0;
	do
	{
		if (i == 5)
			//break;
		continue;
		printf("%d", i);
		i++;
	} 
	while (i < 10);
	return 0;
}

int main()
{
	int a = 1;
	int b = 1;
	int c = 0;
	scanf("%d", &c);
	for (a = 1; a <= c; a++)
	{
		b = b * a;
		
	}
	printf("%d", b);

	return 0;
}

int main()
{
	int a = 1;
	int b = 1;
	int c = 0;
	int d = 0;
	scanf("%d", &c);
	for (a = 1; a <= c; a++)
	{
		b = b * a;
		d = d + b;

	}
	printf("%d", d);

	return 0;
}

int main()
{
	int a = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 7;
	for (a = 0; a < sz; a++)
	{
		if (arr[a] == k)
		{
			printf("下标：%d\n", a);
			break;
		}
	}
	if (a == sz)
	{
		printf("miss");
	}
	return 0;
}

int main()
{
	int k = 0;
	printf("请输入：\n");
	scanf("%d", &k);
	int sum[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int ge = sizeof(sum) / sizeof(sum[0]);
	int left = 0;
	int right = ge - 1;


	for(;left <= right;)
	{
		int zh = (left + right) / 2;
		if (sum[zh]> k)
		{
			right = zh - 1;

		}
		else if (sum[zh] < k)
		{
			left = zh + 1;

		}
		else
		{
			printf("下标为%d\n", zh);
			break;
		}
	}
	if (left > right)
		printf("miss");

	return 0;
}