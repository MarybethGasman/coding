
#include <stdio.h>
#include <stdlib.h>
extern struct ListNode {
    int val;
    struct ListNode* next;
};
#define MAX_NODE_NUM 10
extern void head_plugin(struct ListNode** ptr2head, struct ListNode* node);
extern struct ListNode* reverse(struct ListNode* head);
extern struct ListNode* reverseK(struct ListNode* head, int k, struct ListNode** next);

extern struct ListNode* reverseKGroup(struct ListNode* head, int k);

int main() {
    struct ListNode nodes[MAX_NODE_NUM];

    nodes[0].val = 10;
    nodes[0].next = NULL;
    struct ListNode* head = &nodes[0];

    for (int i = 9; i > 0; i--) {
        nodes[i].val = i;
        nodes[i].next = NULL;

        head_plugin(&head, &nodes[i]);
    }
    for (struct ListNode* tmp = head; tmp; tmp = tmp->next) {
        printf(" %d ->", tmp->val);
    }
    printf(" NULL");
    printf("\n");
    head = reverse(head);
    printf("reversing the linked list...\n");
    for (struct ListNode* tmp = head; tmp; tmp = tmp->next) {
        printf(" %d ->", tmp->val);
    }
    printf(" NULL");
    printf("\n");
    
    struct ListNode *next;
    printf("reversing the linked list of K size...\n");
    head = reverseKGroup(head, 4);
        for (struct ListNode* tmp = head; tmp; tmp = tmp->next) {
        printf(" %d ->", tmp->val);
    }
    printf(" NULL");
    printf("\n");
    return 0;
}
