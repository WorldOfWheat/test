#include <bits/stdc++.h>

using namespace std;

/*
┏━┳━┳━┓
┃O┃O┃O┃
┃━╋━╋━┃
┃O┃O┃O┃
┃━╋━╋━┃
┃O┃O┃O┃
┗━┻━┻━┛
*/

vector<bool> filled;

string getBinary(int decimal);
int getDecimal(string binary); 
void printTable(string binary); 
void gameJudge(string binary);

int main() {
    
    filled.resize(9, 1);
    for (auto i : filled) {
        cerr << i << '\n';
    }
    printTable("101010101");

    return 0;

}

string getBinary(int decimal) {
    if (decimal >= 1024) {
        return "null";
    }

    bitset<9> bs;
    bs = decimal;

    return (bs.to_string());
}

int getDecimal(string binary) {
    if (binary.length() >= 10) {
        return 0;
    }

    bitset<9> bs(binary);

    return (bs.to_ulong()); 
}

void printTable(string binary) {
    cout << "┏━┳━┳━┓" << '\n';

    for (int i = 0; i <= 2; i++) {
        cout << "┃";
        if (!filled[i]) {
            cout << ' ';
            continue;
        }
        cout << (binary[i] == '1' ? "O" : "X");
    }
    cout << "┃" << '\n';
    
    cout << "┃━╋━╋━┃" << '\n';

    for (int i = 3; i <= 5; i++) {
        cout << "┃";
        if (!filled[i]) {
            cout << ' ';
            continue;
        }
        cout << (binary[i] == '1' ? "O" : "X");
    }
    cout << "┃" << '\n';

    cout << "┃━╋━╋━┃" << '\n';

    for (int i = 6; i <= 8; i++) {
        cout << "┃";
        if (!filled[i]) {
            cout << ' ';
            continue;
        }
        cout << (binary[i] == '1' ? "O" : "X");
    }
    cout << "┃" << '\n';

    cout << "┗━┻━┻━┛" << '\n';

}

void gameJudge(string binary) {
    
}
