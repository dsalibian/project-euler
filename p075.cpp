#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

void next(int a, int b, int c, int max, vector<int>& count){
    int s = a + b + c;

    if( s > max )
        return;

    for(int i = s; i <= max; i += s)
        count[i]++;

    next(  a+2*b+2*c,  2*a+b+2*c, 2*a+2*b+3*c, max, count);
    next(  a-2*b+2*c,  2*a-b+2*c, 2*a-2*b+3*c, max, count);
    next( -a+2*b+2*c, -2*a+b+2*c,-2*a+2*b+3*c, max, count);
}

int f(int n) {
    vector<int> u (n, 0);
    next(3, 4, 5, n, u);

    int c = 0;
    for(int i = 0; i < u.size(); i++)
        if( u[i] == 1 )
            c++;

    return c;
}

int main() {
    int n = 1'500'000;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
