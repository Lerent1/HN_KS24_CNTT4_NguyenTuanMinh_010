#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Manage {
    int id;
    char name[100];
    char position[100];
    char salary[100];
    struct Manage *next;
} Manage;

typedef struct Storage {
    int id;
    char name[100];
    char position[100];
    char salary[100];
    struct Storage *next;
    struct Storage *prev;
} Storage;

Manage *manageHead = NULL;
int count = 1;
Storage *storageHead = NULL;

Manage *createManage(int id, char name[], char position[], char salary[]) {
    Manage *manage = (Manage *)malloc(sizeof(Manage));
    manage->id = id;
    strcpy(manage->name, name);
    strcpy(manage->position, position);
    strcpy(manage->salary, salary);
    manage->next = NULL;

    return  manage;
}

Storage *createStorage(int id, char name[], char position[], char salary[]) {
    Storage *storage = (Storage *)malloc(sizeof(Storage));
    storage->id = id;
    strcpy(storage->name, name);
    strcpy(storage->position, position);
    strcpy(storage->salary, salary);
    storage->next = NULL;
    storage->prev = NULL;

    return storage;
}

void add() {
    char name[100];
    char position[100];
    char salary[100];

    printf("Hay nhap ten cua nhan vien: ");
    scanf("%s", name);
    getchar();
    printf("Hay nhap vi tri cong viec cua nhan vien: ");
    scanf("%s", position);
    getchar();
    printf("Hay nhap luong: ");
    scanf("%s", salary);
    getchar();

    Manage *manage = createManage(count,name,position,salary);
    manage->id = count++;
    manage->next = manageHead;
    manageHead = manage;
}

void printfemp() {
    Manage *manage = manageHead;
    if (manage == NULL) {
        printf("Ko co nhan vien");
    }
    while (manage!= NULL) {
        printf("ID: %d\n", manage->id);
        printf("Name: %s\n", manage->name);
        printf("Position: %s\n", manage->position);
        printf("Salary: %s\n", manage->salary);
        manage = manage->next;
    }
    printf("\n");
}

void deleteManage() {
    int id;
    printf("Hay nhap ID muon xoa: ");
    scanf("%d", &id);
    getchar();

    Manage *manage = manageHead;
    Manage *current = NULL;
    while (manage != NULL) {
        if (manage->id == id) {
            if (current == NULL) {
                manageHead = current->next;
            } else {
                current->next = manage->next;
            }
            free(manage);
            return;
        }
        current = manageHead;
        manageHead = manageHead->next;
    }
}

void updateManage() {
    int id;
    printf("Hay nhap id muon cap nhat: ");
    scanf("%d", &id);
    getchar();

    Manage *manage = manageHead;
    while (manage != NULL) {
        if (manage->id == id) {
            printf("Hay nhap ten moi: ");
            scanf("%s", manage->name);
            getchar();
            printf("Hay nhap vi tri cong viec moi: ");
            scanf("%s", manage->position);
            getchar();
            printf("Hay nhap luong: ");
            scanf("%s", manage->salary);
            getchar();
        }
        manage = manage->next;
    }
}

void sort() {
    for (Manage *i = manageHead; i->next != NULL; i = i->next) {
        for (Manage *j = i; j->next != NULL; j = j->next) {
            if (i->salary > j->salary) {

            }
        }
    }
}

void printfRemove() {
    Storage *storage = storageHead;
    if (storage == NULL) {
        printf("Khong co nhan vien nghi viec");
    }
    while (storage != NULL) {
        printf("ID: %d\n", storage->id);
        printf("Name: %s\n", storage->name);
        printf("Position: %s\n", storage->position);
        printf("Salary: %s\n", storage->salary);
        storage = storage->next;
    }
    printf("\n");
}

void searchName() {
    char search[100];
    printf("Hay nhap ten muon tim kiem: ");
    scanf("%s", search);
    getchar();

    Manage *manage = manageHead;
    int found = 0;
    while (manage != NULL) {
        if (strcmp(search, manage->name) == 0) {
            printf("ID: %d\n", manage->id);
            printf("Name: %s\n", manage->name);
            printf("Position: %s\n", manage->position);
            printf("Salary: %s\n\n", manage->salary);
            found = 1;
        }
        manage = manage->next;
    }
    if (found == 0) {
        printf("Khong tim thay nhan vien nao ten %s", search);
    }
}

int main(void) {
    int choice;

    do {
        printf("1. Them nhan vien\n");
        printf("2. Hien thi danh sach nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Cap nhat thong tin nhan vien\n");
        printf("5. Danh dau nhan vien da nghi viec\n");
        printf("6. Hien thi nhan vien da nghi viec\n");
        printf("7. Sap xep nhan vien\n");
        printf("8. Tim kiem nhan vien\n");
        printf("9. Thoat chuong trinh\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                add();
                break;
            }
            case 2: {
                printfemp();
                break;
            }
            case 3: {
                deleteManage();
                break;
            }
            case 4: {
                updateManage();
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                printfRemove();
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                searchName();
                break;
            }
            case 9: {
                printf("Thoat chuong trinh thanh cong");
                break;
            }
            default : {
                printf("Khong hop le, hay chon lai");
            }
        }
    } while (choice != 9);

    return 0;
}
