#include <stdbool.h>
#include <stdio.h>


#define ROWS 5
#define COLS 5
#define MAX_PATH 100

// Structure to store position
typedef struct {
  int row;
  int col;
} Point;

// Maze definition (0 = path, 1 = wall)
int maze[ROWS][COLS] = {{0, 1, 0, 0, 0},
                        {0, 1, 0, 1, 0},
                        {0, 0, 0, 1, 0},
                        {1, 1, 0, 1, 0},
                        {0, 0, 0, 0, 0}};

Point path[MAX_PATH];
int pathIndex = 0;
int visited[ROWS][COLS] = {0};

// Function Prototypes
bool solveMaze(int r, int c);
void printPath();
bool isValid(int r, int c);

int main() {
  printf("Maze Structure (0=Path, 1=Wall):\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }

  printf("\nFinding path from (0,0) to (%d,%d)...\n", ROWS - 1, COLS - 1);

  if (solveMaze(0, 0)) {
    printf("Path found!\n");
    printPath();
  } else {
    printf("No path exists.\n");
  }

  return 0;
}

bool isValid(int r, int c) {
  // Check bounds, wall, and visited status
  return (r >= 0 && r < ROWS && c >= 0 && c < COLS && maze[r][c] == 0 &&
          !visited[r][c]);
}

bool solveMaze(int r, int c) {
  // Check if current position is valid
  if (!isValid(r, c)) {
    return false;
  }

  // Add current position to path
  path[pathIndex].row = r;
  path[pathIndex].col = c;
  pathIndex++;
  visited[r][c] = 1; // Mark as visited

  // Base Case: Reached bottom-right corner
  if (r == ROWS - 1 && c == COLS - 1) {
    return true;
  }

  // Recursive Step: Try moving in all 4 directions (Down, Right, Up, Left)
  // Prioritizing Down and Right for typical top-left to bottom-right flow

  // Down
  if (solveMaze(r + 1, c))
    return true;

  // Right
  if (solveMaze(r, c + 1))
    return true;

  // Up
  if (solveMaze(r - 1, c))
    return true;

  // Left
  if (solveMaze(r, c - 1))
    return true;

  // Backtracking: Unmark visited and remove from path
  // Note: In some maze variations, we don't unmark visited to prevent
  // re-visiting same bad paths. However, for simple pathfinding without cycles,
  // keeping it visited is fine. But to strictly "backtrack" the path array
  // needs to be decremented.
  pathIndex--;
  // We usually don't unmark 'visited' for simple path existence to avoid
  // infinite loops in open areas, but if we wanted to find *all* paths, we
  // would. For *a* path, keeping it visited is efficient.

  return false;
}

void printPath() {
  printf("Path Coordinates:\n");
  for (int i = 0; i < pathIndex; i++) {
    printf("(%d, %d)", path[i].row, path[i].col);
    if (i < pathIndex - 1)
      printf(" -> ");
  }
  printf("\n");
}
