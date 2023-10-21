#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <cassert>

#include <cryptopp/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>

// this is today's input
static const std::string secretKey = "iwrupvqb";

std::string getMD5HexString(const std::string& input)
{
    using namespace CryptoPP;

    Weak::MD5 hash;
    std::string digest, encoded;

    hash.Update(reinterpret_cast<const byte*>(input.c_str()), input.size());
    digest.resize(hash.DigestSize());
    hash.Final(reinterpret_cast<byte*>(&digest[0]));

    StringSource ss(reinterpret_cast<const byte *>(digest.c_str()), digest.size(), true, new HexEncoder( new StringSink(encoded)));

    return encoded;
}
void partOne() {

    int i = 0;
    std::string hash;

    while (true) {
        hash = getMD5HexString(secretKey + std::to_string(i));

        if (hash.compare(0, 5, "00000") == 0) {
            break;
        }
        ++i;
    }

    std::cout << "Digest: " << hash << std::endl;

    std::cout << "Part One: integer = " << i << std::endl;

}

void testMD5() {
    assert(getMD5HexString(secretKey) == "B62D7001F13AF4BD310E7ECFF0720509");
}

void partTwo() {
    int i = 0;
    std::string hash;

    while (i >= 0) {
        hash = getMD5HexString(secretKey + std::to_string(i));

        if (hash.compare(0, 6, "000000") == 0) {
            break;
        }
        ++i;
    }

    std::cout << "Digest: " << hash << std::endl;

    std::cout << "Part Two: integer = " << i << std::endl;
}


int main() {
    testMD5();

    // partOne();
    partTwo();
}