#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,u,d;
    scanf("%i %i %i",&h,&u,&d);
    int sum=0;
    if(u<=d)
     printf("永遠無法到達");
    else{
     for(int i=1;sum<h;i++)
     {
      sum=sum+u;
      if(sum>=h)
      {
        printf("%i",i);
        break;
      }
      sum=sum-d;

     }
    }
}