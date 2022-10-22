#include <bits/stdc++.h>
#define pb push_back
#define mid (l + r) / 2
using namespace std;
struct e{
    int u, v;
};
int n;
array<bool, 10004> WA;          //不可行的觀察員編號
array<int, 20004> vis;          //DFS是否走訪、二分圖顏色
array<vector<e>, 10004> E;      //每一個觀察員的回傳邊
array<vector<int>, 20004> G;    //存進行DFS的圖

bool dfs(int u, int t){         //用DFS塗色、判斷二分圖

    cerr << u << " " << t << "\n";

    if(vis[u]) return 1;
    bool ans = 1;
    vis[u] = t;
    for(int v : G[u]){
        if(vis[v] == t) return 0;
        ans &= dfs(v, 3 - t);
    }
    return ans;
}

bool check(int p){               //檢查第p個觀察員回傳是否正確
    bool ans = 1;
    for(int i = 0; i < n; i++){
        G[i].clear();
        vis[i] = 0;
    }
    for(int i = 0; i <= p; i++){
        for(auto i : E[i]){ //將觀察員的邊推入G
            G[i.u].pb(i.v);
            G[i.v].pb(i.u);
        }
    }
    for(int i = 0; i < n; i++){
        ans &= dfs(i, 1);        //將每一個連通塊
        //cerr << ans << "\n";
    }
    return ans;
}
void BS(int l, int r){           //二分搜觀察員
    if(check(r)) return;         //當邊的連集不會讓圖有問題，則回傳
    while(l != r){
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    WA[l] = 1;
    E[l].clear();                //剔除一錯誤觀察員
}
signed main(){
    int m, p, k, a, b;
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        E[0].pb({a, b});
    }
    cin >> p >> k;
    for(int i = 1; i <= p; i++){
        for(int j = 0; j < k; j++){
            cin >> a >> b;
            E[i].pb({a, b});
        }
    }
    for(int i = 0; i < 3; i++){     //至多三個觀察員
        BS(0, p);
    }

    return 0;
}