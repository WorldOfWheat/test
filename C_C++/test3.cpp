// 實作B
#include <iostream>

using namespace std;

int main()
{
    // 1.
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // 2
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // 3
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;

    // 4
    int counter = 1;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << counter << '\t';
            counter++;
        }
        cout << endl;
    }
    cout << endl;

    // 5
    for (int i = 1; i <= 5; i++) 
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
    cout << endl;

    // 6
    for (int i = 1; i <= 5; i++) 
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;

    // 7
    for (int i = 1; i <= 5; i++) 
    {
        for (int j = 1; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;

    // 8
    for (int i = 5; i >= 1; i--) 
    {
        for (int j = 1; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
