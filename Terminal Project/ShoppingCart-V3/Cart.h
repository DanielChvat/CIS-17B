/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cart.h
 * Author: Daniel
 *
 * Created on April 26, 2024, 9:30 AM
 */

#ifndef CART_H
#define CART_H

#include "Containers.h"
#include "Item.h"

class Cart {
private:
    Containers::ItemVector items;
public:
    Cart() = default;
    void add(Item i) {items.push(i);}
    Item *get(int index){return items.get(index);}
    int size() {return items.size();}
};

#endif /* CART_H */

