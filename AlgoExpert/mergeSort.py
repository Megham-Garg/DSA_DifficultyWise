def arrDivider(mainArr, auxArr, start, end):
    
    print(mainArr, auxArr, start, end, 1)
    if start == end:
        return mainArr
    mid = (start+end)//2
    print(mainArr, auxArr, start, end, 2)
    auxArr = arrDivider(auxArr, mainArr, start, mid)
    auxArr = arrDivider(auxArr, mainArr, mid+1, end)
    mainArr = mergeArr(mainArr, auxArr, start, mid, end)
    print(mainArr, auxArr, start, end, mid, 3)
    return mainArr

def mergeArr(mainArr, auxArr, start, mid, end):
    left = start
    right = mid+1
    while left <= mid and right <= end:
        if auxArr[left] <= auxArr[right]:
            mainArr[start]=auxArr[left]
            left+=1
        else:
            mainArr[start]=auxArr[right]
            right+=1
        start+=1
    while left <= mid:
        mainArr[start]=auxArr[left]
        left+=1
        start+=1
    while right <= end:
        mainArr[start]=auxArr[right]
        right+=1
        start+=1
    return mainArr

# O(nlogn) time
# O(n) space
def mergeSort(arr):
    auxArr = arr.copy()
    return arrDivider(arr, auxArr, 0, len(arr)-1)
    
print(mergeSort([8,5,2,9,5,6,3]))