#ifndef WORKER_EMPLOYEE_H
#define WORKER_EMPLOYEE_H

#endif //WORKER_EMPLOYEE_H

#pragma once
#include <bits/stdc++.h>
#include "Worker.h"
using namespace std;

class Employee:public Worker{
public:
    virtual void showInfo();
    virtual string getDeptName();

    Employee(int id,int dpid,string name);
};