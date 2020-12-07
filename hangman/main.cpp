#include<Windows.h>
#include<iostream>
#include <conio.h>
#include <vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>//���� �����
using namespace std;

//Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4//����(�����̽���)

int keyControl();
int menuDraw();
void init();
void title();
void gotoxy(int, int);
void infoDraw();

int main() {
    init();
    while (1) {
        title();
        int menuCode = menuDraw();
        if (menuCode == 0) { //���ӽ���

        }else if(menuCode == 1) {//��ŷ

        }
        else if(menuCode == 2) {//����
            return 0;
        }
        system("cls");
    }
    
    return 0;
}

int keyControl() {  //Ű���� ���ڷ� ������ �� �ְ�
    char temp = _getch(); //Ű�� �Է��ϸ� temp�� �־ ���� �޾ƿ� �� �ְ�

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {//�����̽��� ����
        return SUBMIT;
    }
}

void init() {
    system("mode con cols=120 lines=20 | title ��ǰ���");
}

void title() {
    printf("\n\n\n\n");
    printf("           ##    ##       ##         ## ##      ##     ####        ####         ##          ## ##      ## \n");
    printf("           ##    ##     ##  ##       ## ##      ##     ## ##      ## ##       ##  ##        ## ##      ## \n");
    printf("           ########    ########      ##   ##    ##     ##  ##    ##  ##      ########       ##   ##    ## \n");
    printf("           ##    ##   ##      ##     ##     ##  ##     ##   ##  ##   ##     ##      ##      ##     ##  ## \n");
    printf("           ##    ##  ##        ##    ##      ## ##     ##    ####    ##    ##        ##     ##      ## ## \n");
    printf("\n\n\n\n");
}

void gotoxy(int x, int y) {
    HANDLE consoleHandel = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandel, pos);
}

int menuDraw() {
    int x = 24;
    int y = 12;
    gotoxy(x - 2, y); //-2�� > ����Ϸ���
    printf("> ���ӽ���");
    gotoxy(x, y+1);
    printf("  ��ŷ  ");
    gotoxy(x, y+2);
    printf("  ����  ");
    
    while (1) {//Ű���� �������� ������ �� �ְ� ���ѹݺ�
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 12) {
                gotoxy(x - 2, y);//ĭ �� ���߷���
                printf(" ");//�����
                gotoxy(x - 2, --y);//�̵��� ��ġ
                printf(">");//�ٽ� �׸���
            }
            break;
        }
        case DOWN: {
            if (y < 14) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 12;
        }
        }
    }


}

void infoDraw() {//���� ȭ��
    system("cls");
    printf("\n\n");
}

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
    if (!readFromFile.is_open())            //is_open�� ���� �ʴ´ٴ°��� ������ �������� �ʴٴ� ��.
    {
        ofstream writeToFile("words.txt");    //���� �������� words.txt ������ ���� (������ ������ �ڵ� ������)
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
        getline(readFromFile, tmp);    //���پ� �о
        strArr.push_back(tmp);        //�ܾ���(strArr)�� �ܾ� �ֱ�
    }
    readFromFile.close();        //�б��������� �ݱ�
    return;
}