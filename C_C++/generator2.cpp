#include <bits/stdc++.h>
#include "lib/testlib.h"
// #include "testlib.h"
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    fastio;
    
    cout << rnd.next("!{0,1}") << rnd.next("X0|X1|X2|X3|X4|X5") << '\n';

    return 0;
}