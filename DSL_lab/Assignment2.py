def LongestWord():
    sentence = input("Enter sentence: ")

    # Finding longest word
    longest = max(sentence.split(), key=len)

    # Displaying longest word
    print("Longest word is: ", longest)
    print("And its length is: ", len(longest))


def Frequency():
    string = input("Enter the string: ")
    char = input("Please enter the char to find frequency of the character\n")
    count = 0
    for i in range(len(string)):
        if (string[i] == char):
            count = count + 1
    print(count)



def Palindrome():
    str = input("\n Enter some string: ")
    if (str == str[::-1]):
        print("\n The given string is palindrome")
    else:
        print("\n The given string is not palindrome")


def Find_Substr():
    str = input("\n Enter some statement: ")
    word = input("\n Enter the substring to be searched: ")
    #if word in str:
        #print("found")
   # else:
        #print("not found")
    for i in range(len(str) - len(word) + 1):
        if (str[i:i + len(word)] == word):
            return i
    return 'Not Found'


def OccurWords():
    str = input("\n Enter some statement: ")
    counts = dict()
    words = str.split()
    for word in words:
        if word in counts:
            counts[word] += 1
        else:
            counts[word] = 1
    print(counts)


# Driver code
print("\n Program for String operations")
while (True):
    print("\n 1. To display word with the longest length")
    print("\n 2. To determine the frequency of occurrence of particular character in the string")
    print("\n 3. To check whether given string is palindrome or not")
    print("\n 4. To display index of first appearance of the substring")
    print("\n 5. To count the occurrences of each word in a given string")
    print("\n Enter your choice")
    choice = int(input())
    if (choice == 1):
        LongestWord()
    elif (choice == 2):
        Frequency()
    elif (choice == 3):
        Palindrome()
    elif (choice == 4):
        print(Find_Substr())
    elif (choice == 5):
        OccurWords()
    else:
        print("thank you")
        break