#include "../advent.h"
#include <execution>
#include "md5.h"

namespace day04 {
/// Change this to the current day
    static const std::string day = "04";
    static const std::string inputFilename = "..\\day" + day + "\\input.txt";
    static const std::string testFilename = "..\\day" + day + "\\test.txt";

    struct PuzzleInput {
        const std::string secret = "iwrupvqb";

        explicit PuzzleInput(const std::string &filename) {
        }

    };

    std::string getMD5HexString(const std::string &str) {
        Chocobo1::MD5 md5;

        md5.addData(str.c_str(), str.size());
        md5.finalize();

        return md5.toString();
    }

/// Unit Test
    void test() {
        PuzzleInput input(testFilename);
        std::string str = getMD5HexString(input.secret);
        assert(str == "b62d7001f13af4bd310e7ecff0720509");
    }

/// Part One Solution
    int partOne() {
        PuzzleInput input(inputFilename);

        const int block_size = 1024 * 256;
        int block_start = 0;

        std::mutex mutex;
        int index;
        bool halt = false;

        while (!halt) {
            std::vector<int> block(block_size);
            std::iota(block.begin(), block.end(), block_start);

            std::cout << "\rStarting block " << block_start  << std::flush;

            // parallel for loop over the current block of numbers
            // nb i don't know a way to terminate the loop early
            std::for_each(std::execution::par, block.begin(), block.end(), [&](int n) {
                std::string hash = getMD5HexString(input.secret + std::to_string(n));
                if (hash.starts_with("00000")) {
                    std::lock_guard<std::mutex> guard(mutex);
                    if (!halt) {
                        halt = true;
                        index = n;
                    }
                }
            });
            block_start += block_size;
        }
        std::cout << "\r";

        return index;
    }


/// Part Two Solution
    int partTwo() {
        PuzzleInput input(inputFilename);

        const int block_size = 1024 * 256;
        int block_start = 0;
        int index;
        bool halt = false;
        std::mutex mutex;

        while (!halt) {
            std::vector<int> block(block_size);
            std::iota(block.begin(), block.end(), block_start);

            std::cout << "\rStarting block " << block_start <<  std::flush;

            std::for_each(std::execution::par, block.begin(), block.end(), [&](int n) {
                std::string hash = getMD5HexString(input.secret + std::to_string(n));
                if (hash.starts_with("000000")) {
                    std::lock_guard<std::mutex> guard(mutex);
                    if (!halt) {
                        halt = true;
                        index = n;
                    }
                }
            });

            block_start += block_size;
        }

        std::cout << "\r";

        return index;
    }
}

int main() {
    using namespace day04;
    test();

    {
        std::cout << std::fixed << std::setprecision(3);
        auto [seconds, result] = advent::eval<int>(&partOne);

        std::cout << "Day " << day << ": Part One = " << result << "\t\t (completed in " << seconds << "s)."
                  << std::endl;
    }
    {
        std::cout << std::fixed << std::setprecision(3);
        auto [seconds, result] = advent::eval<int>(&partTwo);

        std::cout << "Day " << day << ": Part One = " << result << "\t\t (completed in " << seconds << "s)."
                  << std::endl;
    }
}