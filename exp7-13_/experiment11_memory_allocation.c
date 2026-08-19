#include <stdio.h>

void firstFit(void) {
    int blockSize[20], processSize[20], allocation[20];
    int nb, np, i, j;

    printf("\n--- First Fit ---\n");
    printf("Enter Number of Blocks: ");
    scanf("%d", &nb);
    printf("Enter Number of Processes: ");
    scanf("%d", &np);

    printf("Enter Block Sizes:\n");
    for (i = 0; i < nb; i++) scanf("%d", &blockSize[i]);

    printf("Enter Process Sizes:\n");
    for (i = 0; i < np; i++) scanf("%d", &processSize[i]);

    for (i = 0; i < np; i++) allocation[i] = -1;

    for (i = 0; i < np; i++)
        for (j = 0; j < nb; j++)
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }

    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) printf("%d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
}

void bestFit(void) {
    int blockSize[20], processSize[20], allocation[20];
    int nb, np, i, j, bestIdx;

    printf("\n--- Best Fit ---\n");
    printf("Enter Number of Blocks: ");
    scanf("%d", &nb);
    printf("Enter Number of Processes: ");
    scanf("%d", &np);

    printf("Enter Block Sizes:\n");
    for (i = 0; i < nb; i++) scanf("%d", &blockSize[i]);

    printf("Enter Process Sizes:\n");
    for (i = 0; i < np; i++) scanf("%d", &processSize[i]);

    for (i = 0; i < np; i++) allocation[i] = -1;

    for (i = 0; i < np; i++) {
        bestIdx = -1;

        for (j = 0; j < nb; j++)
            if (blockSize[j] >= processSize[i])
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) printf("%d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
}

void worstFit(void) {
    int blockSize[20], processSize[20], allocation[20];
    int nb, np, i, j, worstIdx;

    printf("\n--- Worst Fit ---\n");
    printf("Enter Number of Blocks: ");
    scanf("%d", &nb);
    printf("Enter Number of Processes: ");
    scanf("%d", &np);

    printf("Enter Block Sizes:\n");
    for (i = 0; i < nb; i++) scanf("%d", &blockSize[i]);

    printf("Enter Process Sizes:\n");
    for (i = 0; i < np; i++) scanf("%d", &processSize[i]);

    for (i = 0; i < np; i++) allocation[i] = -1;

    for (i = 0; i < np; i++) {
        worstIdx = -1;

        for (j = 0; j < nb; j++)
            if (blockSize[j] >= processSize[i])
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) printf("%d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
}

int main(void) {
    int choice;

    printf("Memory Allocation Methods\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: firstFit(); break;
        case 2: bestFit(); break;
        case 3: worstFit(); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}
