//
// Created by bukenya on 14/08/22.
//

#ifndef SPREADSHEET_SPREEDSHEETCELL_H
#define SPREADSHEET_SPREEDSHEETCELL_H
#include<cstddef>
#include<string>
#include<string_view>
#include<utility>
#include<iostream>

class SpreedsheetCell {
public:
    SpreedsheetCell() = default;
    SpreedsheetCell(double initialValue);
    explicit SpreedsheetCell(std::string_view initialValue);

    void set(double inValue);
    void set(std::string_view inString);


    double getValue() const { mNumAccesses++; return mValue; }
    std::string getString() const { mNumAccesses++; return doubleToString(mValue); }

    static std::string doubleToString(double inValue);
    static double stringToDouble(std::string_view inString);

    SpreedsheetCell& operator+=(const SpreedsheetCell& rhs);
    SpreedsheetCell& operator-=(const SpreedsheetCell& rhs);
    SpreedsheetCell& operator*=(const SpreedsheetCell& rhs);
    SpreedsheetCell& operator/=(const SpreedsheetCell& rhs);
    SpreedsheetCell operator-() const;
    SpreedsheetCell& operator++(); //prefix
    SpreedsheetCell operator++(int); //postfix
    SpreedsheetCell& operator--(); //prefix
    SpreedsheetCell operator--(int); //postfix

private:
    double mValue = 0;
    mutable size_t mNumAccesses = 0;

};

SpreedsheetCell operator+(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
SpreedsheetCell operator-(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
SpreedsheetCell operator*(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
SpreedsheetCell operator/(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
bool operator==(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
bool operator<(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
bool operator>(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
bool operator!=(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
bool operator<=(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
bool operator>=(const SpreedsheetCell& lhs, const SpreedsheetCell& rhs);
std::ostream& operator<<(std::ostream& ostr,const SpreedsheetCell& cell);
std::istream& operator>>(std::istream& istr, SpreedsheetCell& cell);

#endif //SPREADSHEET_SPREEDSHEETCELL_H
