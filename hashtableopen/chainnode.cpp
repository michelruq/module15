#include <cstring>

#include "chainnode.h"

ChainNode::ChainNode(FruitName name, std::uint32_t count) : mCount(count), mNext(nullptr)
{
   std::strcpy(mName, name);
}

ChainNode::~ChainNode()
{
    if(mNext != nullptr)
	{
		delete mNext;
	}
}