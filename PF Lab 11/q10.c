#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definitions
typedef struct Employee {
  int id;
  char name[50];
  char designation[50];
  float salary;
  struct Employee *manager; // Pointer to manager
} Employee;

typedef struct {
  char deptName[50];
  Employee
      *employees[100]; // Array of pointers to employees for easier management
  int empCount;
  Employee *head;
} Department;

// Global ID Counter
static int idCounter = 1001;

// Function Prototypes
Employee *createEmployee(char *name, char *designation, float salary,
                         Employee *manager);
void addEmployeeToDept(Department *dept, Employee *emp);
float calculateTotalSalary(Employee *emp, Department *dept);
void getReportingChain(Employee *emp);
int countLevels(Employee *emp);
void displaySubordinates(Employee *manager, Department *dept);
void displaySubordinatesRecursive(Employee *manager, Department *dept,
                                  int level);

int main() {
  Department itDept;
  strcpy(itDept.deptName, "IT Department");
  itDept.empCount = 0;
  itDept.head = NULL;

  printf("--- Employee Hierarchy System ---\n");

  // 1. Create Hierarchy
  // CEO (Head)
  Employee *ceo = createEmployee("Alice CEO", "CEO", 50000, NULL);
  addEmployeeToDept(&itDept, ceo);
  itDept.head = ceo;

  // Managers reporting to CEO
  Employee *mgr1 = createEmployee("Bob Mgr", "Manager", 30000, ceo);
  Employee *mgr2 = createEmployee("Charlie Mgr", "Manager", 32000, ceo);
  addEmployeeToDept(&itDept, mgr1);
  addEmployeeToDept(&itDept, mgr2);

  // Employees reporting to Managers
  Employee *dev1 = createEmployee("Dave Dev", "Developer", 15000, mgr1);
  Employee *dev2 = createEmployee("Eve Dev", "Developer", 16000, mgr1);
  Employee *dev3 = createEmployee("Frank Dev", "Developer", 15500, mgr2);
  addEmployeeToDept(&itDept, dev1);
  addEmployeeToDept(&itDept, dev2);
  addEmployeeToDept(&itDept, dev3);

  // Intern reporting to Developer
  Employee *intern = createEmployee("George Intern", "Intern", 5000, dev1);
  addEmployeeToDept(&itDept, intern);

  // 2. Calculate Total Salary (Recursive)
  // For Bob Mgr: Bob + Dave + Eve + George (Dave's subordinate)
  printf("\n--- Total Salary Calculation ---\n");
  printf("Total Salary for %s and subordinates: %.2f\n", mgr1->name,
         calculateTotalSalary(mgr1, &itDept));

  // 3. Reporting Chain to CEO
  printf("\n--- Reporting Chain ---\n");
  printf("Chain for %s: ", intern->name);
  getReportingChain(intern);
  printf("\n");

  // 4. Count Levels
  printf("\n--- Hierarchy Levels ---\n");
  // Level is depth from CEO. CEO is level 1.
  // Intern -> Dev1 -> Mgr1 -> CEO (4 levels)
  printf("Level of %s: %d\n", intern->name, countLevels(intern));

  // 5. Display Subordinates
  printf("\n--- Subordinates of %s ---\n", mgr1->name);
  displaySubordinates(mgr1, &itDept);

  return 0;
}

Employee *createEmployee(char *name, char *designation, float salary,
                         Employee *manager) {
  Employee *newEmp = (Employee *)malloc(sizeof(Employee));
  newEmp->id = idCounter++;
  strcpy(newEmp->name, name);
  strcpy(newEmp->designation, designation);
  newEmp->salary = salary;
  newEmp->manager = manager;
  return newEmp;
}

void addEmployeeToDept(Department *dept, Employee *emp) {
  if (dept->empCount < 100) {
    dept->employees[dept->empCount++] = emp;
  } else {
    printf("Department full!\n");
  }
}

// Recursive function to calculate total salary of employee + all subordinates
float calculateTotalSalary(Employee *emp, Department *dept) {
  float total = emp->salary;

  // Find direct subordinates
  for (int i = 0; i < dept->empCount; i++) {
    if (dept->employees[i]->manager == emp) {
      // Add subordinate's total salary (recursive)
      total += calculateTotalSalary(dept->employees[i], dept);
    }
  }
  // Note: This logic double counts if the graph is not a tree, but hierarchy is
  // a tree. However, calculateTotalSalary(subordinate) returns subordinate +
  // their subs. So we just add that result. Wait, if I call
  // calculateTotalSalary(subordinate), it returns the sum of that subtree. So
  // 'total += ...' is correct.

  // Optimization: The loop scans the whole array every time. O(N^2) worst case.
  // Acceptable for N=100.

  // Correction: The recursive call 'calculateTotalSalary' will add the
  // subordinate's salary. But 'total' starts with 'emp->salary'. So: Total =
  // MySalary + Sum(Child_Total_Salary) But wait, if I call
  // calculateTotalSalary(child), it returns Child + Child's children. So yes,
  // this is correct.

  return total;
}

// Recursive function to print reporting chain upwards
void getReportingChain(Employee *emp) {
  printf("%s", emp->name);
  if (emp->manager != NULL) {
    printf(" -> ");
    getReportingChain(emp->manager);
  } else {
    printf(" [CEO]");
  }
}

// Recursive function to count levels upwards to CEO
int countLevels(Employee *emp) {
  if (emp->manager == NULL) {
    return 1;
  }
  return 1 + countLevels(emp->manager);
}

// Helper to start the recursive display
void displaySubordinates(Employee *manager, Department *dept) {
  displaySubordinatesRecursive(manager, dept, 1);
}

void displaySubordinatesRecursive(Employee *manager, Department *dept,
                                  int level) {
  for (int i = 0; i < dept->empCount; i++) {
    if (dept->employees[i]->manager == manager) {
      // Print with indentation
      for (int j = 0; j < level; j++)
        printf("  ");
      printf("- %s (%s)\n", dept->employees[i]->name,
             dept->employees[i]->designation);

      // Recurse for this employee's subordinates
      displaySubordinatesRecursive(dept->employees[i], dept, level + 1);
    }
  }
}
