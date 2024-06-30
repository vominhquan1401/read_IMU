#include "angel.h"

#define DATA_LEN 11
uint8_t current_len=0;
uint8_t rec_flag=0;
uint8_t buff[DATA_LEN];
uint8_t angular_flag=0;

void buff_reset(){
	current_len=0;
	rec_flag=0;
}

void data_rec(uint8_t data){
	if(data==0x55 && current_len==0){
		rec_flag=1;
	}
	if(rec_flag){
		if(current_len==10){
			buff[current_len]=data;
			buff_reset();
		}else{
			buff[current_len++]=data;
		}
	}
}

float angular_calculate(uint8_t dataL,uint8_t dataH){
	float result;
	result=(float)((short)((short)dataH<<8)|dataL)/32768.2f*180.2f;
	return result;
}

void angular_setup(axis *ang){
	if(current_len==10){
		ang->x=angular_calculate(buff[2],buff[3]);
		ang->y=angular_calculate(buff[4],buff[5]);
		ang->z=angular_calculate(buff[6],buff[7]);
	}
}
