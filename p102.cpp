#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> read() {
    vector<vector<int>> u;

    ifstream in("dat/p102_triangles");
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

    int c = 0;
    for(int i = 0; i < a.size(); i++) {
        int p0x = a[i][0];
        int p0y = a[i][1];
        int p1x = a[i][2];
        int p1y = a[i][3];
        int p2x = a[i][4];
        int p2y = a[i][5];

        double a = 0.5 *(-p1y*p2x + p0y*(-p1x + p2x) + p0x*(p1y - p2y) + p1x*p2y);
        double s = 1/(2*a)*(p0y*p2x - p0x*p2y);
        double t = 1/(2*a)*(p0x*p1y - p0y*p1x);

        if( s > 0 && t > 0 && (1 - s -  t) > 0 )
            c++;
    }

    return c;
}

int main() {
    cout << f() << endl;

    return 0;
}
