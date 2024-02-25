#include "pair.h"

Pair::Pair() : mName(""), mCount(static_cast<std::int32_t>(-1)), mStatus(PairStatus::Free)
{
	
}

Pair::Pair(FruitName name, std::int32_t count) : mCount(count), mStatus(PairStatus::Engaged)
{
	std::strcpy(mName, name);
}

Pair& Pair::operator= (const Pair& other)
{
	if(&other == this)
	{
		return *this;
	}
	
	std::strcpy(mName, other.mName);
	mCount = other.mCount;
	   
	mStatus = other.mStatus;
	
	return *this;
}