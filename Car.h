#pragma once
#include<iostream>

class Car
{
private:
    float fuel;
    float speed;
    int passengers;
    static int m_totalCount; //not belong to any obj, but belong to class. has to defined outside class

public:
    Car();
    Car(float amount);
    Car(float amount, int pass);
    ~Car();
    static void totalCount();
    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int count);
    void Dashboard();
};







