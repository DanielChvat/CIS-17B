/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Item.cpp
 * Author: Daniel
 * 
 * Created on April 26, 2024, 9:29 AM
 */

#include "Item.h"
#include <iostream>

Containers::Datastream Item::Serialize(){
    unsigned long nameSize = m_name.size();
    unsigned long cursor = 0L;
    unsigned long recordSize = nameSize + sizeof(float) + 2 * sizeof(int) + sizeof(unsigned long);
    char *buffer = new char[recordSize + sizeof(unsigned long)];
    
    WriteToBuf(buffer, (const char *)&recordSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&nameSize, sizeof(unsigned long), cursor);
    
    
    WriteToBuf(buffer, m_name.c_str(), nameSize, cursor);
    WriteToBuf(buffer, (const char *)&m_price, sizeof(float), cursor);
    WriteToBuf(buffer, (const char *)&m_count, sizeof(int), cursor);
    WriteToBuf(buffer, (const char *)&m_id, sizeof(int), cursor);
    
    
    Containers::Datastream data(buffer, recordSize + sizeof(unsigned long));
    return data;
}

void Item::Load(Containers::Datastream *data){
    unsigned long nameSize;
    unsigned long cursor = 0L;
    const char *buffer = (const char *)data->m_data;
    
    ReadFromBuf(buffer, (char *)&nameSize, sizeof(unsigned long), cursor);
    
    char *temp = new char[nameSize + 1];
    ReadFromBuf(buffer, temp, nameSize, cursor);
    temp[nameSize] = '\0';
    this->m_name = std::string((const char *)temp);
    delete []temp;
    
    ReadFromBuf(buffer, (char *)&this->m_price, sizeof(float), cursor);
    ReadFromBuf(buffer, (char *)&this->m_count, sizeof(int), cursor);
    ReadFromBuf(buffer, (char *)&this->m_id, sizeof(int), cursor);
}

