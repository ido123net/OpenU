#include <stdio.h>
#include <math.h>

#define PRECISION 0.000001
#define RANGE 25

double num;
double my_res;
double math_res;
double my_sin(double x);
int in_range(double x);

/* A program that receives a number from the user,
    and calculates its sine compared to the calculation of the sine by the mathematical library */
int main()
{
    printf("Enter a number in range [-25, 25] to calculate its sine:\n");
    scanf("%lf", &num);
    while (!in_range(num))
    {
        printf("the number you entered is not in range [-25, 25] try again:\n");
        scanf("%lf", &num);
    }
    printf("the number you entered is %f and its sine is: \n\t%f\nthe result of the math libary is: \n\t%f\n", num, my_sin(num), sin(num));
    return 0;
}

/* returns 0 if the number not in the range [-25, 25] 1 otherwise */
int in_range(double x)
{
    if (x < -RANGE || x > RANGE)
    {
        return 0;
    }
    return 1;
}

int sign;
int next_multiply;
double numerator;
double denominator;
double next;
double next_num(double x);
double my_abs(double x);

/* An approximate calculation of sine, according to the Taylor column */
double my_sin(double x)
{
    sign = 1;
    numerator = x;
    denominator = 1;
    next_multiply = 2;
    double res = numerator / denominator;
    next = next_num(x);
    while (my_abs(next) >= PRECISION)
    {
        res += (sign * next);
        next = next_num(x);
    }
    return res;
}

/* returns the next num in Taylor series and update the sign */
double next_num(double x)
{
    numerator = (numerator * x * x);                      /* (x^y * x * x) = x^(y+2) */
    denominator *= (next_multiply * (next_multiply + 1)); /* (x! * (x+1) * (x+2)) = (x+2)! */
    next_multiply += 2;                                   /* update for next factorial calculation */
    sign *= -1;
    return numerator / denominator;
}

double my_abs(double x)
{
    if (x < 0)
    {
        return x * -1;
    }
    return x;
}
