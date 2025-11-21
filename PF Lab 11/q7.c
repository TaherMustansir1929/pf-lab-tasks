#include <stdio.h>
#include <string.h>

// Structure Definitions
typedef struct {
  int studentID;
  char name[50];

  // Nested struct definition for Date
  struct Date {
    int day;
    int month;
    int year;
  } dob;

  // Nested struct definition for Address
  struct Address {
    char houseNumber[20];
    char street[50];
    char city[50];
    int postalCode;
  } address;

  // Nested struct definition for Course
  struct Course {
    char courseCode[20];
    char courseName[50];
    int creditHours;
    char grade; // A, B, C, D, F
  } courses[5];

  float cgpa;
} Student;

// Function Prototypes
void addStudent(Student students[], int *count);
void calculateCGPA(Student *student);
void searchStudentByID(Student students[], int count, int id);
void displayStudentsAboveCGPA(Student students[], int count, float threshold);
void findOldestStudent(Student students[], int count);
void findYoungestStudent(Student students[], int count);
int compareDates(struct Date d1, struct Date d2);
float getGradePoint(char grade);

int main() {
  Student students[100]; // Capacity for 100 students
  int count = 0;
  int choice;
  int searchID;
  float threshold;

  while (1) {
    printf("\n--- Student Record Management System ---\n");
    printf("1. Add New Student\n");
    printf("2. Search Student by ID\n");
    printf("3. Display Students with CGPA > Threshold\n");
    printf("4. Find Oldest Student\n");
    printf("5. Find Youngest Student\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addStudent(students, &count);
      break;
    case 2:
      printf("Enter Student ID to search: ");
      scanf("%d", &searchID);
      searchStudentByID(students, count, searchID);
      break;
    case 3:
      printf("Enter CGPA threshold: ");
      scanf("%f", &threshold);
      displayStudentsAboveCGPA(students, count, threshold);
      break;
    case 4:
      findOldestStudent(students, count);
      break;
    case 5:
      findYoungestStudent(students, count);
      break;
    case 6:
      printf("Exiting...\n");
      return 0;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }
  return 0;
}

// Helper function to convert grade char to points
float getGradePoint(char grade) {
  switch (grade) {
  case 'A':
    return 4.0;
  case 'B':
    return 3.0;
  case 'C':
    return 2.0;
  case 'D':
    return 1.0;
  case 'F':
    return 0.0;
  default:
    return 0.0;
  }
}

void calculateCGPA(Student *student) {
  float totalPoints = 0;
  int totalCredits = 0;

  for (int i = 0; i < 5; i++) {
    float points = getGradePoint(student->courses[i].grade);
    totalPoints += points * student->courses[i].creditHours;
    totalCredits += student->courses[i].creditHours;
  }

  if (totalCredits > 0) {
    student->cgpa = totalPoints / totalCredits;
  } else {
    student->cgpa = 0.0;
  }
}

void addStudent(Student students[], int *count) {
  if (*count >= 100) {
    printf("System full! Cannot add more students.\n");
    return;
  }

  Student *s = &students[*count];

  printf("\nEnter Student ID: ");
  scanf("%d", &s->studentID);
  getchar(); // Consume newline

  printf("Enter Name: ");
  fgets(s->name, 50, stdin);
  s->name[strcspn(s->name, "\n")] = 0; // Remove newline

  printf("Enter Date of Birth (DD MM YYYY): ");
  scanf("%d %d %d", &s->dob.day, &s->dob.month, &s->dob.year);
  getchar(); // Consume newline

  printf("Enter Address (HouseNo Street City PostalCode): ");
  // Simple input for address components
  printf("\nHouse Number: ");
  fgets(s->address.houseNumber, 20, stdin);
  s->address.houseNumber[strcspn(s->address.houseNumber, "\n")] = 0;

  printf("Street: ");
  fgets(s->address.street, 50, stdin);
  s->address.street[strcspn(s->address.street, "\n")] = 0;

  printf("City: ");
  fgets(s->address.city, 50, stdin);
  s->address.city[strcspn(s->address.city, "\n")] = 0;

  printf("Postal Code: ");
  scanf("%d", &s->address.postalCode);

  printf("\nEnter 5 Courses Details:\n");
  for (int i = 0; i < 5; i++) {
    printf("Course %d Code: ", i + 1);
    scanf("%s", s->courses[i].courseCode);
    getchar(); // Consume newline

    printf("Course %d Name: ", i + 1);
    fgets(s->courses[i].courseName, 50, stdin);
    s->courses[i].courseName[strcspn(s->courses[i].courseName, "\n")] = 0;

    printf("Course %d Credit Hours: ", i + 1);
    scanf("%d", &s->courses[i].creditHours);

    printf("Course %d Grade (A/B/C/D/F): ", i + 1);
    scanf(" %c", &s->courses[i].grade); // Space before %c to consume whitespace
  }

  calculateCGPA(s);
  (*count)++;
  printf("Student added successfully! Calculated CGPA: %.2f\n", s->cgpa);
}

void searchStudentByID(Student students[], int count, int id) {
  int found = 0;
  for (int i = 0; i < count; i++) {
    if (students[i].studentID == id) {
      printf("\nStudent Found:\n");
      printf("ID: %d\n", students[i].studentID);
      printf("Name: %s\n", students[i].name);
      printf("DOB: %02d/%02d/%d\n", students[i].dob.day, students[i].dob.month,
             students[i].dob.year);
      printf("CGPA: %.2f\n", students[i].cgpa);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Student with ID %d not found.\n", id);
  }
}

void displayStudentsAboveCGPA(Student students[], int count, float threshold) {
  printf("\nStudents with CGPA > %.2f:\n", threshold);
  int found = 0;
  for (int i = 0; i < count; i++) {
    if (students[i].cgpa > threshold) {
      printf("ID: %d, Name: %s, CGPA: %.2f\n", students[i].studentID,
             students[i].name, students[i].cgpa);
      found = 1;
    }
  }
  if (!found) {
    printf("No students found above this threshold.\n");
  }
}

// Returns -1 if d1 < d2 (d1 is older), 1 if d1 > d2 (d1 is younger), 0 if same
int compareDates(struct Date d1, struct Date d2) {
  if (d1.year != d2.year)
    return d1.year - d2.year;
  if (d1.month != d2.month)
    return d1.month - d2.month;
  return d1.day - d2.day;
}

void findOldestStudent(Student students[], int count) {
  if (count == 0) {
    printf("No students in the system.\n");
    return;
  }
  int oldestIndex = 0;
  for (int i = 1; i < count; i++) {
    // Smaller date means older person
    if (compareDates(students[i].dob, students[oldestIndex].dob) < 0) {
      oldestIndex = i;
    }
  }
  printf("\nOldest Student:\n");
  printf("Name: %s, DOB: %02d/%02d/%d\n", students[oldestIndex].name,
         students[oldestIndex].dob.day, students[oldestIndex].dob.month,
         students[oldestIndex].dob.year);
}

void findYoungestStudent(Student students[], int count) {
  if (count == 0) {
    printf("No students in the system.\n");
    return;
  }
  int youngestIndex = 0;
  for (int i = 1; i < count; i++) {
    // Larger date means younger person
    if (compareDates(students[i].dob, students[youngestIndex].dob) > 0) {
      youngestIndex = i;
    }
  }
  printf("\nYoungest Student:\n");
  printf("Name: %s, DOB: %02d/%02d/%d\n", students[youngestIndex].name,
         students[youngestIndex].dob.day, students[youngestIndex].dob.month,
         students[youngestIndex].dob.year);
}
