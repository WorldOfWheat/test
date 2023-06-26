#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Open file
    fstream myFile;
    myFile.open("test.txt", ios::app);

    // Write to the file
    myFile << "\nI want to go to play.";

    // Close file
    myFile.close();

    return 0;
}