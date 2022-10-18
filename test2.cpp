// C++ program to find the Dominant Set of a graph
#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int> > g;
bool box[100000];
 
vector<int> Dominant(int ver, int edge)
{
    vector<int> S; // set S
    for (int i = 0; i < ver; i++) {
        if (!box[i]) {
            S.push_back(i);
            box[i] = true;
            for (int j = 0; j < (int)g[i].size(); j++) {
                if (!box[g[i][j]]) {
                    box[g[i][j]] = true;
                    break;
                }
            }
        }
    }
    return S;
}
 
// Driver function
int main()
{
    int ver, edge, x, y;
 
    ver = 5; // Enter number of vertices
    edge = 4; // Enter number of Edges
    g.resize(ver + 1);
 
    // Setting all index value of an array as 0
    memset(box, 0, sizeof(box));
 
    // Enter all the end-points of all the Edges
    // g[x--].push_back[y--]      g[y--].push_back[x--]
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    vector<int> S = Dominant(ver, edge);
    cout << "The Dominant Set is : { ";
    for (int i = 0; i < (int)S.size(); i++)
        cout << S[i] + 1 << " ";
    cout << "}";
    return 0;
}