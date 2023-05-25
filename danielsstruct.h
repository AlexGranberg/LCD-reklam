#ifndef __D_STRUCT_H
#define __D_STRUCT_H

typedef struct
{
    int ID;
    char name[50];
    int comercials;
    char firstComercial[50];
    char secondComercial[50];
    char thirdComercial[50];
} Company;

typedef struct
{
    Company *CompanyRegister;
    int numberOfCompanies;
} CompanyList;

#endif

/*
typedef struct
{
    int cardNumber;
    int access;
    time_t dateAdded;
} Card;

typedef struct
{
    Card *cards;
    int numberOfCards;
} CardStack;
*/