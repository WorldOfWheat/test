#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<v2p> v3p;
typedef vector<string> vs;

v2i matrix_multiply(v2i matrix_a, v2i matrix_b)
{
    v2i result(matrix_b.size());

    int size_a_row = matrix_a.size();
    int size_b_row = matrix_b.size();
    int size_a_column = matrix_a[0].size();
    int size_b_column = matrix_b[0].size();

    int result_x = 0, result_y = 0;
    for (int i = 0; i < size_a_row; i++) 
    {
        for (int j = 0; j < size_b_column; j++)
        {
            for (int k = 0; k < size_b_row; k++) 
            {
                result[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    return result;
}

void solve()
{
    v2i matrix_a = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    v2i matrix_b = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    
    v2i result = matrix_multiply(matrix_a, matrix_b);
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
