#include<Windows.h>
#include<iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4//선택(스페이스바)
#define WRONGTRIEST 5 

int keyControl();
int menuDraw();
void init();
void title();
void gotoxy(int, int);
void infoDraw();
void game();

int main() {
    init();
    while (1) {
        title();
        int menuCode = menuDraw();
        if (menuCode == 0) { //게임시작
            game();
        }
        else if (menuCode == 1) {//랭킹
            infoDraw();
        }
        else if (menuCode == 2) {//종료
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
    system("mode con cols=120 lines=25 | title 행맨게임");
}

void title() {
    printf("\n\n\n\n");
    printf("        ##    ##       ##         ## ##      ##       ######       ####        ####         ##          ## ##      ## \n");
    printf("        ##    ##     ##  ##       ## ##      ##     ##             ## ##      ## ##       ##  ##        ## ##      ## \n");
    printf("        ########    ########      ##   ##    ##     ##  #####      ##  ##    ##  ##      ########       ##   ##    ## \n");
    printf("        ##    ##   ##      ##     ##     ##  ##     ##     ##      ##   ##   ##  ##     ##      ##      ##     ##  ## \n");
    printf("        ##    ##  ##        ##    ##      ## ##      ########      ##    ####    ##    ##        ##     ##      ## ## \n");
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
    int x = 50;
    int y = 12;
    gotoxy(x - 2, y); //-2는 > 출력하려고
    printf("> 게임시작");
    gotoxy(x, y + 1);
    printf("  조작법 ");
    gotoxy(x, y + 2);
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
    printf("\t\t\t\t\t\t\t게임 설명\n\n\n");
    printf("\t\t\t=============================================================================\n\n\n");
    printf("\t\t\t\t\t\t영어 단어 맞추기 게임입니다.\n\n");
    printf("\t\t\t\t글자 수만큼 빈칸 또는 밑줄을 그려놓고 단어를 맞추는 게임이죠\n\n");
    printf("\t\t\t\t\t   다리 -> 몸통 -> 머리 순으로 없어집니다.\n\n");
    printf("\t\t\t\t\t\t기회는 총 5번 주어집니다.\n\n");
    printf("\t\t\t=============================================================================\n\n\n");
    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}

void DrawMan(int tries) {
	cout << endl << endl;
	cout << "  -----" << endl;
	cout << "  |   |" << endl;
	cout << "  |"; if (tries >= 1)cout << "   0    "; cout << endl;
	cout << "  |"; if (tries >= 3)cout << " ／|＼  "; cout << endl;
	cout << "  |"; if (tries >= 5)cout << " ／ ＼ "; cout << endl;
	cout << "  |" << endl;
	cout << "__|__" << endl;
}

void game(){
	system("cls");
	srand(time(NULL));
	string wList[10] = { "apple", "peach", "banana", "strawberry", "mango",  
        "heimish", "sunrise", "requiem", "cresent", "girlish"};//배열에 단어 10개 저장
	string word;//wList랑 비교할 단어
	string guessed;

	word = wList[rand() % 10];

	int wLength = word.length();
	string dispWord(wLength, '_');

	int found = 0;
	char guess = ' ';
	int tries = 5;
	int flagFound = 0;

	while (tries >= 0) {
		cout << "맞춰보세요: " << endl << endl;

		for (int i = 0; i < wLength; i++)
			cout << " " << dispWord[i] << " ";
		cout << endl << endl << endl;

		cout << "틀린 글자: " << tries << " / " << WRONGTRIEST << endl;
		cout << "다른 글자를 생각해 보세요: " << guessed << endl;

		DrawMan(tries);

		if (found == wLength) {
			cout << endl;
			cout << "**********" << endl;
			cout << "*이겼어요*" << endl;
			cout << "**********" << endl;
			break;
		}

		if (tries == 0)break;

		cout << "골라보세요: ";
		guess = _getwch();

		guessed = guessed + " " + guess;

		if (dispWord.find(guess) != string::npos)tries++;

		flagFound = 0;
		for (int i = 0; i < wLength; i++) {
			if (word[i] == guess && dispWord[i] == '_') {
				dispWord[i] = guess;
				found++;
				flagFound = 1;
			}
		}
		if (!flagFound)
			tries--;
	}

		if (found != wLength) {
			cout << "**********" << endl;
			cout << "* 졌어요 *" << endl;
			cout << "**********" << endl;
		}
        _getch();
}