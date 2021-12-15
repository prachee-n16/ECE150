// Implement bitnode and bitvector.
// Perform bitwise operations on this sequence of bits

#include <iostream>

class BitNode
{
public:
    BitNode(bool b);
    ~BitNode();
    BitNode *get_next(); // returns p_next_bit
    void set_next(BitNode *p_next);
    bool get_bit(); // returns bit data

private:
    bool bit_data_;
    BitNode *p_next_bit_;
};

BitNode::BitNode(bool b)
{
    bit_data_ = b;
    p_next_bit_ = nullptr;
}

BitNode::~BitNode()
{
}

BitNode *BitNode::get_next() { return p_next_bit_; };
bool BitNode::get_bit() { return bit_data_; };
void BitNode::set_next(BitNode *p_next) { p_next_bit_ = p_next; };

class BitVector
{
public:
    BitVector();
    ~BitVector();
    void insert_back(BitNode *p_);

private:
    BitNode *p_bv_head; // start of sequence of bits
    BitNode *p_bv_tail;
};

BitVector::BitVector()
{
    p_bv_head = nullptr;
    p_bv_tail = nullptr;
}
BitVector::~BitVector() {}

int main();
int main()
{
    return 0;
}
