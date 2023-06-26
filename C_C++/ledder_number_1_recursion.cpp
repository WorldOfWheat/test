#include <bits/stdc++.h>
#define MOD (int) 420

using namespace std;

int sum = 0;

void dfs(int start_number, int length_now, int total_length)
{
    if (length_now == total_length) 
    {
        sum++;
        sum %= MOD;
        return;
    }

    for (int i = start_number; i <= 9; i++)
    {
        dfs(i, length_now + 1, total_length);
    }
}

int main()
{
    ifstream ifs;
    ofstream ofs;
    string output_path = "test_case\\solution.txt";
    ofs.open(output_path);
    if (ofs.fail())
    {
        cout << "Solution makes fail" << endl;
        return 1;
    }

    for (int i = 1; i <= 100; i++)
    {
        string path = "test_case\\" + to_string(i) + ".txt";
        ifs.open(path);
        if (ifs.fail())
        {
            cout << "Failure" << endl;
            continue;
        }

        int n, m;
        string str;
        // cin >> n >> m >> str;
        ifs >> n >> m >> str;

        ifs.close();

        sum = 0;
        dfs(str.back() - '0', m, n);

        // cout << sum << '\n';
        ofs << sum << endl;
    }

    ofs.close();

    return 0;
}
