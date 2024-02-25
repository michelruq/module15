#pragma once
#include <cstdint>
#include <cstring>

enum PairStatus
{
	Free,
	Engaged,
	Deleted
};

class Pair
{
	public:
	   static constexpr const std::uint32_t NameLength = static_cast<std::uint32_t>(10);
	   using FruitName = char[NameLength];

	   FruitName mName;
	   std::int32_t mCount;
	   
	   PairStatus mStatus;
	   
	   Pair();
	   Pair(FruitName name, std::int32_t count);
	   Pair& operator= (const Pair& other);
	
};