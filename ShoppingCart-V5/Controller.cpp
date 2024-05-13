/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Controller.cpp
 * Author: Daniel
 * 
 * Created on April 29, 2024, 10:10 PM
 */

#include <iostream>
#include <string>
#include "Controller.h"


int Controller::ReadInt(){
    int temp;
    std::cin >> temp;
    return temp;
}

std::string Controller::ReadStr(){
    std::string temp;
    std::getline(std::cin, temp);
    return temp;
}

char Controller::ReadChar(){
    char c;
    std::cin >> c;
    return c;
}

void Controller::ignore(){
    std::cin.ignore();
}

float Controller::ReadFloat(){
    float temp;
    std::cin >> temp;
    return temp;
}