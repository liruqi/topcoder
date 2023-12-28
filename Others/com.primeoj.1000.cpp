#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <bitset>

#define MAX_N 2038074743
#define IN_N 10
#define STK_PRIME_SIZE 100000000

unsigned int inp[IN_N];

std::bitset<MAX_N> not_prime;
unsigned int* stk_prime;
void sieve_of_eratosthenes(int maxInp) {
    // 初始化标志数组，假设所有数都是素数
    unsigned long i = 2;
    not_prime.set(2, false);
    stk_prime = new unsigned int[maxInp+1];
    stk_prime[0] = 0;
    // 使用埃拉托斯特尼筛法，将非素数的标志位设为0
    for (i = 2; i*i < MAX_N; ++i) {
        if (!not_prime[i]) {
            stk_prime[0]+=1;
            stk_prime[stk_prime[0]] = i;
            if (stk_prime[0] >= maxInp) break;
            for (unsigned long j = i * i; j < MAX_N; j += i) {
                not_prime[j] = true;
            }
        }
    }
    for (; i<MAX_N && stk_prime[0]<maxInp; ++i) {
        if (!not_prime[i]) {
            stk_prime[0]+=1;
            stk_prime[stk_prime[0]] = i;
        }
    }
}

int main() {
	int q = -1;
    char line[100];
	int i;
    unsigned int maxInp = 0;
	for (i = 0; i < IN_N; i++) {
		scanf("%s\n", line);
		if (line[0] != 'q')
			sscanf(line, "%u", &inp[i]);
		else {
			sscanf(line, "qq_group:%u", &inp[i]);
			q = i;
		}
		maxInp = std::max(maxInp, inp[i]);
	}
    // 调用埃拉托斯特尼筛法函数
    sieve_of_eratosthenes(maxInp);
    for (i = 0; i < IN_N; i++) {
		if (i == q)
			printf("qq_group:");
		printf("%u\n", stk_prime[inp[i]]);
	}
    return 0;
}
