#include <stdio.h>

#define EMPTY -1

void insert(int ht[], int m, int key) {
    int index = key % m;

    // Linear probing in case of collision
    while (ht[index] != EMPTY) {
        index = (index + 1) % m;
    }

    ht[index] = key;
}

void display(int ht[], int m) {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (ht[i] == EMPTY)
            printf("HT[%d] : EMPTY\n", i);
        else
            printf("HT[%d] : %d\n", i, ht[i]);
    }
}

int main() {
    int m, n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    int ht[m];

    // Initialize hash table
    for (int i = 0; i < m; i++) {
        ht[i] = EMPTY;
    }

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d four-digit employee keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(ht, m, key);
    }

    display(ht, m);

    return 0;
}
