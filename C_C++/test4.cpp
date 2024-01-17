#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<v2p> v3p;
typedef vector<string> vs;

int n;
v2i graph;

void dfs(int current_point, vector<bool>* visited)
{
    for (auto i : graph[current_point])
    {
        if ((*visited)[i]) 
        {
            continue;
        }
        (*visited)[i] = true;
        dfs(i, visited);
    }
}

void solve()
{
    cin >> n;
    
    vi outdegree(n + 1);
    int middle_point = -1;
    graph.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        outdegree[a]++;
        outdegree[b]++;
        if (outdegree[a] == 3)
        {
            if (middle_point != -1) 
            {
                cout << "No\n";
                return;
            }
            else middle_point = a;
        }
        if (outdegree[b] == 3)
        {
            if (middle_point != -1) 
            {
                cout << "No\n";
                return;
            }
            else middle_point = b;
        }
    }
    
    int tail = -1;
    for (int i = 1; i <= n; i++)
    {
        if (outdegree[i] == 1) 
        {
            if (tail == -1) tail = i;
            else 
            {
                cout << "No\n";
                return;
            }
        }
    }
    
    vector<bool> visited(n + 1);
    dfs(middle_point, &visited);
        
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "No\n";
            return;
        }
    }
    
    cout << "Yes\n";
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
