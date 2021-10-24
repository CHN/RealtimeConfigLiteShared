#pragma once

#include "SerializedTypeSelector.h"

#include <vector>
#include <cstring>

namespace RTCL
{
	class Serializer
	{
	public:

		static std::vector<char> SerializeByEnumType(SerializedType enumType, void* pointer);

	private:

		static std::vector<char> SerializeInt(void* pointer);
		static std::vector<char> SerializeLong(void* pointer);
		static std::vector<char> SerializeFloat(void* pointer);
		static std::vector<char> SerializeDouble(void* pointer);
		static std::vector<char> SerializeCharPointer(void* pointer);
		static std::vector<char> SerializeString(void* pointer);

		static std::vector<char> SerializeBySize(void* pointer, size_t size);

		using SerializeFunctionType = std::vector<char>(*)(void*);

		static constexpr SerializeFunctionType serializeFunctions[6] =
		{
			SerializeInt,
			SerializeLong,
			SerializeFloat,
			SerializeDouble,
			SerializeCharPointer,
			SerializeString
		};
	};
}