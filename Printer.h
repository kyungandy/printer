#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>

class Printer {
protected:
    std::string model;
    std::string manufacturer;
    int printedCount;
    int availableCount;

public:
    Printer(std::string model, std::string manufacturer, int availableCount);
    void print(int pages);
    virtual void printInk(int pages) = 0; // Pure virtual function
    virtual void showStatus() const = 0; // Pure virtual function for status
    virtual ~Printer() {}
};

class InkjetPrinter : public Printer {
private:
    int inkLevel;

public:
    InkjetPrinter(std::string model, std::string manufacturer, int availableCount, int inkLevel);
    void printInk(int pages) override;
    void showStatus() const override; // Override for status
};

class LaserPrinter : public Printer {
private:
    int tonerLevel;

public:
    LaserPrinter(std::string model, std::string manufacturer, int availableCount, int tonerLevel);
    void printInk(int pages) override;
    void showStatus() const override; // Override for status
};

#endif // PRINTER_H