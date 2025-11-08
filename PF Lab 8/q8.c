#include <stdio.h>

int main() {
  float temps[3][7][3];
  int i, j, k;
  float day_avg[3][7];
  float city_avg[3];
  float city_tot[3] = {0, 0, 0};
  char cities[3][20] = {"City A", "City B", "City C"};
  char times[3][10] = {"Morning", "Noon", "Night"};
  char days[7][10] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                      "Friday", "Saturday", "Sunday"};

  printf("Weather Data\n\n");

  printf("Enter temps:\n");
  for (i = 0; i < 3; i++) {
    printf("\n %s \n", cities[i]);
    for (j = 0; j < 7; j++) {
      printf("%s:\n", days[j]);
      for (k = 0; k < 3; k++) {
        printf("  %s: ", times[k]);
        scanf("%f", &temps[i][j][k]);
      }
    }
  }

  printf("\n Temp Data\n");
  for (i = 0; i < 3; i++) {
    printf("\n%s:\n", cities[i]);
    printf("Day\t\tMorning\tNoon\tNight\n");
    for (j = 0; j < 7; j++) {
      printf("%s\t", days[j]);
      for (k = 0; k < 3; k++) {
        printf("%.1f\t", temps[i][j][k]);
      }
      printf("\n");
    }
  }

  printf("\n Daily Avgs\n");
  for (i = 0; i < 3; i++) {
    printf("\n%s:\n", cities[i]);
    for (j = 0; j < 7; j++) {
      float d_total = 0;
      for (k = 0; k < 3; k++) {
        d_total += temps[i][j][k];
      }
      day_avg[i][j] = d_total / 3.0;
      printf("  %s: %.2f\n", days[j], day_avg[i][j]);

      city_tot[i] += day_avg[i][j];
    }
  }

  printf("\n Weekly Avgs\n");
  for (i = 0; i < 3; i++) {
    city_avg[i] = city_tot[i] / 7.0;
    printf("%s: %.2f\n", cities[i], city_avg[i]);
  }

  int hot_c = 0, cold_c = 0;
  for (i = 1; i < 3; i++) {
    if (city_avg[i] > city_avg[hot_c]) {
      hot_c = i;
    }
    if (city_avg[i] < city_avg[cold_c]) {
      cold_c = i;
    }
  }

  printf("\n Extremes\n");
  printf("Hot: %s (%.2f)\n", cities[hot_c], city_avg[hot_c]);
  printf("Cold: %s (%.2f)\n", cities[cold_c], city_avg[cold_c]);

  printf("\n Extremes Per City\n");
  for (i = 0; i < 3; i++) {
    float max_t = temps[i][0][0];
    float min_t = temps[i][0][0];
    int max_d = 0, max_ti = 0;
    int min_d = 0, min_ti = 0;

    for (j = 0; j < 7; j++) {
      for (k = 0; k < 3; k++) {
        if (temps[i][j][k] > max_t) {
          max_t = temps[i][j][k];
          max_d = j;
          max_ti = k;
        }
        if (temps[i][j][k] < min_t) {
          min_t = temps[i][j][k];
          min_d = j;
          min_ti = k;
        }
      }
    }

    printf("\n%s:\n", cities[i]);
    printf("  Hot: %.1f on %s %s\n", max_t, days[max_d], times[max_ti]);
    printf("  Cold: %.1f on %s %s\n", min_t, days[min_d], times[min_ti]);
  }

  printf("\n Summary\n");
  printf("\n1. Range:\n");
  float g_max = temps[0][0][0];
  float g_min = temps[0][0][0];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 7; j++) {
      for (k = 0; k < 3; k++) {
        if (temps[i][j][k] > g_max)
          g_max = temps[i][j][k];
        if (temps[i][j][k] < g_min)
          g_min = temps[i][j][k];
      }
    }
  }
  printf("    Max: %.1f, Min: %.1f\n", g_max, g_min);

  printf("\n2. Consistency:\n");
  for (i = 0; i < 3; i++) {
    float var = 0;
    for (j = 0; j < 7; j++) {
      var += (day_avg[i][j] - city_avg[i]) * (day_avg[i][j] - city_avg[i]);
    }
    var /= 7.0;
    printf("    %s: ", cities[i]);
    if (var < 2)
      printf("Very Stable\n");
    else if (var < 5)
      printf("Stable\n");
    else if (var < 10)
      printf("Moderate\n");
    else
      printf("Varies a lot\n");
  }

  printf("\n3. Time Patterns:\n");
  for (k = 0; k < 3; k++) {
    float t_total = 0;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 7; j++) {
        t_total += temps[i][j][k];
      }
    }
    printf("    %s Avg: %.2f\n", times[k], t_total / 21.0);
  }

  return 0;
}