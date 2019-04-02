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

#include <fstream>
#include <boost/test/unit_test.hpp>
#include <json_spirit/JsonSpiritHeaders.h>
#include <libdevcore/CommonIO.h>
#include <libdevcore/TrieDB.h>
#include <libdevcore/TrieHash.h>
#include <libdevcore/StateCacheDB.h>
#include "MemTrie.h"
#include <test/tools/libtesteth/TestOutputHelper.h>
#include <test/tools/libtesteth/Options.h>
#include <boost/filesystem/path.hpp>

using namespace std;
using namespace dev;
using namespace dev::test;

namespace fs = boost::filesystem;
namespace js = json_spirit;

static unsigned fac(unsigned _i)
{
    return _i > 2 ? _i * fac(_i - 1) : _i;
}

using dev::operator <<;

h256 stringMapHash256(StringMap const& _s)
{
    BytesMap bytesMap;
    for (auto const& _v: _s)
        bytesMap.insert(std::make_pair(bytes(_v.first.begin(), _v.first.end()), bytes(_v.second.begin(), _v.second.end())));
    return hash256(bytesMap);
}

bytes stringMapRlp256(StringMap const& _s)
{
    BytesMap bytesMap;
    for (auto const& _v: _s)
        bytesMap.insert(std::make_pair(bytes(_v.first.begin(), _v.first.end()), bytes(_v.second.begin(), _v.second.end())));
    return rlp256(bytesMap);
}

TEST(core, SSZ_trie)
{
    cnote << "Testing Trie more...";
    // More tests...
    {
        StateCacheDB m;
        GenericTrieDB<StateCacheDB> t(&m);
        t.init();	// initialise as empty tree.
        t.insert(string("a"), string("A"));
        t.insert(string("b"), string("B"));
        cnote << t;
        cnote << m;
        cnote << t.root();
        cnote << stringMapHash256({{"b", "B"}, {"a", "A"}});
        bytes r(stringMapRlp256({{"b", "B"}, {"a", "A"}}));
        cnote << RLP(r);
    }
}
