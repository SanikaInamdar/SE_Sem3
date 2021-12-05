no_rows_A = int(input("Enter number of rows in matrix A:- "))
no_columns_A = int(input("Enter number of columns in matrix A:- "))
A = []
for row in range(no_rows_A):
    a = []
    for column in range(no_columns_A):
        a.append(int(input(f"Enter the element for [{row}][{column}]:- ")))
    A.append(a)

no_rows_B = int(input("Enter number of rows in matrix B:- "))
no_columns_B = int(input("Enter number of columns in matrix B:- "))
B = []
for row in range(no_rows_B):
    b = []
    for column in range(no_columns_B):
        b.append(int(input(f"Enter the element for [{row}][{column}]:- ")))
    B.append(b)

def choice1():
    add = 0
    if no_rows_A == no_rows_B and no_columns_A == no_columns_B:

        result = []
        for i in range(no_rows_A):
            mat = []
            for j in range(no_columns_A):
                add = A[i][j] + B[i][j]
                mat.append(add)
            result.append(mat)
        for row in range(no_rows_A):
            print(result[row])
    else:
        print("Matrix addition not possible!")

def choice2():
    sub = 0
    if no_rows_A == no_rows_B and no_columns_A == no_columns_B:
        result = []
        for i in range(no_rows_A):
            mat = []
            for j in range(no_columns_A):
                sub = A[i][j] - B[i][j]
                mat.append(sub)
            result.append(mat)
        for row in range(len(result)):
            print(result[row])
    else:
        print("Matrix subtraction not possible!")

def choice3():
    if no_rows_B == no_columns_A:
        result = []
        for i in range(no_rows_A):
            mul = []
            for j in range(no_columns_B):
                mul.append(0)
            result.append(mul)
        for i in range(no_rows_A):
            for j in range(no_columns_B):
                for k in range(no_rows_B):
                    result[i][j] += A[i][k] * B[k][j]
        for row in range(len(result)):
            print(result[row])
    else:
        print("Matrix multiplication not possible!")

def choice4():
    transpose = []
    for i in range(no_columns_A):
        elem = []
        for j in range(no_rows_A):
            elem.append(0)
        transpose.append(elem)

    for i in range(no_columns_A):
        for j in range(no_rows_A):
            transpose[i][j] = A[j][i]
    for row in range(len(transpose)):
        print(transpose[row])

    transpose = []
    for i in range(no_columns_B):
        elem = []
        for j in range(no_rows_B):
            elem.append(0)
        transpose.append(elem)

    for i in range(no_columns_B):
        for j in range(no_rows_B):
            transpose[i][j] = B[j][i]
    for row in range(len(transpose)):
        print(transpose[row])


# Menu driven code
while True:
    # Printing the matrices
    print("\nMatrix A is")
    for row in range(no_rows_A):
        print(A[row])

    print("\nMatrix B is")
    for row in range(no_rows_B):
        print(B[row])

    # MAIN MENU
    print("""\nMain Menu
1. Addition of two matrices
2. Subtraction of two matrices
3. Multiplication of two matrices
4. Transpose of matrix""")

    choice = int(input("Enter your choice:- "))

    # Code for addition of two matrices
    if choice == 1:
        choice1()

    # Code for subtraction of two matrices
    elif choice == 2:
        choice2()
    # Code for multiplication of two matrices
    elif choice == 3:
        choice3()

    # Code for transpose of a matrix
    elif choice == 4:
       choice4()
    else:
        print("Please enter a valid choice!")
    y_n = input("\nDo you wish to continue? y/n:- ")
    if y_n.lower() == "n":
        print("\nThank you!")
        break