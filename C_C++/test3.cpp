#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

<<<<<<< HEAD
int exgcd(int a, int b, int x, int y)
{
    if (b == 0) return a;
    
    return gcd(b, a % b);
=======
vector<bool> eratosthenes_sieve(int n)
{
    vector<bool> prime_table(n, true);
    prime_table[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        if (prime_table[i]) 
        {
            int j = 2;
            while (i * j < n)
            {
                prime_table[i * j] = false;
                j++;
            }
        }
    }
    
    return prime_table;
>>>>>>> 0a3fc10 (Tests)
}

void solve()
{
    vector<bool> prime_table = eratosthenes_sieve(1e5);
    
    int n;
    while (cin >> n) 
    {
        cout << prime_table[n] << '\n';
    }
}

int main()
{
    fastio;
    solve();
    return 0;
}