#include "Header.h"

string menu[] = { "PLAY", "LOAD GAME", "OPTION", "CREDIT","HELP", "EXIT" };
string option[] = { "KHONG AP DUNG LUAT CHAN HAI DAU.", "    AP DUNG LUAT CHAN HAI DAU." };
string files[100];
int X = 0, Y = 0, Luat = 1, nfiles = 0, findex = 0;
void DrawBigText() {
	textcolor(299);
	PrintText("               _____                    _____                    _____                   _______         ", 5, 1);
	PrintText("              /\\    \\                  /\\    \\                  /\\    \\                 /::\\    \\        ", 5, 2);
	PrintText("             /::\\    \\                /::\\    \\                /::\\    \\               /::::\\    \\       ", 5, 3);
	PrintText("            /::::\\    \\              /::::\\    \\              /::::\\    \\             /::::::\\    \\      ", 5, 4);
	PrintText("           /::::::\\    \\            /::::::\\    \\            /::::::\\    \\           /::::::::\\    \\     ", 5, 5);
	PrintText("          /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\         /:::/~~\\:::\\    \\    ", 5, 6);
	PrintText("         /:::/  \\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\       /:::/    \\:::\\    \\   ", 5, 7);
	PrintText("        /:::/    \\:::\\    \\      /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\     /:::/    / \\:::\\    \\  ", 5, 8);
	PrintText("       /:::/    / \\:::\\    \\    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\   /:::/____/   \\:::\\____\\ ", 5, 9);
	PrintText("      /:::/    /   \\:::\\    \\  /:::/\\:::\\   \\:::\\    \\  /:::/\\:::\\   \\:::\\____\\ |:::|    |     |:::|    |", 5, 10);
	PrintText("     /:::/____/     \\:::\\____\\/:::/  \\:::\\   \\:::\\____\\/:::/  \\:::\\   \\:::|    ||:::|____|     |:::|    |", 5, 11);
	PrintText("     \\:::\\    \\      \\::/    /\\::/    \\:::\\  /:::/    /\\::/   |::::\\  /:::|____| \\:::\\    \\   /:::/    / ", 5, 12);
	PrintText("      \\:::\\    \\      \\/____/  \\/____/ \\:::\\/:::/    /  \\/___/|:::::\\/:::/    /   \\:::\\    \\ /:::/    /  ", 5, 13);
	PrintText("       \\:::\\    \\                       \\::::::/    /         |:::::::::/    /     \\:::\\    /:::/    /   ", 5, 14);
	PrintText("        \\:::\\    \\                       \\::::/    /          |::|\\::::/    /       \\:::\\__/:::/    /    ", 5, 15);
	PrintText("         \\:::\\    \\                      /:::/    /           |::| \\::/____/         \\::::::::/    /     ", 5, 16);
	PrintText("          \\:::\\    \\                    /:::/    /            |::|  ~|                \\::::::/    /      ", 5, 17);
	PrintText("           \\:::\\    \\                  /:::/    /             |::|   |                 \\::::/    /       ", 5, 18);
	PrintText("            \\:::\\____\\                /:::/    /              \\::|   |                  \\::/____/        ", 5, 19);
	PrintText("             \\::/    /                \\::/    /                \\:|   |                   ~~              ", 5, 20);
	PrintText("              \\/____/                  \\/____/                  \\|___|                                   ", 5, 21);
	textcolor(496);
}
int DrawMenu() {
	textcolor(15);
	PrintText(menu[0], X, Y);
	textcolor(496);
	PrintText(menu[1], X, Y + 1);
	PrintText(menu[2], X, Y + 2);
	PrintText(menu[3], X, Y + 3);
	PrintText(menu[4], X, Y + 4);
	PrintText(menu[5], X, Y + 5);
	return 6;
}
//
void XWin() {
	int x = 15;
	int y = 10;
	textcolor(89);
	PrintText("                                                                                         ", x, y - 1);
	PrintText("    `8.`8888.      ,8'       `8.`888b                 ,8'  8 8888   b.             8     ", x, y + 0);
	PrintText("     `8.`8888.    ,8'         `8.`888b               ,8'   8 8888   888o.          8     ", x, y + 1);
	PrintText("      `8.`8888.  ,8'           `8.`888b             ,8'    8 8888   Y88888o.       8     ", x, y + 2);
	PrintText("       `8.`8888.,8'             `8.`888b     .b    ,8'     8 8888   .`Y888888o.    8     ", x, y + 3);
	PrintText("        `8.`88888'               `8.`888b    88b  ,8'      8 8888   8o. `Y888888o. 8     ", x, y + 4);
	PrintText("        .88.`8888.                `8.`888b .`888b,8'       8 8888   8`Y8o. `Y88888o8     ", x, y + 5);
	PrintText("       .8'`8.`8888.                `8.`888b8.`8888'        8 8888   8   `Y8o. `Y8888     ", x, y + 6);
	PrintText("      .8'  `8.`8888.                `8.`888`8.`88'         8 8888   8      `Y8o. `Y8     ", x, y + 7);
	PrintText("     .8'    `8.`8888.                `8.`8' `8,`'          8 8888   8         `Y8o.`     ", x, y + 8);
	PrintText("    .8'      `8.`8888.                `8.`   `8'           8 8888   8            `Yo     ", x, y + 9);
	PrintText("                                                                                         ", x, y + 10);
	PrintText("            NHAN 'Y' DE TIEP TUC, NHAN BAT CU PHIM NAO DE TRO VE MENU CHINH:             ", x, y + 11);
	textcolor(496);

}
void OWin() {
	int x = 15;
	int y = 10;
	textcolor(89);
	PrintText("                                                                                         ", x, y - 1);
	PrintText("        ,o888888o.           `8.`888b                 ,8'  8 8888   b.             8     ", x, y + 0);
	PrintText("     . 8888     `88.          `8.`888b               ,8'   8 8888   888o.          8     ", x, y + 1);
	PrintText("    ,8 8888       `8b          `8.`888b             ,8'    8 8888   Y88888o.       8     ", x, y + 2);
	PrintText("    88 8888        `8b          `8.`888b     .b    ,8'     8 8888   .`Y888888o.    8     ", x, y + 3);
	PrintText("    88 8888         88           `8.`888b    88b  ,8'      8 8888   8o. `Y888888o. 8     ", x, y + 4);
	PrintText("    88 8888         88            `8.`888b .`888b,8'       8 8888   8`Y8o. `Y88888o8     ", x, y + 5);
	PrintText("    88 8888        ,8P             `8.`888b8.`8888'        8 8888   8   `Y8o. `Y8888     ", x, y + 6);
	PrintText("    `8 8888       ,8P               `8.`888`8.`88'         8 8888   8      `Y8o. `Y8     ", x, y + 7);
	PrintText("     ` 8888     ,88'                 `8.`8' `8,`'          8 8888   8         `Y8o.`     ", x, y + 8);
	PrintText("        `8888888P'                    `8.`   `8'           8 8888   8            `Yo     ", x, y + 9);
	PrintText("                                                                                         ", x, y + 10);
	PrintText("            NHAN 'Y' DE TIEP TUC, NHAN BAT CU PHIM NAO DE TRO VE MENU CHINH:             ", x, y + 11);
	textcolor(496);
}
//
void XODraw() {
	int x = 15;
	int y = 10;
	textcolor(89);
	PrintText("                                                                                            ", x, y - 1);
	PrintText("    8 888888888o.      8 888888888o.            .8.         `8.`888b                 ,8'    ", x, y + 0);
	PrintText("    8 8888    `^888.   8 8888    `88.          .888.         `8.`888b               ,8'     ", x, y + 1);
	PrintText("    8 8888        `88. 8 8888     `88         :88888.         `8.`888b             ,8'      ", x, y + 2);
	PrintText("    8 8888         `88 8 8888     ,88        . `88888.         `8.`888b     .b    ,8'       ", x, y + 3);
	PrintText("    8 8888          88 8 8888.   ,88'       .8. `88888.         `8.`888b    88b  ,8'        ", x, y + 4);
	PrintText("    8 8888          88 8 888888888P'       .8`8. `88888.         `8.`888b .`888b,8'         ", x, y + 5);
	PrintText("    8 8888         ,88 8 8888`8b          .8' `8. `88888.         `8.`888b8.`8888'          ", x, y + 6);
	PrintText("    8 8888        ,88' 8 8888 `8b.       .8'   `8. `88888.         `8.`888`8.`88'           ", x, y + 7);
	PrintText("    8 8888    ,o88P'   8 8888   `8b.    .888888888. `88888.         `8.`8' `8,`'            ", x, y + 8);
	PrintText("    8 888888888P'      8 8888     `88. .8'       `8. `88888.         `8.`   `8'             ", x, y + 9);
	PrintText("                                                                                            ", x, y + 10);
	PrintText("             NHAN 'Y' DE TIEP TUC, NHAN BAT CU PHIM NAO DE TRO VE MENU CHINH:               ", x, y + 11);
	textcolor(496);
}
void MoveUpMenu() {
	Y = Y - 1;
	GotoXY(X, Y);
}
void MoveDownMenu() {
	Y = Y + 1;
	GotoXY(X, Y);
}
int MoveAndChoose(int a, string A[], int _X, int _Y) { //ham di chuyen len xuong va chon doi tuong trong cac dang menu
	char _COMMAND;
	int i = 0;
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) {
			ExitGame();
			return -1;
		}
		else {
			if (i >= 0 && i < a && Y <= 23 + a) {
				if (_COMMAND == 'W' && Y > _Y) {
					textcolor(496);
					GotoXY(X, Y);
					cout << A[i];
					MoveUpMenu();
					i--;
					textcolor(15);
					cout << A[i];
					textcolor(496);
				}
				else if (_COMMAND == 'S' && Y < _Y + a - 1) {
					textcolor(496);
					GotoXY(X, Y);
					cout << A[i];
					MoveDownMenu();
					i++;
					textcolor(15);
					cout << A[i];
					textcolor(496);
				}
				else if (_COMMAND == 13) {
					return i;
				}
			}
		}
	}
}
int MainMenu(int isLoad) {// a la tham so truyen vao, de so sanh voi so muc cua menu
	system("cls");
	DrawBigText();
	X = 55; Y = 23;
	int load = 0;
	int b = isLoad ? 1 : MoveAndChoose(DrawMenu(), menu, 55, 23);
	if (b == 0) {
		load = NewGame(Luat);
		MainMenu(load);
	}
	else if (b == 1) {
		system("cls");
		PrintText("CHON FILE GAME (ENTER DE CHON, ESC DE QUAY LAI):", 40, 4);
		X = 50; Y = 6;
		findex = ChooseOption(DrawLoadFile(), files);
		if (findex != -1)
			load = NewGame(Luat, LoadGame(files[findex]));
	}
	else if (b == 2) {
		system("cls");
		DrawBigText();
		X = 40; Y = 23;
		Luat = ChooseOption(DrawOption(), option);
	}
	else if (b == 3) {
		Credit();
		while (1) {
			if (toupper(_getch())) {
				break;
			}
		}
	}
	else if (b == 4) {
		LawGame();
		while (1) {
			if (toupper(_getch())) {
				break;
			}
		}
	}
	else if (b == 5) {
		ExitGame();
		exit(0);
		return 0;
	}
	MainMenu(load);
}
//
int DrawLoadFile() {
	ifstream listfiles("listFiles.txt"); //mở file để đọc
	int line = 0;
	listfiles >> line;
	textcolor(15);
	for (int i = 0; i < line; i++) {
		listfiles >> files[i];
		PrintText(files[i], X, Y + i);
		textcolor(496);
	}

	textcolor(496);

	listfiles.close();
	return line;
}

int DrawOption() {
	textcolor(15);
	PrintText(option[0], X, Y);
	textcolor(496);
	PrintText(option[1], X, Y + 1);
	return 2;
}

int ChooseOption(int a, string A[]) {
	return MoveAndChoose(a, A, X, Y);
}


// 
int Credit() {
	system("cls");
	PrintText("CREDIT", 57, 5);
	PrintText("=============== DO AN CARO ===============", 39, 6);
	PrintText("TRUONG DAI HOC KHOA HOC TU NHIEN", 43, 7);

	PrintText("==========  GIAO VIEN HUONG DAN ==========", 39, 12);
	PrintText("THAY TRUONG TOAN THINH", 48, 13);
	PrintText("THAY MAI ANH TUAN", 51, 14);
	PrintText("============  NHOM 22 - 20CTT3 ============", 39, 20);
	PrintText("18120445 - HOANG NGUYEN HAI LONG.", 46, 21);
	PrintText("20120442 - NGUYEN HUU CHINH.", 46, 22);
	PrintText("20120452 - DINH VIET DANH", 46, 23);
	PrintText("20120478 - NGUYEN VU HIEU", 46, 24);
	PrintText("20120489 - VO PHI HUNG", 46, 25);
	return 0;
}
//
int LawGame() {
	int x = 20;
	int y = 5;
	system("cls");
	PrintText(" =============================== HUONG DAN ================================", x, y);
	PrintText(" - Game su dung hai ki hieu 'X','O' de dai dien cho nuoc co cua nguoi choi.", x, ++y);
	PrintText(" - Su dung ban co kich thuoc 12x12.                                        ", x, ++y);
	PrintText(" - Tren mot ban co chi cho phep hai nguoi choi tham gia.                   ", x, ++y);
	PrintText(" - Trong muc menu su dung cac phim 'A', 'S', 'Enter' de di chuyen va chon. ", x, ++y);
	PrintText(" - Chon 'PLAY' de bat dau choi ngay.                                       ", x, ++y);
	PrintText(" - Nguoi choi su dung cac phim 'A' de di chuyen sang trai, 'D' de di chuyen", x, ++y);
	PrintText(" sang phai, 'S' de di chuyen xuong duoi va 'W' de di chuyen len tren.      ", x, ++y);
	PrintText(" - Khi dang choi nguoi choi co the luu game bang cach nhan phim 'L' va nhap", x, ++y);
	PrintText(" ten file can luu. Nguoi choi mo lai game da luu bang 2 cach: 'LOAD GAME'  ", x, ++y);
	PrintText(" hoac an phim 'T' va su dung nut 'A', 'S' de chon file.                    ", x, ++y);
	PrintText(" =============================== LUAT CHOI ================================", x, ++y);
	PrintText(" - Nguoi choi duoc phep chon luat cho trong muc 'OPTION' gom luat chan hai ", x, ++y);
	PrintText(" dau va khong choi luat chan hai dau.                                      ", x, ++y);
	PrintText(" - Hai nguoi choi  lan luot di chuyen va chon vao cac o chua duoc danh. Tro", x, ++y);
	PrintText(" choi duoc xem la ket  thuc khi mot trong hai  nguoi choi co 5 quan co lien", x, ++y);
	PrintText(" tiep nhau doi voi  luat khong chan hai dau hay co 5 quan co lien tiep nhau", x, ++y);
	PrintText(" va hai dau khong bi doi thu chan neu ap dung luat chan hai dau. Khi tat ca", x, ++y);
	PrintText(" cac o tren ban co deu kin ma chua ai chien thang thi game dau hoa nhau.   ", x, ++y);
	PrintText(" - Chuc cac ban choi game vui ve. An ESC de tro ve menu chinh...           ", x, ++y);
	return 0;
}