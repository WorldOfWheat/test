#include<cstdio>
int main()  
{  
    char buffer[20]="10549stend#12";  
    char *stop;  
    int ans=strtol(buffer, &stop, 8);   //將八進位制數1054轉成十進位制，後面均為非法字元
    printf("%d\n",ans);  
    printf("%s\n", stop);   
    return 0;
}
