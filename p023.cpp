#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int d(int n) {
    int sum = 1;

    int u = sqrt(n);
    for(int i = 2; i <= u; i++) {
        if( n % i == 0 ) {
            if( n/i == i ) 
                sum += i;            
            else 
                sum += i + n/i;
        }
    }

    return sum;
}

bool abundant(int n) {
    return d(n) > n;
}

int f() {
    vector<int> arr;
    for(int i = 1; i < 28'124; i++)
        if( abundant(i) )
            arr.push_back(i);

    vector<bool> arr2 (28'124, false);

    for(int i = 0; i < arr.size(); i++)
        for(int j = i; j < arr.size(); j++) {
            int ind = arr[i] + arr[j];

            if( ind < arr2.size() )
                arr2[ ind ] = true;
            else 
                break;
        }

    int sum = 0;
    for(int i = 0; i < arr2.size(); i++)
        if( !arr2[i] )
            sum += i;

    return sum;
}

int main() {
    cout << f() << endl;

    return 0;
}
