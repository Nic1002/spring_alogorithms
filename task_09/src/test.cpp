#include "table.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(TableCheckerTest, EmptyTable) {
    TableChecker tc;
    std::istringstream in("0 0\n0\n");
    std::ostringstream out;
    
    tc.readTable(in);
    tc.processQueries(in, out);
    
    EXPECT_EQ(out.str(), "");
}

TEST(TableCheckerTest, SingleRow) {
    TableChecker tc;
    std::istringstream in("1 3\n10 20 30\n2\n1 1\n1 1\n");
    std::ostringstream out;
    
    tc.readTable(in);
    tc.processQueries(in, out);
    
    EXPECT_EQ(out.str(), "Yes\nYes\n");
}

TEST(TableCheckerTest, SortedColumns) {
    TableChecker tc;
    std::istringstream in("3 2\n1 5\n2 6\n3 7\n2\n1 3\n2 3\n");
    std::ostringstream out;
    
    tc.readTable(in);
    tc.processQueries(in, out);
    
    EXPECT_EQ(out.str(), "Yes\nYes\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}