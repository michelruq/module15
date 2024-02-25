#pragma once

#include <cstdint>
#include "chainnode.h"

class HashTableOpen
{
	private:
	   std::uint32_t Size;
	   std::uint32_t count;
       
	
	   std::uint32_t GetHash(char fruitName[10]);
	   void Resize();
	
	public:
	   ChainNode** chainTops;
	
	   HashTableOpen();
	   ~HashTableOpen();
	   void addItem(ChainNode::FruitName name, std::uint32_t count);
	   void del(ChainNode::FruitName name);
       std::uint32_t find(ChainNode::FruitName name);
	
};