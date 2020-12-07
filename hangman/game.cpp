#include <iostream>
#include <string>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include <vector>
#include<fstream>//���� �����
using namespace std;

void SetDictionary(vector<string>& strArr)
{
    static const int INIT_NUM = 30;
    static const string str[INIT_NUM] = { "bacon", "beef", "duck", "kidneys",
"banana", "blackberry", "fig", "gooseberry", "grapefruit",
"pomegranate", "kipper", "trout", "artichoke", "beetroot",
"mushroom", "sultanas", "pepper", "dill", "archery", "canoeing",
"handball", "yoga", "header", "linesman", "gym", "brake",
"victory", "adidas", "spao", "markgonzales" };   
    ifstream readFromFile("words.txt");        //words.txt ������ �б� �������� ����
    if (!readFromFile.is_open())            //is_open�ȿ����� ���� ���� ����
    {
        ofstream writeToFile("words.txt");    //���� �������� words.txt ���� ����
        for (int i = 0; i < INIT_NUM; ++i)    //���� �ܾ���� format�� �°� words.txt ���Ͽ� �Է�
        {
            string tmp = str[i];
            if (i != INIT_NUM - 1)
            {
                tmp += "\n";
            }
            writeToFile.write(tmp.c_str(), tmp.size());    //���Ͽ� ���� �Լ�
            strArr.push_back(str[i]); //�ܾ���(strArr)�� �ܾ ����ֽ��ϴ�.
        }
        writeToFile.close();    //������������ �ݱ�
        return;                    //�Լ���
    }

    //����� �Դٴ°��� �б��������� ���Ͽ��� �Ǿ��ٴ¶�.
    while (!readFromFile.eof())    //���� ������
    {
        string tmp;
        getline(readFromFile, tmp);    //���پ� �б�
        strArr.push_back(tmp);        //�ܾ���(strArr)�� �ܾ� �ֱ�
    }
    readFromFile.close();        //�б��������� �ݱ�
    return;
}
Hangman::Hangman() {
    int count = 0;
    wcount = 0;
    check = true;
    word = "";
}
string Hangman::input() {

}