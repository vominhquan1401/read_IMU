#ifndef ANGEL_H
#define ANGEL_H
#include "main.h"

typedef struct{
	float x;
	float y;
	float z;
}axis;

void buff_reset();
void data_rec(uint8_t data);
float angular_calculate(uint8_t dataL,uint8_t dataH);
void angular_setup(axis *ang);
#endif
