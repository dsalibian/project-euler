#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

uint64_t f(int n) {
    vector<uint64_t> arr;
    vector<uint64_t> arr_2;
    int m = log10(UINT64_MAX) + 1;
    for(int i = 2; i < m; i++) {

        uint64_t l = cbrt(pow(10, i));
        uint64_t u = cbrt(pow(10, i + 1));

        for(int j = l; j < u; j++) {
            uint64_t t = (uint64_t)j * j * j;

            string s = to_string(t);
            sort(s.begin(), s.end());
            
            arr.push_back( stoull(s) );
            arr_2.push_back(t);
        }

        for(int j = 0; j < arr.size(); j++) {
            int c = 0;
            
            for(int k = 0; k < arr.size(); k++) {
                if( arr[j] == arr[k] )
                    c++;
            }

            if( c == n )
                return arr_2[j];
            
        }

        arr.clear();
        arr_2.clear();
        
    }

    return 0;
}

int main() {
    int n = 5;
    
    auto start = chrono::steady_clock::now();
    uint64_t result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}