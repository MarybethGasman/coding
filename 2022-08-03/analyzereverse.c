
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern struct ListNode {
    int val;
    struct ListNode* next;
};
#define MAX_NODE_NUM 1000
extern void head_plugin(struct ListNode** ptr2head, struct ListNode* node);
extern struct ListNode* reverse(struct ListNode* head);
extern struct ListNode* reverseK(struct ListNode* head, int k, struct ListNode** next);
extern struct ListNode* reverseKGroup(struct ListNode* head, int k);

int main() {
    // printf("pid is %d\n", getpid());

    // getchar();
    struct timespec begin;
    struct timespec end;

    struct ListNode* nodes;
    struct ListNode* head = &nodes[0];
    for (int i = 3; i < MAX_NODE_NUM; i++) {
        nodes = malloc(sizeof(struct ListNode) * MAX_NODE_NUM);
        nodes[0].val = i + 1;
        nodes[0].next = NULL;
        head = &nodes[0];
        for (int j = i; j > 0; j--) {
            nodes[j].val = j;
            nodes[j].next = NULL;
            head_plugin(&head, &nodes[j]);
        }
        clock_gettime(CLOCK_MONOTONIC, &begin);
        head = reverseKGroup(head, 3);
        clock_gettime(CLOCK_MONOTONIC, &end);
        // for (struct ListNode* k = head; k; k = k->next) {
        //     printf(" %d -> ", k->val);
        // }
        // printf("NULL");
        // printf("\n");
        printf("%d %llu\n", i, (unsigned long long)end.tv_nsec - begin.tv_nsec);

        free(nodes);
    }

    return 0;
}
