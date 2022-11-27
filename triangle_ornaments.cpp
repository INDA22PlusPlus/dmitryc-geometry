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

double p(int a, int b, int c) {
    return sqrt((2.0 * (a * a + b * b + 0.0) - c * c) / 4.0);
}

double k(double a, double b, int c) {
    double angle_ = (b * b + a * a - c * c);
    double angle = acos((b * b + a * a - c * c) / (2.0 * a * b));
    if (angle > M_PI / 2.0) {
        return M_PI - angle;
    } else {
        // Because it's the same as angle, opposite angle
        return angle;
    }

}

double l(double angle, double hypotenuse) {
    return sin(angle) * hypotenuse * 2;
}


int main() {
    int cases;
    cin >> cases;
    double sum = 0.0;
    for (int i = 0; i < cases; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // Calculate the length using over the top trigonometry
        double median_c = p(a, b, c);
        double half_c = c / 2.0;
        double median_c_angle = k(median_c, half_c, b);
        double length = l(median_c_angle, half_c);

        sum += length;
    }

    cout << sum;

    return 0;
}
