#include <bits/stdc++.h>
#include "boss.h"

using namespace std;

Boss::Boss(int id, int dpid, std::string name) {
    this->m_ID = id;
    this->m_DeptID = dpid;
    this->m_Name = name;
}

void Boss::showInfo() {
    cout << "职工编号： " << this->m_ID << endl;
    cout << "\t职工岗位： " << this->getDeptName() << endl;
    cout << "\t职工姓名： " << this->m_Name << endl;
}

string Boss::getDeptName() {
    return "老板";
}