import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter
import numpy as np
from pprint import pprint

def selection_sort(l: list):
    for i in range(len(l)):
        swapper = min(l[i:])
        l[l.index(swapper)] = l[i]
        l[i] = swapper
    return l

def bubble_sort(l: list):
    for i in range(len(l)):
        flag = 0
        for j in range(len(l)-i-1):
            if l[j] > l[j+1]:
                flag += 1
                helper = l[j]
                l[j] = l[j+1]
                l[j+1] = helper
        if flag == 0:
            break
    return l

def insertion_sort(l: list):
    lSorted = [l[0]]
    for i in range(1, len(l)):
        for j in range(len(lSorted)):
            if l[i] <= lSorted[j]:
                lSorted.insert(j, l[i])
                break
            elif j == len(lSorted) - 1:
                lSorted.append(l[i])
                break
                
    return lSorted

def shell_sort(l: list):
    shell_series = [int(len(l)/2)]
    while shell_series[-1] > 1:
        shell_series.append(int(shell_series[-1]/2))
    
    for step in shell_series:
        for i in range(step):
            if i + step < len(l) and l[i + step] < l[i]:
                helper = l[i + step]
                l[i + step] = l[i]
                l[i] = helper
    return l

def main():
    l = [5132, 5645, 5144, 6682, 7708, 7710, 6689, 5160, 552, 1065, 44, 4142, 8751, 5168, 6711, 1592, 2622, 6735, 4691, 6743, 1121, 3170, 1124, 3173, 6775, 2680, 8828, 8317, 1664, 4737, 4738, 7817, 1162, 5263, 8847, 1180, 7326, 671, 9894, 5799, 680, 170, 175, 8881, 180, 9397, 1220, 197, 7366, 2759, 4820, 3812, 5863, 4328, 6380, 8429, 748, 9455, 7920, 1787, 5883, 6397, 4863, 3330, 6917, 1287, 4368, 1822, 3363, 5935, 5426, 4403, 9534, 3391, 6980, 6992, 7526, 1384, 7027, 4988, 6533, 1927, 392, 6025, 904, 8600, 5017, 4018, 4546, 965, 8652, 5071, 9167, 3539, 8153, 3035, 2025, 7663, 4600, 8188]
    a = np.array(insertion_sort(l))
    b = np.array(bubble_sort(l))
    c = np.array(selection_sort(l))
    d = np.array(shell_sort(l))
    plt.plot(d, '.')
    plt.show()

if __name__ == "__main__":
    main()