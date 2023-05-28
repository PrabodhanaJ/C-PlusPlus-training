//
//  main.cpp
//  iterator-pattern
//

#include <iostream>
#include<vector>

class NumnerIterator {
public:
    virtual ~NumnerIterator() {};
    virtual int next()=0;
    virtual bool isFinished() = 0;
};

class ForwardIterator : public NumnerIterator {
    int currentPosition;
    std::vector<int>& numbers;
public:
    ForwardIterator(std::vector<int>& numbers) : currentPosition(0), numbers(numbers) {};
    int next() override {
        int current = numbers.at(currentPosition);
        currentPosition += 1;
        return current;
    }
    bool isFinished() override {
        return currentPosition >= numbers.size(); 
    }
};

class BackwardIterator : public NumnerIterator {
    int currentPosition;
    std::vector<int>& numbers;
public:
    BackwardIterator(std::vector<int>& numbers) : currentPosition(0), numbers(numbers) {};
    int next() override {
        int current = numbers.at(numbers.size() - currentPosition - 1);
        currentPosition += 1;
        return current;
    }
    bool isFinished() override {
        return currentPosition >= numbers.size();
    }
};

class NumberCollection {
    std::vector<int> numbers;
public:
    NumberCollection(const std::vector<int>& numbers) : numbers(numbers) {};
    NumnerIterator* getForwardsIterator() { return new ForwardIterator(numbers); };
    NumnerIterator* getBackwardsIterator() { return new BackwardIterator(numbers); };
};

int main(int argc, const char * argv[]) {
    std::vector<int> numbers = { 1,2,3,4,5,6,7 };
    NumberCollection nc(numbers);

    NumnerIterator* fi = nc.getForwardsIterator();
    NumnerIterator* bi = nc.getBackwardsIterator();

    std::cout << "\n";
    std::cout << "Iterating through the numbers backwards: \n";

    while (!bi->isFinished()) {
        std::cout << bi->next() << ", ";
    }
    std::cout << "\n";

    std::cout << "Iterating through the numbers forwards: \n";

    while (!fi->isFinished()) {
        std::cout << fi->next() << ", ";
    }

    delete fi;
    delete bi;

    return 0;
}
