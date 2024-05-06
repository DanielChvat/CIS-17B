/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Controller.h
 * Author: Daniel
 *
 * Created on April 29, 2024, 10:10 PM
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>

class Controller {
private:
public:
    int ReadInt();
    char ReadChar();
    std::string ReadStr();
    void ignore();
};

#endif /* CONTROLLER_H */

