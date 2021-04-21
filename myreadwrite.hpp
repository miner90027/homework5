//
// Created by aleks on 04/20/21.
//

#ifndef HOMEWORK5_MYREADWRITE_HPP
#define HOMEWORK5_MYREADWRITE_HPP
#include <ostream>

template<typename Type>
void myWrite(std::ofstream &file, const Type &t){
	file.write(reinterpret_cast<const char *>(&t),sizeof(t));
}

template<typename Type>
void myRead(std::ifstream &file, const Type &t){
	file.read(reinterpret_cast<const char *>(&t),sizeof(t));
}
#endif //HOMEWORK5_MYREADWRITE_HPP
