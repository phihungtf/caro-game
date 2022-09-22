#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ
#define LEFT 3 // Tọa độ trái màn hình bàn cờ
#define TOP 1 // Tọa độ trên màn hình bàn cờ
void FixConsoleWindow();
void GotoXY(int x, int y);
void ResetData();
void DrawBoard(char _BanCo[BOARD_SIZE * 2 + 1][BOARD_SIZE * 4 + 1]);
void StartGame(int a=0);
void GabageCollect();
void ExitGame();
int ProcessFinish(int pWhoWin);
int AskContinue();
int CheckBoard(int pX, int pY);
void MoveLeft();
void MoveRight();
void MoveDown();
void MoveUp();
int NewGame(int LuatCHD, int a = 0);
void textcolor(int x);
int UpDate(int Xmoves, int Omoves, int Xwins, int Ywins);
int CheckDraw();
int CheckRow(int pi, int pj, int LuatCHD);
int CheckColumn(int pi, int pj, int LuatCHD);
int Check1Cross(int pi, int pj, int LuatCHD);
int Check2Cross(int pi, int pj, int LuatCHD);
int CheckWin(int pX, int pY, int LuatCHD);
//Hàm kiểm tra xem có người thắng/thua hay hòa
int TestBoard(int pX, int pY, int LuatCHD);
void PrintText(string text, int x, int y);
void DrawBigText();
int DrawMenu();
void AnConTro();
int MainMenu(int isLoad = 0);
int MoveAndChoose(int a, string A[], int _X, int _Y);
int DrawOption();
int ChooseOption(int a, string A[]);
int DrawLoadFile();
int SaveGame();
void LoadBoard();
int LoadGame(string filename);
int Credit();
void XWin();
void OWin();
void XODraw();
int LawGame();
