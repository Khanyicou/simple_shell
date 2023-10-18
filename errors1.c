c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rint_error(double x)
{
if (isnan(x))
{
printf("Error: The number is NaN.\n");
    
}
else if (isinf(x))
{
printf("Error: The number is infinite.\n");
}
}

void print_d(double x)
{

if (isnan(x))
{
printf("NaN");
}
else if (isinf(x))
{
printf("Inf");
}
else
{
printf("%.1f", x);
}
}

void convert_number(double number, int base)
{
if (base < 2 || base > 36)
{
printf("Error: The base should be between 2 and 36.\n");
return;
}

char *ptr, *end_ptr;
double sign = 1.0;

if (number < 0.0)
{
sign = -1.0;
number = -number;
}

ptr = malloc(100);
if (ptr == NULL) {
printf("Error: Memory allocation failed.\n");
return;
}

end_ptr = ptr;

do
{
int digit = (int)fmod(number, (double)base);
*end_ptr++ = (digit < 10) ? digit + '0' : digit - 10 + 'A';
number /= base;
}
while (number > 0.0);


if (sign < 0.0) {
*end_ptr++ = '-';
}

while (end_ptr > ptr)
{
*--end_ptr;
}

printf("%s\n", ptr);
free(ptr);
}

int main()
{
double number;
int base;

printf("Enter a number: ");
scanf("%lf", &number);

printf("Enter the base for conversion (2-36): ");
scanf("%d", &base);

print_error(number);
print_d(number);
printf("\n");

convert_number(number, base);

return (0);
}
