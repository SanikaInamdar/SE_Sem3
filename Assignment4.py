l=[]
def getinput():
    n=int(input("enter the number of students in class"))
    for i in range(n):
        k=int(input("enter roll no:"))
        l.append(k)

def linear_search():
    c=0
    print("The list: ",l)
    key=int(input("enter roll no. to searched in the list"))
    for i in range(len(l)):
        if(key==l[i]):
            print("the student is present at index",i)
            break;
        else:
            c=c+1
    if(c-1==i):
        print("student not present")

def sentinel_search():
    print("The list: ", l)
    key1 = int(input("enter roll no. to searched in the list"))
    last=l[-1]
    l[-1]=key1
    i=0
    while(key1!=l[i]):
        i=i+1
    l[-1]=last
    if(i<len(l)-1 or key1==l[-1]):
        print("the student is present at index",i)
    else:
        print("student not present")

def binary_search():
   key2 = int(input("enter roll no. to searched in the list"))
   l1=[]
   l1=sorted(l)
   print("sorted list",l1)
   low = 0
   high = len(l1) - 1

   while (low <= high):
       mid = (high + low)//2
       if( l1[mid]<key2):
           low=mid+1
       elif(l1[mid]>key2):
           high=mid-1
       else:
           return mid

   return -1

def fibonacci_search():
    key3 = int(input("enter roll no. to searched in the list"))
    l2 = []
    l2 = sorted(l)
    print("sorted list", l2)

    size = len(l2)

    start = -1

    f0 = 0
    f1 = 1
    f2 = 1
    while (f2 < size):
        f0 = f1
        f1 = f2
        f2 = f1 + f0

    while (f2 > 1):
        index = min(start + f0, size - 1)
        if l2[index] < key3:
            f2 = f1
            f1 = f0
            f0 = f2 - f1
            start = index
        elif l2[index] > key3:
            f2 = f0
            f1 = f1 - f0
            f0 = f2 - f1
        else:
            return index
    if (f1) and (l2[size - 1] == key3):
        return size - 1
    return None

getinput()
while True:

    print("1.Linear Search")
    print("2.Sentinel Search")
    print("3.Binary Search")
    print("4.Fibonacci Search")
    ch=int(input("Enter your choice"))
    if(ch==1):
        linear_search()
    elif(ch==2):
        sentinel_search()
    elif(ch==3):
        value = binary_search()
        if(value!=-1):
            print("the student is present at index",value)
        else:
            print("student not present")
    elif (ch==4):
        value1 = fibonacci_search()
        if (value1 != None):
            print("the student is present at index", value1)
        else:
            print("student not present")
    else:
        print("Please enter a valid choice!")
    y_n = input("\nDo you wish to continue? y/n:- ")
    if y_n.lower() == "n":
        print("\nThank you!")
        break





