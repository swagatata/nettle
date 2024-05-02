#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "laver_table.h"

LaverTable::LaverTable(int n):d_n(n),d_two_to_n(twoPower()) {        
    int size = this->twoPower();
    d_lt.resize(size);
    for (int i = 0; i < size; ++i) {
        d_lt[i].resize(size, 0);
    }
    fill();
}

void LaverTable::fill() {
    // step 1:
    d_lt[d_two_to_n - 1][0] = 1;
    for (int i = 1; i < d_two_to_n; ++i) {
        d_lt[i - 1][0] = i + 1;
    }

    // step 2 : fill the last row
    for (int i = 2; i <= d_two_to_n; ++i) {
        d_lt[d_two_to_n - 1][i - 1] = i;
    }

    // fill from the bottom
    for (int row = d_two_to_n - 1; row >= 1; --row) {
        for (int col = 2; col <= d_two_to_n; ++col) {
            compute(row, col);
        }
    }
}

int LaverTable::compute(int p, int q) {
    // check for boundary
    checkBounds(p);
    checkBounds(q);

    if (d_lt[p - 1][q - 1] != 0) {
        return d_lt[p - 1][q - 1];
    }

    int result = 0;
    compute(p, q - 1);        
    result = compute(d_lt[p-1][q - 2], d_lt[p-1][0]);
        
    // std::cout << "lv[" << p << "][" << q << "] : " << result << "\n";
    d_lt[p - 1][q - 1] = result;
    return result;
}

void LaverTable::checkBounds(int i) {
    if (i < 1 || i > d_two_to_n) {
        std::stringstream ss;
        ss << "index out of bounds : " << i;
        throw ss.str();
    }
}

int LaverTable::twoPower() const {
    // calculate 2 to the power of d_n
    return 1 << d_n;
}

unsigned long long LaverTable::size() const {
    return twoPower() << d_n;
}

int LaverTable::get(int i, int j) const {
    return d_lt[i-1][j-1];
}

void LaverTable::print(std::optional<std::string> filename) {
    // if filename is null, use cout, if not create a file output stream
    std::ostream* output = &std::cout;
    std::ofstream file;
    if (filename.has_value()) {
        file.open(filename.value());
        output = &file;
    }

    *output << "Laver Table for N = " << d_n << std::endl;
    for (int i = 0; i < d_two_to_n; ++i) {
        for (int j = 0; j < d_two_to_n; ++j) {
            *output << std::setfill(' ') << std::setw(4) << d_lt[i][j] << " ";
        }
        *output << std::endl;
    }
}