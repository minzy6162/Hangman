#include<Windows.h>
#include<iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

//Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4//����(�����̽���)
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
        if (menuCode == 0) { //���ӽ���
            game();
        }
        else if (menuCode == 1) {//��ŷ
            infoDraw();
        }
        else if (menuCode == 2) {//����
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
    system("mode con cols=120 lines=25 | title ��ǰ���");
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
    gotoxy(x - 2, y); //-2�� > ����Ϸ���
    printf("> ���ӽ���");
    gotoxy(x, y + 1);
    printf("  ���۹� ");
    gotoxy(x, y + 2);
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
    printf("\t\t\t\t\t\t\t���� ����\n\n\n");
    printf("\t\t\t=============================================================================\n\n\n");
    printf("\t\t\t\t\t\t���� �ܾ� ���߱� �����Դϴ�.\n\n");
    printf("\t\t\t\t���� ����ŭ ��ĭ �Ǵ� ������ �׷����� �ܾ ���ߴ� ��������\n\n");
    printf("\t\t\t\t\t   �ٸ� -> ���� -> �Ӹ� ������ �������ϴ�.\n\n");
    printf("\t\t\t\t\t\t��ȸ�� �� 5�� �־����ϴ�.\n\n");
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
	cout << "  |"; if (tries >= 3)cout << " ��|��  "; cout << endl;
	cout << "  |"; if (tries >= 5)cout << " �� �� "; cout << endl;
	cout << "  |" << endl;
	cout << "__|__" << endl;
}

void game(){
	system("cls");
	srand(time(NULL));
	string wList[10] = { "apple", "peach", "banana", "strawberry", "mango",  
        "heimish", "sunrise", "requiem", "cresent", "girlish"};//�迭�� �ܾ� 10�� ����
	string word;//wList�� ���� �ܾ�
	string guessed;

	word = wList[rand() % 10];

	int wLength = word.length();
	string dispWord(wLength, '_');

	int found = 0;
	char guess = ' ';
	int tries = 5;
	int flagFound = 0;

	while (tries >= 0) {
		cout << "���纸����: " << endl << endl;

		for (int i = 0; i < wLength; i++)
			cout << " " << dispWord[i] << " ";
		cout << endl << endl << endl;

		cout << "Ʋ�� ����: " << tries << " / " << WRONGTRIEST << endl;
		cout << "�ٸ� ���ڸ� ������ ������: " << guessed << endl;

		DrawMan(tries);

		if (found == wLength) {
			cout << endl;
			cout << "**********" << endl;
			cout << "*�̰���*" << endl;
			cout << "**********" << endl;
			break;
		}

		if (tries == 0)break;

		cout << "��󺸼���: ";
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
			cout << "* ����� *" << endl;
			cout << "**********" << endl;
		}
        _getch();
}