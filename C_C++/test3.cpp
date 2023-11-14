#include <bits/stdc++.h>

using namespace std;

stringstream ss;

void printArray(const vector<int> &arr)
{
    for (auto i : arr)
    {
        ss << i << ' ';
    }
    ss << '\n';
}

void printAllPermutations(vector<int> &arr, int start, int end)
{
    if (start + 1 == end)
    {
        printArray(arr);
        return;
    }

    for (int i = start; i < end; i++)
    {
        swap(arr[i], arr[start]);
        printAllPermutations(arr, start + 1, end);
        swap(arr[i], arr[start]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    printAllPermutations(arr, 0, arr.size());

    cout << (ss.str());

    return 0;
}
