#pragma once
//integer.h
class Integer{
public:
    Integer();

    Integer(int value);
    
    Integer(const Integer &value);

    int getValue() const;
    
    void setValue(int value);
    
    void printValue() const;
    
private:
    int number;
};