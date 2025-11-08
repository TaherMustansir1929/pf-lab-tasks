#include <stdio.h>

int main() {
  int image[3][3][3]; // [channel][row][col] - 0=R, 1=G, 2=B
  int i, j, k;
  int channelSum[3] = {0, 0, 0};
  float channelAvg[3];
  float overallBrightness;
  int totalSum = 0;
  char channels[3] = {'R', 'G', 'B'};

  printf("\n Image Pixel Processing (3x3 RGB)\n\n");

  // Input image data
  printf("Enter pixel intensity values (0-255) for 3x3 image\n");

  for (i = 0; i < 3; i++) {
    printf("\n %c Channel\n", channels[i]);
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        printf("Pixel [%d][%d] %c-value: ", j, k, channels[i]);
        scanf("%d", &image[i][j][k]);
      }
    }
  }

  // Display each channel
  printf("\n Image Data Visualization\n");
  for (i = 0; i < 3; i++) {
    printf("\n %c Channel\n", channels[i]);
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        printf("%3d ", image[i][j][k]);
      }
      printf("\n");
    }
  }

  // Calculate channel averages
  printf("\n Channel Intensity Analysis\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        channelSum[i] += image[i][j][k];
      }
    }
    channelAvg[i] = channelSum[i] / 9.0;
    totalSum += channelSum[i];
    printf("%c Channel - Total %d, Average Intensity %.2f\n", channels[i],
           channelSum[i], channelAvg[i]);
  }

  // Calculate overall brightness
  overallBrightness = totalSum / 27.0;
  printf("\n Overall Image Brightness\n");
  printf("Overall Brightness %.2f (out of 255)\n", overallBrightness);
  printf("Brightness Percentage %.2f%%\n", (overallBrightness / 255) * 100);

  // Identify dominant color
  printf("\n Dominant Color Analysis\n");
  int maxChannel = 0;
  for (i = 1; i < 3; i++) {
    if (channelAvg[i] > channelAvg[maxChannel]) {
      maxChannel = i;
    }
  }

  printf("Dominant Color %c (", channels[maxChannel]);
  if (maxChannel == 0)
    printf("Red");
  else if (maxChannel == 1)
    printf("Green");
  else
    printf("Blue");
  printf(")\n");
  printf("Dominant Channel Average %.2f\n", channelAvg[maxChannel]);

  // Color balance report
  printf("\n Color Balance Report\n");
  for (i = 0; i < 3; i++) {
    float percentage =
        (channelAvg[i] / (channelAvg[0] + channelAvg[1] + channelAvg[2])) * 100;
    printf("%c Channel Contribution %.2f%%\n", channels[i], percentage);
  }

  // Image characteristics
  printf("\n Image Characteristics\n");
  if (overallBrightness < 85) {
    printf("Image Classification DARK\n");
  } else if (overallBrightness < 170) {
    printf("Image Classification NORMAL\n");
  } else {
    printf("Image Classification BRIGHT\n");
  }

  // Check if grayscale (all channels similar)
  float diff1 = channelAvg[0] - channelAvg[1];
  float diff2 = channelAvg[1] - channelAvg[2];
  float diff3 = channelAvg[0] - channelAvg[2];

  if (diff1 < 10 && diff1 > -10 && diff2 < 10 && diff2 > -10 && diff3 < 10 &&
      diff3 > -10) {
    printf("Color Distribution GRAYSCALE (channels balanced)\n");
  } else {
    printf("Color Distribution COLORED (channels vary)\n");
  }

  return 0;
}
