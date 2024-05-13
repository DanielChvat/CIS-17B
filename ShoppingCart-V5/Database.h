/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Database.h
 * Author: Daniel
 *
 * Created on April 26, 2024, 9:29 AM
 */

#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <fstream>
#include "Containers.h"
#include "Item.h"

class User;

class Database {
public:
    Database(std::string, std::string);
    ~Database();
    bool ValidateUser(std::string, std::string);
    void addUser(User);
    void deleteUser(int);
    void addItem(Item);
    void deleteItem(int);
    long userCount(){return nRecords;}
    User *FetchUser(std::string);
    User *FetchUser(int n);
    Item *FetchItem(int n);
    long UserCount() {return nRecords;}
    long ItemCount() {return nItems;}
private:
    std::fstream UserFile;
    std::fstream ItemFile;
    std::string userFileName;
    std::string itemFileName;
    User *Records;
    Item *Inventory;
    long nRecords = 0;
    long nItems = 0;
    
    void WriteRecords();
    void WriteItems();
    
    Containers::Datastream ReadUserDatastream();
    Containers::Datastream ReadItemDatastream();
};
#endif /* DATABASE_H */

