//
// Created by YuXiao on 3/26/16.
//

#ifndef LEECODPROJECT_284_PEEKING_ITERATOR_H
#define LEECODPROJECT_284_PEEKING_ITERATOR_H
/// Copyright 2016 yuXiao
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data *data;
public:
    explicit Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    virtual ~Iterator();

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    explicit PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        this->next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return nextval;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ans = nextval;
        if (Iterator::hasNext()) {
            flagNext = true;
            nextval = Iterator::next();
        } else {
            flagNext = false;
        }
        return ans;
    }

    bool hasNext() const {
        return flagNext;
    }

private:
    bool flagNext;
    int nextval;
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

#endif //LEECODPROJECT_284_PEEKING_ITERATOR_H
