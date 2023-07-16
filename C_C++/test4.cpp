#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int seed;
mt19937 mt;
set<pii> coordinates;
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

pii get_ok_coordinate(int height, int width) 
{
    int x, y;
    while (true)
    {
        x = get_random_between(2, height);
        y = get_random_between(2, height);

        auto lower = coordinates.lower_bound({x, y});

        if (lower != coordinates.end())
        {
            if (abs(lower->first - x) < 4 && abs(lower->second - x) < 4)
            {
                continue;
            }
        }

        if (lower != coordinates.begin())
        {
            lower--;
            if (abs(lower->first - x) < 4 && abs(lower->second - x) < 4)
            {
                continue;
            }
        }

        break;
    }

    return make_pair(x, y);
}

pii get_not_ok_coordinate(int height, int width) 
{
    int index = get_random_between(0, coordinates.size());

    auto it = coordinates.begin();
    it = next(it, index);
    int x = it->first + get_random_between(-1, 1 + 1);
    int y = it->second + get_random_between(-1, 1 + 1);

    return make_pair(x, y);
}

int main()
{
    mt.seed(get_random_seed());

    // size
    int height = get_random_between(50, 100 + 1);
    int width = get_random_between(50, 100 + 1);
    cout << height << ' ' << width << '\n';

    // generate points
    int count = 0;
    for (int i = 0; i < 15; i++)
    {
        pii coordinate = get_ok_coordinate(height, width);
        coordinates.insert(coordinate);
    }
    
    // for (auto i : coordinates)
    // {
    //     cout << i.first << ' ' << i.second << '\n';
    // }

    graph.resize(height + 1, vector<char>(width + 1, '-'));
    for (auto i : coordinates)
    {
        int x = i.first;
        int y = i.second;

        int shape = get_random_between(0, 3);
        switch (shape)
        {
        case 0: // square
            graph[x][y] = '#';
            graph[x-1][y-1] = '*';
            graph[x-1][y] = '*';
            graph[x-1][y+1] = '*';
            graph[x][y-1] = '*';
            graph[x][y+1] = '*';
            graph[x+1][y-1] = '*';
            graph[x+1][y] = '*';
            graph[x+1][y+1] = '*';
            break;
        
        case 1: // circle
            graph[x][y] = '#';
            graph[x-1][y] = '*';
            graph[x][y-1] = '*';
            graph[x][y+1] = '*';
            graph[x+1][y] = '*';
            break;

        case 2: // hole square
            graph[x-1][y-1] = '*';
            graph[x-1][y] = '*';
            graph[x-1][y+1] = '*';
            graph[x][y-1] = '*';
            graph[x][y+1] = '*';
            graph[x+1][y-1] = '*';
            graph[x+1][y] = '*';
            graph[x+1][y+1] = '*';
            break;
        }   
    }

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            cout << graph[i][j];
        }
        cout << '\n';
    }

    return 0;

    for (int i = 0; i < 10; i++)
    {
        int index = get_random_between(0, coordinates.size());
        int success_or_fail = get_random_between(0, 2);
        if (success_or_fail)
        {
            pii coordinate = get_ok_coordinate(height, width);
            cout << coordinate.first << ' ' << coordinate.second << '\n';
            int x = coordinate.first;
            int y = coordinate.second;
            graph[x][y] = '+';
            graph[x-1][y-1] = '+';
            graph[x-1][y] = '+';
            graph[x-1][y+1] = '+';
            graph[x][y-1] = '+';
            graph[x][y+1] = '+';
            graph[x+1][y-1] = '+';
            graph[x+1][y] = '+';
            graph[x+1][y+1] = '+';
        }
        else
        {
            pii coordinate = get_not_ok_coordinate(height, width);
            cout << coordinate.first << ' ' << coordinate.second << '\n';
            int x = coordinate.first;
            int y = coordinate.second;
            graph[x][y] = '?';
            graph[x-1][y-1] = '?';
            graph[x-1][y] = '?';
            graph[x-1][y+1] = '?';
            graph[x][y-1] = '?';
            graph[x][y+1] = '?';
            graph[x+1][y-1] = '?';
            graph[x+1][y] = '?';
            graph[x+1][y+1] = '?';
        }
    }

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            cout << graph[i][j];
        }
        cout << '\n';
    }

    return 0;
}