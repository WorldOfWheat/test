def enc(plain_text, key):
    cipher_text = ''
    for i in plain_text:
        cipher_text += chr(((ord(i)-ord('a')) + key) % 26 + ord('a'))
    return cipher_text

def dec(cipher_text, key):
    plain_text = ''
    for i in cipher_text:
        plain_text += chr(((ord(i)-ord('a')) - key) % 26 + ord('a'))
    return plain_text

def crack(cipher_text):
    FREQ = 'etaoinshrdlcumwfgypbvkjxqz'
    alphabet_count = [0] * 26
    for i in range(26):
        alphabet_count[i] = (cipher_text.count(chr(i+ord('a'))), i)
    alphabet_count.sort(reverse=True)
    # print(alphabet_count)



data = 'chinese'
cipher_text = enc(data, 3)
print(cipher_text)
print(dec(cipher_text, 3))
crack(cipher_text)
