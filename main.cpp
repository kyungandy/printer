#include "Printer.h"

int main() {
    InkjetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6345", "�Ｚ����", 3, 20);

    int option, pages;
    char cont;

    do {
        std::cout << "�����͸� �����ϼ��� (1:��ũ��, 2:������): ";
        std::cin >> option;

        if (option == 1) {
            std::cout << "��ũ�� �����͸� �����߽��ϴ�." << std::endl;
            inkjet.showStatus(); // ��ũ�� �������� ���� ���
        }
        else if (option == 2) {
            std::cout << "������ �����͸� �����߽��ϴ�." << std::endl;
            laser.showStatus(); // ������ �������� ���� ���
        }
        else {
            std::cout << "�߸��� �ɼ��Դϴ�." << std::endl;
            continue; // �߸��� �ɼ��� ��� ���� ���� �ݺ�
        }

        std::cout << "�μ��� ������ �� �Է�: ";
        std::cin >> pages;

        if (option == 1) {
            inkjet.printInk(pages); // ��ũ�� �����ͷ� �μ�
        }
        else if (option == 2) {
            laser.printInk(pages); // ������ �����ͷ� �μ�
        }

        std::cout << "��� ����Ʈ �Ͻðڽ��ϱ�? (y/n): ";
        std::cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    std::cout << "������ ����." << std::endl;

    return 0;
}