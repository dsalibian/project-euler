#include <iostream>

using namespace std;

int f(int n) {
    int sum = 0;
    
    for(int i = 3; i < n; i += 3)
        sum += i;
    
    for(int i = 5; i < n; i += 5)
        sum += i;
    
    for(int i = 15; i < n; i += 15)
        sum-=i;
    
    return sum;
}

int main() {
    int n = 1'000;
    
    cout << f(n) << endl;

    return 0;
}
