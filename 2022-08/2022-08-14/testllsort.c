struct ListNode *merge_sort(struct ListNode *head);
void head_plugin(struct ListNode **ptr2head, struct ListNode *node);
struct ListNode {
    int val;
    struct ListNode *next;
};

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NODE_NUM 20
struct ListNode *partition(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next;
}
void print_llist(struct ListNode *head);
int main() {
    srand((unsigned)time(NULL));
    struct ListNode nodes[MAX_NODE_NUM];
    nodes[0].val = 0;
    nodes[1].val = 4;
    nodes[2].val = 3;
    nodes[3].val = 5;
    nodes[4].val = -1;
    nodes[5].val = -2;

    nodes[0].next = NULL;
    struct ListNode *head = &nodes[0];

    for (int i = 1; i < 6; i++) {
        nodes[i].next = NULL;
        head_plugin(&head, &nodes[i]);
    }
    print_llist(head);

    head = partition(head);
    print_llist(head);

    head = partition(head);
    print_llist(head);
    

    head = merge_sort(head);
    print_llist(head);

    return 0;
}

void print_llist(struct ListNode *head) {
    for (struct ListNode *i = head; i; i = i->next) {
        printf("%d -> ", i->val);
    }
    printf("NULL\n");
}