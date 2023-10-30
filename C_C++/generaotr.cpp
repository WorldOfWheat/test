#include "lib/testlib.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) 
{
    registerGen(argc, argv, 1);

    rnd.setSeed(time(0) ^ (int) argv[1]);

    set<string> names_table;
    for (int i = 0; i < 1e6; i++)
    {
        const string person_name = rnd.next("[a-zA-Z]{8}");
        names_table.insert(person_name);
    }

    vector<string> names;

    const int phone_number_amount = rnd.next(10, (int) 1e4);
    // const int phone_number_amount = 5;
    cout << phone_number_amount << '\n';
    for (int i = 0; i < phone_number_amount; i++)
    {
        const string phone_number = rnd.next("09[0-9]{8}");
        cout << phone_number;

        const int extension_amount = rnd.next(0, 30);
        for (int j = 0; j < extension_amount; j++)
        {
            const string extension = rnd.next("[0-9]");
            cout << "->" << extension;
        }

        const string person_name = rnd.any(names_table);
        names_table.erase(person_name);
        cout << "->" << person_name << '\n';
    }

    const int query_amount = rnd.next(10, 1000);
    // const int query_amount = 2;
    cout << query_amount << '\n';
    for (int i = 0; i < query_amount; i++)
    {
        const string person_name = rnd.any(names);
        cout << person_name << '\n';
    }
}