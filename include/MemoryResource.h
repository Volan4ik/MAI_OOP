#ifndef MEMORYRESOURCE_H
#define MEMORYRESOURCE_H

#include <memory_resource>
#include <vector>
#include <cstddef>
#include <iostream>

class MemoryResource : public std::pmr::memory_resource {
public:
    MemoryResource(std::size_t blockSize) : blockSize(blockSize) {
        memoryBlock = new char[blockSize];
        currentPosition = memoryBlock;
    }

    ~MemoryResource() {
        delete[] memoryBlock;
        for (auto ptr : allocatedBlocks) {
            delete[] static_cast<char*>(ptr);
        }
    }

protected:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        if (!freedBlocks.empty() && bytes <= blockSize) {
            // Reuse a previously freed block
            void* result = freedBlocks.back();
            freedBlocks.pop_back();
            return result;
        }

        if (currentPosition + bytes > memoryBlock + blockSize) {
            // If the fixed block is exhausted, allocate a new block
            char* newBlock = new char[bytes];
            allocatedBlocks.push_back(newBlock);
            return newBlock;
        }
        void* result = currentPosition;
        currentPosition += bytes;
        return result;
    }

    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override {
        // Reuse the memory if possible
        if (bytes <= blockSize) {
            freedBlocks.push_back(p);
        } else {
            delete[] static_cast<char*>(p);
        }
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

private:
    char* memoryBlock;
    char* currentPosition;
    std::size_t blockSize;
    std::vector<void*> allocatedBlocks;
    std::vector<void*> freedBlocks;
};

#endif // MEMORYRESOURCE_H