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
    User m_user;
    View terminal;
    Controller control;
    Database database;
public:
    Model();
    Model(User u): m_user(u){}
    void Login();
    void displayStore();
};

#endif /* MODEL_H */

