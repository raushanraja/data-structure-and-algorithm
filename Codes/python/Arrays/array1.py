# Delcarations of arrays
# Operations
#   + length
#   + append
#   + insert
#   + delete
#   + lookup at given index
#   + search


array_Of_Names =['Ram','Shyam', 'Mohan'] 


# length

def getlength(array_Of_Names):
    count = 0
    for i in array_Of_Names:
        count+=1
    return count


def append_at_last(array_Of_Names,item):
    array_Of_Names.append(item)
    return array_Of_Names

def insert_at_index(array_Of_Names,item,position):
    array_length = getlength(array_Of_Names)

    if(array_length< position):
        array_Of_Names.append(item)
        return array_Of_Names
    if(position<0):
        position = 0
    array_Of_Names.append(array_Of_Names[array_length-1])

    for i in range(position+1,array_length):
        array_Of_Names[i] = array_Of_Names[i-1]
    array_Of_Names[position] = item
    return array_Of_Names


def delete(array_Of_Names,position):
    array_length = getlength(array_Of_Names)
    if(array_length<=0):
        array_Of_Names = []
        return array_Of_Names
    if(position>=array_length-1):
        array_Of_Names.pop()
        return array_Of_Names
    for i in range(position,array_length-1):
        array_Of_Names[i] = array_Of_Names[i+1]
    array_Of_Names.pop()
    return array_Of_Names
    


def element_at_index(array_Of_Names,position):
    return array_Of_Names[position-1]

def search():
    # search algorithm implementation
    pass
