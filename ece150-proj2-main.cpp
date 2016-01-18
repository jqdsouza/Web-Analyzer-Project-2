#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <fstream>

// #include "ece150-proj2-stats.cpp" 
// #include "ece150-proj2-helper.cpp"

using namespace std;

extern float avg (float item[], int size);
extern float median (float item[], int size);
extern float stdDev(float item[], float a, int size);
extern float aad(float item[], float m, int size);
extern int randnum_generator(int bias);

int main (int argc, char* argv[]){

ifstream infile;  
infile.open("ece150-proj2-input.txt");

int bias = atoi(argv[1]);

if (argc != 2){
	cerr << "Error: input" << endl;
	return -1;
}

if (bias < 0) {
	cerr << "Error: input" << endl;
	return -1;
}

string input_lines;
int file_number = 0;
string file_uri;
int file_size, file_priority;
string newfile_uri[999];
int newfile_size[999];
int newfile_priority[999];

while (infile.good()){
	getline(infile, input_lines);
	
		if (input_lines.empty()){
			continue;
		}
		
		else {
			stringstream ss(input_lines);
			
			ss >> file_uri >> file_size >> file_priority;
			
			if (file_size <= 0 or file_priority < 0){
				return 1;
			}
			
			newfile_uri[file_number] = file_uri;
			newfile_size[file_number] = file_size;
			newfile_priority[file_number] = file_priority;
			file_number++;
			
		}
}

infile.close();
int num_inputs = 0;				
string uri_input[999];

bool inputcomplete = false;

while (inputcomplete == false){
	cin >> uri_input[num_inputs];
	
	if (uri_input[num_inputs] == "exit"){
		inputcomplete = true;
		break;
	}
	
	else {
		num_inputs++;
	}
}

float input_size[num_inputs];
float input_priority[999];
float transmission_delay[999];
int counter = 0;

	for (int i = 0; i < num_inputs; i++){
		for (int x = 0; x <= file_number; x++){
			if (x < file_number) {
				if (uri_input[i] == newfile_uri[x]) {
					input_size[i] = newfile_size[x];
					input_priority[i] = newfile_priority[x];
					counter++;
					break;
				}
			}
			if (x == file_number) {
				cerr << "Error: input" << endl;
				return -1;
			}
		}
	}
	
int randomnumber = randnum_generator(bias);

for (int i = 0; i < num_inputs-1; i++){
	for (int x = 0; x < num_inputs-1; i++){
		if (input_size[x] > input_size[x+1]){
			int offset = input_size[x+1];
			input_size[x+1] = input_size[x];
			input_size[x] = offset;
		}
	}
}

for (int i = 0; i < num_inputs-1; i++){
	for (int x = 0; x < num_inputs-1; i++){
		if (input_priority[x] > input_priority[x+1]){
			int offset = input_priority[x+1];
			input_priority[x+1] = input_priority[x];
			input_priority[x] = offset;
		}
	}
}

for (int i = 0; i < num_inputs; i++){
	if ((input_size[i] - pow(2.0, bias)) < 0) {
		cerr << "Error: input" << endl;
		return -1;
	}
	
	else {
		transmission_delay[i] = 0.8*(float(randomnumber)+input_size[i]);
	}
}

float output_avg[3];
float output_stan_dev[3];
float output_med[3];
float output_absdev[3];


output_avg[0] = avg(input_size, num_inputs); 					
output_stan_dev[0] = stdDev(input_size, output_avg[0], num_inputs);
output_med[0] = median(input_size, num_inputs);
output_absdev[0] = aad(input_size, output_med[0], num_inputs);

output_avg[1] = avg(input_priority, num_inputs); 					
output_stan_dev[1] = stdDev(input_priority, output_avg[1], num_inputs);
output_med[1] = median(input_priority, num_inputs);
output_absdev[1] = aad(input_priority, output_med[1], num_inputs);

output_avg[2] = avg(transmission_delay, num_inputs); 					
output_stan_dev[2] = stdDev(transmission_delay, output_avg[2], num_inputs);
output_med[2] = median(transmission_delay, num_inputs);
output_absdev[2] = aad(transmission_delay, output_med[2], num_inputs);


	for (int i = 0; i <= 2; i++){
		cout << output_avg[i] << " " << output_med[i] << " " << output_stan_dev[i] << " " << output_absdev[i] << endl; 
	}
	
return 0;
}