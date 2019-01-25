#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int N,s;
int minim;
printf("enter N\n");
scanf("%d",&N);
int a[N];
int b[N];
    for (int l=1;l<=N;l++)
        scanf("%d",&a[l]);
    for (int m=1;m<=N;m++)
      b[m]=0;
    for (int j=1;j<=N;j++)
    {
        s=j+5;
        for (s;s<=N;s++)
            b[j]=a[j]+a[s];
    }
    minim=b[1];
    for (int d=1;d<=N;d++)
    {
        if (b[d]<minim)
            minim=b[d];
    }
    printf("%d",minim);
}
