#include <bits/stdc++.h>

using namespace std;

/*
┏━┳━┳━┓
┃ ┃ ┃ ┃
┃━╋━╋━┃
┃ ┃ ┃ ┃
┃━╋━╋━┃
┃ ┃ ┃ ┃
┗━┻━┻━┛
*/

vector<bool> filled(9, false);
int playerNow;
int table;

bool draw(int decimal);
int getInput();
string getBinary(int decimal);
int getDecimal(string binary); 
void gameJudge(string binary);
void printTable(string binary); 

int main() {
   
    while (true) {
        if (draw(getInput())) {
            printTable(getBinary(table));
            gameJudge(getBinary(table));
        }
    } 
    return 0;

}

bool draw(int place) {
    if (filled[place-1]) {
        cout << "Has been drawen!!!" << '\n';
        return false;
    }

    if (playerNow == 1) {
        table |= (256 >> (place - 1));
    }
    filled[place-1] = true;   
    playerNow = 1 - playerNow;

    return true;
}

int getInput() {
    int in;
    cin >> in;
    
    if (in == 0) {
        exit(0);
    }

    in = in % 9;

    return in;
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

void gameJudge(string binary) {
    bool flag = false;

    for (auto i : {0, 3, 6}) {
        bool row = 
            (binary[i] == binary[i + 1] && binary[i + 1] == binary[i + 2]) &&
            (filled[i] == filled[i + 1] && filled[i + 1] == filled[i + 2] && filled[i]);
        if (row) {
            flag = true;
        }
    }
       
    for (auto i : {0, 1, 2}) {
        bool column =
            (binary[i] == binary[i + 3] && binary[i + 3] == binary[i + 6]) &&
            (filled[i] == filled[i + 3] && filled[i + 3] == filled[i + 6] && filled[i]);
        if (column) {
            flag = true;
        }
    }

    if (
        (binary[0] == binary[4] && binary[4] == binary[8]) &&
        (filled[0] == filled[4] && filled[4] == filled[8] && filled[0])
    ) {
        flag = true;
    }

    if (
        (binary[2] == binary[4] && binary[4] == binary[6]) &&
        (filled[2] == filled[4] && filled[4] == filled[6] && filled[2])
    ) {
        flag = true;
    }
    

    if (flag) {
        cout << "GGGGGGGGGGG " << (1 - playerNow) << '\n';
        exit(0);
    }
}

void printTable(string binary) {
    cout << "┏━┳━┳━┓" << '\n';

    for (int i = 0; i <= 2; i++) {
        cout << "┃";
        if (!filled[i]) {
            cout << ' ';
            continue;
        }
        //cout << binary[i];
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
        //cout << binary[i];
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
        //cout << binary[i];
        cout << (binary[i] == '1' ? "O" : "X");
    }
    cout << "┃" << '\n';

    cout << "┗━┻━┻━┛" << '\n';

}


