#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> read() {
    vector<string> words;
    string s = "";

    ifstream in("dat/p042_words");
    for( ; !in.eof(); ) {
        char c = in.get();

        if( ( c == ',' ) || ( c == '"' && s.length() == 0 ) )
            continue;
        else if( c == '"' && s.length() != 0 ) {
            words.push_back(s);
            s = "";
        } 
        else
            s += c;
    }
    in.close();

    return words;
}

bool triangle(int n) {
    int t = 1;

    for(int i = 0; t < n; i++)
        t = i * ( i + 1 ) / 2;

    return t == n;
}

bool tword(string s) {
    int sum = 0;

    for(int i = 0; i < s.length(); i++)
        sum += s[i] - 64;

    return triangle(sum);
}

int f() {
    int count = 0;
    
    vector<string> words = read();
    for(int i = 0; i < words.size(); i++)
        if( tword(words[i]) )
            count++;
    
    return count;
}

int main() {
    cout << f() << endl;

    return 0;
}
