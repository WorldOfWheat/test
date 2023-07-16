#include <bits/stdc++.h>

using namespace std;

int seed;
mt19937 mt;
set<int> se_x;
set<int> se_y;
vector<pair<int, int>> coordinates;
vector<vector<char>> graph;

int get_random_seed()
{
    int* rand_seed_array = (int*) malloc(sizeof(int) * 100);
    long long rand_seed = 0;
    for (int i = 0; i < 100; i++)
    {
        rand_seed += *(rand_seed_array + i);
    }

    return rand_seed;
}

int get_random_between(int minimum, int maximum)
{
    return mt() % (maximum - minimum) + minimum;
}

int main()
{
    mt.seed(get_random_seed());

    // size
    int height = get_random_between(10, 100 + 1);
    int width = get_random_between(10, 100 + 1);
    // int height = get_random_between(10, 30 + 1);
    // int width = get_random_between(10, 30 + 1);
    cout << height << ' ' << width << '\n';

    // generate points
    int x, y;
    int count = 0;
    do {
        x = get_random_between(2, height);
        y = get_random_between(2, width);

        auto lower_x = se_x.lower_bound(x);
        if (lower_x != se_x.end() && *lower_x - x < 4)
        {
            continue;
        }

        auto lower_y = se_y.lower_bound(y);
        if (lower_y != se_y.end() && *lower_y - y < 4)
        {
            continue;
        }

        se_x.insert(x);
        se_y.insert(y);
        coordinates.push_back({x, y});
        count++;
        // cout << x << ' ' << y << '\n';
    } while (count < 10);
    
    for (auto i : coordinates)
    {
        cout << i.first << ' ' << i.second << '\n';
    }

    graph.resize(height + 1, vector<char>(width + 1, '-'));
    for (auto i : coordinates)
    {
        
    }

    for (auto i : graph)
    {
        for (auto j : i)
        {
            cout << j;
        }
        cout << '\n';
    }

    return 0;
}