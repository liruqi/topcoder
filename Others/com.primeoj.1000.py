import math

MAX_N = 2038074743
IN_N = 10
inp = [0] * IN_N
limit = int(math.sqrt(MAX_N))
primes = []

def simple_sieve(limit):
    is_prime = [True] * (limit)
    is_prime[0] = is_prime[1] = False
    
    ps = []
    for num in range(2, limit):
        if is_prime[num]:
            primes.append(num)
            multiple = num * num  # Start marking multiples from the square of the prime
            while multiple < limit:
                is_prime[multiple] = False
                multiple += num
            ps.append(multiple)
    return ps
    
def sieve_of_eratosthenes(maxInp):    
    prime_states = simple_sieve(limit)

    low = limit
    high = 2 * limit

    while low < MAX_N:
        is_prime = [True] * (limit)
        if high > MAX_N:
            high = MAX_N
        
        for pos in range(len(prime_states)):
            prime = primes[pos]
            multiple = prime_states[pos]
            while multiple < high:
                is_prime[multiple - low] = False
                multiple += prime
            prime_states[pos] = multiple

        # Store new primes found in the current block
        for i in range(low, high):
            if is_prime[i - low]:
                primes.append(i)
        if len(primes) >= maxInp:
            return len(primes)

        low += limit
        high += limit

    return len(primes)

def main():
    global inp
    q = -1
    maxInp = 0

    for i in range(IN_N):
        line = input().strip()
        if line[0] != 'q':
            inp[i] = int(line)
        else:
            inp[i] = int(line.split(":")[1])
            q = i
        maxInp = max(maxInp, inp[i])

    # Call the sieve_of_eratosthenes function
    prime_number = sieve_of_eratosthenes(maxInp)

    for i in range(IN_N):
        if i == q:
            print("qq_group:", end="")
        print(primes[inp[i] - 1])

if __name__ == "__main__":
    main()
