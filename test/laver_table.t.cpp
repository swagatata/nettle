#include "laver_table.h"
#include <gtest/gtest.h>

TEST(LaverTableTest, N0) {
    LaverTable lt(0);
    EXPECT_EQ(lt.size(), 1);
    EXPECT_EQ(lt.get(1, 1), 1);
    lt.print();
}

class LaverTableTest : public ::testing::TestWithParam<int> {
protected:
    LaverTableTest() {}
    virtual ~LaverTableTest() {}
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_P(LaverTableTest, N) {
    int N = GetParam();
    LaverTable lt(N);
    EXPECT_EQ(lt.size(), 1 << (2 * N));
    EXPECT_EQ(lt.get(1, 1), 2);

    std::stringstream filename;
    filename << "LaverTable" << N;
    lt.print(filename.str());
}

INSTANTIATE_TEST_CASE_P(N, LaverTableTest, ::testing::Values(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13));


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}