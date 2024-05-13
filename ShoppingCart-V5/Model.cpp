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
        terminal.Write("Username (admin Username is admin): ");
        u = controller.ReadStr();
        terminal.Write("Password (admin password is password): ");
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
    
    controller.ignore();
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
            case '2': addCart();break;
            case '3': displayCart();break;
            case '4': checkout();break;
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
            case '2': EditItems(); break;
        }
        
        if(choice != '1' && choice != '2' && choice != '3')
            terminal.Writeln("Invalid Choice Please Try Again!");
        
    }while(choice != '3');
}


void Model::displayItems(){
    terminal.Writeln("Id   Product Name        Stock     Price");
    terminal.Writeln("----------------------------------------");
    for(int i=0; i < database->ItemCount(); i++){
       terminal.DisplayItem(database->FetchItem(i), i);
    }
}

void Model::displayCart(){
    terminal.Writeln();
    terminal.Writeln();
    terminal.Writeln("USER CART");
    terminal.Writeln("Id   Product Name        Count     Price");
    terminal.Writeln("----------------------------------------");
    for(int i=0; i < this->m_user->getCartCount(); i++){
        terminal.DisplayItem(this->m_user->getCart(i), i);
    }
}

Model::Model(std::string userFileName, std::string itemFileName){
    try{
        this->database = new Database(userFileName, itemFileName);
    }catch(std::string e){
        std::cout << e << std::endl;
    }
    Welcome();
//    displayStore();
}

void Model::addCart(){
    int id;
    int count = 0;
    terminal.Write("Item ID #");
    id = controller.ReadInt();
    terminal.Write("Count: ");
    count = controller.ReadInt();
    
    while(count > database->FetchItem(id)->getCount()){
        terminal.Write("Count: ");
        count = controller.ReadInt();
    }
    
    Item *item = database->FetchItem(id);
    this->m_user->addCart(*item, count);
    
    item->setCount(item->getCount() - count);
}

void Model::EditUsers(){
    char choice;
    
    terminal.Writeln();
    terminal.Writeln();
    terminal.Write("Would You Like To Edit Or Delete a User (E/D): ");
    choice = controller.ReadChar();
    
    if(choice == 'E' || choice == 'e'){
        terminal.Writeln();
        terminal.Writeln("EDITING USER");
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
            terminal.Writeln("Admin:" + std::string((u->isAdmin()?"Yes": "No")));
        }

        terminal.Writeln();
        terminal.Write("Edit User #: ");
        n = controller.ReadInt();

        User *user = database->FetchUser(n-1);
        terminal.Writeln("User " + std::to_string(n));
        terminal.Writeln("----------------------------------------");
        terminal.Writeln("Username: " + user->getUserName());
        terminal.Writeln("Password: " + user->getPassword());
        terminal.Writeln("Admin:" + std::string((user->isAdmin()?"Yes": "No")));


        controller.ignore();
        terminal.Write("New Username: ");
        u = controller.ReadStr();
        terminal.Write("New Password: ");
        p = controller.ReadStr();
        terminal.Write("Admin (Y/N): ");
        c = controller.ReadChar();

        terminal.Writeln(u);
        terminal.Writeln(p);
        terminal.Writeln(std::string(1, c));
        user->setUserName(u);
        user->setPassword(p);
        if(c == 'Y' || c == 'y')user->setAdmin(true);
        else user->setAdmin(false);
    }else if (choice == 'D' || choice == 'd'){
        terminal.Writeln();
        terminal.Writeln("DELETING USER");
        int n;
        
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
        terminal.Write("Delete User #: ");
        n = controller.ReadInt();
        
        this->database->deleteUser(n-1);
    }
    
    
}

void Model::EditItems(){
    char choice;
    
    terminal.Writeln();
    terminal.Writeln();
    terminal.Write("Would You Like To Edit Delete or Add an Item (E/D/A): ");
    choice = controller.ReadChar();
    
    if(choice == 'E' || choice == 'e'){
        int n;
        std::string name;
        int count; 
        float price;
        displayItems();

        terminal.Writeln();
        terminal.Writeln("EDITING ITEM");
        terminal.Write("Edit Item ID#: ");
        n = controller.ReadInt();

        Item *item = database->FetchItem(n);
        terminal.Writeln("Id   Product Name        Count     Price");
        terminal.Writeln("----------------------------------------");   
        terminal.DisplayItem(item, n);
        
        terminal.Writeln();
        controller.ignore();
        terminal.Write("New Item Name: ");
        name = controller.ReadStr();
        terminal.Write("New Item Count: ");
        count = controller.ReadInt();
        terminal.Write("New Item Price: ");
        price = controller.ReadFloat();
        
        item->setCount(count);
        item->setName(name);
        item->setPrice(price);
    }else if(choice == 'D' || choice == 'd'){
        int n;
        displayItems();
        terminal.Writeln();
        terminal.Writeln("DELETING ITEM");
        terminal.Write("Delete Item ID#: ");
        n = controller.ReadInt();
        this->database->deleteItem(n);
    }else if(choice == 'A' || choice == 'a'){
        std::string name;
        int count, id;
        float price;
        terminal.Writeln();
        terminal.Writeln("ADDING NEW ITEM");
        
        terminal.Write("ITEM ID #: ");
        id = controller.ReadInt();
        terminal.Write("ITEM Name: ");
        controller.ignore();
        name = controller.ReadStr();
        terminal.Write("ITEM Stock: ");
        count = controller.ReadInt();
        terminal.Write("ITEM Price: ");
        price = controller.ReadFloat();
        
        Item n(name, price, count, id);
        this->database->addItem(n);
    }
}


void Model::checkout(){
    float total = 0.f;
    
    for(int i=0; i < this->m_user->getCartCount(); i++){
        Item *item = this->m_user->getCart(i);
        total += item->getPrice() * item->getCount();
    }
    
    this->m_user->clearCart();
    
    terminal.Writeln();
    terminal.Writeln("Thank You For Shopping with us, " + this->m_user->getUserName());
    terminal.Write("ORDER TOTAL: $");
    terminal.WritePrice(total);
}
