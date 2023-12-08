#include "lib/testlib.h"
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define part1 ;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<bool> primes_record;
vector<int> primes_table;

void linar_sive_theory(int maximum = 1e8)
{
    primes_record.resize(maximum + 1, true);

    for (int i = 2; i <= maximum; i++) 
    {
        if (primes_record[i]) primes_table.push_back(i);        

        int len = primes_table.size();
        for (int j = 0; j < len; j++) 
        {
            ll multiply = (ll) i * (ll) primes_table[j];
            if (multiply > maximum) break;
            primes_record[multiply] = false;
            if (i % primes_table[j] == 0) break;
        }
    }
}

int main(int argc, char* argv[]) 
{
    registerGen(argc, argv, 1);

    fastio;

    linar_sive_theory(1e6);

    int p = rnd.any(primes_table);

    int size = primes_table.size();
    int l = 0, r = size;
    while (l < r) 
    {
        int mid = (l + r) >> 1;        
        if (primes_table[mid] >= max(p - (int) 1e5, 2)) r = mid;
        else l = mid + 1;
    }
    int minimum_left = l;
    
    l = 0, r = size;
    while (l < r) 
    {
        int mid = (l + r) >> 1;
        if (primes_table[mid] > min(p + (int) 1e5, primes_table[size-1])) r = mid;
        else l = mid + 1;
    }
    int maximum_right = l - 1;
    
    int q = primes_table[rnd.next(minimum_left, maximum_right)];
    
    ll pq = (ll) p * (ll) q;
    cout << pq << '\n';

    return 0;
}
