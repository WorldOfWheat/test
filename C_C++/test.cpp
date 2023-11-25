#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct interval
{
    int left;
    int right;
    int index;
};

int n;
vector<interval> arr; 
vector<int> record; 
priority_queue<int, vector<int>, greater<int>> pq;

bool compare(interval a, interval b)
{
    // left
    if (a.left > b.left) return false;
    if (a.left < b.left) return true;
    // right
    if (a.right > b.right) return false;
    if (a.right < b.right) return true;
    
    return true;
}

void solve()
{
    cin >> n;
    
    arr.resize(n);
    record.resize(n);
    
    for (int i = 0 ; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[i].left = a;
        arr[i].right = b;
        arr[i].index = i;
    }
    
    sort(begin(arr), end(arr), compare);
    
    int maximum = 1;
    pq.push(arr.front().right);
    record[arr.front().index] = 1;

    for (int i = 1; i < n; i++)
    {
        interval current = arr[i];
        while (pq.size() && pq.top() < current.left) pq.pop();            
        
        pq.push(current.right);

        int size = pq.size();
        record[i] = size;
        maximum = max(maximum, size);
    }
    
    cout << maximum << '\n';
    for (int i = 0; i < n; i++) cout << record[i] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
