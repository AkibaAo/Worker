#include <bits/stdc++.h>
#include "WorkManager.h"
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

int main(){
    WorkerManager wm;
    int choice = 0;

    while(true){
        wm.ShowMenu();
        label0:cout << "请选择操作" << endl;
        cin >> choice;
        if(choice > 7 || choice < 0){
            cout << "非法输入！" << endl;
            goto label0;
        }
        switch (choice) {
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.add_Emp();
                break;
            case 2:
                wm.Show_Emp();
                break;
            case 3:
                wm.Del_Emp();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                system("cls");//??????
                break;
        }
    }

    return 0;
}