#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a,b,c,d;
    int j[52];

    for(i=0; i<52; i++)
    {
        j[i]=i;
    }

    for(i=0; i<52; i++)
    {
        a=rand()%52;

        b=j[i];
        j[i]=j[a];
        j[a]=b;
    }

    for(i=0; i<52; i++)
    {
        a=rand()%52;

        b=j[i];
        j[i]=j[a];
        j[a]=b;
    }


    for(c=0; c<4; c++)
    {
        for(i=0; i<13; i++)
        {
            int cord=j[d++];
            switch(cord%4) 
            {
            case 0:
                printf("梅花");
                break;
            case 1:
                printf("方塊");
                break;
            case 2:
                printf("紅心");
                break;
            case 3:
                printf("黑桃");
                break;
            }

            int e=cord%13+1;
            if(e<=9)
                printf("%d",e);
            else {
                switch(e) {
                case 10:
                    printf("10");
                    break;
                case 11:
                    printf("j");
                    break;
                case 12:
                    printf("q");
                    break;
                case 13:
                    printf("k");
                    break;
                }
            }
        }
    }
    return 0;
}