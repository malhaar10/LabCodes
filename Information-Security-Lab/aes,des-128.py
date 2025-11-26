from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import binascii

# Input message and key
message = "Sensitive Information"
key = b"0123456789ABCDEF0123456789ABCDEF"

# AES-128 uses a key size of 16 bytes (128 bits)
# Truncate the key to 16 bytes
key = key[:16]

# Encrypt the message
cipher = AES.new(key, AES.MODE_CBC)
ciphertext = cipher.encrypt(pad(message.encode(), AES.block_size))

# To decrypt, we need to use the same initialization vector (IV)
iv = cipher.iv
cipher_decrypt = AES.new(key, AES.MODE_CBC, iv=iv)
plaintext = unpad(cipher_decrypt.decrypt(ciphertext), AES.block_size).decode()

# Convert ciphertext to hex format for readability
ciphertext_hex = binascii.hexlify(ciphertext).decode()

print("Ciphertext (hex):", ciphertext_hex)
print("Decrypted message:", plaintext)
