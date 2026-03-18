#include <iostream>
#include <cstdlib>

double rand_double() {
    // Generate random number in (0,1)
    double ret = (double) rand();
    return ret / (RAND_MAX + 1.0);
}

int sample_geometric_rv(double p) {
    double q;
    int n = 0;
    
    q = rand_double();
    n++;
    
    while (q >= p) {
        q = rand_double();
        n++;
    }
    
    return n;
}

int main() {
    double p = 0.5;
    std::cout << "So lan lap voi xac suat p=" << p << " la: " 
              << sample_geometric_rv(p) << '\n';
    return 0;
}