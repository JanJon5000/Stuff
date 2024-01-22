from pprint import pprint

def polibius_chessboard(string: str, dim: int) -> list:
    ans = []
    currentString = ''
    for i in range(len(string)):
        if i % dim == 0 and i != 0:
            ans.append(currentString)
            currentString = string[i]
        else:
            currentString += string[i]
    if currentString != '':
        ans.append(currentString)
    return ans
def ADFGVX(message: str, alph: str, finalKeyWord: str) -> str:
    alph = polibius_chessboard(alph, 6)
    absoluteKey = 'ADFGVX'
    encryptingString = ''
    for char in ''.join([c for c in message.lower() if c != ' ']):
        indexes = []
        xChars = ''
        for i in range(len(alph)):
            for j in range(len(alph[i])):
                if alph[i][j] == 'x':
                    xChars = absoluteKey[i] + absoluteKey[j]
                if alph[i][j] == char:
                    indexes.extend([i, j])    
        encryptingString += absoluteKey[indexes[0]] + absoluteKey[indexes[1]]
    while len(encryptingString) % (len(finalKeyWord)) != 0:
        encryptingString += xChars
    encryptingString = polibius_chessboard(encryptingString, len(finalKeyWord))
    encryptingString = {k:''.join([encryptingString[i][finalKeyWord.find(k)] for i in range(len(encryptingString))]) for k in sorted(finalKeyWord)}
    return (''.join(encryptingString.values()))

def affine_cipher(K: tuple, message: str, alph: str) -> str:
    alph = alph.upper()
    message = message.upper()
    val = lambda x: (K[0]*x + K[1])%len(alph)
    ans = ''
    for char in message:
        if char in alph:
            ans += alph[val(alph.index(char))]
        else:
            ans += char
    return ans

def caesar_cipher(n: int, message: str, alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ') -> str:
    return affine_cipher((1, n), message, alph)

def altbash_cipher(message: str, alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ') -> str:
    return affine_cipher((-1, -1), message, alph)

def autokey_cipher(message: str, primer: str, alph: str) -> str:
    key = primer + message
    ans = ''
    for i in range(len(message)):
        ans += alph[(alph.index(message[i])+alph.index(key[i]))%len(alph)]
    return ans

def beaufort_cipher(key: str, message: str, alph: str) -> str:
    reversedAlph = (affine_cipher((-1, -1), alph, alph))
    ans = ''
    key = key.upper()
    keyIndex = 0
    for letter in message:
        if keyIndex >= len(alph):
            keyIndex = 0
        ans += (reversedAlph[alph.index(key[keyIndex]):] + reversedAlph[:alph.index(key[keyIndex])])[ alph.index(letter)%len(alph) ]
        keyIndex += 1
    return ans

def k_word_alph(key: str) -> str:
    standardAlph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    wantedCipher = ''
    for char in key:
        if char not in wantedCipher:
            wantedCipher += char
    for char in standardAlph:
        if char not in wantedCipher:
            wantedCipher += char
    return wantedCipher
def alberti_cipher(key: str, message: str, specificAlph: str, alph: str) -> str:
    message = message.upper()
    key = key.upper()
    i = 0
    codedMessage = ''
    for element in message:
        if element != ' ':
            if i >= len(key):
                i = 0
            currentAlph = specificAlph[-alph.index(key[i]):] + specificAlph[0:-alph.index(key[i])]
            codedMessage += currentAlph[alph.index(element)]
            i += 1
        else:
            codedMessage += ' '
    return codedMessage

def main():
    standardAlph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    specificAlph = 'ALBERTICPHDFGHJKMNOSUVWXYZ'.upper()
    m = 'this is a test of alberti'.upper()
    print(alberti_cipher('catwalk', m, specificAlph, standardAlph))
    
if __name__=='__main__':
    main()