#include <stdio.h>

/*


How to Identify Unique Words in buildTables

Start with empty wordTable and countTable.

For each word in the input:

Search through wordTable from the start to see if this word already exists:

Compare the current input word with every word in wordTable.

If you find a match:

Increment the corresponding count in countTable.

Stop searching (this word is NOT unique this time).

If you don’t find a match:

Add the word to the end of wordTable.

Set the corresponding count in countTable to 1.

Repeat until you reach the sentinel word (0), which marks the end of input.

Return the total number of unique words you found (size of wordTable and countTable).

---------------------------------------------------------------------------------------------

Example in simple terms

Input: [cat, dog, cat, fish, dog, dog, 0]

Read cat → not found in wordTable → add to wordTable[0], set countTable[0] = 1

Read dog → not found → add to wordTable[1], set countTable[1] = 1

Read cat → found at index 0 → increment countTable[0] to 2

Read fish → not found → add to wordTable[2], countTable[2] = 1

Read dog → found at index 1 → increment countTable[1] to 2

Read dog → found at index 1 → increment countTable[1] to 3

Read 0 → stop.

Result:
wordTable = [cat, dog, fish]
countTable = [2, 3, 1]
*/




void BuildTable(void);


int main(void){
    
    return 0;
}

