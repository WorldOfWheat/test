#include <bits/stdc++.h>

using namespace std;

mt19937 mt;

int get_random_seed()
{
    int* rand_seed_array = (int*) malloc(sizeof(int) * 100);
    long long rand_seed = 0;
    for (int i = 0; i < 100; i++)
    {
        rand_seed += *(rand_seed_array + i);
    }

    return rand_seed ^ time(0);
}

int get_random_between(int minimum, int maximum)
{
    return mt() % (maximum - minimum) + minimum;
}

int main()
{
    mt.seed(get_random_seed());

    for (int i = 0; i < 32; i++)
    {
        cout << (get_random_between(0, 32));
    }

    return 0;
}
