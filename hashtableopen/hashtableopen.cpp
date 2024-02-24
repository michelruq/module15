#include "hashtableopen.h"
#include <cstring>

HashTableOpen::HashTableOpen() : count(10)
{
    Size = static_cast<std::uint32_t>(8);
	chainTops = new ChainNode*[Size];
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < Size; ++i)
	{
		chainTops[i] = nullptr;
	}
	count = 0;
}

HashTableOpen::~HashTableOpen()
{
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < Size; ++i)
	{
		if(chainTops[i] != nullptr)
		{
		   delete chainTops[i];
		}
	}
	delete[] chainTops;
}

std::uint32_t HashTableOpen::GetHash(char fruitName[10])
{
	std::uint32_t sum = static_cast<std::uint32_t>(0);
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < 10; ++i)
	{
		sum += fruitName[i];
	}
	return sum % Size;
}

void HashTableOpen::addItem(ChainNode::FruitName name, std::uint32_t count)
{
   std::uint32_t index = GetHash(name);
   ChainNode* newNode = new ChainNode(name, count);
   if(chainTops[index] != nullptr)
   {
	   newNode->mNext = chainTops[index];
   }
   chainTops[index] = newNode;
   ++count;
}

void HashTableOpen::del(ChainNode::FruitName name)
{
   std::uint32_t index = GetHash(name);
   ChainNode* currentPtr = chainTops[index];
   ChainNode* parentPtr = nullptr;
   while(currentPtr != nullptr)
   {
	   if(!strcmp(currentPtr->mName, name))
	   {
           if(parentPtr != nullptr)
		   {
			   parentPtr->mNext = currentPtr->mNext;
		   }
		   else
		   {
			   chainTops[index] = currentPtr->mNext;
		   }
		   delete currentPtr;
		   --count;
		   break;
	   }
	   parentPtr = currentPtr;
	   currentPtr = currentPtr->mNext;
   }
}

std::uint32_t HashTableOpen::find(ChainNode::FruitName name)
{
   std::uint32_t index = GetHash(name);
   ChainNode* currentPtr = chainTops[index];
   while(currentPtr != nullptr)
   {
	   if(!strcmp(currentPtr->mName, name))
	   {
		   return currentPtr->mCount;
	   }
	   currentPtr = currentPtr->mNext;
   }
   return static_cast<std::uint32_t>(0);
}