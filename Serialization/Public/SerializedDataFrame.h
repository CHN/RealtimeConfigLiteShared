#pragma once

#include "Serializer.h"
#include "SerializedTypeEnum.h"
#include "SerializedTypeSelector.h"

#include <vector>
#include <memory>

namespace RTCL
{
	class SerializedDataFrame
	{
	public:

		template<typename T>
		void AddData(T* pointer)
		{
			AddData(pointer, SerializedTypeSelector<T*>::enumType);
		}

		void AddData(Serializer::PointerType* pointer, SerializedType type);

		const std::vector<char>& GetSerializedData() const;
	
	private:

		std::vector<char> serializedDataVector;
	};
}

