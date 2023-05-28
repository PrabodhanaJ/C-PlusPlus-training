//
//  main.cpp
//  strategy-pattern
//

#include <iostream>

class GreetingStrategy {
public:
    virtual ~GreetingStrategy() {};
    virtual void greet(const std::string& name) = 0;

};

class FormalGreetingStrategy: public GreetingStrategy {
public:
    void greet(const std::string & name) {
        std::cout << "Good morning " << name << ", how do you do?\n";
    }
};

class NormalGreetingStrategy: public GreetingStrategy {
public:
    void greet(const std::string & name) {
        std::cout << "Hi " << name << ", how are you?\n";
    }
};

class InFormalGreetingStrategy: public GreetingStrategy {
public:
    void greet(const std::string & name) {
        std::cout << "Hey " << name << ", what's up?\n";
    }
};

class Person {
    GreetingStrategy* greetinStrategy;
public:
    Person(GreetingStrategy* greetinStrategy) : greetinStrategy(greetinStrategy) {};
    ~Person() { delete greetinStrategy; };
    void greet(const std::string& name) {
        greetinStrategy->greet(name);
    }
};


int main(int argc, const char * argv[]) {
    Person businessPerson( new FormalGreetingStrategy());
    Person normalPerson(new NormalGreetingStrategy());
    Person coolPerson(new InFormalGreetingStrategy());
    Person politician(new FormalGreetingStrategy());

    std::cout << "This Business person says: ";
    businessPerson.greet("Shaun");
    std::cout << "This normal person says: ";
    normalPerson.greet("Shaun");
    std::cout << "This cool person says: ";
    coolPerson.greet("Shaun");
    std::cout << "This politician person says: ";
    politician.greet("Shaun");
    
      
    return 0;
}

/*
// Uh oh - code duplication!
class Politician : public Person {
public:
    void greet(const std::string & name) {
        std::cout << "Good morning " << name << ", how do you do?\n";
    }
};
*/