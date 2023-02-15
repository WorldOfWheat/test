#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    vector<int> difference(arr.size());
    adjacent_difference(arr.begin(), arr.end(), difference.begin());
    for (auto i : difference)
    {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}