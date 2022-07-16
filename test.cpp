#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define db(x) cout << x << " "
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

vector<pii> graph[8+1];
int point[8+1];
bool visited[8+1];
int path[8+1][8+1];

void init();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    memset(&point, (int) 1e18, sizeof(point));
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(1);
    point[1] = 0;
    while (!pq.empty()) {
        int top = pq.top();
        for (auto a : graph[top]) {
            if (top == 1) {
                point[a.F] = a.S;
                pq.push(a.F);
                continue;
            }
            if (visited[a.F]) {
                continue;
            }
            point[a.F] = min(point[graph[top].F]+a.S, point[a.F]);
        }
        visited[top] == true;
        pq.pop();
    }

    return 0;
}

void init() {
    graph[1].push_back(mp(2, 9));
    graph[1].push_back(mp(3, 4));
    graph[1].push_back(mp(4, 5));

    graph[2].push_back(mp(5, 5));

    graph[3].push_back(mp(7, 8));
    graph[3].push_back(mp(8, 10));

    graph[4].push_back(mp(5, 4));
    graph[4].push_back(mp(3, 2));

    graph[5].push_back(mp(2, 5));
    graph[5].push_back(mp(4, 9));
    graph[5].push_back(mp(6, 7));
    graph[5].push_back(mp(8, 20));

    graph[6].push_back(mp(5, 7));
    graph[6].push_back(mp(7, 13));
    graph[6].push_back(mp(9, 14));

    graph[7].push_back(mp(9, 8));

    graph[8].push_back(mp(9, 5));
}

