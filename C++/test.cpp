#include <iostream>
#include <random>

using namespace std;

int binarySearch(vector<int> arr, int left, int right)
{

}

int main()
{
    vector<int> arr;
    random_device rd;
    mt19937 mt(rd());
    for (int i = 0; i < 5; i++)
    {
        arr.emplace_back(mt() % 100);
    }

    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}