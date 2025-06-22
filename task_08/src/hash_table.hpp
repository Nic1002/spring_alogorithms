#pragma once

#include <vector>
#include <functional>

template<typename T>
class Hashtable final
{
private:
    struct Node
    {
        bool full;
        T value;
        Node(T value) : full(true), value(value) {}
    };

    size_t buffer_size = 64;
    size_t size = 0;
    size_t active_size = 0;
    std::vector<Node*> buffer{buffer_size, nullptr};

    std::function<size_t(T)> beginHash, stepHash;

public:
    Hashtable(std::function<size_t(T)> beginHash, std::function<size_t(T)> stepHash) : beginHash(beginHash), stepHash(stepHash) {};
    
    size_t Size() const { return size; }
    size_t ActiveSize() const { return active_size; }
    size_t BufferSize() const { return buffer_size; }

    bool Find(T value)
    {
        size_t begin = beginHash(value) % buffer_size;
        size_t step = stepHash(value) % (buffer_size - 1) + 1;

        for (size_t i = 0; i < buffer_size; ++i)
        {
            if (buffer[begin] == nullptr) return false;
            if (buffer[begin]->full && buffer[begin]->value == value) return true;
            begin = (begin + step) % buffer_size;
        }
        return false;
    }

    void Resize()
    {
        buffer_size *= 2;
        std::vector<Node*> old_buffer(buffer_size, nullptr);
        std::swap(buffer, old_buffer);
        size = 0;
        active_size = 0;
        
        for (size_t i = 0; i < old_buffer.size(); ++i)
        {
            if (old_buffer[i] != nullptr && old_buffer[i]->full)
            {
                Add(old_buffer[i]->value);
                delete old_buffer[i];
            }
        }
    }

    void Rehash()
    {
        std::vector<Node*> old_buffer(buffer_size, nullptr);
        std::swap(buffer, old_buffer);
        size = 0;
        active_size = 0;
        
        for (size_t i = 0; i < old_buffer.size(); ++i)
        {
            if (old_buffer[i] != nullptr && old_buffer[i]->full)
            {
                Add(old_buffer[i]->value);
                delete old_buffer[i];
            }
        }
    }
    
    bool Add(T value)
    {
        if (active_size + 1 > int(0.75 * buffer_size)) Resize();
        if (size > 2 * active_size) Rehash();

        size_t begin = beginHash(value) % buffer_size;
        size_t step = stepHash(value) % (buffer_size - 1) + 1;

        size_t first_empty = buffer_size;
        for (size_t i = 0; i < buffer_size; ++i)
        {
            if (buffer[begin] == nullptr)
            {
                first_empty = begin;
                break;
            }
            if (buffer[begin]->full && buffer[begin]->value == value) return false;
            if (!buffer[begin]->full && first_empty == buffer_size) first_empty = begin;
            begin = (begin + step) % buffer_size;
        }
        
        if (first_empty != buffer_size)
        {
            if (buffer[first_empty] == nullptr)
            {
                buffer[first_empty] = new Node(value);
                active_size++;
            }
            else
            {
                buffer[first_empty]->value = value;
                buffer[first_empty]->full = true;
            }
            size++;
            return true;
        }
        return false;
    }

    bool Remove(T value)
    {
        size_t begin = beginHash(value) % buffer_size;
        size_t step = stepHash(value) % (buffer_size - 1) + 1;

        for (size_t i = 0; i < buffer_size; ++i)
        {
            if (buffer[begin] == nullptr) return false;
            if (buffer[begin]->full && buffer[begin]->value == value)
            {
                buffer[begin]->full = false;
                size--;
                return true;
            }
            begin = (begin + step) % buffer_size;
        }
        return false;
    }
};