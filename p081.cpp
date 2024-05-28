#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> read() {
    vector<vector<int>> u;

    ifstream in("dat/p081_matrix");
    string s;
    for( ; getline(in, s); ) {
        istringstream stream(s);
        int n;
        vector<int> v;

        for( ; stream >> n; ) {
            if (stream.peek() == ',')
                stream.ignore();

            v.push_back(n);
        }

        u.push_back(v);
    }
    in.close();

    return u;
}

int f() {
    vector<vector<int>> a = read();
    int a_size = a.size();
    int a0_size = a[0].size();

    for(int i = 1; i < a_size; i++) {
        a[i][0] += a[i-1][0];
        a[0][i] += a[0][i-1];
    }

    for(int i = 1; i < a_size; i++) 
        for(int j = 1; j < a0_size; j++) 
            a[i][j] += std::min(a[i-1][j], a[i][j-1]);

    return a[a_size-1][a0_size-1];
}

int main() {
    auto start = chrono::steady_clock::now();
    int result = f();
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
