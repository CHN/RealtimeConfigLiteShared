#include "Serializer.h"

std::vector<char> RTCL::Serializer::SerializeByEnumType(SerializedType enumType, void* pointer)
{
	return serializeFunctions[static_cast<int>(enumType)](pointer);
}

std::vector<char> RTCL::Serializer::SerializeInt(void* pointer)
{
	return SerializeBySize(pointer, sizeof(int));
}

std::vector<char> RTCL::Serializer::SerializeLong(void* pointer)
{
	return SerializeBySize(pointer, sizeof(long));
}

std::vector<char> RTCL::Serializer::SerializeFloat(void* pointer)
{
	return SerializeBySize(pointer, sizeof(float));
}

std::vector<char> RTCL::Serializer::SerializeDouble(void* pointer)
{
	return SerializeBySize(pointer, sizeof(double));
}

std::vector<char> RTCL::Serializer::SerializeCharPointer(void* pointer)
{
	auto** const recoveredValue = (char**)pointer;

	return SerializeBySize(*recoveredValue, std::strlen(*recoveredValue));
}

std::vector<char> RTCL::Serializer::SerializeString(void* pointer)
{
	auto* const recoveredValue = static_cast<std::string*>(pointer);

	return SerializeBySize((void*)recoveredValue->c_str(), recoveredValue->length());
}

std::vector<char> RTCL::Serializer::SerializeBySize(void* pointer, size_t size)
{
	std::vector<char> data(size);

	auto* charPointer = static_cast<char* const>(pointer);

	std::copy(charPointer, charPointer + size, data.begin());

	return data;
}
