#include <stdio.h>
/*int main()
{
    int input =0;
    while(scanf("%d",&input)!=EOF)
    {
        int i = 0;
        for(i=0;i<input;i++)
        {
            int j = 0;
            for(j=0;j<input;j++)
            {
                if(i==j||j+i==input-1)
                {
                    printf("*");
                }
                else
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}*/

/*int main()
{
    int input =0;
    while(scanf("%d",&input)!=EOF)
    {
        int i =0;
        for(i =0;i<input;i++)
        {
            int j =0;
            for(j=0;j<input;j++)
            {
                if(i==0||i==input-1||j==0||j==input-1)
                printf("* ");
                else
                printf("  ");
            }
            printf("\n");
        }
    }
    return 0;
}*/

/*int main()
{
    int n,m=0;
    scanf("%d %d",&n,&m);
    int arr[n][m];
    int tem[m][n];
    int i,j =0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
            tem[j][i] =arr[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",tem[i][j]);
        }
        printf("/n");
    }
    return 0;
}*/

/*int main()
{
    int arr[10];
    int tem[10];
    int i =0;
    for(i=0;i<10;i++)
    {
        scanf("%d ",&arr[i]);
        tem[9-i]=arr[i];
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",tem[i]);
    }
    return 0;
}*/

/*int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n+m];
    int i=0;
    for(i=0;i<n+m;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n+m-1;i++)
    {
        int j =0;
        for(j=0;j<n+m-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int tem=0;
                tem=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tem;
            }
        }
    }
    for(i=0;i<n+m;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;    
}*/

/*int main()
{
    int arr[10];
    int i =0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    float sum,avg =0;
    for(i=0;i<10;i++)
    {
     sum += arr[i];
    }
    avg = sum/10;
    printf("%f",avg);

    return 0;
}*/

int main()
{
    int arr1[10]={1,2,3,4,5,6,7,8,9,10};
    int arr2[10]={11,12,13,14,15,16,17,18,19,20};
    int i =0;
    for(i=0;i<10;i++)
    {
        arr1[i]=arr2[i];
    }
    for(i=0;i<10;i++)
    {
        printf("%d\t",arr1[i]);
    }
    
}