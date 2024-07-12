#include <stdio.h>
#include <stdlib.h>

void print(int* nums,int numsSize)
{
    for(int i=0; i<numsSize; i++)
    printf("%d ", nums[i]);
    printf("\n");
}

void rotate01(int* nums, int numsSize, int k) 
{
    while(k--)
    {
        int tem= nums[numsSize-1];
        for(int i= numsSize-1; i>0; i--)
        {
            nums[i]= nums[i-1];
        }
        nums[0]= tem;
    }
    print(nums, numsSize);
}

void rotate02(int* nums, int numsSize, int k)
{
    int numss[numsSize];
    int i= 0;
    k= k%numsSize;
    for(i=0;i<k;i++)
        numss[i]=nums[numsSize-k+i];
    for(i=0;i<numsSize-k;i++)
        numss[i+k]= nums[i];
    for(i=0;i<numsSize;i++)
        nums[i]=numss[i];

        print(nums, numsSize);
} 

int main()
{
    int k = 3;
    int nums[7] = {1,2,3,4,5,6,7};
    int numsSize= sizeof(nums)/sizeof(nums[0]);
   
    rotate01(nums, numsSize, k);
    rotate02(nums, numsSize, k);

    return 0;
}