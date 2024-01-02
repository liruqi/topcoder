#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MAX_N = 2038074743 + 1;
const int IN_N = 10;
const unsigned int SQRT_N = 1000000; // 65536; // math.sqrt(2038074743) -> 45145.041178406296
int inp[IN_N];
int limit = 45146;
int primes[SQRT_N];
bitset< (MAX_N>>1) > is_prime;
int primesLength = 0;
int primeCount = 0;
map<int, int> output;
vector<int> primesCntPerMillion;
int sieve_of_eratosthenes(int maxInp) {
    std::map<int, int>::iterator outputIter = output.begin();
    is_prime.set();    
    for (size_t num = 2; num < MAX_N; num+=2) {
        if (num-1 == SQRT_N*(primesCntPerMillion.size()+1)) {
            primesCntPerMillion.push_back(primeCount);
        }
        if (is_prime[num>>1]) {
            if (num < limit) {
                primes[primesLength++]=num;
                // cout << "+ " << primesLength << ": " << num << endl;
            }
            primeCount++;
            if (primeCount == outputIter->first) {
                outputIter->second = num;
                outputIter++;
                if (outputIter == output.end()) {
                    primesCntPerMillion.push_back(primeCount);
                    return 1;
                }
            }
        }
        for (int i=1; i<primesLength; ++i) {
            size_t multiple = primes[i] * num;
            if (multiple >= MAX_N) {
                break;
            }
            is_prime[multiple>>1] = 0;
            if (num % primes[i] == 0) {
                break; // https://x.com/liruqi/status/1741213686793126188?s=20
            }
        }
        if (num == 2) {
            num = 1; // 后续计算，跳过偶数
        }
    }
    primesCntPerMillion.push_back(primeCount);
    return 3;
}

int main() {
    // 将 "input.txt" 指定为 stdin
    if (!freopen("in1.txt", "r", stdin)) {
        // 如果文件无法打开，打印错误并退出
        printf("Error opening input file.\n");
        return 1;
    }

    int maxInp = 0;
    int q = -1;

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

    for (int i = 0; i < primesCntPerMillion.size(); ++i) {
        cout << primesCntPerMillion[i] << ",";
    }
    return 0;
}
