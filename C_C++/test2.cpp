#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    while (n < 50)
    {
        n++;
        if (n % 2 == 0)
        {
            cout << "Apple" << endl;
            continue;
        }
        if (n % 3 == 0)
        {
            cout << "Banana" << endl;
            continue;
        }
        if (n % 5 == 0)
        {
            cout << "Orange" << endl;
            continue;
        }
        cout << n << endl;
    }


    return 0;
}