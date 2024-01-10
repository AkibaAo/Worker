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
    cout << "ְ������Ϊ�� " << num << endl;
    this->m_EmpNum = num;
}

WorkerManager::~WorkerManager() {

}

void WorkerManager::ShowMenu() {
    cout << "**************************************" << endl;
    cout << "*********��ӭʹ��ְ������ϵͳ��**********" << endl;
    cout << "***********0.�˳��������*************" << endl;
    cout << "***********1.����ְ����Ϣ*************" << endl;
    cout << "***********2.��ʾְ����Ϣ*************" << endl;
    cout << "***********3.ɾ����ְԱ��*************" << endl;
    cout << "***********4.�޸�ְ����Ϣ*************" << endl;
    cout << "***********5.����ְ����Ϣ*************" << endl;
    cout << "***********6.���ձ������*************" << endl;
    cout << "***********7.��������ĵ�*************" << endl;
    cout << "**************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem() {
    cout << "ϵͳ���˳�" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::add_Emp() {
    cout << "���������ְ��������" << endl;
    int addNum = 0;
    cin.sync();
    cin >> addNum;
    if (addNum <= 0 || addNum > INT_MAX / sizeof(Worker*)) {
        cout << "�����addNum��Ϣ����" << endl;
        system("pause");
        system("cls");
        return;
    }

    if (addNum > 0) {
        int newSize = this->m_EmpNum + addNum;

        if (newSize <= 0 || newSize > INT_MAX / sizeof(Worker*)) {
            cout << "�����newSize��Ϣ����" << endl;
            system("pause");
            system("cls");
            return;
        }
        cout << "DEBUG: ���ڷ��������飬newSize = " << newSize << endl;
        Worker** newSpace = new Worker*[newSize];  // ����ָ��ָ���������
        if (this->m_EmpArray != nullptr) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
            delete[] this->m_EmpArray;  // ɾ��������
            this->m_EmpArray = nullptr;
        }

        for (int i = 0; i < addNum; i++) {
            int id = 0;
            int dSelect = 0;
            string name;

            cout << "�������" << i + 1 << "����ְ���ı��;" << endl;
            cin.sync();
            cin >> id;

            cout << "��ѡ���ְ���ĸ�λ;" << endl;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin.sync();
            cin >> dSelect;

            cout << "�������" << i + 1 << "����ְ��������;" << endl;
            cin.sync();
            cin >> name;

            Worker* worker = nullptr;  // ����ָ��ָ���������
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

            cout << "�ɹ����" << i + 1 << "����Ա��" << endl;
            cout << "��Ϣ�ѱ��棡" << endl;
        }

        this->m_FileIsEmpty = false;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->save();
    } else {
        cout << "�������Ϣ����!" << endl;
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
        cout << "��ְ����" << endl;
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
    cout << "��������Ҫɾ����ְ����ţ�" << endl;
    int id = 0;
    cin >> id;
    for (int i = Find_Emp(id); i < m_EmpNum; i++) {
        m_EmpArray[i] = m_EmpArray[i+1];
    }
    m_EmpArray[m_EmpNum - 1] = nullptr;
}