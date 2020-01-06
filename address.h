#ifndef ADDR_STR_H
#define ADDR_STR_H
#include "instructions.h"
#include <iostream>
#include <string>

typedef struct Address{
	std::string type; // The type
	std::string Address1;
	std::string Address2; 
} Address;

#endif