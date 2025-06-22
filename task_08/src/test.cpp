#include <gtest/gtest.h>
#include "hashmap.hpp"

TEST(HashMapTest, InsertAndGet) {
    HashMap map;
    map.insert("apple", 10);
    map.insert("banana", 20);
    
    ASSERT_EQ(map.get("apple"), 10);
    ASSERT_EQ(map.get("banana"), 20);
    ASSERT_THROW(map.get("orange"), std::out_of_range);
}

TEST(HashMapTest, ContainsAndRemove) {
    HashMap map;
    map.insert("one", 1);
    map.insert("two", 2);
    
    ASSERT_TRUE(map.contains("one"));
    ASSERT_TRUE(map.contains("two"));
    ASSERT_FALSE(map.contains("three"));
    
    map.remove("one");
    ASSERT_FALSE(map.contains("one"));
    ASSERT_TRUE(map.contains("two"));
}

TEST(HashMapTest, SizeAndEmpty) {
    HashMap map;
    ASSERT_TRUE(map.isEmpty());
    ASSERT_EQ(map.getSize(), 0);
    
    map.insert("a", 1);
    map.insert("b", 2);
    
    ASSERT_FALSE(map.isEmpty());
    ASSERT_EQ(map.getSize(), 2);
    
    map.remove("a");
    ASSERT_EQ(map.getSize(), 1);
    
    map.clear();
    ASSERT_TRUE(map.isEmpty());
    ASSERT_EQ(map.getSize(), 0);
}

TEST(HashMapTest, Rehashing) {
    HashMap map(2);
    
    map.insert("a", 1);
    map.insert("b", 2);
    map.insert("c", 3);
    
    ASSERT_EQ(map.getSize(), 3);
    ASSERT_EQ(map.get("a"), 1);
    ASSERT_EQ(map.get("b"), 2);
    ASSERT_EQ(map.get("c"), 3);

    map.insert("d", 4);
    ASSERT_EQ(map.getSize(), 4);
    ASSERT_EQ(map.get("d"), 4);
}