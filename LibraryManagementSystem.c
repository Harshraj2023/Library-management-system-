
#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

void addBook() {
    FILE *fp = fopen("books.dat", "ab+");
    struct Book book;

    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    printf("Enter Title: ");
    getchar(); // To clear the newline buffer
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = '\0'; // Remove newline
    printf("Enter Author: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = '\0';

    fwrite(&book, sizeof(struct Book), 1, fp);
    fclose(fp);
    printf("Book added successfully!\n");
}

void listBooks() {
    FILE *fp = fopen("books.dat", "rb");
    struct Book book;

    printf("\nBooks in Library:\n");
    while (fread(&book, sizeof(struct Book), 1, fp)) {
        printf("ID: %d, Title: %s, Author: %s\n", book.id, book.title, book.author);
    }
    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
