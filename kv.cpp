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
        if (is_zero(D))
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
            printf("\nNo solutions\n\n");
            break;

        case 1:
            printf("\nx1 = x2 = x = %lg\n\n", *x1);
            break;

        case 2:
            printf("\nx1 = %f\nx2 = %lg\n\n", *x1, *x2);
            break;

        case 3:
            printf("\nAny number\n\n");
            break;

        default:
            printf("\nError");
            break;
    }

}


int Unit_Solve_Square_Test (int Test_Number, double a, double b, double c, int nRoots_Ref, double x1_Ref, double x2_Ref)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare (a, b, c, &x1, &x2);
    if (is_Equal (nRoots, nRoots_Ref) && is_Equal (x1, x1_Ref) && is_Equal (x2, x2_Ref))
    {
        printf ("Test %d is OK\n\n", Test_Number);
        return 1;
    }
    else
    {
        printf ("Test Number %d FAILED\n           nRoots = %d  x1 = %lg    x2 = %lg\nShould be: nRoots = %d  x1 = %lg    x2 = %lg\n\n", Test_Number, nRoots, x1, x2, nRoots_Ref, x1_Ref, x2_Ref);
        return 0;
    }

}


int Unit_Test ();

#include "test.h"


void Clear_Buffer ()
{
    while (getchar() != '\n') {;}
}

void Buffer_Clear_Test (double* a, double* b, double* c)
{
    bool OK = false;
    while (OK == false)
    {
        int nInput_Numbers = scanf ("%lg %lg %lg", a, b, c);
        if (nInput_Numbers < 3)
        {
            printf ("Please, enter numbers:\n");
            Clear_Buffer ();
        }
        else
        OK = true;
    }
}

int main ()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int nFails = Unit_Test();
    printf ("\n\n%d Fail(s)\n", nFails);
    printf("\nEnter a, b and c:\n");
    Buffer_Clear_Test (&a, &b, &c);
    int nRoots = SolveSquare (a, b, c, &x1, &x2);
    Print_Roots (nRoots, &x1, &x2);


    return 0;
}
