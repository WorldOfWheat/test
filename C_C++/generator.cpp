#include <bits/stdc++.h>
#define part_2

using namespace std;

mt19937_64 random;

string generateTest(int n, int max_m, int max_digit)
{
    stringstream sst;

    string sequence = "";
    while (sequence.length() < max_m)
    {
        sequence += to_string(random());
    }

    sequence = sequence.substr(0, max_m);
    sort(sequence.begin(), sequence.end());
    int zero_index = sequence.find_last_of('0');
    if (zero_index != -1)
    {
        sequence = sequence.substr(zero_index + 1);
    }
    sequence = sequence.substr(0, sequence.find(max_digit + '0'));

    if (sequence.empty())
    {
        return "0";
    }

    sst << n << ' ';
    sst << sequence.length() << '\n';
    sst << sequence << '\n';

    return sst.str();
}

int main(int argc, char *argv[])
{
    random.seed(time(NULL));

    int test_amount;
    cin >> test_amount;
#ifdef part_1
    int max_str_length = 20;
#endif
#ifdef part_2
    int max_str_length = 1e3;
#endif 
#ifdef part_3
    int max_str_length = 1e6;
#endif
#ifdef handwrite
    int max_str_length;
    cin >> max_str_length;
#endif

    ofstream ofs;

    for (int i = 1; i <= test_amount; i++)
    {
        string path = "test_case\\" + to_string(i) + ".txt";
        ofs.open(path);

        int n = random() % max_str_length + 1;
        int m = 0;
        int digit;
        m = random() % n + 1;
        digit = random() % 10 + 1;
        string test_case = generateTest(n, m, digit);

        if (test_case != "0")
        {
            ofs << test_case;
            ofs.close();
        }
        else
        {
            ofs.close();
            remove(path.c_str());
            i--;
        }
    }

    return 0;
}