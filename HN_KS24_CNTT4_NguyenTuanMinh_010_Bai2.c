#include <stdio.h>

int main(void) {
    int choice;

    do {
        printf("1. VISIT\n");
        printf("2. BACK\n");
        printf("3. FORWARD\n");
        printf("4. HISTORY\n");
        printf("5. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice) {
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                printf("Exit\n");
                break;
            }
            default: {
                printf("Wrong choice\n");
            }
        }
    } while(choice != 5);

    return 0;
}