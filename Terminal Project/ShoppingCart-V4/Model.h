/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Model.h
 * Author: Daniel
 *
 * Created on April 26, 2024, 9:29 AM
 */

#ifndef MODEL_H
#define MODEL_H

#include "User.h"
#include "View.h"
#include "Controller.h"
#include "Database.h"

class Model {
private:
    User *m_user;
    View terminal;
    Controller controller;
    Database *database;
    
    void Welcome();
    void Login();
    void createAccount();
    void Home();
    void Admin();
    
    
    void displayItems();
    void EditUsers();
public:
    Model(std::string);
    ~Model() {delete database;}
};

#endif /* MODEL_H */

