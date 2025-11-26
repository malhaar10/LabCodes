def encrypt(text, s):
    result = ""
    for char in text:
        if char.isupper():
            result += chr((ord(char) + s - 65) % 26 + 65)
        elif char.islower():
            result += chr((ord(char) + s - 97) % 26 + 97)
        elif char.isdigit():  
            result += chr((ord(char) + s - 48) % 10 + 48)  
        else:
            result += char
    return result

text = "Malhaar"
shift = 3
print("Original Text:", text)
print("Shift:", shift)
print("Encrypted Text:", encrypt(text, shift))
