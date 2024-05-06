/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   User.cpp
 * Author: Daniel
 * 
 * Created on April 26, 2024, 9:29 AM
 */

#include "User.h"

Containers::Datastream User::Serialize(){
    unsigned long UserNameSize = m_username.size();
    unsigned long passwordSize = m_password.size();
    unsigned long cursor = 0L;
    unsigned long recordSize = UserNameSize + passwordSize + 2 * sizeof(unsigned long) + sizeof(bool);
    char *buffer = new char[recordSize + sizeof(unsigned long)];
    
    WriteToBuf(buffer, (const char *)&recordSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&UserNameSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&passwordSize, sizeof(unsigned long), cursor);
    
    WriteToBuf(buffer, m_username.c_str(), UserNameSize, cursor);
    WriteToBuf(buffer, m_password.c_str(), passwordSize, cursor);
    WriteToBuf(buffer, (const char *)&this->m_admin, sizeof(bool), cursor);
    
    
    
    Containers::Datastream data(buffer, recordSize + sizeof(unsigned long));
    return data;
}
void User::Load(Containers::Datastream *data){
    unsigned long UserNameSize;
    unsigned long passwordSize;
    unsigned long cursor = 0L;
    
    const char *buffer = (const char *)data->m_data;
    ReadFromBuf(buffer, (char *)&UserNameSize, sizeof(unsigned long), cursor);
    ReadFromBuf(buffer, (char *)&passwordSize, sizeof(unsigned long), cursor);
    
    char *temp = new char[UserNameSize + 1];
    ReadFromBuf(buffer, temp, UserNameSize, cursor);
    temp[UserNameSize] = '\0';
    this->m_username = std::string((const char *)temp);
    delete []temp;
    
    temp = new char[passwordSize + 1];
    ReadFromBuf(buffer, temp, passwordSize, cursor);
    temp[passwordSize] = '\0';
    this->m_password = std::string((const char *)temp);
    delete []temp;
    
    ReadFromBuf(buffer, (char *)&this->m_admin, sizeof(bool), cursor);
}

void User::addCart(Item i, int n){
    i.setCount(n);
    this->m_cart.add(i);
}
