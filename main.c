#include <stdio.h>
#include <stdlib.h>

// Node structure for singly circular linked list
struct Node {
    int value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        return 1;
    }
    
    // Edge case: if n == 1, just output 1
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    
    // Build the circular linked list
    struct Node* head = createNode(1);
    struct Node* current = head;
    
    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    
    // Make it circular
    current->next = head;
    
    // Start the Josephus simulation
    // We need to find the node before the one to be deleted
    current = head;
    
    // Find the last node (which points to head)
    while (current->next != head) {
        current = current->next;
    }
    
    // Now 'current' is the last node, and we'll start counting from head
    struct Node* prev = current;  // Node before the current counting position
    struct Node* curr = head;     // Current counting position (starts at 1)
    
    while (prev != curr) {  // While there's more than one node
        // Count m-1 steps to find the node before the one to delete
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        // Delete curr node
        printf("%d\n", curr->value);
        prev->next = curr->next;
        struct Node* toDelete = curr;
        curr = curr->next;
        free(toDelete);
    }
    
    // Output the last remaining node
    printf("%d\n", curr->value);
    free(curr);
    
    return 0;
}