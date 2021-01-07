#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
/*
 *
 */
typedef struct {
    Node *head;
    Node *tail;
} DoublyLinkedList;

/*
 *
 */
void reverse(DoublyLinkedList *list);

void deleteEnd(DoublyLinkedList *list);

void deleteBeginning(DoublyLinkedList *list);

void insert(DoublyLinkedList *list, int i, int value);

void addBeginning(DoublyLinkedList *list, int value);

void testSum();

void testDifference();

void testAreEqual();

void testPalindrome();

void testConcatenate();

void testConcatenate3(DoublyLinkedList *list1, DoublyLinkedList *list2);

void testConcatenate2(DoublyLinkedList *list1);

void testConcatenate1(DoublyLinkedList *list1);

DoublyLinkedList *convertArrayToDoublyLinkedList(int array[], int size);

void destroy(DoublyLinkedList *list);

DoublyLinkedList *copy(DoublyLinkedList *list);

void concatenate(DoublyLinkedList *list1, DoublyLinkedList *list2);

DoublyLinkedList *getDifferenceBetweenLists(DoublyLinkedList *list1, DoublyLinkedList *list2);

int checkSumofFirstHalfEqualSumOfSecondHalf(DoublyLinkedList *list);

int isPalindrome(DoublyLinkedList *list);

int areEqual(DoublyLinkedList *list1, DoublyLinkedList *list2);

void Investigate(char *title, DoublyLinkedList *list);

DoublyLinkedList *init();

Node *newNode(int value);

int get(DoublyLinkedList *list, int i);

void addEnd(DoublyLinkedList *list, int value);

void printlnListForward(DoublyLinkedList *list);

void printlnListBackward(DoublyLinkedList *list);

size_t length(DoublyLinkedList *list);


int main() {
   /* testConcatenate();
    testPalindrome();
    testAreEqual();
    testDifference();
    testSum();*/
   DoublyLinkedList *l1=init();
   DoublyLinkedList *l2=init();
   addEnd(l1,2);
    addEnd(l1,4);
    addEnd(l1,7);
    addEnd(l1,9);
    addEnd(l1,11);
    addEnd(l2,2);
    addEnd(l2,6);
    addEnd(l2,7);
    addEnd(l2,8);
    addEnd(l2,10);
    addEnd(l2,11);
    printlnListForward(getDifferenceBetweenLists(l1,l2));




    return 0;
}


DoublyLinkedList *init() {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node *newNode(int value) {
    Node *n = malloc(sizeof(Node));
    n->data = value;
    n->next = n->prev = NULL;
    return n;
}

void addEnd(DoublyLinkedList *list, int value) {
    Node *n = newNode(value);
    if (!list->head)
        list->head = list->tail = n;
    else {
        list->tail->next = n;
        n->prev = list->tail;
        list->tail = n;
    }

}

int get(DoublyLinkedList *list, int i) {
    Node *n = list->head;
    int j;
    if (n) {
        if (i < length(list)) {
            for (j = 0; j < i; j++)
                n = n->next;
            return n->data;
        } else {
            printf("out of bounds index\n");
            exit(-1);
        }
    } else {
        printf("List is empty");
    }
    return -1;
}


/*
 * convertArrayToDoublyLinkedList
 */
DoublyLinkedList *convertArrayToDoublyLinkedList(int array[], int size) {
    DoublyLinkedList *list = init();
    int i;
    for (i = 0; i < size; i++) {
        addEnd(list, array[i]);
    }
    return list;
}

/*
 * destroy
 */
void destroy(DoublyLinkedList *list) {
    Node *n = list->head;
    while (n) {
        Node *temp = n->next;
        free(n);
        n = temp;
    }
    list->head = list->tail = NULL;
}

/*
 * copy: copy list into a new list and return the new one.
 */
DoublyLinkedList *copy(DoublyLinkedList *list) {
    DoublyLinkedList *newlist = init();
    Node *temp = list->head;
    while (temp != NULL) {
        addEnd(newlist, temp->data);
        temp = temp->next;
    }
    return newlist;
}

/*
 * concatenate: concatenates the second list to the first one
 */
void concatenate(DoublyLinkedList *list1, DoublyLinkedList *list2) {

    if (!list2->head)
        return;
    if (list1->head) {
        list1->tail->next = list2->head;
        list2->head->prev = list1->tail;
        list1->tail = list2->tail;
    } else {
        list1->head = list2->head;
        list1->tail = list2->tail;
    }
}

/*
 * getDifferenceBetweenLists: get all elements in the first list that don't exist in  the second one.
 */
/*DoublyLinkedList *getDifferenceBetweenLists(DoublyLinkedList *list1, DoublyLinkedList *list2) {
    DoublyLinkedList *newlist = init();
    int i, j, allowed;
    for (i = 0; i < length(list1); i++) {
        allowed = 1;
        for (j = 0; j < length(list2); j++) {
            if (get(list1, i) == get(list2, j))
                allowed = 0;
        }
        if (allowed)
            addEnd(newlist, get(list1, i));
    }
    return newlist;
}*/
List *getDupes(List *l1, List *l2) {
    List *l3 = init();
    Node *temp1 = l1->head;
    Node *temp2 = l2->head;
    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
                addEnd(l3,temp1->data);
                temp2 = temp2->next;
                temp1=temp1->next;
        } else if(temp1->data>temp2->data){
                temp2 = temp2->next;
               }
        else{temp1=temp1->next;}
    }

    return l3;
}

/*
 * checkSumofFirstHalfEqualSumOfSecondHalf: check  if sum of first n/2 elements equals sum of the last n/2 elements.
 */
int checkSumofFirstHalfEqualSumOfSecondHalf(DoublyLinkedList *list) {
    int sumFirstHalf = 0;
    int sumSecondHalf = 0;
    int i;
    for (i = 0; i < length(list) / 2; i++)
        sumFirstHalf += get(list, i);
    for (i = length(list) / 2; i < length(list); i++)
        sumSecondHalf += get(list, i);
    return sumFirstHalf == sumSecondHalf ? 1 : 0;
}

/*
 * length: count the number of items stored in the list
 */
size_t length(DoublyLinkedList *list) {
    size_t count = 0;
    Node *n = list->head;
    while (n) {
        count++;
        n = n->next;
    }
    return count;
}


/* isPalindrome: returns 1 if list is palindrome
*               returns 0 if list is not palindrome
*               a palindrome prints forwards as backwards
*               e.g., 1 2 3 2 1
*               e.g., 1 2 3 3 2 1*/


int isPalindrome(DoublyLinkedList *list) {
    Node *temp1 = list->head;
    Node *temp2 = list->tail;
    while (temp1 != NULL) {
        if (temp1->data != temp2->data)
            return 0;
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    return 1;
}


/* areEqual: returns 1 if both lists contain same elements
        *               returns 0 otherwise
*/
int areEqual(DoublyLinkedList *list1, DoublyLinkedList *list2) {
    int i;
    if (length(list1) != length(list2))
        return 0;
    for (i = 0; i < length(list1); i++) {
        if (get(list1, i) != get(list2, i))
            return 0;
    }
    return 1;
}

/*
 * printlnListForward: prints the list {1, 3, 5, 7} as 1 3 5 7
 *                    prints end of line at the end
 */
void printlnListForward(DoublyLinkedList *list) {
    Node *n = list->head;
    printf("[ ");
    if (n) {
        while (n) {
            printf("%d ", n->data);
            n = n->next;
        }
    } else
        printf("empty list ");
    printf("]\n");

}


/*
 * printlnListBackward: prints the list {1, 3, 5, 7} as 7 5 3 1
 *                    prints end of line at the end
 */
void printlnListBackward(DoublyLinkedList *list) {
    Node *n = list->tail;
    printf("[ ");
    if (n) {
        while (n) {
            printf("%d ", n->data);
            n = n->prev;
        }
    } else
        printf("empty list ");
    printf("]\n");
}

/*
 *
 */
void Investigate(char *title, DoublyLinkedList *list) {
    printf("%s\n", title);
    printf("List =         ");
    printlnListForward(list);
    printf("Reverse List = ");
    printlnListBackward(list);
    printf("List Length = %u\n", length(list));
    printf("List isPalindrome = %d\n", isPalindrome(list));
    printf("...................................................\n");
}

/*
 *
 */
void testConcatenate1(DoublyLinkedList *list1) {
    puts("\nSTART testConcatenate1\n");
    DoublyLinkedList *EmptyList = init();
    DoublyLinkedList *list3, *emptyList1;
    list3 = copy(list1);
    Investigate("List3 = copy(List1)\n==================", list3);
    emptyList1 = copy(EmptyList);
    Investigate("EmptyList1 = copy(EmptyList)\n===========================", EmptyList);
    concatenate(list3, emptyList1);
    Investigate("List3<->EmptyList1\n==========================", list3);
    destroy(list3);
    Investigate("List3 (after destroy)\n=====================", list3);
    destroy(emptyList1);
    puts("\nEND testConcatenate1\n");
}

/*
 *
 */
void testConcatenate2(DoublyLinkedList *list1) {
    puts("\nSTART testConcatenate2\n");
    DoublyLinkedList *EmptyList = init();
    DoublyLinkedList *list3, *emptyList1;
    list3 = copy(list1);
    Investigate("List3 = copy(List1)\n==================", list3);
    emptyList1 = copy(EmptyList);
    Investigate("EmptyList1 = copy(EmptyList)\n===========================", EmptyList);
    concatenate(emptyList1, list3);
    Investigate("EmptyList1<->List3\n==========================", emptyList1);
    destroy(emptyList1);
    Investigate("EmptyList1 (after destroy)\n=====================", emptyList1);
    puts("\nEND testConcatenate2\n");

}

/*
 *
 */
void testConcatenate3(DoublyLinkedList *list1, DoublyLinkedList *list2) {
    puts("\nSTART testConcatenate3\n");
    DoublyLinkedList *list3, *list4;
    list3 = copy(list1);
    Investigate("List3 = copy(List1)\n==================", list3);
    list4 = copy(list2);
    Investigate("list4 = copy(List2)\n==================", list4);
    concatenate(list3, list4);
    Investigate("List3<->List4\n=====================", list3);
    destroy(list3);
    Investigate("list3 (after destroy)\n=====================", list3);
    puts("\nEND testConcatenate3\n");

}

/*
 *
 */
void testConcatenate() {
    int array1[] = {0, 1, 2, 3, 4, 5, 6};
    int array2[] = {7, 8, 9};

    DoublyLinkedList *list1 = convertArrayToDoublyLinkedList(array1, sizeof(array1) / sizeof(*array1));
    Investigate("List1\n=====", list1);
    DoublyLinkedList *list2 = convertArrayToDoublyLinkedList(array2, sizeof(array2) / sizeof(*array2));
    Investigate("List2\n=====", list2);

    testConcatenate1(list1);
    testConcatenate2(list1);
    testConcatenate3(list1, list2);

    destroy(list1);
    destroy(list2);
}

/*
 *
 */
void testPalindrome() {
    puts("\nSTART testPalindrome\n");
    int array3[] = {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0};
    int array4[] = {7, 8, 9, 9, 8, 7};

    DoublyLinkedList *list5 = convertArrayToDoublyLinkedList(array3, sizeof(array3) / sizeof(*array3));
    Investigate("List5\n=====", list5);
    DoublyLinkedList *list6 = convertArrayToDoublyLinkedList(array4, sizeof(array4) / sizeof(*array4));
    Investigate("List6\n=====", list6);

    destroy(list5);
    destroy(list6);
    puts("\nEND testPalindrome\n");

}

/*
 *
 */
void testAreEqual() {
    puts("\nSTART testAreEqual\n");
    int array7[] = {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0};
    int array8[] = {7, 8, 9, 9, 8, 7};
    int array9[] = {0, 1, 2, 3, 4, 5};
    DoublyLinkedList *EmptyList = init();
    DoublyLinkedList *list7 = convertArrayToDoublyLinkedList(array7, sizeof(array7) / sizeof(*array7));
    Investigate("List7\n=====", list7);
    DoublyLinkedList *list8 = convertArrayToDoublyLinkedList(array8, sizeof(array8) / sizeof(*array8));
    Investigate("List8\n=====", list8);
    DoublyLinkedList *list9 = convertArrayToDoublyLinkedList(array9, sizeof(array9) / sizeof(*array9));
    Investigate("List9\n=====", list9);
    DoublyLinkedList *emptyList1 = copy(EmptyList);
    Investigate("EmptyList1 = copy(EmptyList)\n===========================", emptyList1);
    DoublyLinkedList *emptyList2 = copy(EmptyList);
    Investigate("EmptyList2 = copy(EmptyList)\n===========================", emptyList2);

    printf("areEqual(list7, list7) = %d\n", areEqual(list7, list7));
    printf("areEqual(list7, list8) = %d\n", areEqual(list7, list8));
    printf("areEqual(list7, list9) = %d\n", areEqual(list7, list9));
    printf("areEqual(list8, list7) = %d\n", areEqual(list8, list7));
    printf("areEqual(list7, EmptyList1) = %d\n", areEqual(list7, emptyList1));
    printf("areEqual(EmptyList1, list7) = %d\n", areEqual(emptyList1, list7));
    printf("areEqual(EmptyList1, EmptyList2) = %d\n", areEqual(emptyList1, emptyList2));

    destroy(list7);
    destroy(list8);
    destroy(list9);
    puts("\nEND testAreEqual\n");

}

/*
 *
 */
void testDifference() {
    puts("\nSTART testDifference\n");
    int array10[] = {2, 4, 8, 9, 13, 17, 20};
    int array11[] = {2, 8, 17, 20};
    DoublyLinkedList *list10 = convertArrayToDoublyLinkedList(array10, sizeof(array10) / sizeof(*array10));
    Investigate("list10\n=====", list10);
    DoublyLinkedList *list11 = convertArrayToDoublyLinkedList(array11, sizeof(array11) / sizeof(*array11));
    Investigate("List11\n=====", list11);
    DoublyLinkedList *list12 = getDifferenceBetweenLists(list10, list11);
    Investigate("list12\n=====", list12);
    destroy(list10);
    destroy(list11);
    destroy(list12);
    puts("\nEND testDifference\n");

}

void testSum() {
    puts("\nSTART testSum\n");
    int array5[] = {12, 4, 8, 9, 13, 2};
    int array6[] = {2, 18, 17, 4};
    int array7[] = {2, 3, 4};
    DoublyLinkedList *list13 = convertArrayToDoublyLinkedList(array5, sizeof(array5) / sizeof(*array5));
    Investigate("list13\n=====", list13);
    DoublyLinkedList *list14 = convertArrayToDoublyLinkedList(array6, sizeof(array6) / sizeof(*array6));
    Investigate("list14\n=====", list14);
    DoublyLinkedList *list15 = convertArrayToDoublyLinkedList(array7, sizeof(array7) / sizeof(*array7));
    Investigate("list15\n=====", list15);
    printf("checkSumofFirstHalfEqualSumOfSecondHalf(list13) = %d\n", checkSumofFirstHalfEqualSumOfSecondHalf(list13));
    printf("checkSumofFirstHalfEqualSumOfSecondHalf(list14) = %d\n", checkSumofFirstHalfEqualSumOfSecondHalf(list14));
    printf("checkSumofFirstHalfEqualSumOfSecondHalf(list15) = %d\n", checkSumofFirstHalfEqualSumOfSecondHalf(list15));

    destroy(list13);
    destroy(list14);
    destroy(list15);
    puts("\nEND testSum\n");
}

void reverse(DoublyLinkedList *list) {
    DoublyLinkedList *tempList = init();
    Node *temp = list->head;
    while (temp != NULL) {
        addEnd(tempList, temp->data);
        temp = temp->next;
    }
    destroy(list);
    temp = tempList->tail;
    while (temp != NULL) {
        addEnd(list, temp->data);
        temp = temp->prev;
    }
}

void deleteBeginning(DoublyLinkedList *list) {
    if (list->head) {
        Node *temp = list->head;
        if (!temp->next) {
            list->tail = list->head = NULL;
        } else {
            list->head = temp->next;
            list->head->prev = NULL;
            free(temp);
        }

    }

}

void insert(DoublyLinkedList *list, int i, int value) {
    Node *temp = list->head;
    Node *previous;
    int j;
    if (i == length(list))
        addEnd(list, value);

    else if (!i) {
        addBeginning(list, value);
    } else if (i > length(list)) {
        printf("out of bounds index at insert");
        exit(-1);
    } else {
        for (j = 0; j < i; j++) {
            previous = temp;
            temp = temp->next;
        }
        Node *n = newNode(value);
        previous->next = n;
        temp->prev = n;
        n->next = temp;
        n->prev = previous;
    }
}

void deleteEnd(DoublyLinkedList *list) {
    if (list->head) {
        Node *temp = list->tail;
        if (!list->head->next) {
            list->tail = list->head = NULL;
        } else {
            list->tail = list->tail->prev;
            list->tail->next = NULL;
        }
        free(temp);
    }
}

void addBeginning(DoublyLinkedList *list, int value) {
    Node *n = newNode(value);
    if (!list->head)
        list->head = list->tail = n;
    else {
        list->head->prev = n;
        n->next = list->head;
        list->head = n;
    }
}

