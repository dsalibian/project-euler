#include <iostream>
#include <vector>

using namespace std;

bool contains(vector<int>& arr, int n) {
    for(int i = 0; i < arr.size(); i++)
        if( arr[i] == n )
            return true;

    return false;
}

int period(int n) {
    vector<int> past;

    string res = "0.";
    int a = n;
    int b = 1;

    for( ; ; ) {

        for( ; b < a; ) {
            b *= 10;
            if( b < a )
                res += '0';
        }

        int t = b / a;

        res += (char)( t + 48 );
        b -= a * t;

        bool k = contains(past, b);
        past.push_back(b);

        if( b == 0 ) 
            return 0;

        if( k ) {
            for(t = 2; res[t] == '0'; t++);

            return res.length() - t - 1;
        }

    }
}

int f(int n) {
    int max = 0;
    int maxi = 0;

    for(int i = 2; i < n; i++) {
        int n = period(i);

        if( n > max ) {
            max = n;
            maxi = i;
        }
    }

    return maxi;
}

int main() {
    int n = 1'000;

    cout << f(n) << endl;

    return 0;
}
