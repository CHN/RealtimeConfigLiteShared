#include "Serializer.h"

RTCL::Serializer::DataType RTCL::Serializer::SerializeByEnumType(SerializedType enumType, PointerType* pointer)
{
	std::vector<char> data;

	data.resize(sizeof(enumType));

	auto* enumTypePointer = (PointerType*)&enumType;

	std::copy(enumTypePointer, enumTypePointer + sizeof(enumType), data.begin());

	serializeFunctions[static_cast<int>(enumType)](pointer, &data);

	return data;
}

void RTCL::Serializer::SerializeInt(PointerType* pointer, DataType* data)
{
	SerializeBySize(pointer, sizeof(int), data);
}

void RTCL::Serializer::SerializeLong(PointerType* pointer, DataType* data)
{
	SerializeBySize(pointer, sizeof(long), data);
}

void RTCL::Serializer::SerializeFloat(PointerType* pointer, DataType* data)
{
	SerializeBySize(pointer, sizeof(float), data);
}
 
void RTCL::Serializer::SerializeDouble(PointerType* pointer, DataType* data)
{
	SerializeBySize(pointer, sizeof(double), data);
}

void RTCL::Serializer::SerializeCharPointer(PointerType* pointer, DataType* data)
{
	auto** const recoveredValue = (char**)pointer;

	SerializeBySize(*recoveredValue, std::strlen(*recoveredValue), data);
}

void RTCL::Serializer::SerializeString(PointerType* pointer, DataType* data)
{
	auto* const recoveredValue = (std::string*)pointer;

	SerializeBySize(recoveredValue->c_str(), recoveredValue->length(), data);
}

void RTCL::Serializer::SerializeBySize(PointerType* pointer, size_t size, DataType* data)
{
	data->reserve(data->size() + sizeof(size) + size);

	auto* sizePointer = (char*)&size;
	data->insert(data->end(), sizePointer, sizePointer + sizeof(size));

	data->insert(data->end(), pointer, pointer + size);
}
