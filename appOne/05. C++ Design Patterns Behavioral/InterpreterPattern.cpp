//
//  main.cpp
//  interpreter-pattern
//
//

#include <iostream>
#include <sstream>

class Expression {
public:
    virtual int evaluate() = 0;
};

class OperationExpression : public Expression {
    std::string operatorSymbol;
    Expression* leftHandSide;
    Expression* rightHandSide;
public:
    OperationExpression(const std::string& operatorSymbol, Expression* lhs,
        Expression* rhs) : operatorSymbol(operatorSymbol), leftHandSide(lhs),
        rightHandSide(rhs) {};
    int evaluate() override {
        if (operatorSymbol == "+")
            return leftHandSide->evaluate() + rightHandSide->evaluate();
        else if (operatorSymbol == "-")
            return leftHandSide->evaluate() - rightHandSide->evaluate();
        else {
            std::cout << "Unrecognized operator: " << operatorSymbol;
            return 0;
        } 
    }
};

class NumberExperssion : public Expression{
    std::string numberString;
public:
    NumberExperssion(const std::string& numberString) : numberString(numberString) {};
    int evaluate() override {
        return std::stoi(numberString);
    }
};

int main(int argc, const char * argv[]) {
    NumberExperssion* five = new NumberExperssion("5");
    NumberExperssion* seven = new NumberExperssion("7");
    OperationExpression* fivePlusSeven = new OperationExpression("+", five, seven);

    std::cout << "Five plus Seven is: " << fivePlusSeven->evaluate() << "\n";

    delete five;
    delete seven;
    delete fivePlusSeven;
    return 0;
}
