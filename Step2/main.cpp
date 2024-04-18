/*
 =================================================================
 Step 2 (Solution see Step 3)
 =================================================================
*/

#include <iostream>
    // std::cin
    // std::cout
    // std::endl
    // std::istream
    // std::ostream
#include <string>
    // std::getline
    // std::string
#include <sstream>
    // std::istringstream

void do_averages(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        float value;
        float sum = 0.0f;
        int count = 0;
        std::istringstream iss{line};
        while (iss >> value) {
            sum += value;
            ++count;
        }
        if (count == 0) return;
        out << sum/count << std::endl;
    }
}

int main() {
    do_averages(std::cin, std::cout);
}
