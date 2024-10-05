#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double f(int n) {
    vector<vector<uint64_t>> points;
    points.reserve(n);

    uint64_t p = 290'797;
    
    for(int i = 0; i < n; i++) {
        uint64_t tp = ( p * p ) % 50'515'093;
        vector<uint64_t> t {p, tp};
        p = ( tp * tp ) % 50'515'093;

        points.push_back(t);
        t.clear();
    }

    sort(points.begin(), points.end());

    uint64_t dist_min = UINT64_MAX;

    for(int i = 0; i < n-1; i++) {
        uint64_t firstx = points[i][0];
        uint64_t x1 = points[i][0];
        uint64_t y1 = points[i][1];

        for(int j = i + 1; j < n; j++) {
            uint64_t dist_x = points[j][0] - firstx;
            dist_x *= dist_x;

            if( dist_x > dist_min ) 
                break;

            uint64_t x2 = points[j][0];
            uint64_t y2 = points[j][1];

            uint64_t a = x2 - x1;
            uint64_t b = y2 - y1;

            uint64_t dist = a*a + b*b;
            dist_min = min(dist_min, dist);

        }

    }
    return sqrt(dist_min);
}

int main() {
    int n = 2'000'000;
    
    cout << setprecision(11) << f(n) << endl;

    return 0;
}
