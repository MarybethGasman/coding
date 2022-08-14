// reverse node in k group
#define NULL 0
//  Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

void head_plugin(struct ListNode **ptr2head, struct ListNode *node) {
    node->next = *ptr2head;
    *ptr2head = node;
}
struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *tmp = NULL;
    struct ListNode *i = head;
    while (i) {
        head = i->next;
        i->next = tmp;
        tmp = i;
        i = head;
    }
    return tmp;
}

#include <stdlib.h>
struct ListNode *merge_sorted_list(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode *result;
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    if (list1->val < list2->val) {
        result = malloc(sizeof(*result));
        result->val = list1->val;
        result->next = merge_sorted_list(list1->next, list2);
    } else {
        result = malloc(sizeof(*result));
        result->val = list2->val;
        result->next = merge_sorted_list(list1, list2->next);
    }
    return result;
}
struct ListNode *merge_sort(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (slow->next->next && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *right = merge_sort(slow->next);
    slow->next = NULL;
    struct ListNode *left = merge_sort(head);
    return merge_sorted_list(left, right);
}