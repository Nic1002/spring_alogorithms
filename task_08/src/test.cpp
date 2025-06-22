#include "hash_table.cpp"
#include <gtest/gtest.h>

TEST(HashTableTest, BasicOperations) {
    HashTable table;
    EXPECT_TRUE(table.empty());
    
    table.insert(1, 100);
    table.insert(2, 200);
    
    EXPECT_EQ(table.size(), 2);
    EXPECT_FALSE(table.empty());
    EXPECT_EQ(table.get(1), 100);
    EXPECT_EQ(table.get(2), 200);
    EXPECT_TRUE(table.contains(1));
    EXPECT_FALSE(table.contains(3));
}

TEST(HashTableTest, UpdateValues) {
    HashTable table;
    table.insert(1, 100);
    table.insert(1, 200);
    
    EXPECT_EQ(table.size(), 1);
    EXPECT_EQ(table.get(1), 200);
}

TEST(HashTableTest, RemoveKeys) {
    HashTable table;
    table.insert(1, 100);
    table.insert(2, 200);
    table.insert(3, 300);
    
    table.remove(2);
    EXPECT_EQ(table.size(), 2);
    EXPECT_FALSE(table.contains(2));
    EXPECT_THROW(table.get(2), std::out_of_range);
    
    table.remove(1);
    table.remove(3);
    EXPECT_TRUE(table.empty());
}

TEST(HashTableTest, Collisions) {
    HashTable table(3); // Маленький размер для теста коллизий
    table.insert(1, 100);
    table.insert(4, 400); // Должно быть коллизия с 1
    table.insert(7, 700); // Коллизия
    
    EXPECT_EQ(table.size(), 3);
    EXPECT_EQ(table.get(1), 100);
    EXPECT_EQ(table.get(4), 400);
    EXPECT_EQ(table.get(7), 700);
    
    table.remove(4);
    EXPECT_FALSE(table.contains(4));
    EXPECT_TRUE(table.contains(1));
    EXPECT_TRUE(table.contains(7));
}

TEST(HashTableTest, Rehashing) {
    HashTable table(3);
    table.insert(1, 100);
    table.insert(2, 200);
    table.insert(3, 300);
    table.insert(4, 400); // Вызовет рехеширование
    
    EXPECT_EQ(table.size(), 4);
    EXPECT_EQ(table.get(1), 100);
    EXPECT_EQ(table.get(2), 200);
    EXPECT_EQ(table.get(3), 300);
    EXPECT_EQ(table.get(4), 400);
}

TEST(HashTableTest, ErrorCases) {
    HashTable table;
    EXPECT_THROW(table.get(1), std::out_of_range);
    
    table.insert(1, 100);
    EXPECT_THROW(table.get(2), std::out_of_range);
    
    table.remove(1);
    EXPECT_THROW(table.get(1), std::out_of_range);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}