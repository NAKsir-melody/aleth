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

class SSZ;

/**
 * Class for interpreting SSZ data.
 */
class SSZ
{
public:
	SSZ() {}
	/// Construct a node of value given in the bytes.
	explicit SSZ(bytesConstRef _d): m_data(_d){};

	/// Construct a node of value given in the bytes.
	explicit SSZ(bytes const& _d): SSZ(&_d) {}

	/// Construct a node to read SSZ data in the bytes given.
	SSZ(byte const* _b, unsigned _s): SSZ(bytesConstRef(_b, _s)) {}

	/// Construct a node to read SSZ data in the string.
	explicit SSZ(std::string const& _s): SSZ(bytesConstRef((byte const*)_s.data(), _s.size())) {}

	bytesConstRef data() const { return m_data; }

	size_t length() const;

	bytesConstRef payload() const { auto l = length(); return m_data.cropped(0, l); }

	std::string toString() const { return payload().cropped(0, length()).toString(); }

private:
	bytesConstRef m_data;
};

/// Human readable version of RLP.
std::ostream& operator<<(std::ostream& _out, dev::SSZ const& _d);

}
