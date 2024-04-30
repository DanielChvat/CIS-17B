/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   User.h
 * Author: Daniel
 *
 * Created on April 26, 2024, 9:29 AM
 */

#ifndef USER_H
#define USER_H

#include <string>
#include "Containers.h"
#include "Cart.h"

class User : public Interfaces::Serializable{
private:
    std::string m_Username;
    std::string m_password;
    bool admin;
    Cart m_cart;
public:
    User(): m_Username(""), m_password(""), admin(false){}
    User(std::string Username, std::string Password): m_Username(Username), m_password(Password){}
    std::string getUserName() {return m_Username;}
    std::string getPassword() {return m_password;}
    Containers::Datastream Serialize();
    void Load(Containers::Datastream *);
    bool isAdmin() {return admin;}
    void addCart(Item i, int n);
    Item *getCart(int index) {return m_cart.get(index);}
};

#endif /* USER_H */

