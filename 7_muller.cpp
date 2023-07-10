#include <stdio.h>
#include <math.h>
const int MAX = 10000;
float f(float x)
{
    return 1 * pow(x, 3) + 2 * x * x + 10 * x - 20;
}
int muller(float a, float b, float c)
{
    int i;
    float result;
    for (i = 0;; ++i)
    {
        float f1 = f(a);
        float f2 = f(b);
        float f3 = f(c);
        float d1 = f1 - f3;
        float d2 = f2 - f3;
        float h1 = a - c;
        float h2 = b - c;
        float cc = f3;
        float bb = (((d2 * pow(h1, 2)) - (d1 * pow(h2, 2))) / ((h1 * h2) * (h1 - h2)));
        float aa = (((d1 * h2) - (d2 * h1)) / ((h1 * h2) * (h1 - h2)));
        float x = ((-2 * cc) / (bb + abs(sqrt(bb * bb - 4 * cc * aa))));
        float y = ((-2 * cc) / (bb - abs(sqrt(bb * bb - 4 * cc * aa))));

        if (x >= y)
            result = x + c;
        else
            result = y + c;

        float m = result * 10000;
        float n = c * 10000;
        m = floor(m);
        n = floor(n);
        if (m == n)
            break;
        a = b;
        b = c;
        c = result;
        if (i > MAX)
        {
            printf("Root can't be found using Muller method\n");
            break;
        }
    }
    if (i <= MAX)
        printf("The root is %f", result);
    return 0;
}
int main()
{
    float a = 1, b = 3, c = 2;
    muller(a, b, c);
    return 0;
}
