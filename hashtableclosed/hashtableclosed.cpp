#include "hashtableclosed.h"


HashTableClosed::HashTableClosed()
{
	Size = static_cast<std::uint32_t>(8);
	array = new Pair[Size];
	count = 0;
}

HashTableClosed::~HashTableClosed()
{
	delete [] array;
}

std::uint32_t HashTableClosed::GetHash(Pair::FruitName name, std::uint32_t offset)
{
	std::uint32_t sum = static_cast<std::uint32_t>(0);
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < std::strlen(name); ++i)
	{
		sum += name[i];
	}
	
	return (sum % Size + offset) % Size;
}

void HashTableClosed::addItem(Pair::FruitName name, std::uint32_t count)
{
   std::int32_t index = static_cast<std::int32_t>(-1);
   std::uint32_t i = static_cast<std::int32_t>(0);
   for(; i < Size; ++i)
   {
      index = GetHash(name,i);
	  if(array[index].mStatus != PairStatus::Engaged)
      {
		  break;
	  }
   }
   
   if(i >= Size)
   {
	   resize();
	   addItem(name, count);
   }
   else
   {
	   array[index] = Pair(name, count);
	   ++count;
   }
}

void HashTableClosed::del(Pair::FruitName name)
{
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < Size; ++i)
	{
		std::uint32_t index = GetHash(name, i);
		if(array[index].mStatus == PairStatus::Engaged)
		{
		   if(!std::strcmp(array[index].mName, name))
		   {
			  array[index].mStatus = PairStatus::Deleted;
			  --count;
			  return;
		   }
		}
	}
}

std::int32_t HashTableClosed::find(Pair::FruitName name)
{
   for(std::uint32_t i = static_cast<std::uint32_t>(0); i < Size; ++i)
   {
      std::uint32_t index = GetHash(name,i);
	  if(array[index].mStatus == PairStatus::Engaged)
      {
		  if(!std::strcmp(array[index].mName, name))
		  {
			  return array[index].mCount;
		  }
	  }
   }
   return -1;
}

void HashTableClosed::resize()
{
	Pair* intermediate = array;
	std::uint32_t oldSize = Size;
	
	Size *= static_cast<std::uint32_t>(2);
	count = static_cast<std::uint32_t>(0);
	
	array = new Pair[Size];
	
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < oldSize; ++i)
	{
		if(intermediate[i].mStatus == PairStatus::Engaged)
		{
			addItem(intermediate[i].mName, intermediate[i].mCount);
		}
	}
	
	delete intermediate;
}
