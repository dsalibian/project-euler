#include <iostream>
#include <cmath>

using namespace std;

int g(int n) {
    if( n < 9 ) 
        return n;

    int s = 0;
    int i = 1;
    for( ; s < n; i++) 
        s += (int)log10(i) + 1;
        
    for(int j = 0; j < s - n; j++)
        i /= 10;

    return i % 10;
}   

int f() {
    int p = 1;
    
    for(int i = 1; i <= 1'000'000; i *= 10) 
        p *= g(i);
    
    
    return p;
}

int main() {
    cout << f() << endl;

    return 0;
}
