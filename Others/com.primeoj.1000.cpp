#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 2038074743;
const int IN_N = 10;
const unsigned int SQRT_N = 65536; // math.sqrt(2038074743) -> 45145.041178406296
int inp[IN_N];
int limit = sqrt(MAX_N);
int inpHash[SQRT_N];
int q = -1;
map<int, int> output;
int primeCount = 0;

void simple_sieve(bool is_prime[], vector<int>& ps) {
    fill(is_prime, is_prime + limit, true);
    is_prime[0] = is_prime[1] = false;

    for (int num = 2; num < limit; ++num) {
        if (is_prime[num]) {
            primeCount ++;
            if (inpHash[primeCount]>0) {
                if (output.find(primeCount) != output.end()) {
                    output[primeCount] = num;
                }
            }
            int multiple = num * num;
            while (multiple < limit) {
                is_prime[multiple] = false;
                multiple += num;
            }
            ps.push_back(multiple);
        }
    }
}

int sieve_of_eratosthenes(int maxInp) {
    bool is_prime[limit];
    vector<int> prime_states;

    simple_sieve(is_prime, prime_states);

    int low = limit;
    int high = 2 * limit;

    while (low < MAX_N) {
        cout << "* " << low << " - " << high << "; " << primeCount << endl;
        fill(is_prime, is_prime + limit, true);
        if (high > MAX_N) {
            high = MAX_N;
        }

        for (size_t pos = 0; pos < prime_states.size(); ++pos) {
            int prime = pos + 2;
            int multiple = prime_states[pos];
            while (multiple < high) {
                is_prime[multiple - low] = false;
                multiple += prime;
            }
            prime_states[pos] = multiple;
        }

        // Print primes matching inp in the order of input
        for (int i = low; i < high; ++i) {
            int hv = i - low;
            if (is_prime[hv]) {
                primeCount ++;
                if (inpHash[primeCount % SQRT_N]>0) {
                    if (output.find(primeCount) != output.end()) {
                        output[primeCount] = i;
                        cout << "$ " << primeCount << " ->" << i << endl;
                    }
                }
                if (primeCount >= maxInp) {
                    return maxInp;
                }
            }
        }

        low += limit;
        high += limit;
    }

    return maxInp;
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
        int hv = inp[i] % SQRT_N;
        inpHash[hv] += 1;
        output[hv] = -1;
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
