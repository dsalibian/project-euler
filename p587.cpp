#include <iostream>
#include <cmath>

using namespace std;

double F(double x) {
    return -0.5*((x - 1)*sqrt(x*(2 - x)) - 2*x - asin(1 - x));
}

double di(double a, double b){
    return F(b) - F(a);
}

double x(double n) {
    return ( ( (n + 1) / n ) - sqrt(2.0/n) ) * ( (n*n) / (n*n + 1) );
}

int f(double n) {
    double v_0 = di(0, 1);

    for(int i = 1; ; i++) {
        double a = x(i);
        double v = di(a, 1) + 0.5*a*a*(1.0/i);

        if( v/v_0 < n )
            return i;
    }
}

int main() {
    double n = 0.001;

    cout << f(n) << endl;

    return 0;
}
