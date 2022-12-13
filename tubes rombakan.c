#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>

typedef struct {
   int skorTertinggi;
   int ronde;
   int modePermainan;
   int jumlahPemain;
   int syaratMenang;
   int menang;
   int papanTerisi;
   int pemainAktif;
   int namaTerisi;
   int batasWaktu;
   char tanda;
   char *pemenang;
} Game;
/* Tipe data Game */

typedef struct {
	char isiPapan[7][7];
} Papan;
/* Tipe data Papan */

typedef struct{ 
   char *nama;
   int skor;
} Pemain;
/* Tipe data Pemain */

Game game;
Papan papan;
Pemain pemain1;
Pemain pemain2;
int opsi; //variabel untuk memilih opsi yang ditampilkan
pthread_t timer_bariskolom; //Deklarasi thread
int stop_thread=0; 
int waktuHabis=0; 
int inProgram;
/* Deklarasi variabel global */

/*=======================================
             Header Modul*/

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

void tampilkanInputPemain();
/*menampilkan hasil tampilan input
*/

void tampilkanPapan();
/*untuk menampilkan papan yang telah diisi oleh para pemain dengan tanda yang sudah ditentukan
*/

void tampilkanOpsiCaraBermain();
/*Modul ini digunakan untuk menampilkan tampilan cara bermain ke layar
I.S : Belum menampilkan tampilan opsi cara bermain
F.S : Menampilkan tampilan opsi cara bermain dan penjelasan cara bermain dengan format :
        Penjelasan Cara bermain
       1...
       2...
       3...
       0. Kembali
*/

void tampilkanPemenang();
/*menampilkan pemenang
*/

void menuModePermainan();
//menampilkan menu mode permainan

void menuJumlahPemain();
//menampilkan menju jumlah Pemain

void mulaiPermainan();
//permainan tik tak toe di mulai

void menuPemenang();

void menuCaraBermain();

void nilaiAwal();
// Nilai awal dalam game

void isiPapan(char tanda);
//untuk mengisi papan dengan tanda

void *timer(void *arg);

void inputNamaPemain1();
//menginput nama pemain1

void inputNamaPemain2();
//menginput nama pemain2

void gantiGiliran();
//ganti giliran antara pemain1 dan pemain2 juga berubah tanda

void checkWin(int klm, int brs, int syrt);
//CHECKWIN
int checkWinHorizontal(int i, int j, int k);

int checkWinVertikal(int i, int j, int k);

int checkWinDiagonalKanan(int i, int j, int k);

int checkWinDiagonalKiri(int i, int j, int k);

void checkHighScore();

void papanKosong();
//mengosongkan papan

//tukar giliran
void tukarGiliranPertama();

void resetNamaPemain();

void inputOpsiMenu(int *inpt);
/* Modul ini untuk memasukan nilai ke dalam variabel opsi untuk yang di tampilkan di layar
I.S : Nilai variabel opsi belum terdefinisi
F.S : Nilai variabel opsi sudah terdefinisi
*/

void gotoxy(int x, int y);
//untuk mengatur posisi printf di cmd

int main() {
	do{
		game.namaTerisi = 0;
		game.ronde = 1;
		inProgram = 1;
	
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
				menuCaraBermain();
				break; 
			case 0:
				inProgram = 0;
				break;
			default:
				gotoxy(1, 26);printf("\nTidak Valid");
		}
	} while(inProgram == 1);
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
	gotoxy(40,19);printf("||                   Menu                ||");
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

void tampilkanInputPemain(Pemain pemain1, Pemain pemain2) {
	gotoxy(40,2);printf(" ========================================= ");
	gotoxy(40,3);printf("||              Nama Pemain              ||");
	gotoxy(40,4);printf(" =========================================");
	gotoxy(40,5);printf("                                          ");
	gotoxy(40,6);printf("                                           ");
	gotoxy(40,7);printf("               Pemain 1 : %s               ", &pemain1.nama);
	gotoxy(40,8);printf("                                           ");
	gotoxy(40,9);printf("               Pemain 2 : %s               ", &pemain2.nama);
	gotoxy(40,10);printf("                                           ");
	gotoxy(40,11);printf(" ========================================= ");
	gotoxy(40,12);printf("||              Nama Pemain              ||");
	gotoxy(40,13);printf(" ========================================= ");
}

void tampilkanPapan() {
	int i, j;
	int k, l;
	int ukuran = game.modePermainan;
	int geserKanan;
	
	
	gotoxy(43 + ukuran*3, 1);
	printf("Ronde %d",game.ronde);
	gotoxy(40 + ukuran*3, 3);
	if(game.pemainAktif == 1) printf("Giliran %s", &pemain1.nama);
	else printf("Giliran %s", &pemain2.nama);
	
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
		
	gotoxy(48 - ukuran, ukuran*3 + 6);printf("%s", &pemain1.nama);
	gotoxy(42 + ukuran*6 + ukuran/3, ukuran*3 + 6); printf("%s", &pemain2.nama);
	gotoxy(50-ukuran, ukuran*3 + 7);printf("%d", pemain1.skor);
	gotoxy(43+ukuran*6 + ukuran/3, ukuran*3 + 7);printf("%d", pemain2.skor);
	gotoxy(42 + ukuran*3 + ukuran, ukuran*3 + 8);printf("%d", game.skorTertinggi);
}

void tampilkanOpsiCaraBermain() {
	gotoxy(40,2);printf(" ===================================================================");
	gotoxy(40,3);printf("||                         Panduan Bermain                         ||");
	gotoxy(40,4);printf(" ===================================================================");
	gotoxy(40,5);printf("||                                                                 ||");
	gotoxy(40,6);printf("|| 1.Game dimulai dengan papan kosong berukuran 3x3, 5x5, atau 7x7 ||");
	gotoxy(40,7);printf("||   (tergantung pada variasi yang dipilih).                       ||");
	gotoxy(40,8);printf("|| 2.Pemain 1 dan pemain 2 bergantian menempatkan bidak mereka     ||");
	gotoxy(40,9);printf("||   (X atau O) pada papan, satu bidak per giliran dan akan diwaktu||");
	gotoxy(40,10);printf("||  selama 10 detik, jika melebihi maka akan diisi bidak secara    ||");
	gotoxy(40,11);printf("||  acak.                                                          ||");
	gotoxy(40,12);printf("|| 3.Bidak ditempatkan pada kotak kosong di papan.                 ||");
	gotoxy(40,13);printf("|| 4.Pemain yang berhasil menempatkan bidaknya secara berurutan    ||");
	gotoxy(40,14);printf("||   pada baris, kolom, atau diagonal papan menang (Untuk 3x3      ||");
	gotoxy(40,15);printf("||   3 bidak berurutan, untuk 5x5 4 bidak berurutan dan untuk 7x7  ||");
	gotoxy(40,16);printf("||   5 bidak berurutan).                                           ||");
	gotoxy(40,17);printf("|| 5.Jika tidak ada kotak kosong tersisa dan tidak ada pemain yang ||");
	gotoxy(40,18);printf("||   menang, game berakhir dengan hasil seri.                      ||");
	gotoxy(40,19);printf("|| 6.Pemain bisa melanjutkan permainan atau tidak.                 ||");
	gotoxy(40,20);printf("|| 7.Untuk setiap pergantian ronde, giliran akan ditukar antar     ||");
	gotoxy(40,21);printf("||   pemain.                                                       ||");
	gotoxy(40,22);printf("|| 8.Jika skor menang pemain lebih tinggi dari skor tertinggi yang ||");
	gotoxy(40,23);printf("||   sebelumnya, maka skor tertinggi akan digantikan.              ||");
	gotoxy(40,24);printf("||                                                                 ||");
	gotoxy(40,25);printf(" =================================================================== ");
	gotoxy(40,26);printf("||                         Panduan Bermain                         ||");
	gotoxy(40,27);printf(" =================================================================== ");
}

void tampilkanPemenang() {
	gotoxy(35, 2); printf(" ============================================================");
	gotoxy(57, 4); printf("%s menang", &game.pemenang);
	gotoxy(35, 6); printf(" ============================================================");
	gotoxy(54, 10); printf("Apakah ingin bermain lagi ?");
	gotoxy(62, 12); printf("1. Ya");
	gotoxy(62, 14); printf("2. Tidak");
	gotoxy(35, 18); printf(" ============================================================");
}

void menuModePermainan() {
	tampilkanOpsiModePermainan();
	inputOpsiMenu(&opsi);
	system("cls");
	switch(opsi) {
		case 1: 
			game.modePermainan = 3;
			mulaiPermainan();
			break;
		case 2:
			game.modePermainan = 5;
			 mulaiPermainan();
			break;
		case 3:
			game.modePermainan = 7;
			mulaiPermainan();
			break;
		case 0: 
			game.jumlahPemain = 0;
			menuJumlahPemain();
		default:
			gotoxy(1, 28);printf("\nTidak Valid");
			return menuModePermainan(); 
	} 
}

void menuJumlahPemain() {
	tampilkanOpsiJumlahPemain();
	inputOpsiMenu(&opsi);
	system("cls");
	switch(opsi) {
		case 1:
			game.jumlahPemain = 1;
			menuModePermainan();
			break;
		case 2:
			game.jumlahPemain = 2;
			menuModePermainan();
			break;
		case 0:
			main();
			break;
		default: 
			gotoxy(1, 28);printf("\nTidak Valid");
			menuJumlahPemain();
	}
}

void mulaiPermainan() {
	//inisial statenya tapi nanti dibuat modul
	nilaiAwal();
//	inputNamaPemain(pemain1, pemain2);
	if(game.namaTerisi == 0){
	tampilkanInputPemain(pemain1, pemain2);
   	gotoxy(1,14);inputNamaPemain1(&pemain1);
    tampilkanInputPemain(pemain1, pemain2);
    gotoxy(1,15);inputNamaPemain2(&pemain2);
    tampilkanInputPemain(pemain1, pemain2);
    game.namaTerisi = 1;
    sleep(1);
	}
    system("cls");
    
	tampilkanPapan();
	
	do {
	
		isiPapan(game.tanda);
		gantiGiliran();
		tampilkanPapan();
	} while(game.menang != 1 && game.papanTerisi < game.modePermainan * game.modePermainan);
	
	Sleep(2);
	system("cls");
	
	if(game.pemainAktif == 2) game.pemenang= pemain1.nama;
	else game.pemenang = pemain2.nama;
	
	menuPemenang();
}

void menuPemenang() {
	tampilkanPemenang();
	inputOpsiMenu(&opsi);
	system("cls");
	switch(opsi) {
		case 1: 
			tukarGiliranPertama();
			game.ronde++;
			mulaiPermainan();
			break;
		case 2:
			resetNamaPemain();
			main();
			break;
		default:
			printf("\nTidak Valid");
			menuPemenang();
	}
}

void menuCaraBermain() {
	tampilkanOpsiCaraBermain();
	inputOpsiMenu(&opsi);
	switch(opsi) {
		case 0: 
			main();
			break;
		default: 
			gotoxy(1, 29);printf("\nTidak valid");
			menuCaraBermain();
	};
}

void nilaiAwal() {
	game.syaratMenang = game.modePermainan - trunc(game.modePermainan/3.5);
	game.tanda = 'O';
	game.pemainAktif = 1;
	game.menang = 0;
	game.papanTerisi = 0;
	papanKosong();
} 

void isiPapan(char tanda) {
	int baris, kolom;
	int isValid,ukuran = game.modePermainan;                                  
	
	isValid = 0;
	game.batasWaktu = 10;
	
	
	do {
		stop_thread = 0;
		gotoxy(0, ukuran*3 + 9);                                  	
		printf("\nMasukan Baris & Kolom : ");	
		pthread_create(&timer_bariskolom, NULL, &timer, NULL);
		scanf("%d %d", &baris, &kolom);	
		stop_thread = 1;		
		pthread_join(timer_bariskolom,NULL);
		
		if (waktuHabis == 1 ) {
			baris = (rand() % (game.modePermainan - 1 + 1)) + 1;
			kolom = (rand() % (game.modePermainan - 1 + 1)) + 1;
		}
			if(isValid != 1 && papan.isiPapan[baris - 1][kolom-1] != 'X' && papan.isiPapan[baris-1][kolom-1] != 'O' && baris > 0 && baris <= game.modePermainan && kolom > 0 && kolom <= game.modePermainan) {
				system("cls");
				papan.isiPapan[baris - 1][kolom - 1] = tanda;
				game.papanTerisi++;
				checkWin(baris - 1, kolom - 1, game.syaratMenang);
				isValid = 1;
				}else {
				gotoxy(1, 24 + game.modePermainan);printf("\nTidak valid\n");
				}
	}while(isValid != 1);
}

void *timer(void *arg) {
  // Inisialisasi variabel
  int i=0,ukuran = game.modePermainan;
  
  while (game.batasWaktu >= 0 && stop_thread == 0) {
  if (i==0){
		gotoxy(0, ukuran*3 + 11); //12  
    	printf("Waktu Anda Tersisa[%d]: ", game.batasWaktu);		
		}else{
		gotoxy(0, ukuran*3 + 11);//12   
    	printf("Waktu Anda Tersisa[%d]: ", game.batasWaktu);
    	}
	sleep(1);
    game.batasWaktu--;
    i++;    	
	}
	if (stop_thread == 1){
		pthread_cancel(timer_bariskolom);
		return NULL;
		}else{
		waktuHabis = 1;
		gotoxy(0, ukuran*3 + 9);		
		printf("\nWaktu Anda sudah Habis!\nketik'0 0'untuk ganti giliran berikutnya!");
		return NULL;
		}
  }

void inputNamaPemain1(){
printf ("Nama pemain 1 = ");
scanf("%s", &pemain1.nama);
}

void inputNamaPemain2(){
printf ("Nama pemain 2 = ");
scanf("%s", &pemain2.nama);
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

void checkWin(int brs, int klm, int syrt) {
	int i = 0;
	do {
		if(game.menang != 1) game.menang = checkWinHorizontal(brs, 0 + i, syrt);
		if(game.menang != 1) game.menang = checkWinVertikal(0 + i, klm, syrt);
		if(game.menang != 1) game.menang = checkWinDiagonalKanan(brs + klm - i, 0 + i, syrt);
		if(game.menang != 1) game.menang = checkWinDiagonalKiri(brs - klm + i, 0 + i, syrt);
		i++;
//		scanf("%d", &test);
	} while (game.menang != 1 && syrt % 3 >= i);
	if(game.menang == 1) {
		if(game.pemainAktif == 1) pemain1.skor++;
		else pemain2.skor++;
		checkHighScore();
	}
}

int checkWinHorizontal(int i, int j, int k) {
	if(k == 0) return 1;
	else return (papan.isiPapan[i][j] == game.tanda && checkWinHorizontal(i, j + 1, k - 1));
}

int checkWinVertikal(int i, int j, int k) {
	if(k == 0) return 1;
	else return (papan.isiPapan[i][j] == game.tanda && checkWinVertikal(i + 1, j, k - 1));
}

int checkWinDiagonalKanan(int i, int j, int k) {
	if(k == 0) return 1;
	else return (papan.isiPapan[i][j] == game.tanda && checkWinDiagonalKanan(i - 1, j + 1, k - 1));
}

int checkWinDiagonalKiri(int i, int j, int k) {
	if(k == 0) return 1;
	else return (papan.isiPapan[i][j] == game.tanda && checkWinDiagonalKiri(i + 1, j + 1, k - 1));
}

void checkHighScore() {
	if(game.pemainAktif == 1) {
		if(game.skorTertinggi < pemain1.skor) game.skorTertinggi = pemain1.skor;
	} else {
		if(game.skorTertinggi < pemain2.skor) game.skorTertinggi = pemain2.skor;
	}
}

void papanKosong() {
	int i, j;
	for (i = 0; i < game.modePermainan;i++) {
		for(j = 0; j < game.modePermainan;j++) {
			papan.isiPapan[i][j] = NULL;
		}
	}
}

void tukarGiliranPertama() {
	int temp;
	
	temp = pemain1.nama;
	pemain1.nama = pemain2.nama;
	pemain2.nama = temp;
	
	pemain1.skor = pemain1.skor + pemain2.skor;
	pemain2.skor = pemain1.skor - pemain2.skor;
	pemain1.skor = pemain1.skor - pemain2.skor;
}

void resetNamaPemain(){
	pemain1.nama = NULL;
	pemain2.nama = NULL;
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
