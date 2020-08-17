#include<stdio.h>

int floorSqrt(int x)
{
    if (x == 0 || x == 1) return x;

    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid=start+((end-start)/2);
        if(mid*mid == x) return mid;
        else if(mid*mid < x) {start = mid + 1;ans = mid;}
        else end=mid;
    }
    return ans;
}

int main()
{
    int x;
    scanf("%d",&x);
    x=floorSqrt(x);
    printf("%d\n",x);
    return 0;
}
