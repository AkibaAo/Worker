#ifndef WORKER_WORKER_H
#define WORKER_WORKER_H

#endif //WORKER_WORKER_H

#pragma once
#include <bits/stdc++.h>
using namespace std;

//职工抽象基类
class Worker{
public:
    int m_ID;//职工编号
    int m_DeptID;//职工所在部门的编号
    string m_Name;//职工姓名

    virtual void showInfo() = 0;//显示职工信息
    virtual string getDeptName() = 0;//获取职工所在的部门的名称
};