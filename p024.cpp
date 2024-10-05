#include <iostream>
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
    
    cout << f(n) << endl;

    return 0;
}
