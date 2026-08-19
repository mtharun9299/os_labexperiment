#include <stdio.h>
#include <string.h>

struct student {
    int regno;
    char name[20];
};

void sequential(void) {
    FILE *fp;
    struct student s;

    fp = fopen("student.dat", "w");
    if (fp == NULL) {
        printf("Unable to open student.dat\n");
        return;
    }

    printf("Enter Register Number: ");
    scanf("%d", &s.regno);
    printf("Enter Name: ");
    scanf("%19s", s.name);

    fprintf(fp, "%d %s\n", s.regno, s.name);
    fclose(fp);

    fp = fopen("student.dat", "r");
    if (fp == NULL) {
        printf("Unable to read student.dat\n");
        return;
    }

    fscanf(fp, "%d %19s", &s.regno, s.name);

    printf("\nRecord Details\n");
    printf("Register Number : %d\n", s.regno);
    printf("Name : %s\n", s.name);

    fclose(fp);
}

void directRandom(void) {
    FILE *fp;
    struct student s;

    fp = fopen("random.dat", "wb+");
    if (fp == NULL) {
        printf("Unable to open random.dat\n");
        return;
    }

    printf("Enter Register Number: ");
    scanf("%d", &s.regno);
    printf("Enter Name: ");
    scanf("%19s", s.name);

    fwrite(&s, sizeof(s), 1, fp);
    rewind(fp);
    fread(&s, sizeof(s), 1, fp);

    printf("\nRecord Found\n");
    printf("Reg No : %d\n", s.regno);
    printf("Name : %s\n", s.name);

    fclose(fp);
}

void indexed(void) {
    FILE *fp;
    int key;
    char line[100];
    int found = 0;

    fp = fopen("index.txt", "w");
    if (fp == NULL) {
        printf("Unable to open index.txt\n");
        return;
    }

    fprintf(fp, "101 Arun\n");
    fprintf(fp, "102 Kumar\n");
    fprintf(fp, "103 Ravi\n");
    fclose(fp);

    printf("Enter Register Number to Search: ");
    scanf("%d", &key);

    fp = fopen("index.txt", "r");
    if (fp == NULL) {
        printf("Unable to read index.txt\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        int regno;
        char name[20];

        if (sscanf(line, "%d %19s", &regno, name) == 2 && regno == key) {
            printf("%d %s\n", regno, name);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found\n");

    fclose(fp);
}

int main(void) {
    int choice;

    printf("File Organization Techniques\n");
    printf("1. Sequential\n");
    printf("2. Direct (Random)\n");
    printf("3. Indexed\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: sequential(); break;
        case 2: directRandom(); break;
        case 3: indexed(); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}
