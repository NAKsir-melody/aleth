/* Aleth: Ethereum C++ client, tools and libraries.
 * Copyright 2018 Aleth Autors.
 * Licensed under the GNU General Public License, Version 3. See the LICENSE file.
 */

#include <libdevcore/SSZ.h>

#include <gtest/gtest.h>

using namespace dev;
using namespace std;

TEST(SSZ, emptyArrayList)
{
    try
    {
        bytes payloadToDecode = fromHex("80");
        SSZ payload(payloadToDecode);
        ostringstream() << payload;

        payloadToDecode = fromHex("с0");
        SSZ payload2(payloadToDecode);
        ostringstream() << payload2;
    }
    catch (std::exception const& _e)
    {
        ADD_FAILURE() << "Exception: " << _e.what();
    }
}
/*
TEST(SSZ, actualSize)
{
    EXPECT_EQ(SSZ{}.actualSize(), 0);

    bytes b{0x79};
    EXPECT_EQ(SSZ{b}.actualSize(), 1);

    b = {0x80};
    EXPECT_EQ(SSZ{b}.actualSize(), 1);

    b = {0x81, 0xff};
    EXPECT_EQ(SSZ{b}.actualSize(), 2);

    b = {0xc0};
    EXPECT_EQ(SSZ{b}.actualSize(), 1);

    b = {0xc1, 0x00};
    EXPECT_EQ(SSZ{b}.actualSize(), 2);
}

TEST(SSZ, bignumSerialization)
{
    // Tests that a bignum can be serialized and deserialized with the SSZ classes.

    dev::u256 bignum("10000000000000000000000");

    dev::SSZStream sszStm{};
    sszStm << bignum;

    auto buffer = sszStm.out();

    dev::SSZ ssz{buffer};
    dev::u256 bignumPost = ssz.toInt<dev::u256>();

    EXPECT_EQ(bignum, bignumPost) << "The post-processed bignum does not match the original.";
}
*/
