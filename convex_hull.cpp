#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int INF = 1000000005;

int main() {
    int test_cases;
    cin >> test_cases;

    vector<vector<pair<int, int>>> all_points;
    while (test_cases != 0) {
        vector<pair<int, int>> points;
        for (int i = 0; i < test_cases; i++) {
            int x, y;
            cin >> x >> y;
            points.emplace_back(x, y);
        }
        all_points.push_back(points);
        cin >> test_cases;
    }
//    cout << "end";

    // Loop through all points
    for (auto points: all_points) {
        // Find highest point, O(N)
        pair<int, int> highest = {0, -INF};
        for (auto point: points) {
            if (point.second > highest.second) {
                highest = point;
            }
        }
        cout << "Highest point: X: " << highest.first << "Y: " << " " << highest.second << endl;
    }

}
