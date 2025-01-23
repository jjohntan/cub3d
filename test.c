#include <stdio.h>

# define ANGLE 170
# define FOV 66
# define WIDTH 200.0
# define STRIPE (FOV / WIDTH)

float angle(float i)
{
    if (i >= 360)
        i -= 360;
    else if (i < 0)
        i += 360;
    return (i);
}
int main()
{
    float i = angle(ANGLE - FOV / 2);
    float end = angle(ANGLE + FOV / 2);
    int counter = WIDTH;

    printf("start: %f end %f \n", i, end);
    while (counter--)
    {
        printf("%f\n", i);
        i = angle(i + STRIPE);
    }
}