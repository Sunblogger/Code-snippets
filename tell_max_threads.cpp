/* 	Tell maximum number of threads on your system.
	This program tries to start as many threads as possible and prints the reached maximum on screen.
	compiling and linking: g++ -lpthread tell_max_threads.cpp -o tmt
	
	This program was only tested on Raspberry OS on x86- and ARMHF-CPU (the nativ Raspberry Pi)
	
		
 * Copyright 2020 
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
#include <mutex>
#include <thread>

std::mutex handling_mutex;
// this function will be called by thread:
void parallel_working() {
	handling_mutex.lock();
	handling_mutex.unlock(); 	
} 

int main() {

int threadcounter;
int thread_threshold = 0;
const int maximum_threads = 1000000;
std::thread thread_array[maximum_threads];
for (threadcounter = 0; threadcounter < maximum_threads; threadcounter++) {
	try {
		thread_array[threadcounter] = std::thread(parallel_working);	// we start next thread
	} catch (...) { // we catch any exception so that program does not crash
		std::cout << "Maximum # of threads on this system: " << threadcounter << std::endl;
		thread_threshold = threadcounter; 	// we reached maximum # of threads
		threadcounter = maximum_threads;	// we stop for-loop
	} // end of catch
}
// now we join all threads
for (threadcounter = 0; threadcounter < thread_threshold; threadcounter++) {	
		thread_array[threadcounter].join();
}
return 0;
}	// end of main
