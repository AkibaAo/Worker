#include <iostream>
#include "WorkManager.h"

WorkerManager::WorkerManager() {
    m_EmpNum = 0;
    m_EmpArray = nullptr;

    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout << "FILE is not exist!" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
    }

    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "FILE is empty!" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
    }

    int num = this->get_EmpNum();
    cout << "职工人数为： " << num << endl;
    this->m_EmpNum = num;
}

WorkerManager::~WorkerManager() {

}

void WorkerManager::ShowMenu() {
    cout << "**************************************" << endl;
    cout << "*********欢迎使用职工管理系统！**********" << endl;
    cout << "***********0.退出管理程序*************" << endl;
    cout << "***********1.增加职工信息*************" << endl;
    cout << "***********2.显示职工信息*************" << endl;
    cout << "***********3.删除离职员工*************" << endl;
    cout << "***********4.修改职工信息*************" << endl;
    cout << "***********5.查找职工信息*************" << endl;
    cout << "***********6.按照编号排序*************" << endl;
    cout << "***********7.清空所有文档*************" << endl;
    cout << "**************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem() {
    cout << "系统已退出" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::add_Emp() {
    cout << "请输入添加职工的数量" << endl;
    int addNum = 0;
    cin.sync();
    cin >> addNum;
    if (addNum <= 0 || addNum > INT_MAX / sizeof(Worker*)) {
        cout << "输入的addNum信息有误！" << endl;
        system("pause");
        system("cls");
        return;
    }

    if (addNum > 0) {
        int newSize = this->m_EmpNum + addNum;

        if (newSize <= 0 || newSize > INT_MAX / sizeof(Worker*)) {
            cout << "输入的newSize信息有误！" << endl;
            system("pause");
            system("cls");
            return;
        }
        cout << "DEBUG: 正在分配新数组，newSize = " << newSize << endl;
        Worker** newSpace = new Worker*[newSize];  // 父类指针指向子类对象
        if (this->m_EmpArray != nullptr) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
            delete[] this->m_EmpArray;  // 删除旧数组
            this->m_EmpArray = nullptr;
        }

        for (int i = 0; i < addNum; i++) {
            int id = 0;
            int dSelect = 0;
            string name;

            cout << "请输入第" << i + 1 << "个新职工的编号;" << endl;
            cin.sync();
            cin >> id;

            cout << "请选择该职工的岗位;" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin.sync();
            cin >> dSelect;

            cout << "请输入第" << i + 1 << "个新职工的姓名;" << endl;
            cin.sync();
            cin >> name;

            Worker* worker = nullptr;  // 父类指针指向子类对象
            switch (dSelect) {
                case 1:
                    worker = new Employee(id, dSelect, name);
                    break;
                case 2:
                    worker = new Manager(id, dSelect, name);
                    break;
                case 3:
                    worker = new Boss(id, dSelect, name);
                    break;
                default:
                    break;
            }

            newSpace[this->m_EmpNum + i] = worker;

            cout << "成功添加" << i + 1 << "名新员工" << endl;
            cout << "信息已保存！" << endl;
        }

        this->m_FileIsEmpty = false;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->save();
    } else {
        cout << "输入的信息有误！!" << endl;
    }

    system("pause");
    system("cls");
}



void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME,ios::out | ios::app);

    if (!ofs.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    for(int i = 0;i < this->m_EmpNum;i++){
        ofs << this->m_EmpArray[i]->m_ID << " "
            << this->m_EmpArray[i]->m_DeptID << " "
            << this->m_EmpArray[i]->m_Name << endl;
    }
    ofs.close();
}
int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id = 0;
    int dId = 0;
    string name;
    int num = 0;

    while(ifs >> id && ifs >> dId && ifs >> name){
        num++;
    }
    return num;
}

void WorkerManager::Show_Emp() {
    if(this->m_FileIsEmpty){
        cout << "无职工！" << endl;
    }else{
        for(int i = 0;i < m_EmpNum;i++){
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}


int WorkerManager::Find_Emp(int id) {
    int index = -1;
    for(int i = 0;i < m_EmpNum;i++){
        if(this->m_EmpArray[i]->m_ID == id){
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::Del_Emp() {
    cout << "请输入想要删除的职工编号！" << endl;
    int id = 0;
    cin >> id;
    for (int i = Find_Emp(id); i < m_EmpNum; i++) {
        m_EmpArray[i] = m_EmpArray[i+1];
    }
    m_EmpArray[m_EmpNum - 1] = nullptr;
}