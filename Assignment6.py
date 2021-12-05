global count
count = 0
def partition(array, start, end):
    pivot = array[start]
    low = start + 1
    high = end
    while True:
        while low <= high and array[high] >= pivot:
            high = high - 1
        while low <= high and array[low] <= pivot:
            low = low + 1
        if low <= high:
            array[low], array[high] = array[high], array[low]
        else:
            break
    array[start], array[high] = array[high], array[start]
    return high

def quick(arr,low,high,):
    if low < high:
        pi = partition(arr,low,high)
        global count
        count = count + 1
        print("The list after iteration {} is:".format(count), l)
        quick(arr, low, pi-1)
        quick(arr, pi+1, high)
while True:
    a = int(input("Enter the number of students in second year:"))
    if a>5:
        break
    else:
        print("There should atleast be more than 5 students in second year!!!")

l=[]

for i in range(a):
    while True:
        b=float(input("Enter the percentage of student {}:".format(i+1)))
        if(b>=0 and b<=100):
            l.append(b)
            break
        else:
            print("The percentage of a student must lie between 0 to 100!!")
print("The entered percentages are:",l)
print("*"*50)

quick(l, 0, len(l) - 1)
print("The sorted list is:", l)
print("*"*50)
l1=l[::-1]
print("The top 5 scores are:")
for i in range(5):
    print("{})".format(i+1), l1[i])