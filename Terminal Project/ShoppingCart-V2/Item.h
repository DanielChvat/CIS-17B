/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Item.h
 * Author: Daniel
 *
 * Created on April 26, 2024, 9:29 AM
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Containers.h"

class Item : public Interfaces::Serializable{
private:
    std::string m_name;     
    float m_price;
    int m_count;
    int m_id;
public:
    Item() : m_name(""), m_price(0.f), m_count(0), m_id(0){};
    Item(std::string name, float price, int count, int id): m_name(name), m_price(price), m_count(count), m_id(id){};
    std::string getName() {return m_name;}
    float getPrice() {return m_price;}
    int getCount() {return m_count;}
    int getId() {return m_id;}
    void setCount(int n) {m_count = n;}
    Containers::Datastream Serialize();
    void Load(Containers::Datastream *data);

};

#endif /* ITEM_H */

