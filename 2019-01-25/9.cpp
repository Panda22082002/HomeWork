#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int N,x,y;
    printf("enter N\n");
    scanf("%d",&N);
    printf("enter x\n");
    scanf("%d",&x);
    printf("enter y\n");
    scanf("%d",&y);
     if((y+2)<N)
    {
        if ((x+1)<=N)
            printf("y=%d,x=%d\n",y+2,x+1);
        if ((x-1)>=0)
            printf("y=%d,x=%d\n",y+2,x-1);
    }
     if((y-2)>=0)
    {
        if ((x+1)<=N)
            printf("y=%d,x=%d\n",y-2,x+1);
        if ((x-1)>=0)
            printf("y=%d,x=%d\n",y-2,x-1);
    }
  if((x+2)<N)
    {
        if ((y+1)<=N)
            printf("x=%d,y=%d\n",x+2,y+1);
        if ((y-1)>=0)
            printf("x=%d,y=%d\n",x+2,y-1);
    }
     if((x-2)>=0)
    {
        if ((y+1)<=N)
            printf("x=%d,y=%d\n",x-2,y+1);
        if ((y-1)>=0)
            printf("x=%d,y=%d\n",x-2,y-1);
    }
return 0;
}
