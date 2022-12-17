groupA = []
groupB = []
groupC = []
total = []
not_cri_bad = []
uni_cri_bad = []


# Function to add student roll numbers to the corresponding lists
def add():
    print("Enter the total number of students in the class")
    T = int(input())
    global total
    for i in range(T):
        total.append(i + 1)

    print("enter the number of students who play cricket")
    C = int(input())
    global groupA
    print("enter the roll no. of students who play cricket")
    for i in range(C):
        cri = int(input("enter roll no"))
        groupA.append(cri)

    print("enter the number of students who play badminton")
    B = int(input())
    global groupB
    print("enter the roll no. of students who play badminton")
    for i in range(B):
        bad = int(input("enter roll no"))
        groupB.append(bad)

    print("enter the number of students who play football")
    F = int(input())
    global groupC
    print("enter the roll no. of students who play football")
    for i in range(F):
        foot = int(input("enter roll no"))
        groupC.append(foot)
    print("Roll numbers of all students:", total)
    print("GROUP-A:(Cricket)", groupA)
    print("GROUP-B:(Badminton)", groupB)
    print("GROUP-C:(Football)", groupC)


# List of students who play cricket and badminton both
def cri_bad():
    global uni_cri_bad
    for i in groupA:
        for j in groupB:
            if i == j:
                uni_cri_bad.append(j)
    print("Roll numbers of all students:", total)
    print("GROUP-A:(Cricket)", groupA)
    print("GROUP-B:(Badminton)", groupB)
    print("GROUP-C:(Football)", groupC)
    print("List of students who play cricket and badminton both are:")
    print(uni_cri_bad)


# List of students who either play cricket or badminton but not both
def cri_bad_notboth():
    global not_cri_bad
    for i in groupA:
        if i not in groupB:
            not_cri_bad.append(i)
    for j in groupB:
        if j not in groupA:
            not_cri_bad.append(j)
    print("Roll numbers of all students:", total)
    print("GROUP-A:(Cricket)", groupA)
    print("GROUP-B:(Badminton)", groupB)
    print("GROUP-C:(Football)", groupC)
    print("List of students who either play cricket or badminton but not both are:")
    print(not_cri_bad)


# List of students who neither play cricket nor badminton
def nei_cri_nor_bad():
    p = []
    s = []

    for i in groupC:
        if i not in groupA:
            s.append(i)
    for j in s:
        if j not in groupB:
            p.append(j)

    print("Roll numbers of all students:", total)
    print("GROUP-A(Cricket):", groupA)
    print("GROUP-B(Badminton):", groupB)
    print("GROUP-C:(Football)", groupC)
    print("Number of students who neither play cricket nor badminton are")
    print(p)
    print(len(p))


# List of students who play cricket and football but not badminton
def cric_foot_not_bad():
    # cric_foot=[]
    final = []
    for i in total:
        if i not in groupB:
            final.append(i)
    # for i in groupA:
    # for j in groupC:
    # if i == j:
    # cric_foot.append(j)

    # for j in cric_foot:
    # if j not in groupB:
    # final.append(j)
    print("Roll numbers of all students:", total)
    print("GROUP-A:(Cricket)", groupA)
    print("GROUP-B:(Badminton)", groupB)
    print("GROUP-C:(Football)", groupC)
    print(" Number of students who play cricket and football but not badminton are:")
    print(final)
    print(len(final))


print("*********INPUT*********")
add()
while (True):
    print("*********MENU*********")
    print("1. List of students who play cricket and badminton both")
    print("2. List of students who either play cricket or badminton but not both")
    print("3. Number of students who neither play cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")
    print("enter choice")
    ch = int(input())
    if (ch == 1):
        cri_bad()

    elif (ch == 2):
        cri_bad_notboth()

    elif (ch == 3):
        nei_cri_nor_bad()

    elif (ch == 4):
        cric_foot_not_bad()

    else:
        print("enter correct choice")
    flag = input("do you want to continue? (y/n)")
    if (flag == "n"):
        print("thank you")
        break

