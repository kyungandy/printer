#include "Printer.h"

int main() {
    InkjetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6345", "삼성전자", 3, 20);

    int option, pages;
    char cont;

    do {
        std::cout << "프린터를 선택하세요 (1:잉크젯, 2:레이저): ";
        std::cin >> option;

        if (option == 1) {
            std::cout << "잉크젯 프린터를 선택했습니다." << std::endl;
            inkjet.showStatus(); 
        }
        else if (option == 2) {
            std::cout << "레이저 프린터를 선택했습니다." << std::endl;
            laser.showStatus(); 
        }
        else {
            std::cout << "잘못된 옵션입니다." << std::endl;
            continue; 
        }

        std::cout << "인쇄할 페이지 수 입력: ";
        std::cin >> pages;

        if (option == 1) {
            inkjet.printInk(pages); 
        }
        else if (option == 2) {
            laser.printInk(pages); 
        }

        std::cout << "계속 프린트 하시겠습니까? (y/n): ";
        std::cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    std::cout << "프린팅 종료." << std::endl;

    return 0;
}
