#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;

}node;


int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            //Free memory so far
            return 1;
        }
        n->number = number;
        n->next = list;
        list = n;
    }

    // print the whole list. by creating a pointer which points to node and the block of memory which has the number of the list:
    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}

// Note: what we are doing here is that we want to create a list which can store data in a sequential way,
//so that we can know the address of the next stored data on the memory. how to do it?
// the way we do this is to address a chunk of memory from heap, to be available for us so that we store the address of the next data on memory, on it.
// this way we can have a trace of where the next data is stored.

// by creating a "Typedef" of a node and addressing the next cell of the memory in it as an integer:


//  typedef struct node
// {
//    int number;
//    struct node *next;
// } node;


// then by creating this "list" as "node *list = NULL;" we create a list which points to the node's address

// HINT: this  "int main(int argc, char *argv[])" helps us to add integers or characters when executing the file on memory like:

// ./list1 1 2 3 4

// this will act as an input like "get_int(""); or get_string("");"

// next step is to allocate a chunk of memory for our next place on the memory (form Heap) to add the numbers and the addresses on it:
//    node *n = malloc(sizeof(node));

// now, if n is not NULL, then we can set "n" as "number" so that the list is pointing at the number field.
// By saying: "n go to number and set it as the number which we typed on "  int number = atoi(argv[i]);" the code is n -> number = number

// now we make the chunk of memory for Next, as NULL so that we don't leak memory:   "n->next = NULL;"
// BUT, we cannot yet say, that "list = n;" why? because this will make the list to point at the new block of memory which is the new number which we typed
// and we will create a memory leak by orphaning the previous block and pointing to the new block.
// SOLUTION: we should point the node (n) of Next to the address of the previous place which the list was pointing at,
// and then, change the list to the new node (n):

// n->next = list;
// list = n;

