#include <gtest/gtest.h>
#include "hash_table.hpp"

size_t simple_begin_hash(int value) {
    return value;
}

size_t simple_step_hash(int value) {
    return value + 1;
}

class HashTableTest : public ::testing::Test {
protected:
    void SetUp() override {
        table = new Hashtable<int>(simple_begin_hash, simple_step_hash);
    }

    void TearDown() override {
        delete table;
    }

    Hashtable<int>* table;
};

TEST_F(HashTableTest, InitialState) {
    EXPECT_EQ(0, table->Size());
    EXPECT_EQ(0, table->ActiveSize());
    EXPECT_EQ(64, table->BufferSize());
}

TEST_F(HashTableTest, AddAndFind) {
    EXPECT_TRUE(table->Add(42));
    EXPECT_TRUE(table->Find(42));
    EXPECT_EQ(1, table->Size());
    EXPECT_EQ(1, table->ActiveSize());
}

TEST_F(HashTableTest, AddDuplicate) {
    EXPECT_TRUE(table->Add(42));
    EXPECT_FALSE(table->Add(42));
    EXPECT_EQ(1, table->Size());
}

TEST_F(HashTableTest, Remove) {
    table->Add(42);
    EXPECT_TRUE(table->Remove(42));
    EXPECT_FALSE(table->Find(42));
    EXPECT_EQ(0, table->Size());
    EXPECT_EQ(1, table->ActiveSize());
}

TEST_F(HashTableTest, RemoveNonExistent) {
    EXPECT_FALSE(table->Remove(42));
}

TEST_F(HashTableTest, HandleCollisions) {
    auto collision_hash = [](int) { return 0; };
    Hashtable<int> coll_table(collision_hash, [](int) { return 1; });
    
    EXPECT_TRUE(coll_table.Add(1));
    EXPECT_TRUE(coll_table.Add(2));
    EXPECT_TRUE(coll_table.Find(1));
    EXPECT_TRUE(coll_table.Find(2));
}

TEST_F(HashTableTest, ResizeWhenFull) {
    Hashtable<int> small_table(simple_begin_hash, simple_step_hash);
    
    for (int i = 0; i < 50; ++i) {
        EXPECT_TRUE(small_table.Add(i));
    }
    
    for (int i = 0; i < 50; ++i) {
        EXPECT_TRUE(small_table.Find(i));
    }
}

TEST_F(HashTableTest, RehashWhenManyDeleted) {
    for (int i = 0; i < 100; ++i) {
        table->Add(i);
    }
    
    for (int i = 0; i < 50; ++i) {
        table->Remove(i);
    }
    
    for (int i = 50; i < 100; ++i) {
        EXPECT_TRUE(table->Find(i));
    }
    for (int i = 0; i < 50; ++i) {
        EXPECT_FALSE(table->Find(i));
    }
}

TEST_F(HashTableTest, AddAfterRemove) {
    table->Add(42);
    table->Remove(42);
    EXPECT_TRUE(table->Add(42));
    EXPECT_TRUE(table->Find(42));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}