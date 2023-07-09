#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x - x - 1;
}

double MullerMethod(double x0, double x1, double x2, double error)
{
    double h1, h2, d1, d2, root, error1 = 100, a, b, c, x3;
    int iteration=0;
    
    h1 = x1 - x0;
    h2 = x2 - x1;
    d1 = (f(x1) - f(x0)) / h1;
    d2 = (f(x1) - f(x0)) / h1;
    while (error1 >= error)
    {
        c = f(x2);
        a = (d2 - d1) / (h1 + h2);
        b = (h2 * a) + d2;
        double dsk = sqrt(b * b - 4 * a * c), dominot;
        if (abs(b + dsk) > abs(b - dsk))
        {
            dominot = b + dsk;
        }
        else
            dominot = b - dsk;
        double dx = -2 * c / dominot;
        x0 = x1;
        x1 = x2;
        x2 = x2 + dx;
        h1 = x1 - x0;
        h2 = x2 - x1;
        d1 = (f(x1) - f(x0)) / h1;
        d2 = (f(x1) - f(x0)) / h2;
        root = x2;
        error1 = abs((x2 - x1) / x2) * 100;
        cout << "Iteration " << iteration << ": x0 = " << x0 << ", x1 = " << x1 << ", x2 = " << x2 << " ";
        cout << "Percentage error: " << error1 << "%" << endl;
    }
    return root;
}

int main()
{
    double x0, x1, x2, error;
    cin >> x0 >> x1 >> x2 >> error;
    double root = MullerMethod(x0, x1, x2, error);
    cout << "Root : " << root << endl;
    return 0;
}
