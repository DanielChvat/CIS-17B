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
    Containers::Datastream temp;
    return temp;
}
void User::Load(Containers::Datastream *){

}

void User::addCart(Item i, int n){
    i.setCount(n);
    this->m_cart.add(i);
}
