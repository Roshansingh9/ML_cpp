#include <iostream>

using namespace std;

double bayesTheorem(double priorA, double likelihoodB_givenA, double priorNotA, double likelihoodB_givenNotA) {
    double numerator = likelihoodB_givenA * priorA;
    double denominator = numerator + likelihoodB_givenNotA * priorNotA;
    return numerator / denominator;
}

int main() {
    // P(A): prior probability of event A
    double priorA = 0.01;         

    // P(B|A): probability of evidence B given A
    double likelihoodB_givenA = 0.95;   

    // P(~A): prior probability of event not A
    double priorNotA = 1 - priorA;    

    // P(B|~A): probability of evidence B given not A
    double likelihoodB_givenNotA = 0.05; 

    double posterior = bayesTheorem(priorA, likelihoodB_givenA, priorNotA, likelihoodB_givenNotA);

    cout << "P(A|B) = " << posterior << endl;

    return 0;
}
