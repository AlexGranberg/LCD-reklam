#ifndef __STRUCT_H
#define __STRUCT_H

typedef struct {

int ID = 1;
char name[50] = "Hederlige Harrys Bilar";
int comercials = 3;
char firstComercial[50] = "Köp bil hos Harry";
char secondComercial[50] = "En god bilaffär (för Harry!)";
char thirdComercial[50] = "Hederlige Harrys Bilar";
 
} Harrys;

typedef struct {

int ID = 2;
char name[50] = "Farmor Ankas Pajer AB";
int comercials = 2;
char firstComercial[50] = "Köp paj hos Farmor Anka";
char secondComercial[50] = "Skynda innan Mårten ätit alla pajer";
 
} Farmor;

typedef struct {

int ID = 3;
char name[50] = "Svarte Petters Svartbyggen";
int comercials = 2;
char firstComercial[50] = "Låt Petter bygga åt dig";
char secondComercial[50] = "Bygga svart? Ring Petter";
 
} Petters;

typedef struct {

int ID = 4;
char name[50] = "IOT:s REklambyrå";
int comercials = 1;
char secondComercial[50] = "Synas här? IOT:s Reklambyrå";
 
} Egen;

#endif