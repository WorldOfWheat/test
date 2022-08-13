    ifstream cin;
    ofstream cout;
    cin.open("test_input.txt");
    if (cin.fail()) {
        cerr << "ERROR - 1" << "\n";
        return;
    }
    cout.open("test_output.txt");
    if (cout.fail()) {
        cerr << "ERROR - 2" << "\n";
        return;
    }
  
