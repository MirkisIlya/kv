#include <stdio.h>
#include <math.h>
#include <assert.h>



const double E = 1e-5;

bool is_zero (double value)
{
    return (fabs(value) < E);
}


int SolveSquare (double a, double b, double c, double *x1, double *x2)
{
    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (is_zero(a))
    {
        if (is_zero(b))
        {
            return (is_zero(c)) ? 3 : 0;
        }
     *x1 = -c / b;
     return 1;
    }
    else
    {
        double D = b*b - 4*a*c;
        if (D == 0)
        {
            *x1 = -b / (2*a);
            return 1;
        }
        else if (D < 0)
            return 0;
        else
        {
            double sqrt_D = sqrt(D);

            *x1 = (-b - sqrt_D) / (2*a);
            *x2 = (-b + sqrt_D) / (2*a);

            return 2;
        }
    }
}


void Print_Roots (int Number_of_Roots, double* x1, double* x2)
{
    switch (Number_of_Roots)
    {
        case 0:
            printf("No solutions\n");
            break;

        case 1:
            printf("x1 = x2 = x = %f", *x1);
            break;

        case 2:
            printf("x1 = %f\nx2 = %f", *x1, *x2);
            break;

        case 3:
            printf("Any number");
            break;

        default:
            printf("Error");
            break;
    }

}



int main ()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    printf("Enter a, b and c: ");
    scanf("%lg %lg %lg", &a, &b, &c);
    int nRoots = SolveSquare (a, b, c, &x1, &x2);
    Print_Roots (nRoots, &x1, &x2);

    return 0;
}

