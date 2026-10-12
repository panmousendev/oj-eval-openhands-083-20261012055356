#include <iostream>

using namespace std;

// Node structure for singly circular linked list
struct Node {
    int value;
    Node* next;
    
    Node(int val) : value(val), next(nullptr) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    
    // Edge case: if n == 1, just output 1
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    // Build the circular linked list
    Node* head = new Node(1);
    Node* current = head;
    
    for (int i = 2; i <= n; i++) {
        current->next = new Node(i);
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
    Node* prev = current;  // Node before the current counting position
    Node* curr = head;     // Current counting position (starts at 1)
    
    while (prev != curr) {  // While there's more than one node
        // Count m-1 steps to find the node before the one to delete
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        // Delete curr node
        cout << curr->value << endl;
        prev->next = curr->next;
        Node* toDelete = curr;
        curr = curr->next;
        delete toDelete;
    }
    
    // Output the last remaining node
    cout << curr->value << endl;
    delete curr;
    
    return 0;
}