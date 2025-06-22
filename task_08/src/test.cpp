#include "hash_table.cpp"
#include <gtest/gtest.h>

TEST(HashTableTest, InsertAndGet) {
    HashTable table;
    table.insert(1, 100);
    table.insert(2, 200);
    EXPECT_EQ(table.get(1), 100);
    EXPECT_EQ(table.get(2), 200);
}

TEST(HashTableTest, UpdateValue) {
    HashTable table;
    table.insert(1, 100);
    table.insert(1, 200);
    EXPECT_EQ(table.get(1), 200);
}

TEST(HashTableTest, ContainsKey) {
    HashTable table;
    table.insert(1, 100);
    EXPECT_TRUE(table.contains(1));
    EXPECT_FALSE(table.contains(2));
}

TEST(HashTableTest, RemoveKey) {
    HashTable table;
    table.insert(1, 100);
    table.insert(2, 200);
    table.remove(1);
    EXPECT_FALSE(table.contains(1));
    EXPECT_TRUE(table.contains(2));
    EXPECT_EQ(table.size(), 1);
}

TEST(HashTableTest, GetMissingKeyThrows) {
    HashTable table;
    EXPECT_THROW(table.get(1), std::out_of_range);
    table.insert(1, 100);
    EXPECT_THROW(table.get(2), std::out_of_range);
}

TEST(HashTableTest, SizeAndEmpty) {
    HashTable table;
    EXPECT_TRUE(table.empty());
    table.insert(1, 100);
    EXPECT_EQ(table.size(), 1);
    EXPECT_FALSE(table.empty());
    table.remove(1);
    EXPECT_TRUE(table.empty());
}

TEST(HashTableTest, Rehashing) {
    HashTable table(3);
    table.insert(1, 100);
    table.insert(2, 200);
    table.insert(3, 300);
    table.insert(4, 400);
    
    EXPECT_EQ(table.size(), 4);
    EXPECT_EQ(table.get(1), 100);
    EXPECT_EQ(table.get(2), 200);
    EXPECT_EQ(table.get(3), 300);
    EXPECT_EQ(table.get(4), 400);
}

TEST(HashTableTest, CollisionHandling) {
    HashTable table(1);
    table.insert(1, 100);
    table.insert(2, 200);
    table.insert(3, 300);
    
    EXPECT_EQ(table.get(1), 100);
    EXPECT_EQ(table.get(2), 200);
    EXPECT_EQ(table.get(3), 300);
    
    table.remove(2);
    EXPECT_FALSE(table.contains(2));
    EXPECT_EQ(table.get(1), 100);
    EXPECT_EQ(table.get(3), 300);
}

TEST(HashTableTest, LargeInput) {
    HashTable table;
    const int N = 1000;
    for (int i = 0; i < N; i++) {
        table.insert(i, i*10);
    }
    
    for (int i = 0; i < N; i++) {
        EXPECT_EQ(table.get(i), i*10);
    }
    
    for (int i = 0; i < N; i += 2) {
        table.remove(i);
    }
    
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            EXPECT_FALSE(table.contains(i));
        } else {
            EXPECT_EQ(table.get(i), i*10);
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}