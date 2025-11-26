#pip install ecdsa pycryptodome
from ecdsa import SigningKey, SECP256k1
from Crypto.Cipher import AES
from Crypto.Hash import SHA256
from Crypto import Random
#import os

# Generate ECC key pair
private_key = SigningKey.generate(curve=SECP256k1)
public_key = private_key.get_verifying_key()

# Helper functions
def pad(data):
    return data + b"\0" * (AES.block_size - len(data) % AES.block_size)

def unpad(data):
    return data.rstrip(b'\0')

# Derive a shared secret using ECDH
def derive_shared_secret(private_key, public_key):
    shared_secret = private_key.privkey.secret_multiplier * public_key.pubkey.point
    return SHA256.new(int.to_bytes(shared_secret.x(), 32, 'big')).digest()

# Encrypt the message using AES
def encrypt_message(shared_secret, plaintext):
    plaintext = pad(plaintext)
    iv = Random.new().read(AES.block_size)
    cipher = AES.new(shared_secret, AES.MODE_CBC, iv)
    ciphertext = iv + cipher.encrypt(plaintext)
    return ciphertext

# Decrypt the ciphertext using AES
def decrypt_message(shared_secret, ciphertext):
    iv = ciphertext[:AES.block_size]
    cipher = AES.new(shared_secret, AES.MODE_CBC, iv)
    plaintext = unpad(cipher.decrypt(ciphertext[AES.block_size:]))
    return plaintext

# Original message
original_message = "Secure Transactions"

# Step 1: Derive shared secret from ECC keys
shared_secret = derive_shared_secret(private_key, public_key)

# Step 2: Encrypt the message
ciphertext = encrypt_message(shared_secret, original_message.encode('utf-8'))

# Step 3: Decrypt the message
decrypted_message = decrypt_message(shared_secret, ciphertext)

# Display results
print("Original Message:", original_message)
print("Ciphertext:", ciphertext.hex())
print("Decrypted Message:", decrypted_message.decode('utf-8'))
