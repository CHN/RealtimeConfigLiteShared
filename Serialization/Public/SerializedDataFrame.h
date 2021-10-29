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
			AddDataInternal(pointer, SerializedTypeSelector<T*>::enumType);
		}

		const std::vector<char>& GetSerializedData() const;
	
	private:

		void AddDataInternal(Serializer::PointerType* pointer, SerializedType type);

		std::vector<char> serializedDataVector;
	};

	
}

