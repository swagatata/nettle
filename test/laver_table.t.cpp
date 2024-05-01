#include "laver_table.h"
#include <gtest/gtest.h>

TEST(LaverTableTest, N0) {
    LaverTable lt(0);
    EXPECT_EQ(lt.size(), 1);
    EXPECT_EQ(lt.get(1, 1), 1);
    lt.print();
}

TEST(LaverTableTest, N1) {
    LaverTable lt(1);
    EXPECT_EQ(lt.size(), 4);
    EXPECT_EQ(lt.get(1, 1), 2);
    EXPECT_EQ(lt.get(1, 2), 2);
    EXPECT_EQ(lt.get(2, 1), 1);
    EXPECT_EQ(lt.get(2, 2), 2);
    lt.print();
}

TEST(LaverTableTest, N2) {
    LaverTable lt(2);
    EXPECT_EQ(lt.size(), 16);
    EXPECT_EQ(lt.get(1, 1), 2);
    EXPECT_EQ(lt.get(2, 1), 3);
    EXPECT_EQ(lt.get(3, 1), 4);
    EXPECT_EQ(lt.get(4, 1), 1);
    lt.print();
}

TEST(LaverTableTest, N3) {
    LaverTable lt(3);
    EXPECT_EQ(lt.size(), 64);
    EXPECT_EQ(lt.get(1, 1), 2);
    EXPECT_EQ(lt.get(2, 1), 3);
    EXPECT_EQ(lt.get(3, 1), 4);
    // EXPECT_EQ(lt.get(4, 1), 1);
    lt.print();
}

TEST(LaverTableTest, N4) {
    LaverTable lt(4);
    EXPECT_EQ(lt.size(), 256);
    EXPECT_EQ(lt.get(1, 1), 2);
    EXPECT_EQ(lt.get(2, 1), 3);
    EXPECT_EQ(lt.get(3, 1), 4);
    // EXPECT_EQ(lt.get(4, 1), 1);
    lt.print();
    std::cout << "-----------------------------\n";
}

TEST(LaverTableTest, N5) {
    LaverTable lt(5);
    EXPECT_EQ(lt.size(), 32*32);
    EXPECT_EQ(lt.get(1, 1), 2);
    EXPECT_EQ(lt.get(2, 1), 3);
    EXPECT_EQ(lt.get(3, 1), 4);
    // EXPECT_EQ(lt.get(4, 1), 1);
    lt.print();
    std::cout << "-----------------------------\n";
}

TEST(LaverTableTest, N6) {
    LaverTable lt(6);
    EXPECT_EQ(lt.size(), 64*64);
    EXPECT_EQ(lt.get(1, 1), 2);
    EXPECT_EQ(lt.get(2, 1), 3);
    EXPECT_EQ(lt.get(3, 1), 4);
    // EXPECT_EQ(lt.get(4, 1), 1);
    lt.print();
    std::cout << "-----------------------------\n";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}