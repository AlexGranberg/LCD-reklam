#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

int randomCompany(int valueIn)
{
    if(valueIn < 4) return 1;
    if(valueIn < 6) return 2;
    if(valueIn < 8) return 3;
    if(valueIn < 9) return 4;
}