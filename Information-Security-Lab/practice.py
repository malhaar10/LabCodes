from vigenere_cipher import encrypted_text


def generate_key(message, key):
    key = list(key)
    if len(key) == len(message):
        return key
    else:
        for i in range(len(message) - len(key)):
            key.append(key[i % len(key)])
    return "".join(key)

def encryption(message, key):
    ciphertext = []
    key = generate_key(message, key)
    for i in range(len(message)):
        char = message[i]
        if char.isupper():
            encrypted_char = chr((ord(char) + ord(key[i]) - 2 * ord('A')) % 26 + ord('A'))
        elif char.islower():
            encrypted_char = chr((ord(char) + ord(key[i]) - 2 * ord('a')) % 26 + ord('a'))
        else:
            encrypted_char = char
        encrypted_text.append(encrypted_char)
    return "".join(encrypted_text)

def encryption(message, key):
    plaintext = []
    key = generate_key(message, key)
    for i in range(len(message)):
        char = message[i]
        if char.isupper():
            plaintext = chr((ord(char) + ord(key[i]) - 2 * ord('A')) % 26 + ord('A'))
        elif char.islower():
            plaintext = chr((ord(char) + ord(key[i]) - 2 * ord('a')) % 26 + ord('a'))
        else:
            plaintext = char
        encrypted_text.append(pl)
    return "".join(encrypted_text)
