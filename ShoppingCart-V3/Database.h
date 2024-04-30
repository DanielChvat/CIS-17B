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
    private:
        std::fstream UserFile;
        std::string FileName;
        User *Records;
        /* Item *Inventory; */ 
        long nRecords = 0;
        User *FetchUser(std::string UserName);
public:
    Database() = default;
    Database(char *);	
    ~Database();
    bool ValidateUser(char *, char *);	
    void LoadDatabase(std::string FileName);
    void EditUser(std::string name = "", std::string Username = "", std::string password = "", User *user = nullptr);
    void WriteRecords();
    Containers::Datastream ReadUserDatastream();
};
#endif /* DATABASE_H */

