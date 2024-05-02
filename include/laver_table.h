#include <iomanip>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

class LaverTable{
public:
    explicit LaverTable(int n);

    unsigned long long size() const;

    int get(int i, int j) const;

    void print(std::optional<std::string> filename = std::nullopt);

private:
    int compute(int p, int q);

    void checkBounds(int i);

    int twoPower() const;

    void fill();

    int d_n;
    int d_two_to_n;
    std::vector<std::vector<int>> d_lt;
};