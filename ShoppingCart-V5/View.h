/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   View.h
 * Author: Daniel
 *
 * Created on April 26, 2024, 9:29 AM
 */

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Item.h"

class View {
private:
public:
    void Write(std::string text){std::cout << text;}
    void Writeln(std::string text = ""){std::cout << text << std::endl;}
    void WritePrice(float f){std::cout << std::fixed << std::setprecision(2) << f << std::endl;}
    void DisplayItem(Item *item, int);
};

#endif /* VIEW_H */

