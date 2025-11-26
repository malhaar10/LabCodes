from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

# Get user input for the message and the key
message = input("Enter the message to encrypt: ").encode('utf-8')
key = input("Enter an 8-byte key (e.g., 'A1B2C3D4'): ").encode('utf-8')

# Ensure the key is exactly 8 bytes long (DES requirement)
if len(key) != 8:
    raise ValueError("Key must be exactly 8 bytes long.")

# Create a DES cipher object
cipher = DES.new(key, DES.MODE_ECB)

# Encrypt the message
padded_message = pad(message, DES.block_size)  # Pad the message to be a multiple of the block size
ciphertext = cipher.encrypt(padded_message)

# Decrypt the ciphertext
decrypted_padded_message = cipher.decrypt(ciphertext)
decrypted_message = unpad(decrypted_padded_message, DES.block_size)

# Output the results
print("Ciphertext (hex):", ciphertext.hex())
print("Decrypted message:", decrypted_message.decode('utf-8'))