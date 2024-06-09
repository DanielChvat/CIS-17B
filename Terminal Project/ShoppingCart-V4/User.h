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
    std::string m_username;
    std::string m_password;
    bool m_admin;
    Cart m_cart;
public:
    User(): m_username(""), m_password(""), m_admin(false){}
    User(std::string Username, std::string Password, bool admin): m_username(Username), m_password(Password), m_admin(admin){}
    std::string getUserName() {return m_username;}
    std::string getPassword() {return m_password;}
    void setUserName(std::string s) {this->m_username = s;}
    void setPassword(std::string p) {this->m_password = p;}
    void setAdmin(bool b){this->m_admin = b;}
    Containers::Datastream Serialize();
    void Load(Containers::Datastream *);
    bool isAdmin() {return m_admin;}
    void addCart(Item i, int n);
    Item *getCart(int index) {return m_cart.get(index);}
};

#endif /* USER_H */

