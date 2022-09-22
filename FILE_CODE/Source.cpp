#include "Header.h"
// Khai báo kiểu dữ liệu
struct _POINT { int x, y, c; }; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
_POINT _A[BOARD_SIZE][BOARD_SIZE]; //Ma trận bàn cờ
char _BanCo[BOARD_SIZE * 2 + 1][BOARD_SIZE * 4 + 1];
bool _TURN; //true là lượt người thứ nhất và false là lượt người thứ hai
int _COMMAND; // Biến nhận giá trị phím người dùng nhập
int _X, _Y; //Tọa độ hiện hành trên màn hình bàn cờ
int Xwins = 0, Owins = 0; //So tran thang cua X O
int Xmoves = 0, Omoves = 0; //So luot di cua X O


void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
//
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Hàm khởi tạo dữ liệu mặc định ban đầu cho ma trận bàn cờ (hàm nhóm Model)
void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy
			//định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định
	Xmoves = 0; Omoves = 0; // Đổi số lượt thành 0
	_X = _A[0][0].x;
	_Y = _A[0][0].y; // Thiết lập lại tọa độ hiện hành ban đầu
}
//
void AnConTro() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = false;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void DrawBoard(char _BanCo[BOARD_SIZE * 2 + 1][BOARD_SIZE * 4 + 1]) {
	int i, j;
	for (j = 0; j < BOARD_SIZE * 4 + 1; j++)
		for (i = 0; i < BOARD_SIZE * 2 + 1; i++)
		{
			if (j % 4 == 0) {
				if (i % 2 != 0) _BanCo[i][j] = 179;
				else {
					if (j == 0) {
						if (i == 0) _BanCo[i][j] = 218;
						else if (i == BOARD_SIZE * 2) _BanCo[i][j] = 192;
						else _BanCo[i][j] = 195;
					}
					else if (j == BOARD_SIZE * 4) {
						if (i == 0) _BanCo[i][j] = 191;
						else if (i == BOARD_SIZE * 2) _BanCo[i][j] = 217;
						else _BanCo[i][j] = 180;
					}
					else {
						if (i == 0) _BanCo[i][j] = 194;
						else if (i == BOARD_SIZE * 2)_BanCo[i][j] = 193;
						else _BanCo[i][j] = 197;
					}
				}
			}
			else if (i % 2 == 0) _BanCo[i][j] = 196; else _BanCo[i][j] = ' ';
		}

	for (i = 0; i < BOARD_SIZE * 2 + 1; i++) {
		for (j = 0; j < BOARD_SIZE * 4 + 1; j++) {
			GotoXY(LEFT + j, TOP + i);
			cout << _BanCo[i][j];
		}
		cout << endl;
	}
	GotoXY(65, 6);
	cout << "SU DUNG CAC PHIM 'A', 'S', 'D', 'W' DE DI CHUYEN!!";
	GotoXY(60, 16);
	for (int j = 0; j < 2; j++) {
		cout << char(218);
		for (int i = 0; i < 24; i++) {
			cout << char(196);
		}
		cout << char(191) << "     ";
	}
	for (int i = 0; i < 6; i++) {
		GotoXY(60, 17 + i);
		cout << char(179) << "                        " << char(179) << "     ";
		cout << char(179) << "                        " << char(179) << endl;
	}
	GotoXY(60, 23);
	for (int j = 0; j < 2; j++) {
		cout << char(192);
		for (int i = 0; i < 24; i++) {
			cout << char(196);
		}
		cout << char(217) << "     ";
	}
	UpDate(0, 0, Xwins, Owins);
	GotoXY(_X, _Y);

}
//
int UpDate(int Xmoves, int Omoves, int Xwins, int Owins) {
	GotoXY(72, 17); cout << "X";
	GotoXY(69, 19); cout << "Moves: " << Xmoves;
	GotoXY(103, 17); cout << "O";
	GotoXY(100, 19); cout << "Moves: " << Omoves;
	GotoXY(64, 21); cout << "So tran da thang: " << Xwins;
	GotoXY(95, 21); cout << "So tran da thang: " << Owins;
	return 0;
}
//
void StartGame(int a) {
	system("cls");
	DrawBoard(_BanCo);
	if (a == 0) ResetData();
	else LoadBoard();
	GotoXY(_A[0][0].x, _A[0][0].y);
}
//
void GabageCollect()
{
	// Dọn dẹp tài nguyên nếu có khai báo con trỏ
}
//Hàm thoát game (hàm nhóm Control)
void ExitGame() {
	system("cls");
	GabageCollect();
	//Có thể lưu game trước khi exit
}
//Hàm kiểm tra xem có người thắng/thua hay hòa
//Hàm xử lý khi người chơi thua
int ProcessFinish(int pWhoWin) {
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí
	 // thích hợp để in chuỗi thắng/thua/hòa
	switch (pWhoWin) {
	case -1:
		XWin();
		Xwins++; //tang so tran win cua X len 1;
		break;
	case 1:
		OWin();
		Owins++; //tang so tran win cua O len 1;
		break;
	case 0:
		XODraw();
		break;
	case 2:
		_TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra
	}
	GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}
int AskContinue() {
	return toupper(_getch());
}

int CheckDraw() {
	int count = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].c != 0) {
				count++;
			}
		}
	}
	if (count == BOARD_SIZE * BOARD_SIZE) {
		return 1;
	}
	return 0;
}
int CheckRow(int pi, int pj, int LuatCHD) {
	int i = pi, j = pj, count = 0, Dem = 0;
	while ((j - 1 >= 0) && ((_A[i][j - 1].c == 1 && _TURN == false) || (_A[i][j - 1].c == -1 && _TURN == true))) {
		count++;
		j--;
	}
	if ((j - 1 >= 0) && ((_A[i][j - 1].c == -1 && _TURN == false) || (_A[i][j - 1].c == 1 && _TURN == true))) Dem++;
	i = pi;
	j = pj;
	while ((j + 1 <= (BOARD_SIZE - 1)) && ((_A[i][j + 1].c == 1 && _TURN == false) || (_A[i][j + 1].c == -1 && _TURN == true))) {
		count++;
		j++;
	}
	if ((j + 1 <= (BOARD_SIZE - 1)) && ((_A[i][j + 1].c == -1 && _TURN == false) || (_A[i][j + 1].c == 1 && _TURN == true))) Dem++;

	if ((count == 4 && (!LuatCHD || (LuatCHD && Dem != 2))) || count > 4) return 1;
	return 0;
}

int CheckColumn(int pi, int pj, int LuatCHD) {
	int i = pi, j = pj, count = 0, Dem = 0;
	while ((i - 1 >= 0) && ((_A[i - 1][j].c == 1 && _TURN == false) || (_A[i - 1][j].c == -1 && _TURN == true))) {
		count++;
		i--;
	}
	if ((i - 1 >= 0) && ((_A[i - 1][j].c == -1 && _TURN == false) || (_A[i - 1][j].c == 1 && _TURN == true))) Dem++;
	i = pi;
	j = pj;
	while ((i + 1 <= (BOARD_SIZE - 1)) && ((_A[i + 1][j].c == 1 && _TURN == false) || (_A[i + 1][j].c == -1 && _TURN == true))) {
		count++;
		i++;
	}
	if ((i + 1 <= (BOARD_SIZE - 1)) && ((_A[i + 1][j].c == -1 && _TURN == false) || (_A[i + 1][j].c == 1 && _TURN == true))) Dem++;

	if ((count == 4 && (!LuatCHD || (LuatCHD && Dem != 2))) || count > 4) return 1;
	return 0;
}

int Check1Cross(int pi, int pj, int LuatCHD) {
	int i = pi, j = pj, count = 0, Dem = 0;
	while (((i - 1 >= 0) && (j - 1 >= 0)) && ((_A[i - 1][j - 1].c == 1 && _TURN == false) || (_A[i - 1][j - 1].c == -1 && _TURN == true))) {
		count++;
		i--;
		j--;
	}
	if (((i - 1 >= 0) && (j - 1 >= 0)) && ((_A[i - 1][j - 1].c == -1 && _TURN == false) || (_A[i - 1][j - 1].c == 1 && _TURN == true))) Dem++;

	i = pi;
	j = pj;
	while (((i + 1 <= (BOARD_SIZE - 1)) && (j + 1 <= (BOARD_SIZE - 1))) && ((_A[i + 1][j + 1].c == 1 && _TURN == false) || (_A[i + 1][j + 1].c == -1 && _TURN == true))) {
		count++;
		i++;
		j++;
	}
	if (((i + 1 <= (BOARD_SIZE - 1)) && (j + 1 <= (BOARD_SIZE - 1))) && ((_A[i + 1][j + 1].c == -1 && _TURN == false) || (_A[i + 1][j + 1].c == 1 && _TURN == true))) Dem++;

	if ((count == 4 && (!LuatCHD || (LuatCHD && Dem != 2))) || count > 4) return 1;
	return 0;
}

int Check2Cross(int pi, int pj, int LuatCHD) {
	int i = pi, j = pj, count = 0, Dem = 0;
	while (((i - 1 >= 0) && (j + 1 <= (BOARD_SIZE - 1))) && ((_A[i - 1][j + 1].c == 1 && _TURN == false) || (_A[i - 1][j + 1].c == -1 && _TURN == true))) {
		count++;
		i--;
		j++;
	}
	if (((i - 1 >= 0) && (j + 1 <= (BOARD_SIZE - 1))) && ((_A[i - 1][j + 1].c == -1 && _TURN == false) || (_A[i - 1][j + 1].c == 1 && _TURN == true))) Dem++;

	i = pi;
	j = pj;
	while (((i + 1 <= (BOARD_SIZE - 1)) && (j - 1 >= 0)) && ((_A[i + 1][j - 1].c == 1 && _TURN == false) || (_A[i + 1][j - 1].c == -1 && _TURN == true))) {
		count++;
		i++;
		j--;
	}
	if (((i + 1 <= (BOARD_SIZE - 1)) && (j - 1 >= 0)) && ((_A[i + 1][j - 1].c == -1 && _TURN == false) || (_A[i + 1][j - 1].c == 1 && _TURN == true))) Dem++;

	if ((count == 4 && (!LuatCHD || (LuatCHD && Dem != 2))) || count > 4) return 1;
	return 0;
}

int CheckWin(int pX, int pY, int LuatCHD) {
	//Tim i, j
	int _i, _j;
	_j = (_X - 2 - LEFT) / 4;
	_i = (_Y - 1 - TOP) / 2;

	return CheckRow(_i, _j, LuatCHD) || CheckColumn(_i, _j, LuatCHD) || Check1Cross(_i, _j, LuatCHD) || Check2Cross(_i, _j, LuatCHD);
}

//Hàm kiểm tra xem có người thắng/thua hay hòa
int TestBoard(int pX, int pY, int LuatCHD)
{
	if (CheckDraw()) return 0; // Hòa
	else {
		if (CheckWin(pX, pY, LuatCHD))
			return (_TURN == true ? -1 : 1); // -1 nghĩa là lượt ‘true’ thắng
		else
			return 2; // 2 nghĩa là chưa ai thắng
	}
	//return 2;
}

void PrintText(string text, int x, int y)
{
	GotoXY(x, y);
	cout << text;
}

int CheckBoard(int pX, int pY) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) _A[i][j].c = -1; // Nếu lượt hiện hành là true thì c = -1
				else _A[i][j].c = 1; // Nếu lượt hiện hành là false thì c = 1
				return _A[i][j].c;
			}
		}
	}
	return 0;
}
//
void MoveRight() {
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		_X += 4;
		GotoXY(_X, _Y);
	}
}

void MoveLeft() {
	if (_X > _A[0][0].x) {
		_X -= 4;
		GotoXY(_X, _Y);
	}
}

void MoveDown() {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
}
void MoveUp() {
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}

int SaveGame() {
	// Lưu board vào file
	string filename, files[100];
	PrintText("NHAP TEN FILE: ", 70, 10);
	cin >> filename;
	filename += ".txt";
	ofstream file(filename);
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
			file << _A[j][i].c << " ";
		file << endl;
	}
	file << _TURN;
	file.close();

	//Lưu tên file vào listFiles.txt
	ifstream listfiles("listFiles.txt"); //mở file để đọc
	int line = 0;
	listfiles >> line;
	for (int i = 0; i < line; i++)
	{
		listfiles >> files[i];
		if (filename == files[i]) {
			listfiles.close();
			return 0; //nếu tên file đã có trong listfiles thì ko cần thêm
		}
	}

	listfiles.close();

	ofstream _listfiles("listFiles.txt"); //mở file để ghi
	_listfiles << line + 1 << endl; //tăng số dòng
	for (int i = 0; i < line; i++)
	{
		_listfiles << files[i] << endl;
	}

	_listfiles << filename; //thêm file
	_listfiles.close();
	return 0;
}

void LoadBoard() {
	Xmoves = 0; Omoves = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ
			if (_A[i][j].c == -1) {
				PrintText("X", _A[i][j].x, _A[i][j].y); Xmoves++;
			}
			else if (_A[i][j].c == 1) {
				PrintText("O", _A[i][j].x, _A[i][j].y); Omoves++;
			}
		}
	UpDate(Xmoves, Omoves, Xwins, Owins);
	_X = _A[0][0].x; _Y = _A[0][0].y;
	GotoXY(_X, _Y);
}

int LoadGame(string filename) {
	ifstream file(filename);
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			file >> _A[j][i].c;
	file >> _TURN;
	file.close();
	LoadBoard();
	return 1;
}
//
int NewGame(int LuatCHD, int a) {
	StartGame(a);
	bool validEnter = true;
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) {
			ExitGame();
			return 0;
		}
		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 13) {// Người dùng đánh dấu trên màn hình bàn cờ
				switch (CheckBoard(_X, _Y)) {
				case -1: {
					printf("X");
					Xmoves++;
					UpDate(Xmoves, Omoves, Xwins, Owins);
					break;
				}
				case 1: {
					printf("O");
					Omoves++;
					UpDate(Xmoves, Omoves, Xwins, Owins);
					break;
				}
				case 0: validEnter = false; // Khi đánh vào ô đã đánh rồi
				}
				// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard(_X, _Y, LuatCHD))) {
					case -1: case 1: case 0:
						if (AskContinue() != 'Y') {
							system("cls");
							MainMenu();
						}
						else {
							StartGame();
							Xmoves = 0;
							Omoves = 0;
							GotoXY(_A[0][0].x, _A[0][0].y);
						}
						break;
					}
				}
				validEnter = true; // Mở khóa
			}
			else if (_COMMAND == 'L') {
				SaveGame();
				return 0;
			}
			else if (_COMMAND == 'T') {
				return 1;
			}
		}
	}
}
