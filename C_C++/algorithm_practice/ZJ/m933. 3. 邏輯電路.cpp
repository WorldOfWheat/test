#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<bool> vb;

struct node {
    int type; // 1: and, 2: or, 3: xor, 4: not, 0: none
    vi input;
    vi output;
    bool result;
    int time = 0;
};

int p, q, r, m;
vector<node> arr;

void solve() {
    cin >> p >> q >> r >> m;
    
    arr.resize(p + q + r + 1);
    for (int i = 1; i <= p; i++) {
        int a;
        cin >> a;
        arr[i].result = a == 1;
        arr[i].type = 0;
    }
    
    for (int i = 1; i <= q; i++) {
        cin >> arr[p + i].type;
        if (arr[p + i].type == 1) {
            arr[p + i].result = 1;
        }
    }
    
    for (int i = 1; i <= r; i++) {
        arr[p + q + i].type = 0;
    }
    
    vi indegree(p + q + r + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].output.push_back(b);
        indegree[b]++;
    }
    
    list<int> li;
    for (int i = 1; i <= p + q + r; i++) {
        if (indegree[i] == 0) {
            li.push_back(i);
        }
    }
    
    while (li.size()) {
        int front = li.front();
        li.pop_front();
        
        for (auto i : arr[front].output) {
            switch (arr[i].type) {
                case 1: {
                    arr[i].result = arr[i].result && arr[front].result;
                    break;
                }
                case 2: {
                    arr[i].result = arr[i].result || arr[front].result;
                    break;
                }
                case 3: {
                    arr[i].result = arr[i].result ^ arr[front].result;
                    break;
                }
                case 4: {
                    arr[i].result = !arr[front].result;
                    break;
                }
                case 0: {
                    arr[i].result = arr[front].result;
                    break;
                }
            }
            arr[i].time = arr[front].time + 1;
            indegree[i]--;
            if (indegree[i] == 0) {
                li.push_back(i);
            }
        }
    }
    
    int ans = -1e18;
    for (int i = 1; i <= r; i++) {
        ans = max(ans, arr[p + q + i].time);
    }
    cout << ans - 1 << '\n';
    
    for (int i = 1; i <= r; i++) {
        cout << arr[p + q + i].result << ' ';
    }
    cout << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}

// #####################################################################################################

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<bool> vb;

struct node {
    int type;
    vi input;
};

int p, q, r, m;
vector<node> arr;
vector<pair<bool, int>> record;

pii f(int root) {
    if (arr[root].input.size() == 0) {
        return {record[root].first, 0};
    }
    
    if (record[root].second != -1) {
        return record[root];
    }
    
    int maximum = -1e18;    
    bool result = 0;
    if (arr[root].type == 1) {
        result = 1;
    }
    for (auto i : arr[root].input) {
        pii child = f(i);
        switch (arr[root].type) {
            case 1:
                result &= child.first;
                break;
            case 2:
                result |= child.first;
                break;
            case 3:
                result ^= child.first;
                break;
            case 4:
                result = !child.first;
                break;
            case 0:
                result = child.first;
                break;
        }
        maximum = max(maximum, child.second + 1);
    }
    
    return record[root] = {result, maximum};
}

void solve() {
    cin >> p >> q >> r >> m;
    
    record.resize(p + q + r + 1, {0, -1});

    for (int i = 1; i <= p; i++) {
        int a;
        cin >> a;
        record[i].first = a == 1;
    }

    arr.resize(p + q + r + 1);
    for (int i = 1; i <= q; i++) {
        cin >> arr[p + i].type;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[b].input.push_back(a);
    }
    
    int ans = -1e18;
    stringstream ss;
    for (int i = 0; i < r; i++) {
        pii result = f(i + p + q + 1);        
        ans = max(ans, result.second);
        ss << result.first << ' ';
    }

    cout << ans - 1 << '\n' << ss.str() << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
