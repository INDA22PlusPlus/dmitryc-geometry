#include <iostream>
#include <cmath>
using namespace std;

double get_relative_height(int a, int b, int c, double A) {
    if (a == b) {
        return c;
    } else if (a > b) {
        return 2.0 * A / a;
    } else {
        return 2.0 * A / b;
    }
}

double area_triangle(int a, int b, int c) {
    // Semi-perimeter
    double s = (a + b + c + 0.0) / 2.0;
    // Hero's formula
    return sqrt(s * (s - a) * (s - b) * (s - c));
}


int main() {
    int a = 4, b = 5, c = 4;
    double A = area_triangle(a, b, c);
    double h = get_relative_height(a, b, c, A);

    cout << "Area: " << A << endl;
    cout << "Height: " << h << endl;
    return 0;
}
