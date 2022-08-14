//
// Created by bukenya on 14/08/22.
//

#include "SpreedsheetCell.h"
#include<iostream>

#include<stdexcept>

SpreedsheetCell::SpreedsheetCell(double initialValue) : mValue(initialValue){}

SpreedsheetCell::SpreedsheetCell(std::string_view initialValue) : mValue(stringToDouble(initialValue)){}

void SpreedsheetCell::set(double inValue) {
    mValue = inValue;
}
void SpreedsheetCell::set(std::string_view inString) {
    mValue = stringToDouble(inString);
}

std::string SpreedsheetCell::doubleToString(double inValue) {
    return std::to_string(inValue);
}
double SpreedsheetCell::stringToDouble(std::string_view inString) {
    return std::strtod(inString.data(), nullptr);
}
SpreedsheetCell operator+(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    return SpreedsheetCell(lhs.getValue() + rhs.getValue());
}

SpreedsheetCell operator-(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    return SpreedsheetCell(lhs.getValue() - rhs.getValue());
}

SpreedsheetCell operator*(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    return SpreedsheetCell(lhs.getValue() * rhs.getValue());
}
SpreedsheetCell operator/(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    if(rhs.getValue() == 0){
        throw std::invalid_argument("Divide by zero");
    }
    return SpreedsheetCell(lhs.getValue() / rhs.getValue());
}

SpreedsheetCell& SpreedsheetCell::operator+=(const SpreedsheetCell &rhs) {
    set(getValue() + rhs.getValue());
    return *this;
}
SpreedsheetCell& SpreedsheetCell::operator-=(const SpreedsheetCell &rhs) {
    set(getValue() - rhs.getValue());
    return *this;
}

SpreedsheetCell& SpreedsheetCell::operator*=(const SpreedsheetCell &rhs) {
    set(getValue() * rhs.getValue());
    return *this;
}

SpreedsheetCell& SpreedsheetCell::operator/=(const SpreedsheetCell &rhs) {
    if(rhs.getValue() == 0){
        throw std::invalid_argument("Divide by Zero");
    }
    set(getValue() / rhs.getValue());
    return *this;
}

bool operator==(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    return (lhs.getValue() == rhs.getValue());
}

bool operator<(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    return (lhs.getValue() < rhs.getValue());
}
bool operator>(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    return (lhs.getValue() > rhs.getValue());
}
bool operator!=(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    return (lhs.getValue() != rhs.getValue());
}
bool operator<=(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    return (lhs.getValue() <= rhs.getValue());
}
bool operator>=(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs){
    return (lhs.getValue() >= rhs.getValue());
}

SpreedsheetCell SpreedsheetCell::operator-() const {
    return SpreedsheetCell(-getValue());
}

SpreedsheetCell& SpreedsheetCell::operator++(){
    set(getValue() + 1);
    return *this;
}

SpreedsheetCell SpreedsheetCell::operator++(int){
    auto oldCell(*this); // save current value
    ++(*this);          //  Increment using prefix ++
    return oldCell;     // Return the old value
}

SpreedsheetCell& SpreedsheetCell::operator--() {
    set(getValue() - 1);
    return *this;
}
SpreedsheetCell SpreedsheetCell::operator--(int){
    auto oldCell(*this);
    --(*this);
    return oldCell;
}
std::ostream& operator<<(std::ostream& ostr, const SpreedsheetCell& cell){
    ostr << cell.getValue();
    return ostr;
}
std::istream & operator>>(std::istream& istr,  SpreedsheetCell& cell){
    double value;
    istr >> value;
    cell.set(value);
    return istr;
}


