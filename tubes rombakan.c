#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>


int test;
typedef struct{ 
   char nama[99];
   int skor;
} Pemain;

typedef struct {
   int skorTertinggi;
   int ronde;
   int modePermainan;
   int jumlahPemain;
   int syaratMenang;
   int menang;
   int papanTerisi;
   int pemainAktif;
   char tanda;
} Game;
Game game;

typedef struct {
	char isiPapan[7][7];
} Papan;
Papan papan;

int opsi;

int inProgram = 1;

void gotoxy(int x, int y);

void inputOpsiMenu(int *inpt);
/* Modul ini untuk memasukan nilai ke dalam variabel opsi untuk yang di tampilkan di layar
I.S : Nilai variabel opsi belum terdefinisi
F.S : Nilai variabel opsi sudah terdefinisi
*/

int menuJumlahPemain();

int menuModePermainan();

int mulaiPermainan();

void tampilkanMenu();
/* Modul ini digunakan untuk menampilkan Menu Utama
I.S : Belum menampilkan tampilan menu utama
F.S : Menampilkan tampilan menu utama dengan format :
             	Menu
	1. Mulai permainan
	2. Lanjutkan permainan
	3. Cara bermain
	0. Keluar
*/

void tampilkanOpsiJumlahPemain();
/* Modul ini digunakan untuk menampilkan tampilan menu jumlah pemain
I.S : Belum menampilkan tampilan menu jumlah pemain
F.S : Menampilkan tampilan menu jumlah pemain dengan format:
            Jumlah Pemain
	1. Lawan komputer
	2. Lawan pemain
	3. Kembali
*/

void tampilkanOpsiModePermainan();
/* Modul ini digunakan untuk menampilkan tampilan mode permainan pada layar
I.S : Belum menampilkan tampilan opsi mode permainan
F.S : menampilkan tampilan menu jumlah pemain dengan format :
	     Mode Permainan
         1. 3 x 3
         2. 5 x 5
         3. 7 x 7
         0. Kembali
*/
//void tampilkanOpsiCaraBermain();
/*Modul ini digunakan untuk menampilkan tampilan cara bermain ke layar
I.S : Belum menampilkan tampilan opsi cara bermain
F.S : Menampilkan tampilan opsi cara bermain dan penjelasan cara bermain dengan format :
        Penjelasan Cara bermain
       1?..
       2?..
       3?..
       0. Kembali
*/

void tampilkanPapan(Pemain pmn1, Pemain pmn2);

void isiPapan(char tanda);

void gantiGiliran();

void inputNamaPemain(Pemain *pmn1);
/*Modul ini berfungsi untuk menginputkan nama Pemain 1 dan Pemain 2
I.S = Nama pemain belum di inputkan
F.S = Nama pemain sudah di inputkan kedalam variabel pemain
*/

void inputNamaPemain2(Pemain *pmn2);

void tampilkanInputPemain(Pemain *pmn1, Pemain *pmn2);

int main() {
	do{
		tampilkanMenu();
		inputOpsiMenu(&opsi);
		system("cls");
		switch(opsi) {
			case 1: 
				menuJumlahPemain();
				break;
			case 2:
				
				break;
			case 3:
				break;
			case 0:
				inProgram = 0;
				break;
			default:
				gotoxy(1, 26);printf("\nTidak Valid");
		}
	} while(inProgram != 0);
		return 0;
}
 
void tampilkanMenu() {
	gotoxy(40,2);printf(" ========================================= ");
	gotoxy(40,3);printf("|         ________   __     _____         |");
	gotoxy(40,4);printf("|        /__  ___/  / /   / ____/         |");
	gotoxy(40,5);printf("|          / /     / /   / /              |");
	gotoxy(40,6);printf("|         / /     / /   / /__             |");
	gotoxy(40,7);printf("|        /_/     /_/   /_____/            |");
	gotoxy(40,8);printf("|         ________   ____        _____    |");
	gotoxy(40,9);printf("|        /__  ___/  / _  |     / ____/    |");
	gotoxy(40,10);printf("|          / /     / /_| |    / /         |");
	gotoxy(40,11);printf("|         / /     /  __  |   / /__        |");
	gotoxy(40,12);printf("|        /_/     /_/   |_|  /_____/       |");
	gotoxy(40,13);printf("|         ________    ____ _    _____     |");
	gotoxy(40,14);printf("|        /__  ___/  / _ _  /  / ____/     |");
	gotoxy(40,15);printf("|          / /     / /  / /  / /___       |");
	gotoxy(40,16);printf("|         / /     / /__/ /  / /___        |");
	gotoxy(40,17);printf("|        /_/     /____ _/  /_____/        |");
	gotoxy(40,18);printf("===========================================");
	gotoxy(40,19);printf("                   Menu                    ");
	gotoxy(40,20);printf("===========================================");
	gotoxy(40,21);printf("1. Permainan Baru");
	gotoxy(40,22);printf("2. Lanjutkan Permainan");
	gotoxy(40,23);printf("3. Cara Bermain");
	gotoxy(40,24);printf("0. Keluar");
}

void tampilkanOpsiJumlahPemain() {
	gotoxy(40,2);printf(" ========================================= ");
	gotoxy(40,3);printf("||               Jumlah Pemain           ||");
	gotoxy(40,4);printf(" =========================================");
	gotoxy(40,5);printf("|||||||||                         |||||||||");
	gotoxy(40,6);printf("||||||||                           ||||||||");
	gotoxy(40,7);printf("|||||||                             |||||||");
	gotoxy(40,8);printf("||||||                               ||||||");
	gotoxy(40,9);printf("|||||                                 |||||");
	gotoxy(40,10);printf("||||                                   ||||");
	gotoxy(40,11);printf("|||                                     |||");
	gotoxy(40,12);printf("|||          1. Lawan Komputer          |||");
	gotoxy(40,13);printf("|||                                     |||");
	gotoxy(40,14);printf("|||          2. Lawan Pemain            |||");
	gotoxy(40,15);printf("|||                                     |||");
	gotoxy(40,16);printf("|||          0. Kembali                 |||");
	gotoxy(40,17);printf("||||                                   ||||");
	gotoxy(40,18);printf("|||||                                 |||||");
	gotoxy(40,19);printf("||||||                               ||||||");
	gotoxy(40,20);printf("|||||||                             |||||||");
	gotoxy(40,21);printf("||||||||                           ||||||||");
	gotoxy(40,22);printf("|||||||||                         |||||||||");
	gotoxy(40,23);printf("||||||||||                       ||||||||||");
	gotoxy(40,24);printf(" ========================================= ");
	gotoxy(40,25);printf("||               Jumlah Pemain           ||");
	gotoxy(40,26);printf(" ========================================= ");
}


int menuJumlahPemain() {
	tampilkanOpsiJumlahPemain();
	inputOpsiMenu(&opsi);
	system("cls");
	switch(opsi) {
		case 1:
			game.jumlahPemain = 1;
			return menuModePermainan();
			break;
		case 2:
			game.jumlahPemain = 2;
			return menuModePermainan();
			break;
		case 0:
			return main();
			break;
		default: 
			gotoxy(1, 28);printf("\nTidak Valid");
			return menuJumlahPemain();
	}
}

void tampilkanOpsiModePermainan() {
	gotoxy(40,2);printf(" ========================================= ");
	gotoxy(40,3);printf("||            Mode Permainan             ||");
	gotoxy(40,4);printf(" =========================================");
	gotoxy(40,5);printf("|||||||||                         |||||||||");
	gotoxy(40,6);printf("||||||||                           ||||||||");
	gotoxy(40,7);printf("|||||||                             |||||||");
	gotoxy(40,8);printf("||||||                               ||||||");
	gotoxy(40,9);printf("|||||                                 |||||");
	gotoxy(40,10);printf("||||                                   ||||");
	gotoxy(40,11);printf("|||                                     |||");
	gotoxy(40,12);printf("|||            1.    3 x 3              |||");
	gotoxy(40,13);printf("|||                                     |||");
	gotoxy(40,14);printf("|||            2.    5 x 5              |||");
	gotoxy(40,15);printf("|||                                     |||");
	gotoxy(40,16);printf("|||            3.    7 x 7              |||");
	gotoxy(40,17);printf("||||                                   ||||");
	gotoxy(40,18);printf("|||||          0.    Kembali          |||||");
	gotoxy(40,19);printf("||||||                               ||||||");
	gotoxy(40,20);printf("|||||||                             |||||||");
	gotoxy(40,21);printf("||||||||                           ||||||||");
	gotoxy(40,22);printf("|||||||||                         |||||||||");
	gotoxy(40,23);printf("||||||||||                       ||||||||||");
	gotoxy(40,24);printf(" ========================================= ");
	gotoxy(40,25);printf("||               Jumlah Pemain           ||");
	gotoxy(40,26);printf(" ========================================= ");
}



int menuModePermainan() {
	tampilkanOpsiModePermainan();
	inputOpsiMenu(&opsi);
	system("cls");
	switch(opsi) {
		case 1: 
			game.modePermainan = 3;
			return mulaiPermainan();
			break;
		case 2:
			game.modePermainan = 5;
			return mulaiPermainan();
			break;
		case 3:
			game.modePermainan = 7;
			return mulaiPermainan();
			break;
		case 0: 
			game.jumlahPemain = 0;
			return menuJumlahPemain();
		default:
			gotoxy(1, 28);printf("\nTidak Valid");
			return menuModePermainan(); 
	} 
}

int mulaiPermainan() {
	Pemain pemain1;
	Pemain pemain2;
	
	game.syaratMenang = game.modePermainan - trunc(game.modePermainan/3.5);
	game.tanda = 'O';
	game.pemainAktif = '1';
	game.menang = 0;
    tampilkanInputPemain(&pemain1, &pemain2);
    gotoxy(1,14);inputNamaPemain1(&pemain1);
    tampilkanInputPemain(&pemain1, &pemain2);
    gotoxy(1,15);inputNamaPemain2(&pemain2);
    tampilkanInputPemain(&pemain1, &pemain2);
    sleep(1);
    system("cls");
	tampilkanPapan(pemain1, pemain2);
	
	do {
		isiPapan(game.tanda);
		gantiGiliran();
		tampilkanPapan(pemain1, pemain2);
	} while(game.menang != 1 && game.papanTerisi < game.modePermainan * game.modePermainan);
}



void inputOpsiMenu(int *inpt) {
	printf("\n\nPilih Opsi Menu : ");
	scanf("%d", &(*inpt));
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void tampilkanPapan(Pemain pmn1, Pemain pmn2) {
	int i, j;
	int k, l;
	int ukuran = game.modePermainan;
	int geserKanan;
	
	system("cls");
	gotoxy(42 + ukuran*3, 1);
	printf("Round 1");
	gotoxy(42 + ukuran*3, 3);
	printf("timer");
	
	k = 0;
	for(i = 0; i <= ukuran * 3 ; i++) {
		geserKanan = 0;
		l = 0;
		for(j = 0; j <= ukuran * 8; j++) {
			gotoxy(45 - ukuran + geserKanan,i+4);
			geserKanan++;
			if(j % 8 == 0) printf("|");
			if(i % 3 == 0) printf("_");
			if(i % 3 == 2 && j % 8 == 4) {
				printf("%c", papan.isiPapan[k][l]);
				l = l + 1;
			}
		}
		
		if(i % 3 == 0 && i != 0) k += 1;
		
	}
		
	gotoxy(45 - ukuran, ukuran*3 + 6);printf("%s", pmn1.nama);
	gotoxy(42 + ukuran*6 + ukuran/3, ukuran*3 + 6); printf("%s", pmn2.nama);
	gotoxy(47-ukuran, ukuran*3 + 7);printf("%d", pmn1.skor);
	gotoxy(44+ukuran*6 + ukuran/3, ukuran*3 + 7);printf("%d", pmn2.skor);
	gotoxy(42 + ukuran*3 + ukuran, ukuran*3 + 8);printf("%d", game.skorTertinggi);
}

void tampilkanInputPemain(Pemain *pmn1, Pemain *pmn2) {
	gotoxy(40,2);printf(" ========================================= ");
	gotoxy(40,3);printf("||              Nama Pemain              ||");
	gotoxy(40,4);printf(" =========================================");
	gotoxy(40,5);printf("                                          ");
	gotoxy(40,6);printf("                                           ");
	gotoxy(40,7);printf("               Pemain 1 : %s               ",pmn1->nama);
	gotoxy(40,8);printf("                                           ");
	gotoxy(40,9);printf("               Pemain 2 : %s               ",pmn2->nama);
	gotoxy(40,10);printf("                                           ");
	gotoxy(40,11);printf(" ========================================= ");
	gotoxy(40,12);printf("||              Nama Pemain              ||");
	gotoxy(40,13);printf(" ========================================= ");
}

void isiPapan(char tanda) {
	int baris, kolom;                                  
	printf("\nMasukan Baris : ");
	scanf("%d", &baris);
	printf("\nMasukan kolom : ");
	scanf("%d", &kolom);
		
	if(papan.isiPapan[baris - 1][kolom-1] != 'X' && papan.isiPapan[baris-1][kolom-1] != 'O') {
		papan.isiPapan[baris - 1][kolom - 1] = tanda;
		game.papanTerisi++;
	} else {
		printf("\nTidak valid\n");
	}
}

void gantiGiliran() {
	if(game.pemainAktif == 1) {
				game.tanda = 'O';
				game.pemainAktif = 2;
		} else {
				game.tanda = 'O';
				game.pemainAktif = 1;
		}
}

void inputNamaPemain1(Pemain *pmn1){
printf ("Nama pemain 1 = ");
scanf("%s",pmn1->nama);
}

void inputNamaPemain2(Pemain *pmn2){
printf ("Nama pemain 2 = ");
scanf("%s",pmn2->nama);
}
