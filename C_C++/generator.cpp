#include <bits/stdc++.h>
#define part_1

using namespace std;

mt19937 random;

void generateTest(int n, int m, int max_digit)
{
    cout << n << ' ' << m << endl;

    vector<int> digit_percents(max_digit + 1, 0);
    int sum_of_percent = 0;
    for (int i = 1; i <= max_digit; i++)
    {
        digit_percents[i] = random() % 100 + 1;
        cout << digit_percents[i] << '\n';
        sum_of_percent += digit_percents[i];
    }
    cout << sum_of_percent << endl;
    for (int i = 1; i <= max_digit; i++)
    {
        digit_percents[i] = digit_percents[i] / sum_of_percent;
    }

    return;
    vector<int> test_sequences(9 + 1);
    stringstream ss;
    for (int i = 1; i <= max_digit; i++)
    {
        int random_number = random() % m + 1;
        for (int j = 0; j < random_number; j++)
        {
            ss << i;
        }
    }

    cout << ss.str() << endl;
}

int main(int argc, char *argv[])
{
    random.seed(time(NULL));
#ifdef part_1
    int max_str_length = 20;
#elif part_2
    int max_str_length = 1e3;
#elif part_3
    int max_str_length = 1e6;
#endif

    int n = 0, m = 0;
    do
    {
        n = random() % max_str_length + 1;
        m = random() % max_str_length + 1;
    }
    while (!(n > m));

    generateTest(n, m, 4);

    return 0;
}