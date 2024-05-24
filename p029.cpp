#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int maxlen(vector<string>& arr) {
    int max = 0;
    for(int i = 0; i < arr.size(); i++)
        max = std::max(max, (int)arr[i].length());

    return max;
}

string add(vector<string>& arr) {
    int m = maxlen(arr);
    string fsum (m, '0');

    int carry = 0;
    for(int i = 0; i < m; i++) {
        int sum = carry;

        for(int j = 0; j < arr.size(); j++) {
            int ind = arr[j].length() - 1 - i;

            if( ind > -1 )
                sum += (int)arr[j][ind] - 48;
        }

        fsum[m - 1 - i] = (char)( ( sum % 10 ) + 48 );
        carry = sum / 10;
    }

    if( carry != 0)
        fsum = to_string(carry) + fsum;

    return fsum;
}

string mult(const string& n, const string& m) {
    int l = n.length() + m.length();
    string p (l, '0');

    vector<string> arr (m.length(), "");

    int sum = 0;
    int carry = 0;

    for(int i = m.length() - 1; i > -1; i--) {
        int carry = 0;
        for(int j = n.length() - 1; j > -1; j--) {
            arr[i] = '0' + arr[i];
            int tp = (int)(m[i] - 48) * (int)(n[j] - 48) + carry;  
            arr[i][ arr[i].length() - n.length() + j ] = ( tp % 10 ) + 48;
            carry = tp / 10;
        }
        if( carry != 0 )
            arr[i] = to_string(carry) + arr[i];
    }

    for(int i = 0; i < arr.size(); i++)
        for(int j = 0; j < arr.size() - 1 - i; j++)
            arr[i] += '0';

    return add(arr);
}

string pow(int a, int b) {
    string p = "1";

    for(int i = 0; i < b; i++)
        p = mult(p, to_string(a));
        
    return p;
}

int f(int n) {
    set<string> set;

    for(int i = 2; i <= n; i++) 
        for(int j = 2; j <= n; j++) 
            set.insert( pow(i, j) );

    return set.size();
}

int main() {
    int n = 100;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}