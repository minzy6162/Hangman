#include<Windows.h>
#include<iostream>
#include <conio.h>
#include <vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>//파일 입출력
using namespace std;

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4//선택(스페이스바)

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
        if (menuCode == 0) { //게임시작

        }else if(menuCode == 1) {//랭킹

        }
        else if(menuCode == 2) {//종료
            return 0;
        }
        system("cls");
    }
    
    return 0;
}

int keyControl() {  //키보드 문자로 선택할 수 있게
    char temp = _getch(); //키를 입력하면 temp에 넣어서 값을 받아올 수 있게

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
    else if (temp == ' ') {//스페이스바 선택
        return SUBMIT;
    }
}

void init() {
    system("mode con cols=120 lines=20 | title 행맨게임");
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
    gotoxy(x - 2, y); //-2는 > 출력하려고
    printf("> 게임시작");
    gotoxy(x, y+1);
    printf("  랭킹  ");
    gotoxy(x, y+2);
    printf("  종료  ");
    
    while (1) {//키보드 방향으로 선택할 수 있게 무한반복
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 12) {
                gotoxy(x - 2, y);//칸 수 맞추려고
                printf(" ");//지우고
                gotoxy(x - 2, --y);//이동할 위치
                printf(">");//다시 그리기
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

void infoDraw() {//게임 화면
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
    ifstream readFromFile("words.txt");        //words.txt 파일을 읽기 전용으로 오픈
    if (!readFromFile.is_open())            //is_open이 되지 않는다는것은 파일이 존재하지 않다는 뜻.
    {
        ofstream writeToFile("words.txt");    //쓰기 전용으로 words.txt 파일을 오픈 (파일이 없으면 자동 생성됨)
        for (int i = 0; i < INIT_NUM; ++i)    //샘플 단어들을 format에 맞게 words.txt 파일에 입력
        {
            string tmp = str[i];
            if (i != INIT_NUM - 1)
            {
                tmp += "\n";
            }
            writeToFile.write(tmp.c_str(), tmp.size());    //파일에 쓰는 함수
            strArr.push_back(str[i]); //단어장(strArr)에 단어를 집어넣습니다.
        }
        writeToFile.close();    //쓰기전용파일 닫기
        return;                    //함수끝
    }

    //여기로 왔다는것은 읽기전용으로 파일오픈 되었다는뜻.
    while (!readFromFile.eof())    //파일 끝까지
    {
        string tmp;
        getline(readFromFile, tmp);    //한줄씩 읽어서
        strArr.push_back(tmp);        //단어장(strArr)에 단어 넣기
    }
    readFromFile.close();        //읽기전용파일 닫기
    return;
}