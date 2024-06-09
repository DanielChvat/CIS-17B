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

Database::Database(std::string FileName) {
  this->FileName = FileName;
  this->UserFile.open(FileName, ios::in | ios::binary);

  if (!UserFile.is_open()) {
    throw std::string("ERROR: Database could not be loaded!");
  }

  // Logic For Loading Database all at once
  UserFile.read((char *)&nRecords, sizeof(nRecords));
  Records = new User[nRecords];
  
  // change made here for utilizing Load
  for (int i = 0; i < nRecords; i++) {
    Containers::Datastream userDataStream = ReadUserDatastream();
    Records[i].Load(&userDataStream);
  }
  UserFile.close();
}

Database::~Database() {
    WriteRecords();
    if(UserFile.is_open())UserFile.close();
    delete[] Records;
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

bool Database::ValidateUser(std::string UserName, std::string Password) {
  User *temp = FetchUser(UserName);
  
  if (!temp || Password != temp->getPassword()) return false;

  return true;
}

// write all users in the database function
void Database::WriteRecords() {
  if (!UserFile.is_open()) {
    UserFile.open(FileName, ios::out | ios::binary | ios::trunc);
  }
  
  UserFile.write((char *)&nRecords, sizeof(nRecords));

  for (int i = 0; i < nRecords; i++) {
    Containers::Datastream recordData = Records[i].Serialize();
    UserFile.write(recordData.m_data, recordData.m_size);
  }

  UserFile.close();
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