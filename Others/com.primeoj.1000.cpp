#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 2038074743 + 1;
const int IN_N = 10;
const unsigned int SQRT_N = 65536; // math.sqrt(2038074743) -> 45145.041178406296
int inp[IN_N];
int limit = sqrt(MAX_N);
int primes[SQRT_N];
int prime_states[SQRT_N];
char is_prime[SQRT_N];

int primesLength = 0;
int primeCount = 0;
int q = -1;
map<int, int> output;

int sieve_of_eratosthenes(int maxInp) {
    std::map<int, int>::iterator outputIter = output.begin();
    fill(is_prime, is_prime + limit, 1);
    is_prime[0] = is_prime[1] = false;

    for (int num = 2; num < limit; ++num) {
        if (is_prime[num]) {
            primes[primesLength]=num;
            primeCount ++;
            if (primeCount == outputIter->first) {
                outputIter->second = num;
                outputIter++;
                if (outputIter == output.end()) return 1;
            }
            int multiple = num * num;
            while (multiple < limit) {
                is_prime[multiple] = 0;
                multiple += num;
            }
            prime_states[primesLength] = multiple;
            primesLength += 1;
        }
    }
    int low = limit;
    int high = 2 * limit;

    while (low < MAX_N) {
        // cout << "* " << low << " - " << high << "; " << primeCount << endl;
        fill(is_prime, is_prime + limit, 1);
        if (high > MAX_N) {
            high = MAX_N;
        }

        for (size_t pos = 0; pos < primesLength; ++pos) {
            int prime = primes[pos];
            int multiple = prime_states[pos];
            while (multiple < high) {
                is_prime[multiple - low] = 0;
                multiple += prime;
            }
            
            prime_states[pos] = multiple;
        }

        // Print primes matching inp in the order of input
        for (int i = low; i < high; ++i) {
            int hv = i - low;
            if (is_prime[hv]) {
                primeCount ++;
                if (primeCount == outputIter->first) {
                    outputIter->second = i;
                    outputIter++;
                    if (outputIter == output.end()) return 2;
                }
                
            }
        }

        low += limit;
        high += limit;
    }

    return 3;
}

int main() {
    int maxInp = 0;

    for (int i = 0; i < IN_N; ++i) {
        string line;
        getline(cin, line);
        if (line[0] != 'q') {
            inp[i] = stoi(line);
        } else {
            inp[i] = stoi(line.substr(9));
            q = i;
        }
        maxInp = max(maxInp, inp[i]);
        output[inp[i]] = -1;
    }

    // Call the sieve_of_eratosthenes function
    sieve_of_eratosthenes(maxInp);

    for (int i = 0; i < IN_N; ++i) {
        if (i == q) {
            cout << "qq_group:";
        }
        cout << output[inp[i]] << endl;
    }
    return 0;
}
