#include "hash_table.cpp"
#include <gtest/gtest.h>

TEST(HashTableTest, InsertAndGet) {
    HashTable table;
    table.Insert(1, 100);
    table.Insert(2, 200);
    EXPECT_EQ(table.Get(1), 100);
    EXPECT_EQ(table.Get(2), 200);
}

TEST(HashTableTest, UpdateValue) {
    HashTable table;
    table.Insert(1, 100);
    table.Insert(1, 200);
    EXPECT_EQ(table.Get(1), 200);
}

TEST(HashTableTest, ContainsKey) {
    HashTable table;
    table.Insert(1, 100);
    EXPECT_TRUE(table.Contains(1));
    EXPECT_FALSE(table.Contains(2));
}

TEST(HashTableTest, RemoveKey) {
    HashTable table;
    table.Insert(1, 100);
    table.Insert(2, 200);
    table.Remove(1);
    EXPECT_FALSE(table.Contains(1));
    EXPECT_TRUE(table.Contains(2));
    EXPECT_EQ(table.Size(), 1);
}

TEST(HashTableTest, GetMissingKeyThrows) {
    HashTable table;
    EXPECT_THROW(table.Get(1), std::out_of_range);
    table.Insert(1, 100);
    EXPECT_THROW(table.Get(2), std::out_of_range);
}

TEST(HashTableTest, SizeAndEmpty) {
    HashTable table;
    EXPECT_TRUE(table.Empty());
    table.Insert(1, 100);
    EXPECT_EQ(table.Size(), 1);
    EXPECT_FALSE(table.Empty());
    table.Remove(1);
    EXPECT_TRUE(table.Empty());
}

TEST(HashTableTest, Rehashing) {
    HashTable table(3);
    table.Insert(1, 100);
    table.Insert(2, 200);
    table.Insert(3, 300);
    table.Insert(4, 400);
    
    EXPECT_EQ(table.Size(), 4);
    EXPECT_EQ(table.Get(1), 100);
    EXPECT_EQ(table.Get(2), 200);
    EXPECT_EQ(table.Get(3), 300);
    EXPECT_EQ(table.Get(4), 400);
}

TEST(HashTableTest, CollisionHandling) {
    HashTable table(1); // Все ключи в одном бакете
    table.Insert(1, 100);
    table.Insert(2, 200);
    table.Insert(3, 300);
    
    EXPECT_EQ(table.Get(1), 100);
    EXPECT_EQ(table.Get(2), 200);
    EXPECT_EQ(table.Get(3), 300);
    
    table.Remove(2);
    EXPECT_FALSE(table.Contains(2));
    EXPECT_EQ(table.Get(1), 100);
    EXPECT_EQ(table.Get(3), 300);
}

TEST(HashTableTest, LargeInput) {
    HashTable table;
    const int N = 10000;
    for (int i = 0; i < N; i++) {
        table.Insert(i, i*10);
    }
    
    for (int i = 0; i < N; i++) {
        EXPECT_EQ(table.Get(i), i*10);
    }
    
    for (int i = 0; i < N; i += 2) {
        table.Remove(i);
    }
    
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            EXPECT_FALSE(table.Contains(i));
        } else {
            EXPECT_EQ(table.Get(i), i*10);
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}