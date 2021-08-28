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


int is_Equal (double value1, double value2)
{
    double difference = fabs(value1)-fabs(value2);
    return (fabs(difference) < E);
}


void Print_Roots (int Number_of_Roots, double* x1, double* x2)
{
    switch (Number_of_Roots)
    {
        case 0:
            printf("No solutions\n\n");
            break;

        case 1:
            printf("x1 = x2 = x = %lg\n\n", *x1);
            break;

        case 2:
            printf("x1 = %f\nx2 = %lg\n\n", *x1, *x2);
            break;

        case 3:
            printf("Any number\n\n");
            break;

        default:
            printf("Error");
            break;
    }

}


int Unit_Solve_Square_Test (int Test_Number, double a, double b, double c, int nRoots_Ref, double x1_Ref, double x2_Ref)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = SolveSquare (a, b, c, &x1, &x2);
    if (is_Equal (nRoots, nRoots_Ref) && is_Equal (x1, x1_Ref) && is_Equal (x2, x2_Ref))
    {
        printf ("Test Number %d FAILED\nnRoots = %d  x1 = %lg    x2 = %lg\nShould be: nRoots = %d  x1 = %lg    x2 = %lg\n\n", Test_Number, nRoots, x1, x2, nRoots_Ref, x1_Ref, x2_Ref);
        return 1;
    }
    else
    {
        printf ("Test is OK");
        return 0;
    }

}



int main ()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    printf("Enter a, b and c:\n");
    scanf("%lg %lg %lg", &a, &b, &c);
    int nRoots = SolveSquare (a, b, c, &x1, &x2);
    Print_Roots (nRoots, &x1, &x2);

    int nFails = Unit_Solve_Square_Test(1, 1, -3, 2, 2, 1, 3);
    printf ("\n\n%d Fail(s)", nFails);

    return 0;
}
