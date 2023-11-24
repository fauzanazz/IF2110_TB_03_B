#include <stdio.h>
#include "datetime.h"

int maxDay = GetMaxDay(2, 2020); // Leap year, February
printf("Max day in February 2020: %d\n", maxDay); // Expected output: 29

maxDay = GetMaxDay(2, 2021); // Non-leap year, February
printf("Max day in February 2021: %d\n", maxDay); // Expected output: 28

maxDay = GetMaxDay(4, 2021); // April
printf("Max day in April 2021: %d\n", maxDay); // Expected output: 30

maxDay = GetMaxDay(7, 2021); // July
printf("Max day in July 2021: %d\n", maxDay); // Expected output: 31