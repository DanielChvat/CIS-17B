/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Containers.cpp
 * Author: Daniel
 * 
 * Created on April 26, 2024, 10:27 AM
 */

#include "Containers.h"
#include "Item.h"

Containers::ItemVector::~ItemVector(){
    delete []this->m_arr;
}

void Containers::ItemVector::push(Item data){
    m_size++;
    if(!m_arr){
        m_arr = new Item[m_size];
        m_arr[m_size-1] = data;
        return;
    }

    Item *temp = new Item[m_size];
    for(int i=0; i < m_size-1; i++){
        temp[i] = m_arr[i];
    }

    delete []m_arr;
    temp[m_size-1] = data;
    m_arr = temp;
}

Item *Containers::ItemVector::get(int index){
    if(index >= m_size){
        return nullptr; 
    }
    
    return &m_arr[index];
}

void Interfaces::Serializable::WriteToBuf(char *dst, const char *src, unsigned long size, unsigned long &cursor){
    for(int i=0; i < size; i++){
        dst[cursor++] = src[i];
    }
}

void Interfaces::Serializable::ReadFromBuf(const char *src, char *dst, unsigned long size, unsigned long &cursor){
    for(int i=0; i < size; i++){
        dst[i] = src[cursor++];
    }
}
