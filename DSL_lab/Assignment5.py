def InsertionSort(arr):
    i = 1
    n=len(arr)
    c=0
    for i in range(n):
        temp = arr[i]
        j = i - 1
        while ((j >= 0) & (arr[j] > temp)):
            arr[j + 1] = arr[j]
            j = j - 1

        arr[j + 1] = temp
        c=c+1
        print(arr)


    print("sorted list" ,arr)
    print("no. of iterations:",c)
    print("Top Five Scores are:")
    for i in range(len(arr) - 1,len(arr) - 6,-1):
        print(arr[i])


def ShellSort(arr):
    n=len(arr)
    d = n // 2
    c=0
    while d > 0:
        for i in range(d, n):
            temp = arr[i]
            j = i
            while (j >= d and arr[j - d] > temp):
                arr[j] = arr[j - d]
                j -= d

            arr[j] = temp
        d = d // 2
        print(arr)
        c=c+1


    print("the sorted array",arr)
    print("no. of iterations:", c)
    print("Top Five Scores are:")
    for i in range(len(arr) - 1,len(arr) - 6, -1):
        print(arr[i])

    # Driver Code


def input_list():
    array = []
    while True:
        n = int(input("Enter total number of students : "))
        if n < 5:
            print("Enter the number of students greater  5.")

            continue
        print("Enter the percentage of students one by one")
        print("--------------------------------------------------------")

        a = n
        while a > 0:
            percent = float(input("Enter the percentage of student "))
            if (percent > 100 or percent < 0):
                print("Percentage must be between 0 and 100.")
                continue
            else:
                array.append(percent)
            a = a-1
        print("Enter list of percentage: ", array)
        print("--------------------------------------------------------")
        return array



while (True):
    print("Main Menu")
    print("1. Insertion Sort")
    print("2. Shell Sort")
    print("3. Exit")
    print("Enter your Choice: ")
    choice = int(input())
    if (choice == 1):
        student_list = input_list()
        print("The unsorted list is ", student_list)
        print("The sorted Scores are:")
        InsertionSort(student_list)
    elif (choice == 2):
        student_list = input_list()
        print("The unsorted list is ", student_list)
        print("The sorted Scores are:")
        ShellSort(student_list)
    else:
        print("Exitting")
        break
