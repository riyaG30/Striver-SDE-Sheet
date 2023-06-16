 Node* rev(Node* head, int m, int n)
{
    if (head == NULL)
        return NULL;

    int cnt = 1;
    Node* pre = NULL;
    Node* curr = head;

    // Move the pointer to the m-th node
    while (curr != NULL && cnt < m) {
        pre = curr;
        curr = curr->next;
        cnt++;
    }

    Node* start = pre; // Node before the reversed section
    Node* revStart = curr; // Start of the reversed section

    // Reverse the portion from m to n
    while (curr != NULL && cnt <= n) {
        Node* next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        cnt++;
    }

    // Connect the reversed portion to the remaining part
    if (start != NULL)
        start->next = pre;
    else
        head = pre; // If m = 1, update the head to the new start

    revStart->next = curr; // Connect the end of reversed portion to the remaining part

    return head;
}

Node* reverseBetween(Node* head, int m, int n)
{
    // Code here
    return rev(head, m, n);
}
