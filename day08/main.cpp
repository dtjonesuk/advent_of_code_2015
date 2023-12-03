#include "../advent.h"

namespace day08 {
/// Change this to the current day
    static const std::string day = "08";
    static const std::string inputFilename = "..\\day" + day + "\\input.txt";
//    static const std::string testFilename = "..\\day" + day + "\\test.txt";

    struct PuzzleInput {
        std::vector<std::string> lines;

        explicit PuzzleInput(const std::string &filename) {
            std::ifstream istream(filename);
            std::string line;

            while (std::getline(istream, line)) {
                // do something
                lines.emplace_back(std::move(line));
            }
        }

    };

    // count the unused chars in a quote-string
    int countChars(const std::string &str) {
        int unused = 0;

        for (auto it = str.begin(); it != str.end(); ++it) {
            if (*it == '"') {
                ++unused;
            } else if (*it == '\\') {
                ++it;
                switch (*it) {
                    case '\\':
                    case '"':
                        ++unused;
                        break;
                    case 'x':
                        std::string hex = {*++it, *++it};
                        unused += 3;
                        break;
                }
            }
        }

        return unused;
    }

    std::string encodeString(const std::string &str) {
        std::string output = "\"";
        for (auto it = str.begin(); it != str.end(); ++it) {
            if (*it == '"') {
                output += "\\\"";
            } else {
                if (*it == '\\') {
                    ++it;
                    switch (*it) {
                        case '\\':
                            output += "\\\\\\\\";
                            break;
                        case '\"':
                            output += "\\\\\\\"";
                            break;
                        case 'x':
                            std::string hex = {*++it, *++it};
                            output += "\\\\x" + hex;
                            break;
                    }

                } else {
                    output += *it;
                }
            }
        }
        output += "\"";
        return output;
    }

/// Unit Test
    void test() {
        assert(countChars("\"\"") == 2);
        assert(countChars("\"abc\"") == 2);
        assert(countChars("\"aaa\\\"aaa\"") == 3);
        assert(countChars("\"\\x27\"") == 5);
    }

/// Part One Solution
    int partOne() {
        PuzzleInput input(inputFilename);

        int total = std::transform_reduce(input.lines.begin(), input.lines.end(), 0, std::plus{}, countChars);

        return total;
    }


/// Part Two Solution
    int partTwo() {
        PuzzleInput input(inputFilename);

        int total = std::transform_reduce(input.lines.begin(), input.lines.end(), 0, std::plus{}, [](const std::string& line) {
            std::string encoded = encodeString(line);
            return static_cast<int>(encoded.size() - line.size());
        });

        return total;

    }
}

int main() {
    using namespace day08;
    test();

    {
        std::cout << std::fixed << std::setprecision(3);
        auto [seconds, result] = advent::eval<int>(&partOne);

        std::cout << "Day " << day << ": Part One = " << result << "\t\t (completed in " << seconds << "s).\n";
    }
    {
        std::cout << std::fixed << std::setprecision(3);
        auto [seconds, result] = advent::eval<int>(&partTwo);

        std::cout << "Day " << day << ": Part One = " << result << "\t\t (completed in " << seconds << "s).\n";
    }
}







