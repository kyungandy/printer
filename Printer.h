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
    virtual void printInk(int pages) = 0; 
    virtual void showStatus() const = 0; 
    virtual ~Printer() {}
};

class InkjetPrinter : public Printer {
private:
    int inkLevel;

public:
    InkjetPrinter(std::string model, std::string manufacturer, int availableCount, int inkLevel);
    void printInk(int pages) override;
    void showStatus() const override; 
};

class LaserPrinter : public Printer {
private:
    int tonerLevel;

public:
    LaserPrinter(std::string model, std::string manufacturer, int availableCount, int tonerLevel);
    void printInk(int pages) override;
    void showStatus() const override; 
};

#endif 
