#include <memory>
#include <assert.h>

using std::make_unique;
using std::unique_ptr;

class DEVector {
   public:
    DEVector() : capacity(INIT_CAPACITY) {
        buffer = std::make_unique<char[]>(capacity);
        lPos = INIT_CAPACITY / 2;
        rPos = lPos;
    }

    DEVector(unsigned capacity) {
        this->capacity = capacity;
        buffer = std::make_unique<char[]>(capacity);
        lPos = capacity / 2;
        rPos = lPos;
    }

    DEVector(const DEVector& o) { copyFrom(o); }

    ~DEVector() = default;

    DEVector& operator=(const DEVector& o) {
        copyFrom(o);
        return *this;
    }

    unsigned getLength() const { return rPos - lPos; }
    unsigned getCapacity() const { return capacity; }

    void leftRealloc() {
        unsigned newCapacity = capacity * ALLOC_FACTOR,
                 diff = newCapacity - capacity;

        auto newBuffer = std::make_unique<char[]>(newCapacity);

        for (unsigned i = lPos; i < rPos; i++) {
            newBuffer[i + diff] = buffer[i];
        }

        lPos += diff;
        rPos += diff;
        capacity = newCapacity;
        buffer.reset(newBuffer.release());
    }

    void rightRealloc() {
        unsigned newCapacity = capacity * ALLOC_FACTOR;
        auto newBuffer = std::make_unique<char[]>(newCapacity);

        for (unsigned i = lPos; i < rPos; i++) {
            newBuffer[i] = buffer[i];
        }

        capacity = newCapacity;
        buffer.reset(newBuffer.release());
    }

    void pushRight(char value) {
        if (rPos + 1 >= capacity) {
            rightRealloc();
        }

        buffer[rPos] = value;
        rPos++;
    }

    void pushLeft(char value) {
        if (lPos <= 0) {
            leftRealloc();
        }

        lPos--;
        buffer[lPos] = value;
    }

    char operator[](unsigned i) const {
        unsigned position = i + lPos;
        assert(position < rPos);
        return buffer[position];
    }

    char& operator[](unsigned i) {
        unsigned position = i + lPos;
        assert(position < rPos);
        return buffer[position];
    }

   private:
    static const unsigned INIT_CAPACITY = 1024;
    static const unsigned ALLOC_FACTOR = 2;
    unique_ptr<char[]> buffer;
    unsigned capacity;
    unsigned lPos;
    unsigned rPos;

    void copyFrom(const DEVector& o) {
        this->capacity = o.capacity;
        buffer = std::make_unique<char[]>(this->capacity);
        lPos = o.lPos;
        rPos = o.rPos;

        for (unsigned i = lPos; i < rPos; i++) {
            buffer[i] = o.buffer[i];
        }
    }
};
