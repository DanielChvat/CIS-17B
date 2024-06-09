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
#include <string>

#include "View.h"
#include "Item.h"
#include "User.h"

int main(int argc, char** argv) {
    View terminal;
    User user;
    Item a("Shoes", 10.99, 100, 1);
    Item b("Jeans", 11.99, 12, 2);
    Item c("Leggings", 12.99, 13, 3);
    Item d("Socks", 13.99, 14, 4);
    
    user.addCart(a, 10);
    user.addCart(b, 5);
    user.addCart(c, 2);
    user.addCart(d, 14);

    terminal.Writeln(user.getCart(0)->getName() + " " + std::to_string(user.getCart(0)->getCount()));
    terminal.Writeln(user.getCart(1)->getName() + " " + std::to_string(user.getCart(1)->getCount()));
    terminal.Writeln(user.getCart(2)->getName() + " " + std::to_string(user.getCart(2)->getCount()));
    terminal.Writeln(user.getCart(3)->getName() + " " + std::to_string(user.getCart(3)->getCount()));
    return 0;
}

