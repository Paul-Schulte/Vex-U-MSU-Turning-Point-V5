#pragma once
#include "main.h"


extern int selectedAuton;
extern bool test1;
extern bool test2;
extern bool test3;

void runScreen();
void updateLineVariable(int line, float value);
void updateLineVariable(int line, std::string value);
void startAuton();
