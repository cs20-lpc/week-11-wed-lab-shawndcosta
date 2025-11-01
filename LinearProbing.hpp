#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class LinearProbing : public HashTableClosed<T> {
private:
    int skip; // skip factor
public:
    LinearProbing(int size = 101, int skipFactor = 3)
        : HashTableClosed<T>(size), skip(skipFactor) {}

    
    int probeIndex(const T& key, int i) override {
        // TODO: Implement linear probing with skip
            return (this->hash1(key) + i * skip) % this->M;
    }
};
