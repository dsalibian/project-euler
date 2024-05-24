#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

uint64_t f(int n) {
    string s = "0123456789";
    
    for(int i = 0; i < n - 1; i++)
        next_permutation(s.begin(), s.end());

    return stoll(s);
}

int main() {
    int n = 1'000'000;

    auto start = chrono::steady_clock::now();
    uint64_t result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
