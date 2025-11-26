message = 'Information Security'
value = 5381
for letter in message:
    value = (value * 33) + ord(letter)
    value = value & 0xFFFFFFFF
print(value)