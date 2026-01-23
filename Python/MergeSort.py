# Merge sort is a popular sorting algorithm known for its efficiency and stability.
# It follows the Divide and Conquer approach. 
# It works by recursively dividing the input array into two halves, 
# recursively sorting the two halves and finally merging them back 
# together to obtain the sorted array.
 

def mergesort(array):

    if len(array) <= 1:
        return array
    
    mid = len(array) // 2 
    left = mergesort(array[:mid])
    right = mergesort(array[mid:])

    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0


    while (i < len(left) and (j < len(right))):
        if(left[i] < right[j]):
            result.append(left[i])
            i+=1
        elif(left[i] > right[j]):
            result.append(right[j])
            j+= 1
    
    result.extend(left[i:])
    result.extend(right[j:])

    return result


if __name__ == "__main__":
    array = [5,1,4,6,2,9,10,8,7,3,11]
    
    for i in range(len(array)):
        print(f"{i} : {array[i]} ")
    print("\n")
    result = mergesort(array)
    for i in range(len(result)):
         print(f"{result[i]} ")
    print("\n")
    

