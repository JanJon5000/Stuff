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



def main():
    standardAlph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    m = 'THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG'
    print(caesar_cipher(23, m))
    pass

if __name__=='__main__':
    main()