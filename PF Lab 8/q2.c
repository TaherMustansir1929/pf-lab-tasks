#include <math.h>
#include <stdio.h>

int main() {
  float mat[5][5];
  int r, c, i, j;
  int sq, zero, idn, diag, scl, up, low, sym, skew, row_m, col_m, idem, nil;
  float det;

  printf("Matrix Type Check\n\n");

  printf("Rows (max 5): ");
  scanf("%d", &r);
  printf("Cols (max 5): ");
  scanf("%d", &c);

  printf("\nEnter matrix vals:\n");
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      printf("Element [%d][%d]: ", i, j);
      scanf("%f", &mat[i][j]);
    }
  }

  printf("\nMatrix:\n");
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      printf("%.2f\t", mat[i][j]);
    }
    printf("\n");
  }

  printf("\n Matrix Types Found\n\n");

  sq = (r == c);
  if (sq)
    printf("Square Matrix (Size %dx%d)\n", r, c);
  else
    printf("Rectangular Matrix (Size %dx%d)\n", r, c);

  zero = 1;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (mat[i][j] != 0) {
        zero = 0;
        break;
      }
    }
    if (!zero)
      break;
  }
  if (zero)
    printf("Zero Matrix\n");

  idn = sq;
  if (sq) {
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
        if (i == j && mat[i][j] != 1)
          idn = 0;
        if (i != j && mat[i][j] != 0)
          idn = 0;
      }
    }
    if (idn)
      printf("Identity Matrix\n");
  }

  diag = sq;
  if (sq) {
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
        if (i != j && mat[i][j] != 0) {
          diag = 0;
          break;
        }
      }
      if (!diag)
        break;
    }
    if (diag && !idn && !zero)
      printf("Diagonal Matrix\n");
  }

  scl = sq && diag;
  if (sq && diag && !idn && !zero) {
    float fd = mat[0][0];
    for (i = 1; i < r; i++) {
      if (mat[i][i] != fd) {
        scl = 0;
        break;
      }
    }
    if (scl)
      printf("Scalar Matrix\n");
  }

  up = sq;
  if (sq) {
    for (i = 0; i < r; i++) {
      for (j = 0; j < i; j++) {
        if (mat[i][j] != 0) {
          up = 0;
          break;
        }
      }
      if (!up)
        break;
    }
    if (up && !diag)
      printf("Upper Triangular Matrix\n");
  }

  low = sq;
  if (sq) {
    for (i = 0; i < r; i++) {
      for (j = i + 1; j < c; j++) {
        if (mat[i][j] != 0) {
          low = 0;
          break;
        }
      }
      if (!low)
        break;
    }
    if (low && !diag)
      printf("Lower Triangular Matrix\n");
  }

  sym = sq;
  if (sq) {
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
        if (mat[i][j] != mat[j][i]) {
          sym = 0;
          break;
        }
      }
      if (!sym)
        break;
    }
    if (sym)
      printf("Symmetric Matrix\n");
  }

  skew = sq;
  if (sq) {
    for (i = 0; i < r; i++) {
      if (mat[i][i] != 0) {
        skew = 0;
        break;
      }
    }
    if (skew) {
      for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
          if (mat[i][j] != -mat[j][i]) {
            skew = 0;
            break;
          }
        }
        if (!skew)
          break;
      }
    }
    if (skew)
      printf("Skew Symmetric Matrix\n");
  }

  if (sq) {
    if (r == 2) {
      det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    } else if (r == 3) {
      det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
            mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
            mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    } else
      det = 1;

    if (det == 0)
      printf("Matrix Singular (Det = 0)\n");
    else
      printf("Non Singular Matrix (Det = %.2f)\n", det);
  }

  row_m = (r == 1);
  if (row_m)
    printf("Row Matrix\n");

  col_m = (c == 1);
  if (col_m)
    printf("Column Matrix\n");

  if (sq && r <= 3) {
    float prod[5][5];
    idem = 1;
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
        prod[i][j] = 0;
        for (int k = 0; k < c; k++) {
          prod[i][j] += mat[i][k] * mat[k][j];
        }
      }
    }
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
        if (fabs(prod[i][j] - mat[i][j]) > 0.01) {
          idem = 0;
          break;
        }
      }
      if (!idem)
        break;
    }
    if (idem)
      printf("Idempotent Matrix\n");
  }

  if (sq && r <= 3) {
    float powr[5][5], tmp[5][5];
    nil = 0;
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
        powr[i][j] = mat[i][j];
      }
    }
    for (int p = 2; p <= 5; p++) {
      for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
          tmp[i][j] = 0;
          for (int k = 0; k < c; k++) {
            tmp[i][j] += powr[i][k] * mat[k][j];
          }
        }
      }
      int allz = 1;
      for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
          if (fabs(tmp[i][j]) > 0.01) {
            allz = 0;
            break;
          }
        }
        if (!allz)
          break;
      }
      if (allz) {
        nil = 1;
        printf("Nilpotent Matrix (A^%d = 0)\n", p);
        break;
      }
      for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
          powr[i][j] = tmp[i][j];
        }
      }
    }
  }

  return 0;
}
