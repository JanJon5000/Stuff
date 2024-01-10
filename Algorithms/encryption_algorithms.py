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
def ADFGVX(password: str, alph: str, finalKeyWord: str) -> str:
    alph = polibius_chessboard(alph, 6)
    absoluteKey = 'ADFGVX'
    encryptingString = ''
    for char in ''.join([c for c in password.lower() if c != ' ']):
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

def main():
    print(ADFGVX(password='attack at 1200am', alph='1q2w3e4r5t6y7u8i9o0pasdfghjklzxcvbnm', finalKeyWord='privacy'))

if __name__=='__main__':
    main()