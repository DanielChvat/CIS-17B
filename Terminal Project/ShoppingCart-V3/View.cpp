/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   View.cpp
 * Author: Daniel
 * 
 * Created on April 26, 2024, 9:29 AM
 */

#include <iostream>
#include <iomanip>
#include "View.h"


void View::DisplayItem(Item &item){
    std::cout << std::left << std::setw(5) << item.getId() << std::setw(20) << item.getName() << std::setw(10) << item.getCount() << std::setw(10) << item.getPrice() << std::endl;
}
