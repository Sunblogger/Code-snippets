/*
 print_colors_in_terminal.cpp
 Release: 0.1, date: 05.03.2021
 
 Prints colors and textformats in a terminal. Program was tested only on Raspberry OS.
 
 * Copyright 2021
 * 
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#include <iostream>
#include <string>
#include <map>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This function prints all kind of colors and forms like bold, bright and so on on screen.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_colors_in_terminal() {

std::map<const std::string, const std::string> foreground_colors = {{"black", "30"}, {"red", "31"}, {"green","32"},{"yellow","33"},{"blue","34"},{"magenta","35"},{"cyan","36"},{"white","37"}};
std::map<const std::string, const std::string> background_colors = {{"black", "40"}, {"red", "41"}, {"green","42"},{"yellow","43"},{"blue","44"},{"magenta","45"},{"cyan","46"},{"white","47"}};
std::map<const std::string, const std::string> text_format = {{"reset", "0"}, {"bold", "1"},{"underline", "4"},{"inverse", "7"},{"double underlined", "21"},{"underline off", "24"}, {"inverse off", "27"}};
std::map<const std::string, const std::string> color_format = {{"normal" , "0"}, {"bold", "1"},{"decreased intensity", "2"},{"italic", "3"},{"underlined", "4"},{"blinking", "5"}, {"normal", "6"}, {"black on colored background", "7"}, {"unvisible", "8"},{"deleted", "9"}, {"framed", "50"}, {"encircled", "51"},{"overlined", "52"}};

std::map<const std::string, const std::string>::iterator foreground_iterator, background_iterator, text_format_iterator, color_format_iterator;
std::string escape_sequence_foreground, escape_sequence_background, escape_sequence_color_format;
const std::string reset_string = "\033[0m";

std::cout << "======== Exapmples for colors ========================" << std::endl;
for (foreground_iterator = foreground_colors.begin(); foreground_iterator != foreground_colors.end(); ++foreground_iterator) {
	escape_sequence_foreground = "\033[" + foreground_iterator->second + "m";
	for (background_iterator = background_colors.begin(); background_iterator != background_colors.end(); ++background_iterator) { 
		std::cout << "Foreground color: " << escape_sequence_foreground << foreground_iterator->first << reset_string << " on background color: " << "\033[" + foreground_iterator->second + ';' + background_iterator->second + 'm' << background_iterator->first << reset_string << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
}

std::cout << "======== Exapmples for text formats ===" << std::endl;
	
for (text_format_iterator = text_format.begin(); text_format_iterator != text_format.end(); ++text_format_iterator) {	
	escape_sequence_color_format = "\033[0;" + text_format_iterator->second + 'm';
	std::cout << escape_sequence_color_format << "Example text in " << text_format_iterator->first << reset_string << std::endl;
}	

std::cout << "======== Examples for color formats =========================" << std::endl;
	
for (color_format_iterator = color_format.begin(); color_format_iterator != color_format.end(); ++color_format_iterator) {		
	escape_sequence_color_format = "\033[" + color_format_iterator->second + "m";
	std::cout << "Example in " << color_format_iterator->first << " :" << escape_sequence_color_format << " This is the example." << reset_string << std::endl;
}

}; // end of print_colors_in_terminal()


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is main.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
print_colors_in_terminal();	
return 0;
}
