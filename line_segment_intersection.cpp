#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int INF = 1000000005;

pair<int, int> add(pair<int, int> a, pair<int, int> b, char sign = '+') {
    if (sign == '+') {
        return {a.first + b.first, a.second + b.second};
    } else {
        return {a.first - b.first, a.second - b.second};
    }
}

bool left(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return add(b, a, '-').first * add(c, a, '-').second -
    add(a, b, '-').second * add(c, a, '-').first
    > 0;
}

int main() {
    int test_cases;
    cin >> test_cases;

    vector<vector<pair<int, int>>> all_points;
    for (int j = 0; j < test_cases; j++) {
//        cout << j << endl;
        vector<pair<int, int>> points;
        for (int i = 0; i < 4; i++) {
            int x, y;
            cin >> x >> y;
            pair<int, int> point = {x, y};
            points.emplace_back(point);
        }
        all_points.push_back(points);
    }
//    cout << "end";
//    for (auto highest: highest_points) {
//        cout << "Highest point: X: " << highest.first << " Y: " << highest.second << endl;
//    }

    // Loop through all points
    for (auto points: all_points) {
        // Find highest point, O(N)
        pair<int, int> a, b, c, d;
        a = points[0];
        b = points[1];
        c = points[2];
        d = points[3];
        for (auto point: points) {
            cout << "X: " << point.first << " Y: " << point.second << endl;
        }

        cout << left(a, b, c) << endl;


        cout << endl;
    }
}
