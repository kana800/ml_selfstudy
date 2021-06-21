"""External Sort Algorithm, which sort large files, based on mergesort
"""

def merge(l,r):
    i = j = k = 0

    while i < len(l) and j < len(r):
        if l[i] < r[j]:
            arr[k] = l[i]
            i += 1
        else:
            arr[k] = r[j]
            j += 1
        k += 1

    # checking for elements that is left in the arrays
    while i < len(l):
        arr[k] = l[i]
        i += 1
        k += 1

    while j < len(r):
        arr[k] = r[j]
        j += 1
        k += 1

    return arr


def mergesort(arr):
    """
    desc: sorting algorithm
    args:
        arr -> array
    """
    if len(arr) > 1:
        mid = len(arr) // 2
        leftsubarray = arr[:mid]
        rightsubarray= arr[mid:]

        l = mergesort(leftsubarray)
        r = mergesort(rightsubarray)

        return merge(l,r)


if __name__ == "__main__":
    arr = [5,6,3,4,5,8]
    print(arr)

    arr = mergesort(arr)

    print(arr)
