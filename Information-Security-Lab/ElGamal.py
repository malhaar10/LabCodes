#pg17,q4
import random
from math import pow

# Function to find the greatest common divisor
def gcd(a, b):
    if a < b:
        return gcd(b, a)
    elif a % b == 0:
        return b
    else:
        return gcd(b, a % b)

# Function to generate a large random number
def gen_key(q):
    key = random.randint(int(pow(10, 20)), q)
    while gcd(q, key) != 1:
        key = random.randint(int(pow(10, 20)), q)
    return key

# Function for modular exponentiation
def power(a, b, c):
    x = 1
    y = a
    while b > 0:
        if b % 2 != 0:
            x = (x * y) % c
        y = (y * y) % c
        b = int(b / 2)
    return x % c

# Function to encrypt the message
def encrypt(msg, q, h, g):
    en_msg = []
    k = gen_key(q)  # Private key for sender
    s = power(h, k, q)
    p = power(g, k, q)
    for i in range(0, len(msg)):
        en_msg.append(s * ord(msg[i]))
    return en_msg, p

# Function to decrypt the message
def decrypt(en_msg, p, key, q):
    dr_msg = []
    h = power(p, key, q)
    for i in range(0, len(en_msg)):
        dr_msg.append(chr(int(en_msg[i] / h)))
    return ''.join(dr_msg)

# Main function
def main():
    msg = "Confidential Data"
    print("Original Message:", msg)

    # Public key parameters
    q = random.randint(int(pow(10, 20)), int(pow(10, 50)))
    g = random.randint(2, q)
    key = gen_key(q)  # Private key for receiver
    h = power(g, key, q)

    print("Public Key (p, g, h):", (q, g, h))
    print("Private Key x:", key)

    # Encrypt the message
    en_msg, p = encrypt(msg, q, h, g)
    print("Encrypted Message:", en_msg)

    # Decrypt the message
    dr_msg = decrypt(en_msg, p, key, q)
    print("Decrypted Message:", dr_msg)

if __name__ == '__main__':
    main()
