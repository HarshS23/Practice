# Binary search algorithm 

# Binary Search is a searching algorithm that operates on a sorted 
# or monotonic search space, repeatedly dividing it into halves to 
# find a target value or optimal answer in logarithmic time O(log N).



def BinarySearch(array, key):

    low = 0
    high = len(array) - 1
    
    while low <= high:
        mid = low + (high - low) // 2 

        if(array[mid] == key): # if array[mid] == key then just return mid 
            return mid
        
        elif(key > array[mid]):        # if the key > mid --> low becomed mid + 1 
            low = mid + 1    
        
        elif(key < array[mid]): 
            high = mid - 1      # if the key < mid --> high = mid - 1 
    
    return -1                   # not found in the array 

# recursive version 

def BinSearchr(array, low, high, key):
    # base case 
    if low > high: # not found or missinput 
        SyntaxError(f"Low cannot be greater than high")
        return -1 
    
    mid = low + (high - low) // 2 

    # recursive cases
    if(key == array[mid]):
        return mid
    elif(array[mid] < key):
        return BinSearchr(array, mid + 1, high, key)
    elif(array[mid] > key):
        return BinSearchr(array, low, mid -1, key)


if __name__ == "__main__":
    array = [1,2,3,4,5,6,7,8,9,10,11]
    x = BinSearchr(array, 0, len(array) - 1 ,8)
    print(f"This is the Index in array: {x}\nValue: {array[x]}\n")
