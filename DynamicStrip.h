class DynamicStrip {
public:
    DynamicStrip() : position(0) {}
    DynamicStrip(const DynamicStrip&) = delete;
    ~DynamicStrip() = default;

    DynamicStrip& operator++() {
        strip[position] += 1;
        return *this;
    }

    DynamicStrip& operator--() {
        strip[position] -= 1;
        return *this;
    }

    void left() {
        if (position > 0) {
            position--;
        } else {
            strip.pushLeft(0);
        }
    }

    void right() {
        position++;
        if (position >= strip.getLength()) {
            strip.pushRight(0);
        }
    }

    void put() { putchar(strip[position]); }

    void read() { strip[position] = getchar(); }

    char operator*() const { return strip[position]; }

private:
    DEVector strip;
    unsigned position;
};
