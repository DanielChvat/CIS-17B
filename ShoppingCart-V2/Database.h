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

class User;

class Database {
public:
    Database(char *);	
    ~Database();
    bool ValidateUser(char *, char *);	
    void EditUser(std::string name = "", std::string Username = "", std::string password = "", User *user = nullptr);
    void WriteRecords();
    Containers::Datastream ReadUserDatastream();
private:
	std::fstream UserFile;
	char *FileName;
	User *Records;
	long nRecords = 0;
	User *FetchUser(std::string UserName);
};
#endif /* DATABASE_H */

