#pragma once

template <typename T>
class Set
{
public:
	Set() = default;

	bool virtual operator[](T element) const = 0;

	virtual ~Set() = default;
};
