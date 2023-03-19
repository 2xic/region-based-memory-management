Saw this [tweet](https://twitter.com/jarredsumner/status/1635351881789865985) by Jarred Sumner.

Exercise: implement a simple [region-based memory management](https://en.wikipedia.org/wiki/Region-based_memory_management) with the features

Example interface from wikipedia
```c
Region *r = createRegion();
ListNode *head = NULL;
for (int i = 1; i <= 1000; i++) {
    ListNode* newNode = allocateFromRegion(r, sizeof(ListNode));
    newNode->next = head;
    head = newNode;
}
// ...
// (use linked list here)
// ...
destroyRegion(r);
```
