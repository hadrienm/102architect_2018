#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv)
{
  if (argc < 5) {
    return(84);
  }
    int a = 0;
    float x = atof(argv[1]);
    float y = atof(argv[2]);
    float first_line[3] = {1.00, 0.00, 0.00};
    float seconde_line[3] = {0.00, 1.00, 0.00};
    float last_line[3] = {0.00, 0.00, 1.00};
    float save_first[3] = {0.00, 0.00, 0.00};
    float save_seconde[3] = {0.00, 0.00, 0.00};
    float save_x = x;
    float save_y = y;

    for (int b = 2; b != argc; b++) {
            if (argv[b][a] == '-' && argv[b][a + 1] == 't') {
                printf("Translation along vector (%0.0f, %0.0f)\n", atof(argv[b + 1]), atof(argv[b + 2]));
                a = 0;
                x = x  + atof(argv[b + 1]);
                y = y  + atof(argv[b + 2]);
                first_line[2] += atof(argv[b + 1]);
                seconde_line[2] += atof(argv[b + 2]);
                b += 2;
            }
            if (argv[b][a] == '-' && argv[b][a + 1] == 'z') {
                printf("Scaling by factors %0.0f and %0.0f \n", atof(argv[b + 1]), atof(argv[b + 2]));
                a = 0;
                x = x * atof(argv[b + 1]);
                y = y * atof(argv[b + 2]);
                first_line[0] *= atof(argv[b + 1]);
                first_line[1] *= atof(argv[b + 1]);
                first_line[2] *= atof(argv[b + 1]);
                seconde_line[0] *= atof(argv[b + 2]);
                seconde_line[1] *= atof(argv[b + 2]);
                seconde_line[2] *= atof(argv[b + 2]);
                b += 2;
            }
            if (argv[b][a] == '-' && argv[b][a + 1] == 'r') {
                printf("Rotation by a %0.0f degree angles\n", atof(argv[b + 1]));
                float save_x = x;
                float angle = atof(argv[b + 1]);

                angle = angle * M_PI;
                angle = angle / 180;
                x = cos(angle) * x - sin(angle) * y;
                y = sin(angle) * save_x + cos(angle) * y;
                save_first[0] = first_line[0];
                save_first[1] = first_line[1];
                save_first[2] = first_line[2];

                save_seconde[0] = seconde_line[0];
                save_seconde[1] = seconde_line[1];
                save_seconde[2] = seconde_line[2];

                first_line[0] = cos(angle) * save_first[0] - sin(angle) * save_seconde[0];
                first_line[1] = cos(angle) * save_first[1] - sin(angle) * save_seconde[1];
                first_line[2] = cos(angle) * save_first[2] - sin(angle) * save_seconde[2];

                seconde_line[0] = sin(angle) * save_first[0] + cos(angle) * save_seconde[0];
                seconde_line[1] = sin(angle) * save_first[1] + cos(angle) * save_seconde[1];
                seconde_line[2] = sin(angle) * save_first[2] + cos(angle) * save_seconde[2];
                b += 1;

            } if (argv[b][a] == '-' && argv[b][a + 1] == 's') {
              printf("Reflection over an axis with an inclination angle of %0.0f degrees\n", atof(argv[b + 1]));
              float angle = atof(argv[b + 1]);
              float save_x = x;
              angle = angle * M_PI;
              angle = angle / 180;

              x = cos(2 * angle) * x + sin(2 * angle) * y;
              y = sin(2 * angle) * save_x - cos(2 * angle) * y;
              save_first[0] = first_line[0];
              save_first[1] = first_line[1];
              save_first[2] = first_line[2];

              save_seconde[0] = seconde_line[0];
              save_seconde[1] = seconde_line[1];
              save_seconde[2] = seconde_line[2];

              first_line[0] = cos(2 * angle) * save_first[0] + sin(2 * angle) * save_seconde[0];
              first_line[1] = cos(2 * angle) * save_first[1] + sin(2 * angle) * save_seconde[1];
              first_line[2] = cos(2 * angle) * save_first[2] + sin(2 * angle) * save_seconde[2];

              seconde_line[0] = sin(2 * angle) * save_first[0] - cos(2 * angle) * save_seconde[0];
              seconde_line[1] = sin(2 * angle) * save_first[1] - cos(2 * angle) * save_seconde[1];
              seconde_line[2] = sin(2 * angle) * save_first[2] - cos(2 * angle) * save_seconde[2];
              b += 1;
            }
    }
    printf("%0.2f %0.2f %0.2f\n", first_line[0], first_line[1], first_line[2]);
    printf("%0.2f %0.2f %0.2f\n", seconde_line[0], seconde_line[1], seconde_line[2]);
    printf("%0.2f %0.2f %0.2f\n", last_line[0], last_line[1], last_line[2]);
    printf("(%0.0f, %0.0f) => ", save_x, save_y);
    printf("(%0.2f, %0.2f)\n", x, y);
}
