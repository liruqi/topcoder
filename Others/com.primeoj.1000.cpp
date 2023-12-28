#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const unsigned int MAX_N = 2038074743;
const unsigned int IN_N = 10;
const unsigned int SQRT_N = 65536; // math.sqrt(2038074743) -> 45145.041178406296
unsigned int inp[IN_N];
unsigned int limit = sqrt(MAX_N);
vector<unsigned int> primes;
vector<unsigned int> prime_states;
bool is_prime[SQRT_N];

int simple_sieve(unsigned int limit) {
    fill(is_prime, is_prime + limit, true);
    for (unsigned int num = 2; num < limit; ++num) {
        if (is_prime[num]) {
            primes.push_back(num);
            unsigned int multiple = num * num;
            while (multiple < limit) {
                is_prime[multiple] = false;
                multiple += num;
            }
            prime_states.push_back(multiple);
        }
    }
    return 0;
}

unsigned int sieve_of_eratosthenes(unsigned int maxInp) {
    simple_sieve(limit);

    unsigned int low = limit;
    unsigned int high = 2 * limit;

    while (low < MAX_N) {
        bool is_prime[limit];
        fill(is_prime, is_prime + limit, true);
        if (high > MAX_N) {
            high = MAX_N;
        }

        for (size_t pos = 0; pos < prime_states.size(); ++pos) {
            unsigned int prime = primes[pos];
            unsigned int multiple = prime_states[pos];
            while (multiple < high) {
                is_prime[multiple - low] = false;
                multiple += prime;
            }
            prime_states[pos] = multiple;
        }

        // Store new primes found in the current block
        for (unsigned int i = low; i < high; ++i) {
            if (is_prime[i - low]) {
                primes.push_back(i);
            }
        }

        if (primes.size() >= static_cast<size_t>(maxInp)) {
            return primes.size();
        }

        low += limit;
        high += limit;
    }

    return primes.size();
}

unsigned int main() {
    unsigned int q = -1;
    unsigned int maxInp = 0;

    for (unsigned int i = 0; i < IN_N; ++i) {
        string line;
        getline(cin, line);
        if (line[0] != 'q') {
            inp[i] = stoi(line);
        } else {
            inp[i] = stoi(line.substr(9));
            q = i;
        }
        maxInp = max(maxInp, inp[i]);
    }

    // Call the sieve_of_eratosthenes function
    unsigned int prime_number = sieve_of_eratosthenes(maxInp);

    for (unsigned int i = 0; i < IN_N; ++i) {
        if (i == q) {
            cout << "qq_group:";
        }
        cout << primes[inp[i] - 1] << endl;
    }

    return 0;
}
