#include <stdio.h>
#include <math.h>

void raizes(float a, float b, float c, float *x1, float *x2);

float delta;

int main()
{

    int resp = 1;
    float a, b, c, x1, x2;

    while (resp != 0)
    {
        scanf("%f %f %f", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        raizes(a, b, c, &x1, &x2);
        if (delta >= 0)
        {
            printf("%.1f %.1f\n", x1, x2);
        }
        else
        {
            printf("complexo\n");
        }
    }

    return 0;
}

void raizes(float a, float b, float c, float *x1, float *x2)
{
    delta = (b * b) - (4 * a * c);
    *x1 = ((-1 * b) + (sqrt(delta))) / (2 * a);
    *x2 = ((-1 * b) - (sqrt(delta))) / (2 * a);
}