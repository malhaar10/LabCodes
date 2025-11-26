from Crypto.Cipher import DES, AES
from Crypto.Util.Padding import pad, unpad
import time

# Input message and keys
message = "Performance Testing of Encryption Algorithms"
des_key = b"8bytekey"  # DES key must be 8 bytes
aes_key = b"0123456789ABCDEF0123456789ABCDEF"  # AES-256 key must be 32 bytes

# Pad the keys if necessary
des_key = des_key[:8]  # DES key should be exactly 8 bytes
aes_key = aes_key[:32]  # AES-256 key should be exactly 32 bytes

# Measure DES encryption and decryption time
des_cipher = DES.new(des_key, DES.MODE_CBC)
start_time = time.time()
des_ciphertext = des_cipher.encrypt(pad(message.encode(), DES.block_size))
des_encryption_time = time.time() - start_time

des_decrypt_cipher = DES.new(des_key, DES.MODE_CBC, iv=des_cipher.iv)
start_time = time.time()
des_plaintext = unpad(des_decrypt_cipher.decrypt(des_ciphertext), DES.block_size).decode()
des_decryption_time = time.time() - start_time

# Measure AES-256 encryption and decryption time
aes_cipher = AES.new(aes_key, AES.MODE_CBC)
start_time = time.time()
aes_ciphertext = aes_cipher.encrypt(pad(message.encode(), AES.block_size))
aes_encryption_time = time.time() - start_time

aes_decrypt_cipher = AES.new(aes_key, AES.MODE_CBC, iv=aes_cipher.iv)
start_time = time.time()
aes_plaintext = unpad(aes_decrypt_cipher.decrypt(aes_ciphertext), AES.block_size).decode()
aes_decryption_time = time.time() - start_time

# Report results
print("DES Encryption Time: {:.6f} seconds".format(des_encryption_time))
print("DES Decryption Time: {:.6f} seconds".format(des_decryption_time))
print("AES-256 Encryption Time: {:.6f} seconds".format(aes_encryption_time))
print("AES-256 Decryption Time: {:.6f} seconds".format(aes_decryption_time))