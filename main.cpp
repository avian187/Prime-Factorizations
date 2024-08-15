
#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    // To find the prime factorization,
    // we will use the sieve of Eratosthenes
    // to find all prime numbers up to sqrt(n).
    // Then we will divide n by each prime number
    // and keep track of the number of times it
    // divides n.
    int sqrt_n = sqrt(n);
    bool is_prime[sqrt_n + 1]; // is_prime bool array to store whether a number is prime
    for (int i = 0; i <= sqrt_n; i++) {
        is_prime[i] = true; // initialize all numbers as prime
    }
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime
    for (int i = 2; i <= sqrt_n; i++) { // iterate through all numbers up to sqrt(n)
        if (is_prime[i]) { // if the number is prime
            for (int j = i * i; j <= sqrt_n; j += i) { // mark all multiples of the prime number as not prime
                is_prime[j] = false;
            }
        }
    }

    // Find the prime factorization
    cout << "Prime factorization: ";
    bool is_composite = false;
    for (int i = 2; i <= sqrt_n; i++) {
        if (is_prime[i]) { // if the number is prime (true)
            int count = 0;
            while (n % i == 0) { // while n is divisible by i
                n /= i;
                count++; // increment the count
            }
            if (count > 0) { // if i divides n
                if (is_composite) {
                    cout << " * "; // print a * if the number is composite
                }
                cout << i;
                if (count > 1) {
                    cout << "^" << count; // print the count if it is greater than 1
                }
                is_composite = true; // set is_composite to true
            }
        }
    }
    if (n > 1) { // if n is greater than 1
        if (is_composite) {
            cout << " * "; // print a * if the number is composite
        }
        cout << n; // print n
    }
    cout << endl;

    // Output whether the number is prime or composite
    if (is_composite) {
        cout << "The number is composite." << endl;
    } else {
        cout << "The number is prime." << endl;
    }

}
