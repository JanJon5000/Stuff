import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter
import numpy as np
from pprint import pprint
from math import floor

def selection_sort(l: list) -> list:
    ans = l[:]
    for i in range(len(ans)):
        swapper = min(ans[i:])
        ans[ans.index(swapper)] = ans[i]
        ans[i] = swapper
    return ans

def bubble_sort(l: list) -> list:
    ans = l[:]
    for i in range(len(ans)):
        flag = 0
        for j in range(len(ans)-i-1):
            if ans[j] > ans[j+1]:
                flag += 1
                helper = ans[j]
                ans[j] = ans[j+1]
                ans[j+1] = helper
        if flag == 0:
            break
    return ans

def insertion_sort(l: list) -> list:
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

def shell_sort(l: list) -> list:
    ans = l[:]
    shell_series = [int(len(ans)/2)]
    while shell_series[-1] > 1:
        shell_series.append(int(shell_series[-1]/2))
    
    for step in shell_series:
        for i in range(step):
            if i + step < len(ans) and ans[i + step] < ans[i]:
                helper = ans[i + step]
                ans[i + step] = ans[i]
                ans[i] = helper
    ans = insertion_sort(ans)
    return ans

def comb_sort(l: list) -> list:
    ans = l[:]
    gaps = [floor(len(ans)/1.3)]
    while gaps[-1] >= 1:
        gaps.append(floor(gaps[-1]/1.3))
    
    for step in gaps:
        for i in range(step):
            if i + step < len(ans) and ans[i] > ans[i + step]:
                helper = ans[i]
                ans[i] = ans[i + step]
                ans[i + step] = helper

    ans = bubble_sort(ans)

    return ans

def merge_sort(l: list) -> list:
    if len(l) > 1:
        left = l[:(len(l) // 2)]
        right = l[(len(l) // 2):]

        merge_sort(left)
        merge_sort(right) 

        k = 0
        while left != [] and right != []:
            if left[0] <= right[0]:
                l[k] = left[0]
                del left[0]
                k += 1
            else:
                l[k] = right[0]
                del right[0]
                k += 1 

        for i in range(len(left)):
            l[k] = left[i]
            k += 1
        for j in range(len(right)):
            l[k] = right[j]
            k += 1

        return l

# chyba źle zaimplementowane - to wciaz zwykly insertion sort - dodaje wiecej elementow i nie jest zaimplementowany na zasadzie przesówania 
def library_sort(l: list) -> list:
    ans = ['', l[0]]
    j = 1
    while j < len(l):
        if l[j] > max([x for x in ans if x != '']):
            ans.append('')
            ans.append(l[j])
        else:
            for element in ans:
                if element == '':
                    continue
                else:
                    if element > l[j]:
                        index = ans.index(element)
                        ans[index-1] = l[j]
                        ans.insert(index-1, '')
                        ans.insert(index+1, '')
                        break
        j += 1         
    
    return [i for i in ans if i!='']

def cycle_sort(l: list) -> list:
    ans = l[:]
    for i in range(len(ans)):
        placeholder = ans[i]
        place = len([ans[i] for i in range(len(ans)) if ans[i] < placeholder])
        while ans.index(placeholder) != place:
            helper = ans[place]
            ans[ans.index(placeholder)] = ans[place]
            ans[place] = placeholder
            
            place = len([ans[i] for i in range(len(ans)) if ans[i] < helper])
            placeholder = helper

    return ans

def gnome_sort(l: list) -> list:
    ans = l[:]
    for i in range(1, len(ans)):
        j = i
        while j - 1 >= 0 and ans[j] < ans[j-1]:
            helper = ans[j]
            ans[j] = ans[j-1]
            ans[j-1] = helper
            j -= 1
    return ans

def bucket_sort(l: list) -> list:
    ans = []
    a = []
    for i in range(0, 10):
        ans.append([x for x in l if x < 1000 + i*1000 and x > 0 + i*1000])
        ans[-1] = selection_sort(ans[-1])
        a.extend(ans[-1])
    return a

def heapify(l: list) -> list:
    ans = l[:]
    flag = True
    while flag:
        for i in range(len(ans)-1, -1, -1):
            dictOfIndexes = {x:ans[x] for x in [i, 2*i+1, 2*i+2] if x < len(ans)}
            if max(dictOfIndexes.values()) != ans[i]:
                helper = ans[i]
                ans[i] = max(dictOfIndexes.values())
                for j in dictOfIndexes.keys():
                    if dictOfIndexes[j] == max(dictOfIndexes.values()):
                        ans[j] = helper
                        break
        flag = False
        for i in range(len(ans)):
            indexesToCheck = [ans[x] for x in [2*i+1, 2*i+2, i] if x < len(ans)]
            if ans[i] != max(indexesToCheck):
                flag = True
                break
    return ans
def heap_sort(l: list) -> list:
    workingList = heapify(l)
    ans = []
    while workingList != []:
        ans = [workingList[0]] + ans
        del workingList[0]
        workingList = heapify(workingList)
    return ans

def tournament(l: list) -> list:
    ans = l[:]
    for i in range(0, len(ans)-1, 1):
        if i >= len(ans):
            break
        ans[i] = ans[i+1] if i+1 < len(ans) and ans[i] > ans[i + 1] else ans[i]
        if i + 1 < len(ans):
            del ans[i+1]
    return ans
def tournament_sort(l: list) -> list:
    workingList = l[:]
    ans = []
    while workingList != []:
        while len(workingList) != 1:
            workingList = tournament(workingList)
        ans.append(workingList[0])
        workingList = [x for x in l[:] if x not in ans]
    return ans

def counting_sort(l: list) -> list:
    countArray = [0 for _ in range(max(l)+1)]
    for i in range(max(l)+1):
        countArray[i] = l.count(i)
        if i >= 1:
            countArray[i] += countArray[i-1]
    ans = [0 for _ in range(len(l))]
    for i in range(len(ans)-1, -1, -1):
        ans[countArray[l[i]] - 1] = l[i]
        countArray[l[i]] -= 1
    print(ans)
    return ans

def radix_sort(l: list) -> list:
    pass


def main():
    p = [5132, 5645, 5144, 6682, 7708, 7710, 6689, 5160, 552, 1065, 44, 
         4142, 8751, 5168, 6711, 1592, 2622, 6735, 4691, 6743, 1121, 3170, 
         1124, 3173, 6775, 2680, 8828, 8317, 1664, 4737, 4738, 7817, 1162, 
         5263, 8847, 1180, 7326, 671, 9894, 5799, 680, 170, 175, 8881, 180, 
         9397, 1220, 197, 7366, 2759, 4820, 3812, 5863, 4328, 6380, 8429, 
         748, 9455, 7920, 1787, 5883, 6397, 4863, 3330, 6917, 1287, 4368, 
         1822, 3363, 5935, 5426, 4403, 9534, 3391, 6980, 6992, 7526, 1384, 
         7027, 4988, 6533, 1927, 392, 6025, 904, 8600, 5017, 4018, 4546, 
         965, 8652, 5071, 9167, 3539, 8153, 3035, 2025, 7663, 4600, 8188]
    
    plt.plot(np.array(counting_sort(p)), '.')
    plt.show()


if __name__ == "__main__":
    main()