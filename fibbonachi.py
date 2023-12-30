def fibbonachi(num):
    for _ in range(num-2):
        listFibonachi.append(listFibonachi[-1] + listFibonachi[-2])

listFibonachi = [0, 1]

x = int(input('podaj ilość kolejnych liczb ciągu fibonachiego jakie chcesz zobaczyc: '))
fibbonachi(x)
print(listFibonachi)