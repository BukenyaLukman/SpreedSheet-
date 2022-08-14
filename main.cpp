#include <iostream>

#include "SpreedsheetCell.h"


int main() {

    SpreedsheetCell c1(4);
    SpreedsheetCell c2(6);
    SpreedsheetCell c3 = -c1;
    c1++;
    ++c2;

    std::cout << (c1 == c2) << std::endl;
    std::cout << (c1 < c2) << std::endl;
    std::cout << (c1 != c2) << std::endl;
    std::cout << (c1 > c2) << std::endl;
    std::cout << (c1 <= c2) << std::endl;


    int number = 0;
    std::cout << "The number is " << number <<  std::endl;
    std::string  str;
    std::cin >> number >> str;

    SpreedsheetCell myCell, anotherCell, aThirdCell;

    std::cout << "Input 3 SpreedSheetCells: " << std::endl;
    std::cin >> myCell >>  anotherCell >> aThirdCell;
    std::cout << myCell << anotherCell << aThirdCell <<  std::endl;

    std::cout << "Input 3 SpreedSheetCells: " << std::endl;
    operator>>(operator>>(operator>>(std::cin, myCell), anotherCell), aThirdCell);

    return 0;
}
