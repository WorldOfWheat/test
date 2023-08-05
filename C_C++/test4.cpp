#include <iostream>
#include "lib/testlib.h"

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    rnd.setSeed(time(0));

    // for (int i = 0; i < 100; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << (rnd.next("25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9]")) << '.';
    //     }
    //     cout << rnd.next("25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9]") << '\n';
    // }

    cout << (rnd.next(-10, 10)) << '\n';

    return 0;
}
