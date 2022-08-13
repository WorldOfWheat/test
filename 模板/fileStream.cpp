    ifstream in;
    ofstream out;
    in.open("test_input.txt");
    if (in.fail()) {
        cout << "ERROR - 1" << "\n";
        return;
    }
    out.open("test_output.txt");
    if (out.fail()) {
        cout << "ERROR - 2" << "\n";
        return;
    }
  
