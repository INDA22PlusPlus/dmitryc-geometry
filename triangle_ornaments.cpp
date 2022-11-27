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

double get_median_c(int a, int b, int c) {
    return sqrt((2.0 * (a * a + b * b + 0.0) - c * c) / 4.0);
}

double get_angle_lowe_triangle(double a, double b, int c) {
    double angle = acos((b * b + a * a - c * c) / (2.0 * a * b));
    if (angle > M_PI / 2.0) {
        return M_PI - angle;
    } else {
        // Because it's the same as angle, opposite angle
        return angle;
    }

}

double get_double_length_lower_triangle(double angle, double hypotenuse) {
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
        double median_c = get_median_c(a, b, c);
        double half_c = c / 2.0;
        double median_c_angle = get_angle_lowe_triangle(median_c, half_c, b);
        double length = get_double_length_lower_triangle(median_c_angle, half_c);

        sum += length;
    }

    cout << sum;

    return 0;
}
