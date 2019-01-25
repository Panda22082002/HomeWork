#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int N;
    int k=1;
    printf("enter N\n");
    scanf("%d",&N);
    int a[N];
    for (int l=1;l<=N;l++)
    {
        scanf("%d",&a[l]);
        if (((a[l]%2)!=0)&&((a[l]%3)!=0))
            k*=a[l];
    }
    printf("%d",k);
    return 0;
}
