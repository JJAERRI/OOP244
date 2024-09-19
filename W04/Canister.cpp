//Workshop4
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-06-05
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"
using namespace std;
namespace seneca {

    const double PI = 3.14159265;

    void Canister::setToDefault()
    {
        // Sets the Canister to default values.
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    void Canister::setName(const char* Cstr) // Sets the name of the content inside the Canister if it is usable.
    {

        if (Cstr != nullptr && m_usable) // if(Cstr && m_usable) << 이것도 됨
        {
            delete[] m_contentName;  // 이미 존재하는 이름이 있다면 메모리를 해제
            /*m_contentName = nullptr;  */ //이건 없어도 되는건데?                         
            m_contentName = new char[strlen(Cstr) + 1];        
            strcpy(m_contentName, Cstr);                 
        }

    }

    bool Canister::isEmpty() const // Checks if the Canister is empty by comparing its volume to a very small value.
    {
        return m_contentVolume < 0.00001;
    }

    bool Canister::hasSameContent(const Canister& C) const // Checks if another Canister has the same content by comparing content names.
    {
        return m_contentName && C.m_contentName && strcmp(m_contentName, C.m_contentName) == 0;
     }

    Canister::Canister() // Default constructor that initializes the Canister to default values.
    {
        setToDefault();

    }
    
    Canister::Canister(const char* contentName)  // Constructor that initializes the Canister to default values and sets the content name.
    {

        setToDefault();
        setName(contentName);
    }

    // Constructor that initializes the Canister with given dimensions and content name.
    // Marks the Canister as unusable if dimensions are out of range.
    Canister::Canister(double height, double diameter, const char* contentName) 
    {
        setToDefault();

        if (height < 10 || diameter < 10 || height > 40 || diameter > 30) 
        {
            m_usable = false;
        }
        else 
        {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0;
            setName(contentName);
        }
    }

    // Destructor that deallocates memory for the content name.
    Canister::~Canister() 
    {

        delete[] m_contentName;
        m_contentName = nullptr;
    }

    // Sets the content of the Canister if it is usable and either empty or already has the same content.
    // Marks the Canister as unusable if the content is different.
    Canister& Canister::setContent(const char* contentName) 
    {
        if (!contentName) 
        {
            m_usable = false;
        }
        else if (isEmpty()) 
        {
            setName(contentName);
        }
        else if (strcmp(contentName, m_contentName)) 
        {
            m_usable = false;
        }
        return *this;
    }

    // Adds a specified quantity to the Canister's content if it is usable and within capacity.
    Canister& Canister::pour(double quantity) 
    {
        if (m_usable && quantity > 0 && ((quantity + volume()) <= capacity())) 
        {
            m_contentVolume += quantity;
        }
        else 
        {
            m_usable = false;
        }
        return *this;
    }

    // Pours content from another Canister into this one, adjusting volumes accordingly. //이건도 많이봄
    //Canister& Canister::pour(Canister& srcCan) 
    //{

    //    this->setContent(srcCan.m_contentName);
    //    if (srcCan.volume() > (this->capacity() - this->volume())) 
    //    {
    //        srcCan.m_contentVolume -= (this->capacity() - this->volume());
    //        this->m_contentVolume = this->capacity();
    //    }
    //    else 
    //    {
    //        this->pour(srcCan.volume());
    //        srcCan.m_contentVolume = 0.0;
    //    }
    //    return *this;
    //}

    //둘다 똑같은데 밑에껀 교수님꺼

    Canister& Canister::pour(Canister& C)
    {

        setContent(C.m_contentName);
        if (C.volume() > capacity() - volume() )
        {
            C.m_contentVolume -= (capacity() - volume());
            m_contentVolume = capacity();
        }
        else
        {
            pour(C.contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }

    double Canister::volume()const 
    {

        return m_contentVolume; // Returns the current volume of the Canister.

    }

    // Displays the Canister's details including capacity, dimensions, and content.
    std::ostream& Canister::display()const 
    {
        cout.width(7);
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable) 
        {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) 
        {
            cout << " of ";
            cout.width(7);
            cout.setf(ios::right);
            cout << m_contentVolume << "cc   " << m_contentName;
        }
        return cout;
    }

    // Calculates and returns the capacity of the Canister based on its dimensions.
    double Canister::capacity()const 
    {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    // Clears the Canister by resetting its content and marking it as usable.
    void Canister::clear() 
    {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }

}