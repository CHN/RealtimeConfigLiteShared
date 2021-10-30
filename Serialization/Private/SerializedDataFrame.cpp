#include "SerializedDataFrame.h"

void RTCL::SerializedDataFrame::AddData(Serializer::PointerType* pointer, SerializedType type)
{
	auto serializedData = Serializer::SerializeByEnumType(type, pointer);
	serializedDataVector.insert(serializedDataVector.end(), serializedData.begin(), serializedData.end());
}

const std::vector<char>& RTCL::SerializedDataFrame::GetSerializedData() const
{
	return serializedDataVector;
}

