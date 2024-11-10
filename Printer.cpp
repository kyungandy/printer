#include "Printer.h"

// Printer class implementation
Printer::Printer(std::string model, std::string manufacturer, int availableCount)
    : model(model), manufacturer(manufacturer), availableCount(availableCount), printedCount(0) {}

void Printer::print(int pages) {
    if (pages > availableCount) {
        std::cout << "Not enough available pages to print." << std::endl;
        return;
    }
    printedCount += pages;
    availableCount -= pages;
}

// InkjetPrinter class implementation
InkjetPrinter::InkjetPrinter(std::string model, std::string manufacturer, int availableCount, int inkLevel)
    : Printer(model, manufacturer, availableCount), inkLevel(inkLevel) {}

void InkjetPrinter::printInk(int pages) {
    if (inkLevel <= 0) {
        std::cout << "Ink level is too low to print." << std::endl;
        return;
    }

    if (pages > availableCount) {
        std::cout << "Not enough paper available." << std::endl;
        return;
    }

    print(pages); // Call the base class print method
    inkLevel -= pages; // Decrease ink level by the number of pages printed
    std::cout << "Printed " << pages << " pages." << std::endl;
    showStatus(); // Display current status after printing
}

void InkjetPrinter::showStatus() const {
    std::cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 잉크 " << inkLevel << std::endl;
}

// LaserPrinter class implementation
LaserPrinter::LaserPrinter(std::string model, std::string manufacturer, int availableCount, int tonerLevel)
    : Printer(model, manufacturer, availableCount), tonerLevel(tonerLevel) {}

void LaserPrinter::printInk(int pages) {
    if (tonerLevel <= 0) {
        std::cout << "Toner level is too low to print." << std::endl;
        return;
    }

    if (pages > availableCount) {
        std::cout << "Not enough paper available." << std::endl;
        return;
    }

    print(pages); // Call the base class print method
    tonerLevel -= pages; // Decrease toner level by the number of pages printed
    std::cout << "Printed " << pages << " pages." << std::endl;
    showStatus(); // Display current status after printing
}

void LaserPrinter::showStatus() const {
    std::cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 토너 " << tonerLevel << std::endl;
}