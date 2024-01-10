#ifndef WORKER_WORKMANAGER_H
#define WORKER_WORKMANAGER_H

#endif //WORKER_WORKMANAGER_H

#pragma once
#include <bits/stdc++.h>
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager{
public:
    WorkerManager();
    ~WorkerManager();
    void ShowMenu();
    void exitSystem();
    int m_EmpNum = 0;
    Worker** m_EmpArray;
    Worker ** get_EmpArray(int id,string name,int dId);
    bool m_FileIsEmpty;
    int Find_Emp(int id);
    int get_EmpNum();
    void add_Emp();
    void save();
    void Show_Emp();
    void Del_Emp();
};