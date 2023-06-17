#include <iostream>

using namespace std;

int main()
{
    int n = 1;
    int counter = 0;
    while (true)
    {
        if (420 % n == 1009 % n)
        {
            counter++;
        }
        if (counter == 4)
        {
            break;
        }
        n++;
    }

    cout << n << endl;

    return 0;
}
