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
    Database(std::string);
    ~Database();
    bool ValidateUser(std::string, std::string);
    void addUser(User);
    long userCount(){return nRecords;}
    void WriteRecords();
    User *FetchUser(std::string);
    User *FetchUser(int n);
    long UserCount() {return nRecords;}
private:
    std::fstream UserFile;
    std::string FileName;
    User *Records;
    long nRecords = 0;
    
    Containers::Datastream ReadUserDatastream();
};
#endif /* DATABASE_H */

