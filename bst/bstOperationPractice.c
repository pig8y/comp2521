/*
 * BST Operations Practice - Starter Template
 *
 * Goal:
 * Implement each TODO operation without looking at bst_reference.c first.
 * tree size is the maximum allowed number of nodes.
 * Duplicate values should be rejected.
 *
 * Suggested order:
 * 1. createNode, insert
 * 2. inorder/preorder/postorder, search
 * 3. findMinNode/findMaxNode, deleteNode
 * 4. countLeaves, deleteAllLeaves
 * 5. levelorder, printRange, findClosest
 *
 * Compile: gcc -std=c11 -Wall -Wextra -pedantic bst_practice_template.c -o bst_practice
 * Run:     ./bst_practice
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <Queue.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *newNode(int value);
Node *insert(Node *root, int value);
bool search(Node *root, int value);
Node *deleteNode(Node *root, int value);
Node *deleteAllLeaves(Node *root);
Node *findMinNode(Node *root);
Node *findMaxNode(Node *root);
int findClosest(Node *root, int target);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
void levelorder(Node *root);
int countLeaves(Node *root);
void printRange(Node *root);
void freeTree(Node *root);
void printMenu(void);
void clearInput(void);
Node *joinTree(Node *t1, Node *t2);

int main(void) {
    Node *root = NULL;
    int maxSize, count = 0;
    int choice, value, target;

    printf("Enter maximum BST size: ");
    if (scanf("%d", &maxSize) != 1 || maxSize <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    for (;;) {
        printMenu();
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Please enter an integer option.\n");
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Value to insert: ");
                if (scanf("%d", &value) == 1) {
                    root = insert(root, value);
                } else {
                    clearInput();
                }
                break;
            case 2:
                printf("Value to search: ");
                if (scanf("%d", &value) == 1) {
                    printf(search(root, value) ? "Found.\n" : "Not found.\n");
                } else {
                    clearInput();
                }
                break;
            case 3:
                printf("Value to delete: ");
                if (scanf("%d", &value) == 1) {
                    root = deleteNode(root, value);
                } else {
                    clearInput();
                }
                break;
            case 4:
                printf("Inorder: "); inorder(root); printf("\n");
                break;
            case 5:
                printf("Preorder: "); preorder(root); printf("\n");
                break;
            case 6:
                printf("Postorder: "); postorder(root); printf("\n");
                break;
            case 7:
                printf("Level order: "); levelorder(root); printf("\n");
                break;
            case 8:
                printf("Number of leaves: %d\n", countLeaves(root));
                break;
            case 9:
                root = deleteAllLeaves(root);
                break;
            case 10:
                printRange(root);
                break;
            case 11:
                printf("Target value: ");
                if (scanf("%d", &target) == 1) {
                    int closest = findClosest(root, target);
                    if (closest == -1) printf("Tree is empty.\n");
                    else printf("Closest value: %d\n", closest);
                } else {
                    clearInput();
                }
                break;
            case 12:
                printf("Current size: %d / %d\n", count, maxSize);
                break;
            case 0:
                freeTree(root);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

/* ========================= YOUR IMPLEMENTATION AREA ========================= */

Node *newNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = value;
    
    return newNode;
}

Node *insert(Node *root, int value) {
    if (root == NULL) return newNode(value);
    if (root->value == value) return root;

    if (value > root->value) {
        root->right = insert(root->right, value);
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    }

    return root;
}

bool search(Node *root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->value == value) {
        return true;
    }

    if (value > root->value) return search(root->right, value);
    if (value < root->value) return search(root->left, value);

    return false;
}

Node *findMinNode(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->left == NULL) {
        return root;
    } else {
        return findMinNode(root->left);
    }
}

Node *findMaxNode(Node *root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->right == NULL) {
        return root;
    } else {
        return findMaxNode(root->right);
    }
}

Node *deleteNode(Node *root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else {
        Node *new = root;
        if (root->left != NULL && root->right != NULL) {
            new = joinTree(root->left, root->right);
        } else if (root->left == NULL) {
            new = root->right;
        } else {
            new = root->left;
        }
        free(root);
        return new;
    }
    return root;
}

void preorder(Node *root) {
    if (root == NULL) return;
    
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
    
}

void postorder(Node *root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
    
}

void levelorder(Node *root) {
    if (root == NULL) return;
    Queue q = QueueNew();
    QueueEnqueue(q, root);

    while(!QueueIsEmpty(q)) {
        Node *n = QueueDequeue(q);
        printf("%d ", n->value);
        
        if (n->left != NULL) QueueEnqueue(q, n->left);
        if (n->right != NULL) QueueEnqueue(q, n->right);
    }
    QueueFree(q);
}

int countLeaves(Node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

Node *deleteAllLeaves(Node *root) {
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    root->left = deleteAllLeaves(root->left);
    root->right = deleteAllLeaves(root->right);
   
    return root;
}

void printRange(Node *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    int min = findMinNode(root)->value;
    int max = findMaxNode(root)->value;

    printf("minimum: %d, maximum: %d, difference: %d", min, max, max - min);
}

int findClosest(Node *root, int target) {
    if (root == NULL) return -1;
    int closest = root->value;

    while(root != NULL) {
        if (abs(target - root->value) <= abs(closest - target)) closest = root->value;
        if (root->value == target) return target;
        else if (target > root->value) root = root->right; 
        else root = root->left;
    }

    return closest;
}

/* =========================== GIVEN HELPER FUNCTIONS ========================= */

void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void printMenu(void) {
    printf("\n========== BST MENU ==========\n");
    printf("1.  Insert\n");
    printf("2.  Search\n");
    printf("3.  Delete one value\n");
    printf("4.  Print inorder\n");
    printf("5.  Print preorder\n");
    printf("6.  Print postorder\n");
    printf("7.  Print level order\n");
    printf("8.  Count leaves\n");
    printf("9.  Delete all current leaves\n");
    printf("10. Find range\n");
    printf("11. Find closest value\n");
    printf("12. Show current size\n");
    printf("0.  Exit\n");
    printf("==============================\n");
}

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

/* =========================== MY WRITTEN HELPER FUNCTION ========================= */

// Joining two tree together by using the minimum value of node in t2 as root
// Assume t1_max < t2_min
Node *joinTree(Node *t1, Node *t2) {
    if (t1 == NULL) {
        return t2;
    } else if (t2 == NULL) {
        return t1;
    } else if (t2->left == NULL) {
        t2->left = t1;
        return t2;
    } else {
        Node *curr = t2;
        Node *temp = NULL;
        
        while (curr->left != NULL) {
            temp = curr;
            curr = curr->left;
        }
            temp->left = curr->right;
            curr->left = t1;
            curr->right = t2;
            return curr;
    }
}