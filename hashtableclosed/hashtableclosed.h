#pragma once

#include <cstdint>
#include <cstring>
#include "pair.h"

class HashTableClosed
{
	private:
	   Pair* array;
	   std::uint32_t Size;
	   std::uint32_t count;
	   
	   std::uint32_t GetHash(Pair::FruitName name, std::uint32_t offset);
	
	public:
	   HashTableClosed();
	   ~HashTableClosed();
	   void addItem(Pair::FruitName name, std::uint32_t count);
	   void del(Pair::FruitName name);
	   std::int32_t find(Pair::FruitName name);
	   void resize();
	
};