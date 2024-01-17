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
    int size_a_row = matrix_a.size();
    int size_b_row = matrix_b.size();
    int size_a_column = matrix_a[0].size();
    int size_b_column = matrix_b[0].size();
    
    v2i result(size_a_row, vi(size_a_column));

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

void print_matrix(v2i matrix)
{
    int size_row = matrix.size();
    int size_column = matrix[0].size();
    for (int i = 0; i < size_row; i++)
    {
        for (int j = 0; j < size_column; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

v2i matrix_fast_pow(v2i matrix, int power, int mod = 1e9 + 7)
{
    v2i result = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0},
    };

    v2i current_value(matrix);
    while (power > 0)    
    {
        if (power & 1) 
        {
            result = matrix_multiply(current_value, result);
        }
        power >>= 1;
        current_value = matrix_multiply(current_value, current_value);
    }

    return result;
}

int n;
vi arr(3);

void solve()
{
    cin >> n;

    for (int i = 0; i < 3; i++) cin >> arr[i];
    
    if (n <= 3) 
    {
        cout << arr[n-1] << ' ';
        return;
    }

    const v2i matrix = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0},
    };
    
    const v2i multiplier =
    {
        {arr[0]},
        {arr[1]},
        {arr[2]},
    };

    const v2i multiplicand = matrix_fast_pow(matrix, n - 3 - 1);

    int result = matrix_multiply(multiplicand, multiplier)[0][0];
    cout << result << '\n';
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
