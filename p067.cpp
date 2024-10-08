#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> read() {
    vector<vector<int>> u;

    ifstream in("dat/p067_triangle");
    string s;
    for( ; getline(in, s); ) {
        istringstream stream(s);
        int n;
        vector<int> v;

        for( ; stream >> n; )
            v.push_back(n);

        u.push_back(v);
    }
    in.close();

    return u;
}

int f() {
    vector<vector<int>> u = read();

    for(int i = u.size() - 1; i > -1; i--) 
        for(int j = 0; j < i; j++) 
            u[i - 1][j] += max(u[i][j], u[i][j+1] );
        
    return u[0][0];
}

int main() {    
    cout << f() << endl;

    return 0;
}
