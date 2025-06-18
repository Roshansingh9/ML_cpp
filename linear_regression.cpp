#include <iostream>
#include <vector>

using namespace std;

double mean(const vector<double>& v) {
    double sum = 0;
    for (double val : v) sum += val;
    return sum / v.size();
}

void linearRegression(const vector<double>& x, const vector<double>& y, double& m, double& b) {
    double x_mean = mean(x);
    double y_mean = mean(y);
    double numerator = 0, denominator = 0;
    for (size_t i = 0; i < x.size(); ++i) {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += (x[i] - x_mean) * (x[i] - x_mean);
    }
    m = numerator / denominator;
    b = y_mean - m * x_mean;
}

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4, 5, 4, 5};
    double slope = 0, intercept = 0;
    linearRegression(x, y, slope, intercept);
    cout << "y = " << slope << " * x + " << intercept << endl;
    double x_new = 6;
    cout << "Prediction for x = " << x_new << ": y = " << slope * x_new + intercept << endl;
    return 0;
}
