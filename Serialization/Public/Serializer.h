#pragma once

#include "SerializedTypeSelector.h"

#include <vector>
#include <cstring>

namespace RTCL
{
	class Serializer
	{
	public:

		using PointerType = const char;
		using DataType = std::vector<char>;

		static DataType SerializeByEnumType(SerializedType enumType, PointerType* pointer);

	private:

		static void SerializeInt(PointerType* pointer, DataType* data); // Should be int32_t or int64_t
		static void SerializeLong(PointerType* pointer, DataType* data);
		static void SerializeFloat(PointerType* pointer, DataType* data);
		static void SerializeDouble(PointerType* pointer, DataType* data);
		static void SerializeCharPointer(PointerType* pointer, DataType* data);
		static void SerializeString(PointerType* pointer, DataType* data);

		static void SerializeBySize(PointerType* pointer, size_t size, DataType* data);

		using SerializeFunctionType = void(*)(PointerType*, DataType*);

		static constexpr SerializeFunctionType serializeFunctions[] =
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