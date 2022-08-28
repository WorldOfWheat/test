---
slideOptions:
  transition: slide
  spotlight: true
---

# test

----

test2
aesrjle;rajl;er
farjhgnjarejlkgnhkaej
jerjhgrel;gjhnerk
jlkarhgaerhg

----

test3
test3
test3
test3
test3
test3

---

afjdlksfjadlk
asd;fna;lj
flasdgnjal;g
gjaflkghn;jlg
aj;hgn;
jkghsljkdg
jksldfhbgsdjlk
s;dfjghsgh

----

54654654646545

---

51521653215151

<span>123456<!-- .element: class="fragment" data-fragment-index="1" --></span> 
<span>123435234456<!-- .element: class="fragment" data-fragment-index="2" --></span>
<span>1236254634456<!-- .element: class="fragment" data-fragment-index="3" --></span>

---

<span><!-- .element: class="fragment highlight-green"-->lkjeawlk</span>

<span><!-- .element: class="fragment highlight-red"-->lkjeaweaweawlk</span>

<span><!-- .element: class="fragment highlight-blue"-->eaweawelkjeawlk</span>

---

``` cpp [ 1 | 2 | 3-20 ]
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x > z; x--)
#define ln "\n"
#define sp " "
#define MAX (int) 2e5 + 1

using namespace std;

vector<int> graph[MAX];
vector<pii> edge(MAX);
vector<bool> vis(MAX);
vector<int> deph(MAX);
vector<int> value(MAX);

void dfs(int x, int y) {

    for (auto i : graph[x]) {

        if (vis[i]) {
            continue;
        }

        vis[i] = true;

        dfs(i, y+1);

    }

    vis[x] = false;
    deph[x] = y;

}

void dfs2(int x, int y) {

    for (auto i : graph[x]) {

        if (vis[i]) {
            continue;
        }

        if (deph[x] >= deph[i]) {
            continue;
        }

        vis[i] = true;

        dfs(i, y+value[x]);

    }

    vis[x] = false;
    value[x] += y;

}

void solve() {

    int n;
    cin >> n;
    rep2 (i, 1, n-1) {
        cin >> edge[i].F >> edge[i].S;
        graph[edge[i].F].pb(edge[i].S);
        graph[edge[i].S].pb(edge[i].F);
    }

    vis[1] = true;
    dfs(1, 1);
    vis[1] = false;


    int m;
    cin >> m;
    rep (i, 0, m) {

        int a, b, c;
        cin >> a >> b >> c;
        pii top = edge[b];
        int f = top.F;
        int s = top.S;
        if (deph[top.F] < deph[top.S]) {

            swap(f, s);
            a = 3 - a;

        }
        if (a == 1) {

            value[1] += c;
            value[top.S] -= c;

        }
        else {

            value[top.S] += c;

        }
    }

    dfs2(1, value[1]);



}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}

```