/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "SSZ.h"
using namespace std;
using namespace dev;


static void streamOut(std::ostream& _out, dev::SSZ const& _d, unsigned _depth = 0)
{
    if(_depth) {
        return;
    }
	_out << escaped(_d.toString(), false);
}

size_t SSZ::length() const
{
	size_t ret = m_data.size();
	return ret;
}

size_t SSZ::itmes() const
{
// ret might be 2 or 17
// in case of short node -> [bytes, bytes]
// in case of extention node -> List17[{uint8, bytes}]
	size_t ret = 0;
	int index = 4;
	size_t size = m_data.size();
    //variable length
    while(size) 
    {
        int prefix = 0;
        prefix |= data[3] << 24;
        prefix |= data[2] << 16;
        prefix |= data[1] << 8;
        prefix |= data[0] << 0;

        size
        
        ret++;
    }
	return ret;
}

std::ostream& dev::operator<<(std::ostream& _out, SSZ const& _d)
{
	streamOut(_out, _d);
	return _out;
}
