#pragma once

#include "SerializedTypeEnum.h"

#include <string>

namespace RTCL
{
	template<typename T>
	struct SerializedTypeSelector
	{
		static constexpr SerializedType type = "Type is not implemented";
	};

	template<>
	struct SerializedTypeSelector<int*>
	{
		static constexpr SerializedType type = SerializedType::kInt;
	};

	template<>
	struct SerializedTypeSelector<long*>
	{
		static constexpr SerializedType type = SerializedType::kLong;
	};

	template<>
	struct SerializedTypeSelector<float*>
	{
		static constexpr SerializedType type = SerializedType::kFloat;
	};

	template<>
	struct SerializedTypeSelector<double*>
	{
		static constexpr SerializedType type = SerializedType::kDouble;
	};

	template<>
	struct SerializedTypeSelector<const char**>
	{
		static constexpr SerializedType type = SerializedType::kCharPointer;
	};

	template<>
	struct SerializedTypeSelector<std::string*>
	{
		static constexpr SerializedType type = SerializedType::kString;
	};
}

