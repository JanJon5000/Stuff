from pprint import pprint
from random import randint

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
    standardAlph = 'ABCDEFGHIJKLMNOPRSTUVWXYZ'
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

def r_matrix_key_generator(n: int, alphLen: int) -> list:
    matrix = [[randint(0, alphLen-1) for _ in range(n)] for _ in range(n)]
    return matrix
def hill_cipher(message: str, matrixKey: list, alph: str) -> str:
    wordVector = [alph.index(char) for char in message]
    codedMessage = [sum([matrixKey[y][x]*wordVector[x] for x in range(len(wordVector))])%len(alph) for y in range(len(matrixKey))]
    codedMessage = ''.join([alph[x] for x in codedMessage])
    return codedMessage

def alph_f(alph: str):
    newAlph = []
    for i in range(int(len(alph)/5)):
        newAlph.append(alph[0+i*5:5+i*5])
    return newAlph
def four_square_cipher(message: str, keywords: tuple) -> str:
    standardAlph = 'ABCDEFGHIJKLMNOPRSTUVWXYZ'
    message = message.upper()
    partitionedMessage = [message[0+i*2:2+i*2] for i in range(int(len(message)/2+1))]
    squares = [alph_f(k_word_alph(keywords[0].upper())), alph_f(k_word_alph(keywords[1].upper()))]
    ansMessage = ''
    for pair in partitionedMessage:
        if len(pair) != 2:
            ansMessage += pair
            continue
        else:
            c1 = standardAlph.index(pair[0])
            c2 = standardAlph.index(pair[1])
            print(pair, c1//5, c2%5, squares)
            ansMessage += squares[0][c1//5][c2%5]
            print()
            ansMessage += squares[1][c2//5][c1%5]

    return ansMessage

def main():
    standardAlph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    noQ = 'ABCDEFGHIJKLMNOPRSTUVWXYZ'
    m = 'helpmeobiwankenobi'.upper()
    print(four_square_cipher(m, ('example', 'keyword')))
    
if __name__=='__main__':
    main()