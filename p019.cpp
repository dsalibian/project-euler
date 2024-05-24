#include <iostream>
#include <chrono>

using namespace std;

int f() {
    int days = 0;
    int sundays = 0;

    for(int i = 1901; i < 2001; i++) {
        for(int j = 1; j <= 12; j++) {
            bool b0 = j == 4 || j == 6 || j == 9|| j == 11;

            bool b1 = ( j == 2 ) && ( i % 4 != 0 );
            bool b2 = ( j == 2 ) && ( i % 4 == 0 ) && ( i % 100 == 0) && ( i % 400 != 0);

            bool b3 = ( j == 2 ) && ( i % 4 == 0 ) && ( i % 100 != 0 );
            bool b4 = ( j == 2 ) && ( i % 4 == 0 ) && ( i % 100 == 0 ) && ( i % 400 == 0 );

            if( b0 ) {
                for(int k = 1; k <= 30; k++) {
                    days++;
                    if( k == 1 && days % 7 == 5)
                        sundays++;
                }
            }
            else if( b1 || b2 ) {
                for(int k = 1; k <= 28; k++) {
                    days++;
                    if( k == 1 && days % 7 == 5 )
                        sundays++;
                }
            }
            else if( b3 || b4 ) {
                for(int k = 1; k <= 29; k++) {
                    days++;
                    if( k == 1 && days % 7 == 5 )
                        sundays++;
                }
            }
            else {
                for(int k = 1; k <= 31; k++) {
                    days++;
                    if( k == 1 && days % 7 == 5 )
                        sundays++;
                }
            }
        }   
    }

    return sundays;
}

int main() {
    auto start = chrono::steady_clock::now();
    int result = f();
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
