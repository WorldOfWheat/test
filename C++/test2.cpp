#include <bits/stdc++.h>

using namespace std;

vector<int> arr(10);

int binarySearch(int target, int left, int right) {
    if (left + 1 >= right) {
        return right;
    }

    int mid = (left + right) >> 1;
    if (arr[mid] > target) {
        return binarySearch(target, left, mid);
    }
    if (arr[mid] < target) {
        return binarySearch(target, mid, right);
    }

    return mid;
}

int binarySearch2(int target, int left, int right) {
    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            right = mid;
        }
        if (arr[mid] < target) {
            left = mid;
        }
    }

    return right;
}

int binarySearch3(int target, int left, int right) {
    int result = 0;
    for (int i = right - left; i > 0; i >>= 1) {
        while (result + i < right && arr[result + i] < target) {
            result += i;
        }
    }

    return result + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}