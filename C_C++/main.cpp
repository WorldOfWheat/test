#include <bits/stdc++.h>
#include "librarys/testlib/testlib.h"
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int main(int argc, char * argv[]) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	registerGen(argc, argv, 1);

	for (int i =0; i < 10; i++)
	{
		cout << (rnd.next("[a-zA-Z0-9]{1, 20}")) << '\n';
	}

	return 0;
}