#include <iostream>
#include <cmath>
#include <iomanip>

double arctanTaylorSeries(double x, int n) {
    double result = 0.0;
    double sign = 1.0;

    for (int i = 1; i <= 2*n-1; i+=2) {
        result += sign * (std::pow(x, i) / i);
        sign *= -1; // Alterna el signo
    }

    return result;
}

double computePiMachin(int n) {
    return 4.0 * (4.0 * arctanTaylorSeries(1.0/5.0, n) - arctanTaylorSeries(1.0/239.0, n));
}

int main() {
    int n;
    std::cout << "Introduce el valor de n: ";
    std::cin >> n;
    
    double pi_approximation = computePiMachin(n);
    
    // Ajusta la precisión de la salida a 20 decimales
    std::cout << std::fixed << std::setprecision(20);
    std::cout << "Aproximación de pi usando " << n << " términos: " << pi_approximation << std::endl;

    return 0;
}
