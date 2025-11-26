
import string

alphabet = string.ascii_uppercase

def main():
    msg = "THISMANEISBEINGSOLD"
    key = "F"

    if key.lstrip('-+').isdigit():
        key = alphabet[int(key)]
    
    enc = auto_encryption(msg, key)

    print("Plaintext : " + msg)
    print("Encrypted : " + enc)
    print("Decrypted : " + auto_decryption(enc, key))

def auto_encryption(msg, key):
    length = len(msg)

    # generating the keystream
    new_key = key + msg
    new_key = new_key[:len(new_key) - len(key)]
    encrypt_msg = ""

    # applying encryption algorithm
    for x in range(length):
        first = alphabet.index(msg[x])
        second = alphabet.index(new_key[x])
        total = (first + second) % 26
        encrypt_msg += alphabet[total]
    
    return encrypt_msg

def auto_decryption(msg, key):
    current_key = key
    decrypt_msg = ""

    # applying decryption algorithm
    for x in range(len(msg)):
        get1 = alphabet.index(msg[x])
        get2 = alphabet.index(current_key[x])
        total = (get1 - get2) % 26
        total = total + 26 if total < 0 else total
        decrypt_msg += alphabet[total]
        current_key += alphabet[total]
    
    return decrypt_msg

if __name__ == "__main__":
    main()

