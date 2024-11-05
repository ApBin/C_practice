#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int age = 0;

	scanf("%d", &age);

	if (18 <= age)
		printf("长大了可以恋爱\n");
    else
		printf("好好学习\n");


	return 0;
}


int main()
{
	int age = 0;
	scanf("%d", &age);
	if (age < 18)
		printf("骚年");
	else if (age > 18 && 26 > age)
		printf("青年");
	else if (age >= 26 && age < 40)
		printf("中年");
	else if (age >= 40 && age < 60)
	printf("壮年");
	else if (age >= 60 && age < 100)
		printf("老年");
	else
		printf("老不死");


	return 0;
}

int main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
			printf("%d", i);

	}
		return 0;
}