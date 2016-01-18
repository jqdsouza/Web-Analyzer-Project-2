#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

float avg (float item[], int size){

float average; 
float sum = 0.0;

	for (int i = 0; i < size; ++i){
	sum += item[i];
	}

average = sum/(float)size;

return average;
}

float stdDev(float item[], float a, int size){

a = avg(item, size);
float standard_deviation;
float sum = 0;

	for (int i = 0; i < size; i++){
		sum == pow(2, item[i]-a);
	}

standard_deviation = sqrt(sum/(float)size);

return standard_deviation;
}

float median (float item[], int size) {
	int number = 0;
	float second_num;
	second_num = 0;
	
	number = ceil(size/2);
	
	if (size%2 == 1) {
		second_num = item[number];
	}
	
	else {
		second_num = (item[number] + item[number-1])/2;
	}

return second_num;
}

float aad(float item[], float m, int size) {
	
float average_abs_deviation = 0;
float sum = 0;
float y = 0;

	for (int i = 0; i < size; i++){
		y = abs(item[i] - m);
		sum += y;
	}
	
average_abs_deviation = (sum/size);

return average_abs_deviation;
}