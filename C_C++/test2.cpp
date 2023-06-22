#include <iostream>

using namespace std;

int main()
{
    // 1.印出 1~10
    for (int i = 1; i <= 10; i++)
    {
        cout << i << ' ';
    }
    cout << endl;

    // 2.印出 0~9
    for (int i = 0; i < 10; i++)
    {
        cout << i << ' ';
    }
    cout << endl;

    // 3.印出 0~10
    for (int i = 0; i <= 10; i++)
    {
        cout << i << ' ';
    }
    cout << endl;

    // 4.印出 20 ~ 30
    for (int i = 20; i <= 30; i++)
    {
        cout << i << ' ';
    }
    cout << endl;

    // 5.印出 0 ~ 29 之間的所有偶數
    // 第一種
    for (int i = 0; i < 30; i++) 
    {
        if (i % 2 == 0)
        {
            cout << i << ' ';
        }
    }
    cout << endl;
    // 第二種
    for (int i = 0; i < 30; i += 2)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}