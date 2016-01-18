#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int randnum_generator(int bias) {

if (bias == 0) {
	return 0;
}

int max = pow(2, bias);
int range = 2*max;

int random_num;

srand(time(NULL));
random_num = (rand()%(range)) - max;

return random_num;
}
	


