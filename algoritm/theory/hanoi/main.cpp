#include <iostream>
#include <stdexcept>
#include <vector>
#include <windows.h>
using namespace std;

class Tower {
public:
    // конструктор и метод SetDisks нужны, чтобы правильно создать башни
    Tower(int disks_num) {
        FillTower(disks_num);
    }

    int GetDisksNum() const {
        return disks_.size();
    }

    void SetDisks(int disks_num) {
        FillTower(disks_num);
    }

    // добавляем диск на верх собственной башни
    // обратите внимание на исключение, которое выбрасывается этим методом
    void AddToTop(int disk) {
        int top_disk_num = disks_.size() - 1;

        if (0 != disks_.size() && disk >= disks_[top_disk_num]) {
            throw invalid_argument("Невозможно поместить большой диск на маленький");
        } else {
            // допишите этот метод и используйте его в вашем решении
            disks_.push_back(disk);
        }
    }

    vector<int> GetDisks() const {
        return disks_;
    }

    void MoveTopTo(Tower &dest) {
        int top_disk_num = disks_.size() - 1;

        try {
            dest.AddToTop(disks_[top_disk_num]);
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
            throw;
        }

        disks_.pop_back();
    }

    void MoveDisks(const int disks_num,  Tower &buffer, Tower &dest) {
        if ( disks_num > 0) {
            MoveDisks(disks_num - 1,  dest,buffer);
            MoveTopTo(dest);
             buffer.MoveDisks(disks_num - 1,  *this, dest);
        }
    }

private:
    vector<int> disks_;

    // используем приватный метод FillTower, чтобы избежать дубликации кода
    void FillTower(const int disks_num) {
        for (int i = disks_num; i > 0; i--) {
            disks_.push_back(i);
        }
    }
};

ostream &operator<<(ostream &out, const Tower &tower) {
    for (const auto &disk: tower.GetDisks()) {
        out << disk << " ";
    }
    return out;
}


void SolveHanoi(vector<Tower> &towers) {
    int disks_num = towers[0].GetDisksNum();

    towers[0].MoveDisks(disks_num, towers[1], towers[2]);
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

    int towers_num = 3;
    int disks_num = 3;
    vector<Tower> towers;

    // добавим в вектор три пустые башни
    for (int i = 0; i < towers_num; ++i) {
        towers.push_back(0);
    }

    // добавим на первую башню три кольца
    towers[0].SetDisks(disks_num);

    cout << "Before" << endl;
    for (int i = 0; i < towers.size(); ++i) {
        cout << i << ": " << towers[i] << endl;
    }

    SolveHanoi(towers);

    cout << "After" << endl;

    for (int i = 0; i < towers.size(); ++i) {
        cout << i << ": " << towers[i] << endl;
    }
}

/*
[[],[],[]] vector Tower

 башня    башни
[[3,2,1],[_], [_]]

 3 _ 2,1
 _ 3 2,1

_ 3,2,1 _

результат
[[_], [_], [3,2,1]]


 4,3,2,1 _ _
 -> 3,2,1 -> 4 - стек 3 дисков на ось, 4 диск на ось,
    3,2,1 -  стек 3 дисков на 4 диск
    -> 2,1 -> 3 - стек 2 дисков на ось, 3 диск на ось (где 4 диск)
        2,1 - стек 2 дисков на 3 диск
        -> 1->2 - 1 на ось, 2 на 3
        1 - 1 диск на 2 диск

 1 функция берет нужный стек и используют 2 функцию для перемещения
 1 функция берет нужный диск и используют 2 функцию для перемещения
 */