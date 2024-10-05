#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> read() {
    vector<vector<int>> u;

    ifstream in("dat/p082_matrix");
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

struct Node{
    int dist;
    Node* next[3];
};

int f() {
    vector<vector<int>> u = read();

    vector<pair<Node, bool>> nodes;
    
    for(int i = 0; i < u.size(); i++)
        for(int j = 0; j < u[i].size(); j++) {

        }

    return 0;
}

int main() {
    cout << f() << endl;

    return 0;
}
