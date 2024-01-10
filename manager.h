#ifndef WORKER_MANAGER_H
#define WORKER_MANAGER_H

#endif //WORKER_MANAGER_H

#pragma once
#include <bits/stdc++.h>
#include "Worker.h"

using namespace std;

class Manager:public Worker{
public:
    virtual void showInfo();
    virtual string getDeptName();

    Manager(int id,int dpid,string name);
};