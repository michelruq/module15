#pragma once

#include <cstdint>

class ChainNode
{
	public:
	   static constexpr const std::uint32_t NameLength = static_cast<std::uint32_t>(10);
	   using FruitName = char[NameLength];
	   
	   FruitName mName;
	   std::uint32_t mCount;
	   
	   ChainNode* mNext;
	   
	   ChainNode(FruitName name, std::uint32_t count);
	   ~ChainNode();
	   
};