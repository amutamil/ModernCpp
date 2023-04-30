#pragma once
#include "Account.h"

//As we don't want to bind transact module tightly with child classes, savings, checking we are going for using base class
//The base class pointer object points to the child class pointer object
void Transact(Account* pAccount);
void Transact(Account& pAccount);
