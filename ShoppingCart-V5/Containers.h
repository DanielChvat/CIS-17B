/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Containers.h
 * Author: Daniel
 *
 * Created on April 26, 2024, 10:27 AM
 */

#ifndef CONTAINERS_H
#define CONTAINERS_H

class Item;

namespace Containers{
    class ItemVector{
    private:
        Item *m_arr;
        int m_size;
    public:
        ItemVector(): m_arr(nullptr), m_size(0){};
        ~ItemVector();
        void push(Item data);
        Item *get(int index);
        int size() {return m_size;}
        void clear();
    };
    struct Datastream {
    public:
        Datastream(char *data, long size) : m_data(data), m_size(size){}
        Datastream() = default;
        ~Datastream() {delete []this->m_data;}
        char *m_data;
        long m_size;
    };
}
namespace Interfaces{
    class Serializable {
    public:
        void WriteToBuf(char *dst, const char *src, unsigned long size, unsigned long &cursor);
        void ReadFromBuf(const char *src, char *dst, unsigned long size, unsigned long &cursor);
    private:
        virtual Containers::Datastream Serialize() = 0;
        virtual void Load(Containers::Datastream *) = 0;
    };
}

#endif /* CONTAINERS_H */

