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
#include <string>

void Model::Welcome(){
    char choice;
    
    do{
        terminal.Writeln();
        terminal.Writeln("Welcome to the Store!");
        terminal.Writeln("----------------------------");
        terminal.Writeln("1. Login to Existing Account");
        terminal.Writeln("2. Create New Account");
        terminal.Writeln("3. Quit");
        terminal.Writeln();
        terminal.Write("Enter Your Choice: ");
        choice = controller.ReadChar();
        
        
        switch(choice){
            case '1': Login(); break;
            case '2': createAccount(); break;
        }
        
        if(choice != '1' && choice != '2' && choice != '3')terminal.Writeln("Invalid Choice Please Try Again!");
    }while(choice != '3');
}

void Model::Login(){
    std::string u;
    std::string p;
    
    controller.ignore();
    User user;
    do{
        terminal.Writeln();
        terminal.Writeln("Login to Existing Account");
        terminal.Writeln("----------------------------");
        terminal.Write("Username: ");
        u = controller.ReadStr();
        terminal.Write("Password: ");
        p = controller.ReadStr();
    }while(!database->ValidateUser(u, p));
    
    this->m_user = database->FetchUser(u);
    
    if(this->m_user->isAdmin())Admin();
    else Home();
}

void Model::createAccount(){
    std::string u;
    std::string p;
    User user;
    
    terminal.Writeln();
    terminal.Writeln("Create New Account");
    terminal.Writeln("----------------------------");
    terminal.Write("Username: ");
    u = controller.ReadStr();
    terminal.Write("Password: ");
    p = controller.ReadStr();
    
    user.setUserName(u);
    user.setPassword(p);
    
    database->addUser(user);
}

void Model::Home(){
    char choice;
    
    do{
        terminal.Writeln();
        terminal.Writeln("Welcome Back, " + m_user->getUserName() + "!");
        terminal.Writeln("----------------------------");
        terminal.Writeln("1. Display the Store Inventory");
        terminal.Writeln("2. Add Item to Your Cart");
        terminal.Writeln("3. View Your Cart");
        terminal.Writeln("4. Purchase Items In Cart");
        terminal.Writeln("5. Logout");
        terminal.Writeln();
        terminal.Write("Enter Your Choice: ");
        choice = controller.ReadChar();
        
        switch(choice){
            case '1': displayItems(); break;
            case '2': break;
            case '3': break;
            case '4': break;
        }
        
        if(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5')
            terminal.Writeln("Invalid Choice Please Try Again!");
        
    }while(choice != '5');
}

void Model::Admin(){
    char choice;
    
    do{
        terminal.Writeln();
        terminal.Writeln("Welcome Back, " + m_user->getUserName() + "!");
        terminal.Writeln("----------------------------");
        terminal.Writeln("1. Edit Users");
        terminal.Writeln("2. Edit Items");
        terminal.Writeln("3. Logout");
        terminal.Writeln();
        terminal.Write("Enter Your Choice: ");
        choice = controller.ReadChar();
        
        switch(choice){
            case '1': EditUsers(); break;
            case '2': break;
        }
        
        if(choice != '1' && choice != '2' && choice != '3')
            terminal.Writeln("Invalid Choice Please Try Again!");
        
    }while(choice != '3');
}


void Model::displayItems(){
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

    terminal.Writeln("ID   Product Name        Stock     Price");
    terminal.Writeln("----------------------------------------");
    for(int i=0; i < nitems; i++){
       terminal.DisplayItem(item[i]);
    }
}

Model::Model(std::string FileName){
    this->database = new Database(FileName);
    Welcome();
//    displayStore();
}

void Model::EditUsers(){
    int n;
    std::string u, p;
    char c;
    controller.ignore();
    for(int i=0; i < database->UserCount(); i++){
        User *u = database->FetchUser(i);
        terminal.Writeln();
        terminal.Writeln();
        terminal.Writeln("User " + std::to_string(i+1));
        terminal.Writeln("----------------------------------------");
        terminal.Writeln("Username: " + u->getUserName());
        terminal.Writeln("Password: " + u->getPassword());
    }
    
    terminal.Writeln();
    terminal.Write("Edit User #: ");
    n = controller.ReadInt();
    
    User *user = database->FetchUser(n-1);
    terminal.Writeln("User " + std::to_string(n));
    terminal.Writeln("----------------------------------------");
    terminal.Writeln("Username: " + user->getUserName());
    terminal.Writeln("Password: " + user->getPassword());
    
    
    controller.ignore();
    terminal.Write("New Username: ");
    u = controller.ReadStr();
    terminal.Write("New Password: ");
    p = controller.ReadStr();
    terminal.Write("Admin (Y/N): ");
    c = controller.ReadChar();
    
    user->setUserName(u);
    user->setPassword(p);
    if(c == 'Y' || c == 'y')user->setAdmin(true);
    else user->setAdmin(false);
}

