/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    Node * nextA;
    Node * currentB;
    
    if(!headA)
        return headB;
    if(!headB)
        return headA;
    for(nextA = headA->next; headA; headA = nextA) {
        Node * prevB = NULL;
        for(currentB = headB; currentB; currentB = currentB->next) {
            if(headA->data <= currentB->data) {
                if(prevB == NULL) {
                    nextA = headA->next;
                    headA->next = currentB;
                    headB = headA;
                    break;
                }
                else {
                    nextA = headA->next;
                    headA->next = currentB;
                    prevB->next = headA;
                    break;
                }
            }
            prevB = currentB;
        }
        if(currentB == NULL) {
            prevB->next = headA;
            nextA = headA->next;
        }
    }
    return headB;
}
