#include <iostream>
#include <cmath>

using namespace std;

uint64_t f() {
    int c = 0;

    for(int i = 0; i < 10; i++) 
        for(int j = 0; (int)( j * log10(i) ) + 1 >= j; j++) 
            if( (int)( j * log10(i) ) + 1 == j ) 
                c++;
            
    return c;
}

int main() {    
    cout << f() << endl;

    return 0;
}
