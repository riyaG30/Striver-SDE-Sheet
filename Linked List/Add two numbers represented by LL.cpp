  public:
    //Function to add two numbers represented by linked list.
    struct Node* reverseList(struct Node* list)
{
    Node *prev = NULL, *cur = list, *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverseList(first);
    second = reverseList(second);
 
    int carry = 0;
    Node *head = NULL, *prev = NULL;
    Node* sum = NULL;
    // if any one of these is left we are still left with addition
    while (first != NULL or second != NULL or carry == 1)
    {
        int newVal = carry;
        if (first)
            newVal += first->data;
        if (second)
            newVal += second->data;
        // to be used in the next node calculation
        carry = newVal / 10;
        newVal = newVal % 10;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newVal;
        // appending in the beginning of the final ans list,
        // this way we do not have to reverse in the end
        newNode->next = sum;
        sum = newNode;
        // initialising nodes for next iteration
 
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
 
    return sum;
        
    }
