from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
import base64

def pad(data):
    return data + b"\0" * (AES.block_size - len(data) % AES.block_size)

def encrypt(plain_text, key):
    plain_text = pad(plain_text)
    iv = get_random_bytes(AES.block_size)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    encrypted_text = iv + cipher.encrypt(plain_text)
    return base64.b64encode(encrypted_text).decode('utf-8')
def decrypt(encrypted_text, key):
    encrypted_text = base64.b64decode(encrypted_text)
    iv = encrypted_text[:AES.block_size]
    cipher = AES.new(key, AES.MODE_CBC, iv)
    plain_text = cipher.decrypt(encrypted_text[AES.block_size:])
    return plain_text.rstrip(b"\0").decode('utf-8')
# Prompt the user to enter a message and a key
message = input("Enter the message you want to encrypt: ")
key = input("Enter a 16-byte key (e.g., 'A1B2C3D4E5F6G7H8'): ").encode('utf-8')
# Ensure the key is 16 bytes long
if len(key) != 16:
    raise ValueError("Key must be 16 bytes long.")
encrypted = encrypt(message.encode('utf-8'), key)
print(f"Encrypted: {encrypted}")
decrypted = decrypt(encrypted, key)
print(f"Decrypted: {decrypted}")
