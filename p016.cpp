#include <iostream>
#include <vector>

using namespace std;

vector<int> twice(vector<int>& n) {
    vector<int> product (n.size());
    int carry = 0;

    for(int i = 0; i < n.size(); i++) {
        int p = n[i] * 2 + carry;
        product[i] = p % 10;
        carry = p / 10;
    }

    if( carry != 0 ) 
        product.push_back(carry);

    return product;
}

vector<int> twopow(int n) {
    vector<int> m = { 1 };
    for(int i = 0; i < n; i++)
        m = twice(m);

    return m;
}

int f(int n) {
    int sum = 0;

    vector<int> m = twopow(n);
    for(int i = 0; i < m.size(); i++)
        sum += m[i];

    return sum;
}

int main() {
    int n = 1000;

    cout << f(n) << endl;

    return 0;
}
