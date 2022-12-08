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
}
