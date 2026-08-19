#include <stdio.h>

void fifo(int pages[], int n, int f) {
    int frames[10], i, j, k = 0, fault = 0, found;

    for (i = 0; i < f; i++) frames[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < f; j++)
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }

        if (!found) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            fault++;
        }
    }

    printf("FIFO Page Faults = %d\n", fault);
}

void lru(int pages[], int n, int f) {
    int frames[10], time[10];
    int i, j, fault = 0, count = 0, found, pos, min;

    for (i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if (!found) {
            min = time[0];
            pos = 0;

            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            fault++;
        }
    }

    printf("LRU Page Faults = %d\n", fault);
}

int optimalFaults(int pages[], int n, int f) {
    int frames[10], i, j, k, found, pos, farthest, next, fault = 0;

    for (i = 0; i < f; i++) frames[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < f; j++)
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }

        if (found) continue;

        fault++;

        for (j = 0; j < f; j++)
            if (frames[j] == -1)
                break;

        if (j < f) {
            frames[j] = pages[i];
            continue;
        }

        farthest = -1;
        pos = 0;

        for (j = 0; j < f; j++) {
            next = n + 1;

            for (k = i + 1; k < n; k++)
                if (pages[k] == frames[j]) {
                    next = k;
                    break;
                }

            if (next > farthest) {
                farthest = next;
                pos = j;
            }
        }

        frames[pos] = pages[i];
    }

    return fault;
}

int main(void) {
    int pages[50], n, f, i, choice;

    printf("Enter Number of Pages: ");
    scanf("%d", &n);

    printf("Enter Reference String:\n");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter Number of Frames: ");
    scanf("%d", &f);

    printf("\n1. FIFO\n2. LRU\n3. Optimal\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: fifo(pages, n, f); break;
        case 2: lru(pages, n, f); break;
        case 3: printf("Optimal Page Faults = %d\n", optimalFaults(pages, n, f)); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}
