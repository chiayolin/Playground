def is_prime(n):
    if n < 2:
        return False
    return not list(filter(lambda x: n % x is 0, range(2, n)))

number = 1
prime_list = []
nth_prime = 10001
while len(prime_list) <= nth_prime:
    number += 2
    if is_prime(number):
        prime_list.append(number)
        print(len(prime_list), number) if not (len(prime_list) % 1000) else None
print(prime_list[-1])
