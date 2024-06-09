/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Database.cpp
 * Author: Daniel
 * 
 * Created on April 26, 2024, 9:29 AM
 */

#include <fstream>
#include <iostream>
#include <string>
#include "Database.h"
#include "User.h"

using std::ios;

Database::Database(std::string userFileName, std::string itemFileName) {
  this->userFileName = userFileName;
  this->itemFileName = itemFileName;
  this->UserFile.open(userFileName, ios::in | ios::binary);
  this->ItemFile.open(itemFileName, ios::in | ios::binary);

  if (!UserFile.is_open() || !ItemFile.is_open()) {
    throw std::string("ERROR: Database could not be loaded!");
  }

  // Logic For Loading Database all at once
  UserFile.read((char *)&nRecords, sizeof(long));
  ItemFile.read((char *)&nItems, sizeof(long));
  Records = new User[nRecords];
  Inventory = new Item[nItems];
  
  // change made here for utilizing Load
  for(int i = 0; i < nRecords; i++) {
    Containers::Datastream userDataStream = ReadUserDatastream();
    Records[i].Load(&userDataStream);
  }
  
  for(int i = 0; i < nItems; i++){
      Containers::Datastream itemDataStream = ReadItemDatastream();
      Inventory[i].Load(&itemDataStream);
  } 
  
  UserFile.close();
  ItemFile.close();
}

Database::~Database() {
    WriteRecords();
    WriteItems();
    if(UserFile.is_open())UserFile.close();
    if(ItemFile.is_open())ItemFile.close();
    delete[] Records;
    delete []Inventory;
}

User *Database::FetchUser(std::string UserName) {
  for (int i = 0; i < nRecords; i++) {
    if (Records[i].getUserName() == UserName)
        return &Records[i];
  }
  return nullptr;
}

User *Database::FetchUser(int n){
    return &Records[n];
}

Item *Database::FetchItem(int n){
    return &Inventory[n];
}

bool Database::ValidateUser(std::string UserName, std::string Password) {
  User *temp = FetchUser(UserName);
  
  if (!temp || Password != temp->getPassword()) return false;

  return true;
}

// write all users in the database function
void Database::WriteRecords() {
  if (!UserFile.is_open()) {
    UserFile.open(userFileName, ios::out | ios::binary | ios::trunc);
  }
  
  UserFile.write((char *)&nRecords, sizeof(nRecords));

  for (int i = 0; i < nRecords; i++) {
    Containers::Datastream recordData = Records[i].Serialize();
    UserFile.write(recordData.m_data, recordData.m_size);
  }

  UserFile.close();
}

void Database::WriteItems(){
    
    if(!ItemFile.is_open()){
        this->ItemFile.open(itemFileName, ios::out | ios::binary | ios::trunc);
    }
    
    
    
    ItemFile.write((char *)&nItems, sizeof(long));
    
    for(int i = 0; i < nItems; i++){
        Containers::Datastream itemData = Inventory[i].Serialize();
        ItemFile.write(itemData.m_data, itemData.m_size);
    }
    ItemFile.close();
}

// function for reading and returning user datastream from file
Containers::Datastream Database::ReadUserDatastream() {

  // Read the size of the next user record.
  long recordSize = 0;
  UserFile.read(reinterpret_cast<char *>(&recordSize), sizeof(recordSize));

  if (UserFile.fail()) {
    throw std::runtime_error("Failed to read record size.");
  }

  // Allocate buffer for user data.
  char *buffer = new char[recordSize];

  // Read the user record data based on the size
  UserFile.read(buffer, recordSize);

  // Check if read was successful
  if (UserFile.fail()) {
    delete[] buffer;
    throw std::runtime_error("Failed to read user data.");
  }

  return Containers::Datastream(buffer, recordSize);
}

Containers::Datastream Database::ReadItemDatastream(){
    long recordSize = 0;
    ItemFile.read((char *)&recordSize, sizeof(long));
    
    if(ItemFile.fail()){
        throw std::runtime_error("Failed to read record size.");
    }
    
    char *buffer = new char[recordSize];
    ItemFile.read(buffer, recordSize);
    
    if(ItemFile.fail()){
        delete []buffer;
        throw std::runtime_error("Failed to read item data.");
    }
    
    return Containers::Datastream(buffer, recordSize);
}

void Database::addUser(User newUser){
    User *temp = new User[this->nRecords + 1];
    
    for(int i=0; i < this->nRecords; i++){
        temp[i] = Records[i];
    }
    temp[nRecords] = newUser;
    
    delete []Records;
    this->Records = temp;
    nRecords++;
}

void Database::deleteUser(int n){
    int offset = 0;
    User *temp = new User[this->nRecords - 1];
    for(int i=0; i < this->nRecords; i++){
        if(i == n) {
            offset = 1;
            continue;
        }
        
        temp[i - offset] = this->Records[i];
    }
    delete []this->Records;
    this->Records = temp;
    this->nRecords--;
}

void Database::addItem(Item newItem){
    Item *temp = new Item[this->nItems + 1];
    
    for(int i=0; i < this->nItems; i++){
        temp[i] = Inventory[i];
    }
    temp[nItems] = newItem;
    
    delete []Inventory;
    this->Inventory = temp;
    nItems++;
}

void Database::deleteItem(int n){
    int offset = 0;
    Item *temp = new Item[this->nItems - 1];
    for(int i = 0; i < this->nItems; i++){
        if(i == n){
            offset = 1;
            continue;
        }
        temp[i-offset] = this->Inventory[i];
    }
    delete []this->Inventory;
    this->Inventory = temp;
    this->nItems--;
}