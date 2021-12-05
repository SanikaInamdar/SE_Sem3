
def diag_check():
    c=0
    for i in range(no_rows_A):
        for j in range(no_columns_A):
            if(i==j and A[i][j]!=0):
                continue
            elif(i!=j and A[i][j]==0):
                continue
            else:
                c=c+1
                break

    if(c>=1):
        print("The input matrix is not a Diagonal Matrix")
    else:
        print("The input matrix is Diagonal Matrix")



while (True):
    no_rows_A = int(input("Enter number of rows in matrix A:- "))
    no_columns_A = int(input("Enter number of columns in matrix A:- "))
    A = []  # For storing the first input matrix from user
    if(no_rows_A==no_columns_A):
        for row in range(no_rows_A):
            a = []  # matrix for adding column entries of every row
            for column in range(no_columns_A):
                a.append(int(input(f"Enter the element for [{row}][{column}]:- ")))
            A.append(a)
        print("\nMatrix A is")
        for row in range(no_rows_A):
            print(A[row])
        diag_check()
    else:
        print("enter N*N matrix ")
    flag = input("do you want to continue? (y/n)")
    if (flag == "n"):
        print("thank you")
        break



