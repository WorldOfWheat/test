    ifstream cin;
    ofstream cout;
    cin.open("test_input.txt");
    if (cin.fail()) {
        cerr << "ERROR - Input" << "\n";
        return;
    }
    cout.open("test_output.txt");
