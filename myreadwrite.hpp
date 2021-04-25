/* Aleks McCormick
 * UAF CS 202
 * Homework 5
 * PROGRAM NAME: Template read() and write()
 * 04/20/2021
 */

#ifndef HOMEWORK5_MYREADWRITE_HPP
#define HOMEWORK5_MYREADWRITE_HPP
#include <fstream>

template<typename Type>
void myWrite(std::ofstream &file, const Type &t){
	file.write(reinterpret_cast<const char *>(&t),sizeof(t));
}

template<typename Type>
void myRead(std::ifstream &file,Type &t){
	file.read(reinterpret_cast<char *>(&t),sizeof(t));
}
#endif //HOMEWORK5_MYREADWRITE_HPP
