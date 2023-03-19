#include "Region.h"
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

int main(){
    Region *r = createRegion();
    ListNode *head = NULL;
    for (int i = 1; i <= 1000; i++)
    {
        ListNode *newNode = (ListNode*)allocateFromRegion(r, sizeof(ListNode));
        newNode->val = i;
        newNode->next = head;
        head = newNode;
    }
    // ...
    // (use linked list here)
    while (head != NULL){
        printf("%i ", head->val);
        head = head->next;
    }
    printf("\n");
    // ...
    destroyRegion(r);
}
