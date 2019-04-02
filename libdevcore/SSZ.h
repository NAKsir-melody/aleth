/* Aleth: Ethereum C++ client, tools and libraries.
 * Copyright 2019 Aleth Autors.
 * Licensed under the GNU General Public License, Version 3. See the LICENSE file.
 */

/**
 * Simple Serialization / deserialization for ethereum 2.0 
 * @file
 */

#pragma once

#include "Exceptions.h"
#include "FixedHash.h"
#include "vector_ref.h"

#include <array>
#include <exception>
#include <iomanip>
#include <iosfwd>
#include <vector>

namespace dev
{

/**
 * Class for interpreting SSZ data.
 */
class SSZ
{
public:
	SSZ() {}

	/// Construct a node of value given in the bytes.
	explicit SSZ(bytesConstRef _d): m_data(_d) {}

	/// Construct a node of value given in the bytes.
	explicit SSZ(bytes const& _d): SSZ(&_d) {}

	/// Construct a node to read SSZ data in the bytes given.
	SSZ(byte const* _b, unsigned _s): SSZ(bytesConstRef(_b, _s)) {}

	/// Construct a node to read SSZ data in the string.
	explicit SSZ(std::string const& _s): SSZ(bytesConstRef((byte const*)_s.data(), _s.size())) {}

	bytesConstRef data() const { return m_data; }

	/// No value.
	bool isNull() const { return m_data.size() == 0; }

	/// Contains a zero-length string or zero-length list.
	bool isEmpty() const { return !isNull(); }

	size_t itemCount() const { return isList() ? items() : 0; }

	/// List value.
	bool isList() const { return !isNull() && m_data[0] >= c_rlpListStart; }

	/// @returns the number of data items.
	size_t items() const;
private:
	bytesConstRef m_data;
};

}
