#ifndef WORKER_BOSS_H
#define WORKER_BOSS_H

#endif //WORKER_BOSS_H

#pragma once
#include <bits/stdc++.h>
#include "Worker.h"

using namespace std;

class Boss:public Worker{
public:
    virtual void showInfo();
    virtual string getDeptName();

    Boss(int id,int dpid,string name);
};