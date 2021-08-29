int Unit_Test ()
{
    int failed = 0;
//                                 #      a      b     c   nRoots x1    x2
    if (Unit_Solve_Square_Test(    1,     1,    -3,    2,    2,    1,    2) == 0) failed++ ;
    if (Unit_Solve_Square_Test(    2,     1,    -5,    4,    2,    1,    4) == 0) failed++ ;
    if (Unit_Solve_Square_Test(    3,     1,    -5,    6,    2,    2,    3) == 0) failed++ ;
    if (Unit_Solve_Square_Test(    4,     2,    -5,    2,    2,  0.5,    2) == 0) failed++ ;
    if (Unit_Solve_Square_Test(    5,     1,    -9,    8,    2,    1,    7) == 0) failed++ ;
    if (Unit_Solve_Square_Test(    6,     1,    -3,    4,    0,    0,    0) == 0) failed++ ;
    if (Unit_Solve_Square_Test(    7,     1,    -4,    4,    1,    2,    0) == 0) failed++ ;
    if (Unit_Solve_Square_Test(    8,     0,    -3,    3,    1,    1,    0) == 0) failed++ ;
    if (Unit_Solve_Square_Test(    9,     0,     0,    1,    0,    0,    0) == 0) failed++ ;
    if (Unit_Solve_Square_Test(    10,    0,     0,    0,    3,    0,    0) == 0) failed++ ;

    return failed;

}