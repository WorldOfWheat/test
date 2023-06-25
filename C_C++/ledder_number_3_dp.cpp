#include <bits/stdc++.h>
#define MOD (int) 420

using namespace std;

int main()
{
    ifstream ifs;
    ofstream ofs;
    string output_path = "test_case\\solution2.txt";
    ofs.open(output_path);

    for (int i = 1; i <= 100; i++)
    {
        string input_path = "test_case\\" + to_string(i) + ".txt";
        ifs.open(input_path);
        if (ifs.fail())
        {
            ifs.close();
            continue;
        }

        int n, m;
        string str;
        // cin >> n >> m >> str;
        ifs >> n >> m >> str;

        ifs.close();

        vector<vector<int>> dp;
        dp.resize(10, vector<int>(n + 1));
        dp[str.back() - '0'][m] = 1;
        for (int i = str.back() - '0'; i <= 9; i++)
        {
            for (int j = m + 1; j <= n; j++)
            {
                dp[i][j] += dp[i][j - 1] + dp[i-1][j];
                dp[i][j] %= MOD;
            }
        }

        int sum = 0;
        for (int i = 1; i <= 9 ; i++)
        {
            sum += dp[i][n];
            sum %= MOD;
        }

        // cout << sum << endl;
        ofs << sum << endl;
    }
    ofs.close();

    return 0;
}
