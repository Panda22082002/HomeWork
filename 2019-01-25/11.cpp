#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
int N,s;
int k=0;
printf("enter N\n");
scanf("%d",&N);
int a[N];
    for (int l=1;l<=N;l++)
        scanf("%d",&a[l]);
    for (int j=2;j<=N;j++)
    {
        s=a[j-1];
        if ((a[j]>s)&&(a[j]<(s*2)))
            k++;
    }
    printf("%d",k);
    return 0;
}
