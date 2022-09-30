#include <iostream>

using namespace std;
 
int main() {

    string str = "aabxcbaba";

    int cont = 0;
    int ans = 0;

    for (int i = 0; i < str.length(); i++) {
        char top = str[i];
    
        if (cont == 1 && top == 'b') {
            ans++;
        }

        if (top == 'a') {
            cont = 1;
        }
        else {
            cont = 0;
        }
        
    }

    cout << ans << "\n";

    return 0;

}
