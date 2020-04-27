# definition
# Operations
#  + push()
#  + pop()
#  + isEmpty()

# Stack using array is simple if  elemets are fixed in number:
# + In general programming language, create an array
# + Start filling from start for push() operation
# + When deleting or retriving using pop() start retrival & deletion from end of array

array_stack = []


def array_push(element):
    global array_stack
    array_stack.append(element)
    print("Array Stack is: \n")
    for i in range(len(array_stack)-1, -1, -1):
        print("| ", str(array_stack[i]), "| ")
    print("\n")


def array_pop():
    global array_stack
    if(len(array_stack) == 0):
        print("****Stack is empty*****")
        return 0
    print("Deleting")
    array_stack.pop()
    print("Array Stack is: \n")
    for i in range(len(array_stack)-1, -1, -1):
        print("| ", str(array_stack[i]), "| ")
    print("\n")


if __name__ == "__main__":
    Exit = False
    print("Choose option:")
    while not Exit:
        print("1.Push\n2.Pop\n3.Exit: ")
        option = input()
        if(int(option) == 3):
            Exit = True
        elif(int(option) == 1):
            array_push(int(input('Enter element to add to stack: ')))
        elif(int(option) == 2):
            array_pop()
        else:
            continue

