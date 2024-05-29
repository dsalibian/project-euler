#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> read() {
    vector<vector<int>> u;

    ifstream in("dat/p099_base_exp");
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

    double max = 0;
    int maxi = 0;

    for(int i = 0; i < a.size(); i++) {
        double m = a[i][1] * log(a[i][0]);
        if( m > max ){
            max = m;
            maxi = i;
        }
    }

    return ++maxi;
}

int main() {
    auto start = chrono::steady_clock::now();
    int result = f();
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}