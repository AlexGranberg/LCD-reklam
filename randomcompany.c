#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

int randomCompany(int valueIn)
{
    if(valueIn < 5001) return 1;
    if(valueIn < 8001) return 2;
    if(valueIn < 9501) return 3;
    if(valueIn < 10501) return 4;
}