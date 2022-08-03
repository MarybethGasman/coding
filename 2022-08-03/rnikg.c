
#define likely(x)      __builtin_expect(!!(x), 1)
#define unlikely(x)    __builtin_expect(!!(x), 0)


// reverse node in k group
#define NULL 0
//  Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

void head_plugin(struct ListNode** ptr2head, struct ListNode* node) {
    node->next = *ptr2head;
    *ptr2head = node;
}

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* tmp = NULL;
    struct ListNode* i = head;
    while (likely(i)) {
        head = i->next;
        i->next = tmp;
        tmp = i;
        i = head;
    }
    return tmp;
}

struct ListNode* reverseK(struct ListNode* head, int k, struct ListNode** next, int *cont) {
    struct ListNode* tmp = NULL;
    struct ListNode* i = head;
    int cnt = 0;
    while (likely(i && cnt < k)) {
        head = i->next;
        i->next = tmp;
        tmp = i;
        i = head;
        cnt++;
    }
    *cont = cnt;
    *next = i;
    return tmp;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* newHead;
    struct ListNode* next;
    int cnt;
    newHead = reverseK(head, k, &next, &cnt);
    if (cnt != k) {
        return reverse(newHead);
    }
    head->next = reverseKGroup(next, k);
    return newHead;
}