#include "hashtable.h"

Hashtable::Hashtable() : count(10)
{
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < count; ++i)
	{
		array[i] = static_cast<std::int32_t>(-1);
	}
}

std::uint32_t Hashtable::hash(std::uint32_t value)
{
	return value;
}

void Hashtable::addItem(std::uint32_t value)
{
	array[hash(value)] = value;
	++count;
}

void Hashtable::del(std::uint32_t delval)
{
	if(find(delval))
	{
		array[hash(delval)] = static_cast<std::int32_t>(-1);
		--count;
	}
}

bool Hashtable::find(std::uint32_t findval)
{
	return (array[hash(findval)] != static_cast<std::int32_t>(-1));
}