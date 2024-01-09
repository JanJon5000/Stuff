import random

def knuth_shuffle(l: list) -> list:
    for i in range(len(l)-1, 1, -1):
        j = random.randint(0, i)
        helper = l[i]
        l[i] = l[j]
        l[j] = helper
    return l

def main():
    p = [10, 20, 30, 40, 5]
    print(knuth_shuffle(p))

if __name__ == '__main__':
    main()