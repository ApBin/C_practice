#include <stdio.h>
#include <windows.h>
#include <time.h>

/*void menu()
{
    printf ("***猜数字游戏**\n");
    printf ("* 1.开始游戏 **\n");
    printf ("* 0.退出游戏 **\n");
}

void game()
{
    int i = rand()%100+1;
    int guess = 0;
    do
    {
        printf("猜猜看数字(0-100):>");
        scanf("%d",&guess);

        if(guess>i)
        printf("猜大了\n");
        else if(guess<i)
        printf("猜小了\n");
        else
        {
            printf("正确\n");
            break;
        }

    } while (guess!=i);
    
}

int main()
{
    int input = 0;
    srand((unsigned int)time(0));
    do
    {
        menu();
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                break;
            default:
                printf("Miss\n");
                break;
        }
    } while (input);
    
    return 0;
}*/

/*int main()
{
    char str[] = "hello bit";
    printf("%d %d\n", sizeof(str), strlen(str));
	  return 0;
}*/

/*int main()
{
    int a,b,c=0;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(a+b>c&&a+c>b&&b+c>a)
        {
            if(a==b&&b==c&&c==a)
                printf("Equilateral triangle!\n");
            else if(a==b||b==c||c==a)
                printf("Isosceles triangle!\n");
            else
                printf("Ordinary triangle!\n");
        }
        else
            printf("Not a triangle!\n");
    }
    return 0;
}*/

/*int main()
{
    int i = 0;
    for(i=1;i<10;i++)
    {
        int j = 0;
        for(j=1;j<=i;j++)
        {
            printf("%d*%d=%d\t",i,j,i*j);
        }
        printf("\n");
    }
 return 0;
}*/

int main()
{
    int i =0;
    for(i=100;i<201;i++)
    {
        int j =0;
        for(j=2;j<=i;j++)
        {           
            if(i%j==0)
                break;
        }
        if(i==j)
        printf("%d\t",i);
    }

    return 0;
}