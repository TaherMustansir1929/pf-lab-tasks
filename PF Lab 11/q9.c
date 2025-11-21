#include <stdio.h>
#include <string.h>

#define MAX_BOOKS_PER_MEMBER 3
#define BOOK_FILE "books.dat"
#define MEMBER_FILE "members.dat"

// Structure Definitions
typedef struct {
  int bookID;
  char title[100];
  char author[50];
  char isbn[20];
  int publicationYear;
  int isBorrowed; // 0 = Available, 1 = Borrowed
} Book;

typedef struct {
  int memberID;
  char name[50];
  char contact[20];
  int borrowedBookIDs[MAX_BOOKS_PER_MEMBER]; // Stores IDs of borrowed books, -1
                                             // if empty
  int borrowedCount;
} Member;

// Global Arrays (Simulating Database)
Book books[100];
int bookCount = 0;
Member members[100];
int memberCount = 0;

// Function Prototypes
void loadData();
void saveData();
void addBook();
void addMember();
void issueBook();
void returnBook();
void searchBooks();
void displayBorrowedBooks();
void listAllBooks();
void listAllMembers();

int main() {
  loadData();
  int choice;

  while (1) {
    printf("\n--- Library Management System ---\n");
    printf("1. Add New Book\n");
    printf("2. Add New Member\n");
    printf("3. Issue Book\n");
    printf("4. Return Book\n");
    printf("5. Search Books\n");
    printf("6. Display Borrowed Books by Member\n");
    printf("7. List All Books\n");
    printf("8. List All Members\n");
    printf("9. Save & Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addBook();
      break;
    case 2:
      addMember();
      break;
    case 3:
      issueBook();
      break;
    case 4:
      returnBook();
      break;
    case 5:
      searchBooks();
      break;
    case 6:
      displayBorrowedBooks();
      break;
    case 7:
      listAllBooks();
      break;
    case 8:
      listAllMembers();
      break;
    case 9:
      saveData();
      printf("Data saved. Exiting.\n");
      return 0;
    default:
      printf("Invalid choice.\n");
    }
  }
  return 0;
}

void loadData() {
  FILE *fp = fopen(BOOK_FILE, "rb");
  if (fp) {
    bookCount = fread(books, sizeof(Book), 100, fp);
    fclose(fp);
  }

  fp = fopen(MEMBER_FILE, "rb");
  if (fp) {
    memberCount = fread(members, sizeof(Member), 100, fp);
    fclose(fp);
  }
  printf("Data loaded successfully.\n");
}

void saveData() {
  FILE *fp = fopen(BOOK_FILE, "wb");
  if (fp) {
    fwrite(books, sizeof(Book), bookCount, fp);
    fclose(fp);
  }

  fp = fopen(MEMBER_FILE, "wb");
  if (fp) {
    fwrite(members, sizeof(Member), memberCount, fp);
    fclose(fp);
  }
}

void addBook() {
  if (bookCount >= 100) {
    printf("Library is full.\n");
    return;
  }
  Book *b = &books[bookCount];
  printf("Enter Book ID: ");
  scanf("%d", &b->bookID);
  getchar();
  printf("Enter Title: ");
  fgets(b->title, 100, stdin);
  b->title[strcspn(b->title, "\n")] = 0;
  printf("Enter Author: ");
  fgets(b->author, 50, stdin);
  b->author[strcspn(b->author, "\n")] = 0;
  printf("Enter ISBN: ");
  scanf("%s", b->isbn);
  printf("Enter Year: ");
  scanf("%d", &b->publicationYear);
  b->isBorrowed = 0;
  bookCount++;
  printf("Book added.\n");
}

void addMember() {
  if (memberCount >= 100) {
    printf("Member list is full.\n");
    return;
  }
  Member *m = &members[memberCount];
  printf("Enter Member ID: ");
  scanf("%d", &m->memberID);
  getchar();
  printf("Enter Name: ");
  fgets(m->name, 50, stdin);
  m->name[strcspn(m->name, "\n")] = 0;
  printf("Enter Contact: ");
  scanf("%s", m->contact);

  for (int i = 0; i < MAX_BOOKS_PER_MEMBER; i++)
    m->borrowedBookIDs[i] = -1;
  m->borrowedCount = 0;

  memberCount++;
  printf("Member added.\n");
}

void issueBook() {
  int mID, bID;
  printf("Enter Member ID: ");
  scanf("%d", &mID);
  printf("Enter Book ID: ");
  scanf("%d", &bID);

  int mIdx = -1, bIdx = -1;
  for (int i = 0; i < memberCount; i++)
    if (members[i].memberID == mID)
      mIdx = i;
  for (int i = 0; i < bookCount; i++)
    if (books[i].bookID == bID)
      bIdx = i;

  if (mIdx == -1 || bIdx == -1) {
    printf("Member or Book not found.\n");
    return;
  }

  if (books[bIdx].isBorrowed) {
    printf("Book is already borrowed.\n");
    return;
  }

  if (members[mIdx].borrowedCount >= MAX_BOOKS_PER_MEMBER) {
    printf("Member has reached borrowing limit.\n");
    return;
  }

  // Issue
  books[bIdx].isBorrowed = 1;
  for (int i = 0; i < MAX_BOOKS_PER_MEMBER; i++) {
    if (members[mIdx].borrowedBookIDs[i] == -1) {
      members[mIdx].borrowedBookIDs[i] = bID;
      break;
    }
  }
  members[mIdx].borrowedCount++;
  printf("Book issued successfully.\n");
}

void returnBook() {
  int mID, bID;
  printf("Enter Member ID: ");
  scanf("%d", &mID);
  printf("Enter Book ID: ");
  scanf("%d", &bID);

  int mIdx = -1, bIdx = -1;
  for (int i = 0; i < memberCount; i++)
    if (members[i].memberID == mID)
      mIdx = i;
  for (int i = 0; i < bookCount; i++)
    if (books[i].bookID == bID)
      bIdx = i;

  if (mIdx == -1 || bIdx == -1) {
    printf("Member or Book not found.\n");
    return;
  }

  int found = 0;
  for (int i = 0; i < MAX_BOOKS_PER_MEMBER; i++) {
    if (members[mIdx].borrowedBookIDs[i] == bID) {
      members[mIdx].borrowedBookIDs[i] = -1;
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("This member has not borrowed this book.\n");
    return;
  }

  books[bIdx].isBorrowed = 0;
  members[mIdx].borrowedCount--;
  printf("Book returned successfully.\n");
}

void searchBooks() {
  char query[50];
  printf("Enter Title or Author to search: ");
  getchar();
  fgets(query, 50, stdin);
  query[strcspn(query, "\n")] = 0;

  printf("\nSearch Results:\n");
  for (int i = 0; i < bookCount; i++) {
    if (strstr(books[i].title, query) || strstr(books[i].author, query)) {
      printf("ID: %d, Title: %s, Author: %s, Status: %s\n", books[i].bookID,
             books[i].title, books[i].author,
             books[i].isBorrowed ? "Borrowed" : "Available");
    }
  }
}

void displayBorrowedBooks() {
  int mID;
  printf("Enter Member ID: ");
  scanf("%d", &mID);

  int mIdx = -1;
  for (int i = 0; i < memberCount; i++)
    if (members[i].memberID == mID)
      mIdx = i;

  if (mIdx == -1) {
    printf("Member not found.\n");
    return;
  }

  printf("\nBooks borrowed by %s:\n", members[mIdx].name);
  if (members[mIdx].borrowedCount == 0) {
    printf("No books borrowed.\n");
    return;
  }

  for (int i = 0; i < MAX_BOOKS_PER_MEMBER; i++) {
    int bID = members[mIdx].borrowedBookIDs[i];
    if (bID != -1) {
      // Find book details
      for (int j = 0; j < bookCount; j++) {
        if (books[j].bookID == bID) {
          printf("- %s (ID: %d)\n", books[j].title, books[j].bookID);
        }
      }
    }
  }
}

void listAllBooks() {
  printf("\n--- All Books ---\n");
  for (int i = 0; i < bookCount; i++) {
    printf("ID: %d, Title: %s, Status: %s\n", books[i].bookID, books[i].title,
           books[i].isBorrowed ? "Borrowed" : "Available");
  }
}

void listAllMembers() {
  printf("\n--- All Members ---\n");
  for (int i = 0; i < memberCount; i++) {
    printf("ID: %d, Name: %s, Borrowed: %d\n", members[i].memberID,
           members[i].name, members[i].borrowedCount);
  }
}
