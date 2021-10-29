#include "Serializer.h"

RTCL::Serializer::DataType RTCL::Serializer::SerializeByEnumType(SerializedType enumType, PointerType* pointer)
{
	std::vector<char> data;
	SerializeInt((PointerType*)&enumType, &data);
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
	std::copy(&size, &size + sizeof(size_t), data->begin());

	data->reserve(data->size() + size);

	std::copy(pointer, pointer + size, data->begin());
}
