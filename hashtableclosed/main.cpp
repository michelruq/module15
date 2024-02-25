#include <iostream>

#include "hashtableclosed.h"

struct test
{
	char* name;
	std::uint32_t count;
};

test array[] = { 
                 {(char*)"apple", 10},
				 {(char*)"orange", 15},
				 {(char*)"banana", 2},
		         {(char*)"lemon", 6},
		         {(char*)"pear", 7},
		         {(char*)"kiwi", 4},
		         {(char*)"mandarin", 9}
				 };

int main (int argc, char* argv[])
{
	HashTableClosed oHashTableClosed;
	
	for(std::uint32_t i = 0; i < sizeof(array)/sizeof(test); ++i)
	{
		oHashTableClosed.addItem(array[i].name, array[i].count); 
		std::cout << i << std::endl;
	}
	
	for(std::uint32_t i = 0; i < sizeof(array)/sizeof(test); ++i)
	{
       std::cout << i << "start finding" << "  ";
	   std::cout << oHashTableClosed.find(array[i].name) ;
	   std::cout << "  complete finding" << std::endl;
	}
	
	std::cout << "start deletion" << std::endl;
	
	for(std::uint32_t j = 0; j < sizeof(array)/sizeof(test); ++j)
	{
		std::cout << array[j].name << "deleted" << std::endl;
		oHashTableClosed.del(array[j].name);

		for(std::uint32_t i = 0; i < sizeof(array)/sizeof(test); ++i)
		{
		   std::cout << i << "start finding" << "  ";
		   std::cout << oHashTableClosed.find(array[i].name) ;
		   std::cout << "  complete finding" << std::endl;
		}
	}
	
	oHashTableClosed.resize();
	
	return 0;
}