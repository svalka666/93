#pragma execution_character_set("utf-8")
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <string>
#include <Windows.h>
using namespace std;
struct Price {
    string productName;
    string shopName;
    double cost;
};
void EnterData(Price* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "����� " << i + 1 << ":" << endl;
        cout << "����� ������: ";
        cin >> array[i].productName;
        cout << "����� ��������: ";
        cin >> array[i].shopName;
        cout << "������� ������: ";
        cin >> array[i].cost;
    }
}

void Print(const Price* array, int size) {
    cout << "=========================================" << endl;
    cout << "|  �����  |  �������  |  �������, ���  |" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "| " << setw(7) << left << array[i].productName << " | "
            << setw(9) << left << array[i].shopName << " | "
            << setw(15) << right << fixed << setprecision(2) << array[i].cost << " |" << endl;
    }
    cout << "=========================================" << endl;
}
void SortByProductName(Price* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[i].productName > array[j].productName) {
                swap(array[i], array[j]);
            }
        }
    }
}
void SearchShopByName(const Price* array, int size, const string& shopName) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (array[i].shopName == shopName) {
            cout << "�������� ������� '" << shopName << "':" << endl;
            cout << "�����: " << array[i].productName << ", �������: " << array[i].cost << " ���" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "������� � ������ '" << shopName << "' �� ��������." << endl;
    }
}

void LoadFromFile(Price*& p, int& N, const char* filename)
{
    delete[] p;                                  

    ifstream fin(filename, ios::binary);            

    fin.read((char*)&N, sizeof(N));               

    p = new Price[N];                         

    for (int i = 0; i < N; i++)
        fin.read((char*)&p[i], sizeof(Price));  

    fin.close();         
}

// ������� ��� ������ ����� � ����
void SaveToFile(Price* p, const int N, const char* filename) {
    ofstream fout(filename, ios::binary);            // ������� ������� ���� ������ 

    fout.write((char*)&N, sizeof(N));                // �������� ������� �������� 

    for (int i = 0; i < N; i++)
        fout.write((char*)&p[i], sizeof(Price)); // �������� �������� ������ 

    fout.close();                                    // ������� ���� 
}
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int N;
    cout << "������ N: "; cin >> N;

    Price* p = new Price[N];

    int found;
    char filename[100];
    string iproduct;
    string shopName;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << "  [1] - �������� ����� � ���������" << endl;
        cout << "  [2] - ���� ����� �� �����" << endl;
        cout << "  [3] - ������� ������������ �����" << endl;
        cout << "  [4] - ����� ��������" << endl;
        cout << "  [5] - ����� ����� � ����" << endl;
        cout << "  [6] - ���������� ����� �� �����" << endl << endl;
        cout << "  [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
        cout << endl << endl << endl;
        switch (menuItem)
        {
        case 1:
            EnterData(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            SortByProductName(p, N);

            break;
        case 4:
            cout << "������ ����� ������:" << endl;
            cin.get();
            cin.sync();

            cout << "    ����� ��������: "; getline(cin, shopName);
            cout << endl;
            SearchShopByName(p, N, shopName);
            break;
        case 5:
            cin.get();
            cin.sync();

            cout << "������ ��'� �����: "; cin.getline(filename, 99);
            SaveToFile(p, N, filename);

            break;
        case 6:
            cin.get();
            cin.sync();

            cout << "������ ��'� �����: "; cin.getline(filename, 99);
            LoadFromFile(p, N, filename);

            break;
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menuItem != 0);

    return 0;
}