#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return 0;
    newNode->value = val;
    newNode->next = 0;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    
    struct Node* head = createNode(1);
    struct Node* current = head;
    
    int i;
    for (i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    
    current->next = head;
    
    current = head;
    while (current->next != head) {
        current = current->next;
    }
    
    struct Node* prev = current;
    struct Node* curr = head;
    
    while (prev != curr) {
        for (i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        printf("%d\n", curr->value);
        prev->next = curr->next;
        struct Node* toDelete = curr;
        curr = curr->next;
        free(toDelete);
    }
    
    printf("%d\n", curr->value);
    free(curr);
    
    return 0;
}