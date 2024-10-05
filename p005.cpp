#include <iostream>

using namespace std;

int f(int n) {
    for(int i = n; ; i += n) {
        for(int j = 3; j < n; j++) {
            if( i % j != 0 ) 
                goto continue2;
        }
        return i;
        continue2:;
    }

    return -1;
}

int main() {
    int n = 20;

    cout << f(n) << endl;

    return 0;
}
