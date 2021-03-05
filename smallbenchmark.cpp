/* smallbenchmark.cpp
This program helps you to compare the performance of a platform (OS + hardware) with other platforms.
Example: Raspberry OS on Raspberry Pi 2 is one platform. Raspberry OS on Intel Corei7 is another platform (this also valid if Raspberry OS is running in Virtualbox-VM).
 
 * Copyright 2021 
 * 
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <sstream>
#include <random>

int main(int argc, char **argv)
{
std::chrono::time_point<std::chrono::system_clock> start_program_timepoint, stop_program_timepoint;	// timepoint when program starts and when it stops
std::chrono::duration<double_t> runtime;	// this variable will hold the time the program needed to run
std::random_device rand_dev;	// this random-device is needed to initialize the random-generator so that we get always different random number sequence
std::default_random_engine random_generator(rand_dev());		// we initialize random generator so that we get every cycle different numbers	
std::uniform_int_distribution<int> int_distribution(0,99999);	// we want to have numbers between 0 and 99999	
int number_to_convert;		// this integer will be converted to a string
unsigned int max_loops; 	// the maximum # of loops we will run
unsigned int loop_counter;	// how many times will we run through our loop	
std::vector<std::string> string_vector;	// this vector will hold the strings  
std::stringstream converter;	// a string-stream-object for converting purposes

if (argc == 2) {	// if we have 1 argument for the program we assume, that this is the number of runs
converter << argv[1];		// we save the argument in our string-stream
converter >> max_loops;		// we convert the string to an integer
max_loops *= 100000;		// we take factor 100.000 to have smaler numbers as argument for the program

start_program_timepoint = std::chrono::system_clock::now();	// we save timepoint before we start 
for (loop_counter = 0; loop_counter < max_loops; ++loop_counter) {
	number_to_convert = int_distribution(random_generator);
	converter << number_to_convert;
	string_vector.push_back(converter.str());	// we add at end of vector the string
}	// end of for-loop	

stop_program_timepoint = std::chrono::system_clock::now();	// we save the time when operation was finished
runtime = stop_program_timepoint - start_program_timepoint;	// we calculate time which was needed for the operation

std::cout << "Time to run: " << runtime.count() * 1000 << " msec"<< std::endl;
} else {	// number of arguments is not correct, we print a little help:
	std::cout << "Specify number of runs for program as only parameter." << std::endl;
}	
	
return 0;
}
