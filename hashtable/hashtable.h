#pragma once

#include <cstdint>

class Hashtable
{
	private:
	   static constexpr const std::uint32_t Size = static_cast<std::uint32_t>(10);
	   std::uint32_t count;
	   std::int32_t array[Size];
	
	   std::uint32_t hash(std::uint32_t value);
	
	public:
	   Hashtable();
	   void addItem(std::uint32_t value);
	   void del(std::uint32_t delval);
       bool find(std::uint32_t findval);
	
};