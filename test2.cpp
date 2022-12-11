<<<<<<< HEAD
#include<cstdio>
int main()  
{  
    char buffer[20]="10549stend#12";  
    char *stop;  
    int ans=strtol(buffer, &stop, 8);   //將八進位制數1054轉成十進位制，後面均為非法字元
    printf("%d\n",ans);  
    printf("%s\n", stop);   
    return 0;
=======
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,arr[1000000];
signed main() {
    cin>>n>>k;
    for(int i=1,j;i<=n;i++){
        cin>>j;
        arr[i]=arr[i-1]+j;
    }
    int sum=-1000,ans=-1e5,l=0;
    for(int i=1;i<=n;i++){
        sum=arr[i]-arr[l];
        if(sum>k){
            l++;
            i--;
            continue;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
>>>>>>> f4ed1a3a9ddc1dc54b714d1e53588e803f6ee4fb
}
