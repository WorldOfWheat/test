#include <iostream>

using namespace std;

int main()
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 44216921d236f72874629e3fc812c014b2dd6b9c
