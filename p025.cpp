#include <iostream>

using namespace std;

void trim(string& s) {
    for( ; s.length() > 1 && s[0] == '0'; )
        s.erase(0, 1);
}

string add(const string& a, const string& b) {
    int l = max(a.length(), b.length());

    string fsum (l, '0');

    int carry = 0;
    for(int i = 0; i < l; i++) {
        int ind0 = a.length() - 1 - i;
        int ind1 = b.length() - 1 - i;

        int sum = 0;

        if( ind0 > -1 )
            sum += (int)(a[ind0] - 48);

        if( ind1 > -1 )
            sum += (int)(b[ind1] - 48);

        sum += carry;

        fsum[l - 1 - i] = (char)( ( sum % 10 ) + 48 );
        carry = sum / 10;

    }

    if( carry != 0 )
        fsum = to_string(carry) + fsum;

    trim(fsum);
    return fsum;
}


int f(int n) {
    
    string f1 = "1";
    string f2 = "1";

    int i = 2;
    for( ; f2.length() < n; i++) {
        string t = add(f1, f2);
        f1 = f2;
        f2 = t;
    }
   
    return i;
}

int main() {
    int n = 1'000;

    cout << f(n) << endl;

    return 0;
}
