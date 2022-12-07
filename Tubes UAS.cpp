#include<stdio.h>
#include<stdlib.h>

typedef struct{ 
   Char *nama;
   Int skor;
   Char tandaGiliran;
}pemain


typedef struct {
   Int skorTertinggi;
   Int ronde;
   Int ukuranPapan;
   Int modePermainan;
   Int syaratMenang;
   Int menang;
   Int papanTerisi;
}game


int opsi, jumlahPemain = 0, modePermainan = 0;

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
/*

int pilihOpsiCaraBermain();
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
       1…..
       2…..
       3…..
       0. Kembali
*/
int main() {

	do {
		tampilkanMenu();
		inputOpsiMenu(&opsi);
		
		switch (opsi) {
		case 1:
			while(opsi != 0 && modePermainan == 0) {
			jumlahPemain = pilihOpsiJumlahPemain();
			if(opsi == 0) {
				opsi = 1;
				break;
			} else {
			modePermainan = pilihOpsiModePermainan();
			opsi = 1;
			}
		}
			break;
		case 2: /*lanjut game*/
			break;
		case 3: pilihOpsiCaraBermain();
			break;
		default:
			printf("\nMasukan tidak valid");
			}
		} while (opsi != 0 && jumlahPemain == 0 && modePermainan == 0);
		printf("\n\n %d %d %d \n\n", opsi, jumlahPemain, modePermainan);
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
	modePermainan = 0;
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
