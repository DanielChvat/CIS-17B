/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Daniel
 *
 * Created on April 26, 2024, 9:28 AM
 */

#include "View.h"
#include "Item.h"
#include "Containers.h"

int main(int argc, char** argv) {
    View terminal;
    Containers::ItemVector test;
    
    Item a("Shoes", 10.99, 100, 1);
    Item b("Jeans", 11.99, 12, 2);
    Item c("Leggings", 12.99, 13, 3);
    Item d("Socks", 13.99, 14, 4);
    
    test.push(a);
    test.push(b);
    test.push(c);
    test.push(d);
    
    terminal.Writeln(test.get(0)->getName());
    terminal.Writeln(test.get(1)->getName());
    terminal.Writeln(test.get(2)->getName());
    terminal.Writeln(test.get(3)->getName());
    
    
    
    return 0;
}

