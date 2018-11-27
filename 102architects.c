#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv)
{
    int a = 0;
    float x = atof(argv[1]);
    float y = atof(argv[2]);

    for (int b = 2; b != argc; b++) {
            if (argv[b][a] == '-' && argv[b][a + 1] == 't') {
                a = 0;
                x = x  + atof(argv[b + 1]);
                y = y  + atof(argv[b + 2]);
                b += 2;
            }
            if (argv[b][a] == '-' && argv[b][a + 1] == 'z') {
                a = 0;
                x = x * atof(argv[b + 1]);
                y = y * atof(argv[b + 2]);
                b += 2;
            }
            if (argv[b][a] == '-' && argv[b][a + 1] == 'r') {
                float angle = atof(argv[b + 1]);
                float save_x = x;

                angle = angle * M_PI;
                angle = angle / 180;
                x = cos(angle) * x - sin(angle) * y;
                y = sin(angle) * save_x + cos(angle) * y;
                b += 1;

            } if (argv[b][a] == '-' && argv[b][a + 1] == 's') {
              float angle = atof(argv[b + 1]);
              float save_x = x;

              angle = angle * M_PI;
              angle = angle / 180;

              x = cos(2 * angle) * x + sin(2 * angle) * y;
              y = sin(2 * angle) * save_x - cos(2 * angle) * y;
              b += 1;
            }
    }
    printf("%0.2f %0.2f\n", x, y);
}
