#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int f() {
    vector<string> names;
    string s = "";

    ifstream in("dat/p022_names");
    for( ; !in.eof(); ) {
        char c = in.get();

        if( c == ',' )
            continue;
        else if( c == '"' && s.length() == 0 )
            continue;
        else if( c == '"' && s.length() != 0 ) {
            names.push_back(s);
            s = "";
        } 
        else
            s += c;
    }
    in.close();

    sort(names.begin(), names.end());

    int total = 0;
    for(int i = 0; i < names.size(); i++) {
        int score = 0;
        for(int j = 0; j < names[i].length(); j++)
            score += names[i][j] - 64;
        score *= i + 1;
        total += score;

    }

    return total;
}

int main() {
    auto start = chrono::steady_clock::now();
    int result = f();
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
