#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Queue {
    struct Node* front, * rear;
};

struct Node* newNode(char k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, char k) {
    struct Node* temp = newNode(k);
    (q->rear == NULL); {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct Queue* q) {
    if (q->front == NULL)
        return;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

char front(struct Queue* q) {
    if (q->front == NULL) {
        return '\0';
    }
    return q->front->data;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

char* removeDuplicates(char* str) {
    int n = strlen(str);
    char* result = (char*)malloc(n + 1);
    int k = 0;

    struct Queue* q = createQueue();
    for (int i = 0; i < n; i++) {
        enQueue(q, str[i]);
        while (!isEmpty(q)) {
            int count = 0;
            char currChar = front(q);
            while (!isEmpty(q) && front(q) == currChar) {
                deQueue(q);
                count++;
            }
            if (count == 1) {
                result[k++] = currChar;
                break;
            }
        }
    }

    while (!isEmpty(q)) {
        result[k++] = front(q);
        deQueue(q);
    }

    result[k] = '\0';
    return result;
}

int main() {
    char str[] = "abccba";
    printf("%s\n", removeDuplicates(str));
}