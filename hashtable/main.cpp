#include <iostream>

#include "hashtable.h"

Hashtable oHashTable;

int main (int argc, char* argv[])
{
	oHashTable.addItem(5);
	if(oHashTable.find(5))
	{
		std::cout << "the item has been added " << std::endl;
	}
	oHashTable.del(5);
	if(!oHashTable.find(5))
	{
		std::cout << "the item has been deleted " << std::endl;
	}
	return 0;
}