#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>

typedef struct{ 
   char nama[99] = "test";
   int skor = 99;;
} Pemain;

struct {
   int skorTertinggi;
   int ronde;
   int modePermainan;
   int jumlahPemain;
   int syaratMenang;
   int menang;
   int papanTerisi;
   int pemainAktif = 1;
   char tanda = 'O';
} game;

struct {
	char isiPapan[7][7] = {" "};
} papan;

int opsi;

void gotoxy(int x, int y);

void inputOpsiMenu(int *inpt);
/* Modul ini untuk memasukan nilai ke dalam variabel opsi untuk yang di tampilkan di layar
I.S : Nilai variabel opsi belum terdefinisi
F.S : Nilai variabel opsi sudah terdefinisi
*/

int pilihOpsiJumlahPemain();
/* Modul ini berfungsi untuk memilih opsi yang ada, seperti untuk memilih menu yang ada, memilih jumlah pemain, 
apakah ingin melawan komputer atau pemain, untuk kembali ke menu sebelumnya, dan mengembalikan nilai jumlah 
*/

int pilihOpsiModePermainan();
/* Modul ini berguna untuk memilih opsi yang ada seperti untuk memilih menu yang ada,memilih mode permainan, 
apakah ingin bermain dengan papan 3x3, 5x5,7x7, untuk kembali ke menu sebelumnya, dan mengembalikan nilai mode permainan
*/

// int pilihOpsiPanduanBermain();
/* Modul ini berguna untuk memilih opsi yang ada dalam tampilan dan mengembalikan nilai cara bermain
*/

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
void tampilkanOpsiCaraBermain();
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

int checkWinHorizontalKanan(int i, int j, int k);
int checkWinHorizontalKiri(int i, int j, int k);
int checkWinVertikalAtas(int i, int j, int k);
int checkWinVertikalBawah(int i, int j, int k);

int main() {
	Pemain pemain1;
	Pemain pemain2;

	do {
		tampilkanMenu();
		inputOpsiMenu(&opsi);
		
		switch (opsi) {
		case 1:
			while(opsi != 0 && game.modePermainan == 0) {
			game.jumlahPemain = pilihOpsiJumlahPemain();
			if(opsi == 0) {
				opsi = 1;
				break;
			} else {
			game.modePermainan = pilihOpsiModePermainan();
			game.syaratMenang = game.modePermainan - trunc(game.modePermainan/3.5);
			printf("\n%d\n", game.syaratMenang);
			opsi = 2;
			}
		}
			break;
		case 2: /*lanjut game*/
			break;
		case 3: ;
			break;
		default:
			printf("\nMasukan tidak valid");
			}
		} while (opsi != 0 && game.jumlahPemain == 0 && game.modePermainan == 0);
		
		tampilkanPapan(pemain1, pemain2);
		do {
			isiPapan(game.tanda);
			gantiGiliran();
			tampilkanPapan(pemain1, pemain2);
		} while(game.menang != 1 && game.papanTerisi < game.modePermainan * game.modePermainan);	
		return 0;
}


void tampilkanMenu() {
	printf("\n\n ========================================= ");
	printf("\n|         ________   __     _____         |");
	printf("\n|        /__  ___/  / /   / ____/         |");
	printf("\n|          / /     / /   / /              |");
	printf("\n|         / /     / /   / /__             |");
	printf("\n|        /_/     /_/   /_____/            |");
	printf("\n|         ________   ____        _____    |");
	printf("\n|        /__  ___/  / _  |     / ____/    |");
	printf("\n|          / /     / /_| |    / /         |");
	printf("\n|         / /     /  __  |   / /__        |");
	printf("\n|        /_/     /_/   |_|  /_____/       |");
	printf("\n|         ________    ____ _    _____     |");
	printf("\n|        /__  ___/  / _ _  /  / ____/     |");
	printf("\n|          / /     / /  / /  / /___       |");
	printf("\n|         / /     / /__/ /  / /___        |");
	printf("\n|        /_/     /____ _/  /_____/        |");
	printf("\n===========================================");
	printf("\n                   Menu                    ");
	printf("\n===========================================");
	printf("\n1. Permainan Baru");
	printf("\n2. Lanjutkan Permainan");
	printf("\n3. Cara Bermain");
	printf("\n0. Keluar");
}

void tampilkanOpsiJumlahPemain() {
	system("cls");
	printf("\n\n ========================================= ");
	printf("\n||               Jumlah Pemain           ||");
	printf("\n =========================================");
	printf("\n|||||||||                         |||||||||");
	printf("\n||||||||                           ||||||||");
	printf("\n|||||||                             |||||||");
	printf("\n||||||                               ||||||");
	printf("\n|||||                                 |||||");
	printf("\n||||                                   ||||");
	printf("\n|||                                     |||");
	printf("\n|||          1. Lawan Komputer          |||");
	printf("\n|||                                     |||");
	printf("\n|||          2. Lawan Pemain            |||");
	printf("\n|||                                     |||");
	printf("\n|||          0. Kembali                 |||");
	printf("\n||||                                   ||||");
	printf("\n|||||                                 |||||");
	printf("\n||||||                               ||||||");
	printf("\n|||||||                             |||||||");
	printf("\n||||||||                           ||||||||");
	printf("\n|||||||||                         |||||||||");
	printf("\n||||||||||                       ||||||||||");
	printf("\n ========================================= ");
	printf("\n||               Jumlah Pemain           ||");
	printf("\n ========================================= ");
}

int pilihOpsiJumlahPemain() {
	do {
		tampilkanOpsiJumlahPemain();
		inputOpsiMenu(&opsi);
		switch(opsi) {
			case 1: return 1;
			break;
			case 2: return 2;
			break;
			default: printf("Masukan Tidak Valid");
		}
	} while(opsi != 0);
	game.modePermainan = 0;
	return 0;
}

void tampilkanOpsiModePermainan() {
	system("cls");
	printf("\n\n ========================================= ");
	printf("\n||            Mode Permainan             ||");
	printf("\n =========================================");
	printf("\n|||||||||                         |||||||||");
	printf("\n||||||||                           ||||||||");
	printf("\n|||||||                             |||||||");
	printf("\n||||||                               ||||||");
	printf("\n|||||                                 |||||");
	printf("\n||||                                   ||||");
	printf("\n|||                                     |||");
	printf("\n|||            1.    3 x 3              |||");
	printf("\n|||                                     |||");
	printf("\n|||            2.    5 x 5              |||");
	printf("\n|||                                     |||");
	printf("\n|||            3.    7 x 7              |||");
	printf("\n||||                                   ||||");
	printf("\n|||||          0.    Kembali          |||||");
	printf("\n||||||                               ||||||");
	printf("\n|||||||                             |||||||");
	printf("\n||||||||                           ||||||||");
	printf("\n|||||||||                         |||||||||");
	printf("\n||||||||||                       ||||||||||");
	printf("\n ========================================= ");
	printf("\n||               Jumlah Pemain           ||");
	printf("\n ========================================= ");
}

int pilihOpsiModePermainan() {
	do {
		tampilkanOpsiModePermainan();
		inputOpsiMenu(&opsi);
		switch(opsi) {
			case 1: return 3;
				break;
			case 2: return 5;
				break;
			case 3: return 7;
				break;
			default:
				printf("Masukan Tidak Valid");
			}
	} while(opsi != 0);
	return 0;
}

void tampilkanOpsiCaraBermain() {
	system("cls");
	printf("\n\n ========================================= ");
	printf("\n||            Cara Bermain               ||");
	printf("\n =========================================");
	printf("\n|||||||||__________________________|||||||||");
	printf("\n||||||||____________________________||||||||");
	printf("\n|||||||______________________________|||||||");
	printf("\n||||||________________________________||||||");
	printf("\n|||||                                 |||||");
	printf("\n||||                                   ||||");
	printf("\n|||                                     |||");
	printf("\n|||                                     |||");
	printf("\n|||                                     |||");
	printf("\n|||                                     |||");
	printf("\n|||                                     |||");
	printf("\n|||                                     |||");
	printf("\n||||                                   ||||");
	printf("\n|||||          0.    Kembali          |||||");
	printf("\n||||||                               ||||||");
	printf("\n|||||||_____________________________|||||||");
	printf("\n||||||||___________________________||||||||");
	printf("\n|||||||||_________________________|||||||||");
	printf("\n||||||||||_______________________||||||||||");
	printf("\n ========================================= ");
	printf("\n||            Cara Bermain               ||");
	printf("\n ========================================= ");
}

int pilihOpsiCaraBermain() {
	 do {
	 	tampilkanOpsiCaraBermain();
		inputOpsiMenu(&opsi);
		switch(opsi) {
			default:
				printf("Masukan Tidak Valid");
			}
	} while(opsi != 0);
	opsi = 1;
	return 0;
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
				printf("%c", papan.isiPapan[k][l++]);
			}
		}
		
		if(i % 3 == 2) k++;
		
	}
		
	gotoxy(45 - ukuran, ukuran*3 + 6);printf("%s", pmn1.nama);
	gotoxy(42 + ukuran*6 + ukuran/3, ukuran*3 + 6); printf("%s", pmn2.nama);
	gotoxy(47-ukuran, ukuran*3 + 7);printf("%d", pmn1.skor);
	gotoxy(44+ukuran*6 + ukuran/3, ukuran*3 + 7);printf("%d", pmn2.skor);
	gotoxy(42 + ukuran*3 + ukuran, ukuran*3 + 8);printf("%d", game.skorTertinggi);
}

void isiPapan(char tanda) {
	int baris, kolom;x
	
	printf("\nMasukan Baris : ");
	scanf("%d", &baris);
	printf("\nMasukan kolom : ");
	scanf("%d", &kolom);
		
	if(papan.isiPapan[baris - 1][kolom - 1] != 'X' && papan.isiPapan[baris][kolom] != 'O') {
		papan.isiPapan[baris - 1][kolom - 1] = tanda;
		if(game.menang != 1) game.menang = checkWinHorizontalKanan(baris - 1, kolom - 1, game.syaratMenang);
		printf("\ngame menang : %d\n", game.menang);
		game.papanTerisi++;
	} else {
		printf("\nTidak valid\n");
	}
}

void gantiGiliran() {
	if(game.pemainAktif == 1) {
				game.tanda = 'X';
				game.pemainAktif = 2;
		} else {
				game.tanda = 'O';
				game.pemainAktif = 1;
		}
}

int checkWinHorizontalKanan(int i, int j, int k) {
	if(k == 0) {
		return 1;
	} else {
	return (papan.isiPapan[i][j] == game.tanda && checkWinHorizontalKanan(i, j + 1, k - 1));
	}
}

int checkWinHorizontalKiri(int i, int j, int k) {
	if(k == 0) {
		return 1;
	} else {
	return (papan.isiPapan[i][j] == game.tanda && checkWinHorizontalKanan(i, j - 1, k - 1));
	}
}

int checkWinVertikalAtas(int i, int j, int k) {
	if(k == 0) {
		return 1;
	} else {
	return (papan.isiPapan[i][j] == game.tanda && checkWinHorizontalKanan(i - 1, j, k - 1));
	}
}

int checkWinVertikalBawah(int i, int j, int k) {
	if(k == 0) {
		return 1;
	} else {
	return (papan.isiPapan[i][j] == game.tanda && checkWinHorizontalKanan(i + 1, j, k - 1));
	}
}

