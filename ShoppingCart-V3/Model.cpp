/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Model.cpp
 * Author: Daniel
 * 
 * Created on April 26, 2024, 9:29 AM
 */

#include "Model.h"
#include "Item.h" 
#include <iostream>
#include <fstream>

void Model::Login(){
    std::string Username;
    std::string Password;
    terminal.Writeln("Welcome to the Store!");
    terminal.Write("Username: ");
    Username = control.ReadStr();
    terminal.Write("Password: ");
    Password = control.ReadStr();
    terminal.Writeln();
    terminal.Writeln();

    
}

void Model::displayStore(){
    // Eventually this will be part of the database this is just here for debug will fix later
    const int nitems = 4;
    Item item[nitems];
    Item a("Shoes", 10.99, 100, 1);
    Item b("Jeans", 11.99, 12, 2);
    Item c("Leggings", 12.99, 13, 3);
    Item d("Socks", 13.99, 14, 4);
    item[0] = a;
    item[1]= b;
    item[2] = c;
    item[3] = d;

    for(int i=0; i < nitems; i++){
       terminal.DisplayItem(item[i]);
    }
}

Model::Model(){
    try{
        database.LoadDatabase("debug.bin");
    }catch(std::string s){
        std::cout << s << std::endl;
    }
    Login();
    displayStore();
}

