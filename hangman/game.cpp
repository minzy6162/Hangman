#include <iostream>
#include <string>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include <vector>
#include<fstream>//파일 입출력
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
    ifstream readFromFile("words.txt");        //words.txt 파일을 읽기 전용으로 오픈
    if (!readFromFile.is_open())            //is_open안열리면 파일 존재 안함
    {
        ofstream writeToFile("words.txt");    //쓰기 전용으로 words.txt 파일 열기
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
        getline(readFromFile, tmp);    //한줄씩 읽기
        strArr.push_back(tmp);        //단어장(strArr)에 단어 넣기
    }
    readFromFile.close();        //읽기전용파일 닫기
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