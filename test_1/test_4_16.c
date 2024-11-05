#include <stdio.h>

/*int main()
{
    int arr[10]={0};
    int i=0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    int j=0;
    for(j=0;j<9;j++)
    {
        int i=0;

        for(i=0;i<9-j;i++)
        {
            if(arr[i]<arr[i+1])
            {
                int tem=0;
                tem =arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=tem;
            }
        }

    }
    printf("%d",arr[0]);

    return 0;
}*/

/*int main()
{
    double a =0;
    double b =0;
    double sum =0;

    int i =0; 
    for (i=1;i<100;i+=2)
    {
        a += 1.0/i;
    }

    int j =0;
    for (j=2;j<101;j+=2)
    {
        b -= 1.0/j;
    }

    sum =a+b;
    printf("%lf",sum);

    return 0;

}*/

/*int main()
{
    int j =0;
    int i =0;
    for(i=0;i<101;i++)
    {
        if(i%10==9)
        {
            j++;
        }
        if(i/10==9)
        {
            j++;
        }
    }
    printf("%d",j);
    return 0;
}*/

/*int main()
{
    int sum =0;

    int i =0;
    for(i=1000;i<2001;i++)
    {
        if(i%4==0)
        printf("%d ",i);
    }

    return 0;
}*/

int main ()
{
    int arr[]={0};
    int i =0;
    for (i=0;i<2;i++)
    {
        scanf("%d",&arr[i]);
    }
    int a =arr[0];
    int b =arr[1];
    if(a>=b)
    {
        int c =a%b;
        for(;c!=0;)
        {
            a=b;
            b=c;
            c=a%b;
        }
        printf("%d\n",b);
    } 
    else
    {
		int d = b%a;
		while (d != 0)
        {
			b = a;
			a = d;
			d = b%a;
		}
        printf("%d\n",a);
    }

    return 0;
}