# include "stdio.h"
# include "stdlib.h"
# include "string.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *aux = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *aux2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    aux = l1;
    aux2 = l2;
    int carry = 0, sum = 0;
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *current = (struct ListNode *) malloc(sizeof(struct ListNode));
    head = current;
    while (aux != NULL || aux2 != NULL) {
        sum = carry;
        if (aux != NULL) {
            sum += aux->val;
            aux = aux->next;
        }
        if (aux2 != NULL) {
            sum += aux2->val;
            aux2 = aux2->next;
        }
        carry = sum / 10;
        current->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
    }
    if (carry > 0) {
        current->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = carry;
    }
    current->next = NULL;
    return head->next;
}

void displayVector(int vet[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int vet[] = {2, 4, 3}, vet2[] = {5, 6, 7};
    addTwoNumbers(vet, vet2);
    displayVector(vet, 3);
}