"""External Sort Algorithm, which sort large files, based on mergesort
"""
def mergesort(r):
    """
    desc: sorting algorithm
    args:
        arr -> array
    """
    if len(r) > 1:
        middle = len(r) // 2
        leftsubarray = r[:middle]
        rightsubarray= r[middle:]

        mergesort(leftsubarray)
        mergesort(rightsubarray)

        i = 0
        j = 0
        k = 0

        while i < len(leftsubarray) and j < len(rightsubarray):
            if ord(leftsubarray[i][0]) <  ord(rightsubarray[j][0]):
                r[k] = leftsubarray[i]
                i += 1
            else:
                r[k] = rightsubarray[j]
                j += 1
            k += 1

        # remaning elements
        while i < len(leftsubarray):
            r[k] = leftsubarray[i]
            i += 1
            k += 1

        while j < len(rightsubarray):
            r[k] = rightsubarray[j]
            j += 1
            k += 1


if __name__ == "__main__":

    # testing 
    from teststring import string
    from re import sub
    string = sub(r'[^\w\s]',"", string)
    string = string.split()

    mergesort(string)

    print(string)
