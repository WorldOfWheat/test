#include <bits/stdc++.h>
#define example
#define pii pair<int, int>

using namespace std;

int seed;
mt19937 mt;
set<int> se_x;
set<int> se_y;
set<pii> coordinates;
vector<vector<char>> graph;
stringstream ss;
stringstream ss2;

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
        y = get_random_between(2, width);

        auto lower_x = se_x.lower_bound(x);
        auto lower_y = se_y.lower_bound(y);
        auto lower_x_2 = lower_x;
        auto lower_y_2 = lower_y;

        if (lower_x_2 != se_x.begin())
        {
            lower_x_2--;
        }
        if (lower_y_2 != se_y.begin())
        {
            lower_y_2--;
        }

        if ((abs(*lower_x - x) < 4 || abs(*lower_x_2 - x) < 4) && (abs(*lower_y - y) < 4 || abs(*lower_y_2 - y) < 4))
        {
            continue;
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
    int x = it->first;
    int y = it->second;

    // x += get_random_between(-1, 1 + 1);
    // y += get_random_between(-1, 1 + 1);

    return make_pair(x, y);
}

bool is_ok_coordinate(pii coordinate, int height, int width)
{
    int x = coordinate.first;
    int y = coordinate.second;
    auto lower_x = se_x.lower_bound(x);
    auto lower_y = se_y.lower_bound(y);
    if ((lower_x != se_x.end() && *lower_x == x) && (lower_y != se_y.end() && *lower_y == y))
    {
        return false;
    }
    return true;
}

int main()
{
    mt.seed(get_random_seed());

    for (int q = 1; q <= 30; q++)
    {
        cout << q << endl;

        // init all container
        se_x.clear();
        se_y.clear();
        coordinates.clear();
        graph.clear();
        ss.str("");
        ss.clear();
        ss2.str("");
        ss2.clear();
        // size
#ifdef example
        int height = get_random_between(10, 20 + 1);
        int width = 10;
#else
        int height = get_random_between(50, 100 + 1);
        int width = get_random_between(50, 100 + 1);
#endif
        ss << height << ' ' << width << '\n';
        // generate points
#ifdef example
        for (int i = 0; i < 2; i++)
#else
        for (int i = 0; i < 12; i++)
#endif
        {
            pii coordinate = get_ok_coordinate(height, width);
            coordinates.insert(coordinate);
            se_x.insert(coordinate.first);
            se_y.insert(coordinate.second);
        }
        
        // write workpiece
        graph.resize(height + 1, vector<char>(width + 1, '-'));
        for (auto i : coordinates)
        {
            int x = i.first;
            int y = i.second;

            graph[x][y] = '#';
            graph[x-1][y-1] = '*';
            graph[x-1][y] = '*';
            graph[x-1][y+1] = '*';
            graph[x][y-1] = '*';
            graph[x][y+1] = '*';
            graph[x+1][y-1] = '*';
            graph[x+1][y] = '*';
            graph[x+1][y+1] = '*';
        }

        // print graph
        for (int i = 1; i <= height; i++)
        {
            for (int j = 1; j <= width; j++)
            {
                ss << graph[i][j];
            }
            ss << '\n';
        }

        // test moment
#ifdef example
        int moment = 2;
#else
        int moment = 1000;
#endif
        // int moment = 10;

        int command_count = 0;
        // generate move points
        for (int i = 0; i < moment; i++)
        {
            int if_execute = get_random_between(0, 2);
            // put nothing
            if (!if_execute) 
            {
                pii p = {get_random_between(1, height + 1), get_random_between(1, width + 1)};
                while (is_ok_coordinate(p, height, width))
                {
                    p = {get_random_between(1, height + 1), get_random_between(1, width + 1)};
                }

                int index = (p.first - 1) * width + p.second;
                ss2 << "ptp p" << index << '\n';
                ss2 << "get" << '\n';

                p = {get_random_between(1, height + 1), get_random_between(1, width + 1)};
                index = (p.first - 1) * width + p.second;
                ss2 << "ptp p" << index << '\n';
                ss2 << "put" << '\n';

                command_count += 4;
                continue;
            }
            
            // get workpisse
            auto it = coordinates.begin();
            it = next(it, get_random_between(0, coordinates.size()));
            pii coordinate = *it;

            int x = coordinate.first;
            int y = coordinate.second;
            ss2 << "ptp p" << (x - 1) * width + y << '\n';
            ss2 << "get" << '\n';
            command_count += 2;
            se_x.erase(x);
            se_y.erase(y);
            coordinates.erase(coordinate);

            // success or collusion
            int success_or_fail = get_random_between(0, 2);
            if (success_or_fail)
            {
                coordinate = get_ok_coordinate(height, width);
                se_x.insert(coordinate.first);
                se_y.insert(coordinate.second);
                coordinates.insert(coordinate);
            }
            else
            {
                coordinate = get_not_ok_coordinate(height, width);
            }
            x = coordinate.first;
            y = coordinate.second;
            ss2 << "ptp p" << (x - 1) * width + y << '\n';
            ss2 << "put" << '\n';
            command_count += 2;

            while (!success_or_fail)
            {
                success_or_fail = get_random_between(0, 2);
                if (success_or_fail)
                {
                    coordinate = get_ok_coordinate(height, width);
                    se_x.insert(coordinate.first);
                    se_y.insert(coordinate.second);
                    coordinates.insert(coordinate);
                }
                else
                {
                    coordinate = get_not_ok_coordinate(height, width);
                }
                x = coordinate.first;
                y = coordinate.second;
                ss2 << "ptp p" << (x - 1) * width + y << '\n';
                ss2 << "put" << '\n';
                command_count += 2;
            }
        }

        ofstream ofs;
#ifdef example
        ofs.open("D:\\tests\\example_" + to_string(q) + ".txt");
#else
        ofs.open("D:\\tests\\" + to_string(q) + ".txt");
#endif
        ss << command_count << '\n' << ss2.str();
        ofs << (ss.str()) << '\n';
    }

    return 0;
}