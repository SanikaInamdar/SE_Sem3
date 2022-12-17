no_rows_A = int(input("Enter number of rows in matrix A:- "))
no_columns_A = int(input("Enter number of columns in matrix A:- "))
A = []   # For storing the first input matrix from user
for row in range(no_rows_A):
    a = []   # matrix for adding column entries of every row
    for column in range(no_columns_A):
        a.append(int(input(f"Enter the element for [{row}][{column}]:- ")))
    A.append(a)

no_rows_B = int(input("Enter number of rows in matrix B:- "))
no_columns_B = int(input("Enter number of columns in matrix B:- "))
B = []      # For storing the second input matrix from user
for row in range(no_rows_B):
    b = []       # matrix for adding column entries of every row
    for column in range(no_columns_B):
        b.append(int(input(f"Enter the element for [{row}][{column}]:- ")))
    B.append(b)

def add_matrix():
    add = 0
    if no_rows_A == no_rows_B and no_columns_A == no_columns_B:     # condition for addition of 2 matrices

        output = []     # matrix to store the final result
        for i in range(no_rows_A):
            x = []      # matrix to store the added elements of a single row
            for j in range(no_columns_A):
                add = A[i][j] + B[i][j]     # addition of elements of matrices at position i and j respectively
                x.append(add)
            output.append(x)
        for row in range(no_rows_A):
            print(output[row])
    else:
        print("Matrix addition not possible!")

def sub_matrix():
    sub = 0
    if no_rows_A == no_rows_B and no_columns_A == no_columns_B:     # condition for subtraction of 2 matrices
        output = []     # matrix to store the final result
        for i in range(no_rows_A):
            mat = []        # matrix to store the subtracted elements of a single row
            for j in range(no_columns_A):
                sub = A[i][j]-B[i][j]        # subtraction of elements of matrices at position i and j respectively
                mat.append(sub)

            output.append(mat)
        for row in range(len(output)):
            print(output[row])

    else:
        print("Matrix Subtraction is not possible")

def multiplication_matrix():
    if no_rows_B == no_columns_A:       # condition for multiplication of 2 matrices
        result = []
        for i in range(no_rows_A):
            mul = []
            for j in range(no_columns_B):
                mul.append(0)
            result.append(mul)      # an empty matrix(null matrix) of required order is created
        for i in range(no_rows_A):
            for j in range(no_columns_B):
                for k in range(no_rows_B):
                    result[i][j] += A[i][k] * B[k][j]     # multiplication and storing the result in i and j positions of result mqatrix
        for row in range(len(result)):
            print(result[row])
    else:
        print("Matrix multiplication not possible!")

def transpose_matrix():
    print("Transpose of matrix A:")
    transpose = []
    for i in range(no_columns_A):   # starting from columns instead of rows
        elem = []
        for j in range(no_rows_A):
            elem.append(0)
        transpose.append(elem)      # an empty matrix(null matrix) of required order is created

    for i in range(no_columns_A):
        for j in range(no_rows_A):
            transpose[i][j] = A[j][i]    # copying elements of orignal matrix A to transpose matrix at the required position
    for row in range(len(transpose)):
        print(transpose[row])       # printing transpose matrix

    print("Transpose of matrix B:")
    transpose = []
    for i in range(no_columns_B):       # starting from columns instead of rows
        elem = []
        for j in range(no_rows_B):
            elem.append(0)
        transpose.append(elem)       # an empty matrix(null matrix) of required order is created

    for i in range(no_columns_B):
        for j in range(no_rows_B):
            transpose[i][j] = B[j][i]       # copying elements of orignal matrix A to transpose matrix at the required position
    for row in range(len(transpose)):
        print(transpose[row])       # printing transpose matrix

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
        add_matrix()

    # Code for subtraction of two matrices
    elif choice == 2:
        sub_matrix()
    # Code for multiplication of two matrices
    elif choice == 3:
        multiplication_matrix()

    # Code for transpose of a matrix
    elif choice == 4:
        transpose_matrix()
    else:
        print("Please enter a valid choice!")
    y_n = input("\nDo you wish to continue? y/n:- ")
    if y_n.lower() == "n":
        print("\nThank you!")
        break