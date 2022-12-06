#include<stdio.h>
#include<stdlib.h>

typedef struct {

} Player;

typedef struct {
	int skorTertinggi;
	int modePermainan;
	
} Game;

int opsi, jumlahPemain = 0, modePermainan = 0;

void inputOpsiMenu(int *inpt);
/*Memasukan nilai untuk memilih menu*/

int pilihOpsiJumlahPemain();

int pilihOpsiModePermainan();

int pilihOpsiPanduanBermain();

void tampilkanMenu();

void tampilkanOpsiJumlahPemain();

void tampilkanOpsiModePermainan();

void tampilkanOpsiPanduanBermain();

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
		case 3: pilihOpsiPanduanBermain();
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

void tampilkanOpsiPanduanBermain() {
	system("cls");
	printf("\n\n ========================================= ");
	printf("\n||            Panduan Bermain            ||");
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
	printf("\n||            Panduan Bermain            ||");
	printf("\n ========================================= ");
}

int pilihOpsiPanduanBermain() {
	 do {
	 	tampilkanOpsiPanduanBermain();
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
