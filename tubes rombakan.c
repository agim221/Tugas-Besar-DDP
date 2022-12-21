/* 
Program : TicTacToe.c
Version : 0.3.6.0
Deskripsi Program : Permainan Tic Tac Toe
Author : Ferdi.A.A, M.Agim, M.Fahri.Y.D.P
Tanggal : 20/12/2022
*/

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

inProgram = 1;

char opsi; //variabel untuk memilih opsi yang ditampilkan
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
/* Prosedur yang akan menampilkan pemenang dari game tersebut
I.S: belum menampilkan
F.S: menampilkan tampilan pemenang
*/

void tampilkanYakinKeluar();
/* Prosedur yang akan menampilkan yakin atau tidak nya user keluar dari game tersebut
I.S: belum menampilkan
F.S: menampilkan tampilan apakah yakin ingin keluar dari game
*/

void menuModePermainan();
/* Prosedur yang akan menampilkan tampilan menu mode permainan dan disuruh untuk memilih opsi tersebut
I.S: tampilan menu opsi mode permainan belum muncul dan kita belum disuruh memilih opsi tersebut.
F.S: tampilan menu opsi mode permainan muncul dan disuruh memilih opsi yang ada
*/

void menuJumlahPemain();
/* Prosedur yang akan menampilkan menu opsi jumlah pemain dan disuruh memasukan input
I.S: tampilan menu opsi jumlah pemain belum muncul dan belum disuruh memasukan input
F.S: menampilkan menu opsi jumlah pemain dan disuruh memasukan input untuk memilih opsi tersebut.
*/

void mulaiPermainan();
/* Prosedur ini adalah prosedur untuk memulai permainan
I.S: Permainan belum dimulai, papan belum ditampilkan, dan kita belum disuruh memasukan baris dan kolom untuk mengisi papan
F.S: Permainan sudah dimulai, papan sudah ditampilkan, dan kita disuruh memasukan baris dan kolom untuk mengisi papan
*/

void menuPemenang();
/* Menu pemenang ini akan menampilkan menu bagi pemain yang menang dan kita akan disuruh memasukan pilihan opsi apakah akan menalnjutkan permainan atau tidak, jika iya maka akan bermain lagi, jika tidak maka akan kembali ke main modul.
I.S: belum menampilkan pemenang
F.S: menampilkan pemenang
*/

void menuCaraBermain();
/* Modul ini digunakan untuk menampilkan Menu Cara Bermain
I.S : Belum menampilkan tampilan menu cara bermain dan belum disuruh memilih opsi
F.S : Menampilkan tampilan menu cara bermain dan disuruh memilih opsi
*/

void menuYakinKeluar();
/* Prosedur untuk meyakinkan kembali user untuk keluar dari program
I.S : Tampilan menuYakinKeluar belum muncul
F.S : Tampilan menuYakinKeluar muncul
*/

void nilaiAwal();
/* Prosedur ini adalah prosedur inisialisasi ketika game dimulai
I.S: variabel game.syaratMenang, game.tanda, game.pemainAktif, game.menang, game.papanTerisi kosong
F.S :  variabel game.syaratMenang, game.tanda, game.pemainAktif, game.menang, game.papanTerisi berisi nilai inisialisasi
*/

void isiPapan(char tanda);
/* Prosedur untuk memilih opsi-opsi ditampilan menu yang ada
I.S: nilai dari variabel opsi tak terdefinisi
F.S: nilai dari variabel opsi terdefinisi
*/

void *timer(void *arg);
/* Prosedur untuk menghitung mundur angka sebagai timer
IS : Tidak terdapat waktu pernghitung mundur 
FS : Terdapat waktu penghitung mundur
Prosedur ini berfungsi untuk membuat waktu penghitung mundur
*/

void inputNamaPemain1();
/* Prosedur yang berguna untuk memasukan nama ke dalam variabel pmn1.nama
I.S: Variabel pmn1.nama kosong
F.S variabel pmn1.nama terisi sesuai nama yang dimasukan
*/

void inputNamaPemain2();
/* Prosedur yang berguna untuk memasukan nama ke dalam variabel pmn2.nama
I.S: Variabel pmn2..nama kosong
F.S: Variabel pmn2.nama terisi sesuai nama yang dimasukan
*/

void gantiGiliran();
/* Prosedur untuk mengganti giliran pemain setelah mengisi papan
IS : Pemain pertama mendapat giliran pertama dengan simbol ‘O’ dan pemain kedua mendapat giliran kedua dengan simbol ‘X’. 
FS : Pemain pertama mendapat giliran menjadi giliran kedua dengan simbol pemain kedua dan berlaku untuk pemain kedua juga.
prosedur yang akan mengubah variabel tanda dari ‘O’ menjadi ‘X’ atau pun sebaliknya.
*/

void checkWin(int klm, int brs, int syrt);
/* Prosedur yang akan mengecek tanda sebanyak 3/4/5 kotak sesuai mode permainan
I.S: game.menang = 0
F.S: game.menang = 1
*/
	int checkWinHorizontal(int i, int j, int k);
/* Fungsi yang akan mengecek tanda secara horizontal dari kiri ke kanan sebanyak 3/4/5 kotak sesuai dengan persyaratan menang. 
Jika tandanya sama semua maka akan mengembalikan nilai 1 jika tidak maka akan mengembalikan nilai 0.
*/
	int checkWinVertikal(int i, int j, int k);
/* Fungsi yang akan mengecek tanda secara vertikal dari atas ke bawah sebanyak 3/4/5 kotak sesuai dengan persyaratan menang. 
Jika tandanya sama semua maka akan mengembalikan nilai 1 jika tidak maka akan mengembalikan nilai 0.
*/
	int checkWinDiagonalKanan(int i, int j, int k);
/* Fungsi yang akan mengecek tanda secara diagonal dari kiri bawah ke kanan atas sebanyak 3/4/5 kotak sesuai dengan persyaratan menang. 
Jika tandanya sama semua maka akan mengembalikan nilai 1 jika tidak maka akan mengembalikan nilai 0.
*/
	int checkWinDiagonalKiri(int i, int j, int k);
/* Fungsi yang akan mengecek tanda secara diagonal dari kiri atas ke kanan bawahsebanyak 3/4/5 kotak sesuai dengan persyaratan menang. 
Jika tandanya sama semua maka akan mengembalikan nilai 1 jika tidak maka akan mengembalikan nilai 0.
*/

void checkHighScore();
/* Fungsi yang akan mengecek high score yang ada jika nilai score sekarang lebih besar daripada high score sebelumnya maka 
high score tersebut akan diganti oleh score sekarang.*/

void papanKosong();
/* Prosedur untuk mengosongkan variabel papan.isiPapan
I.S : papan.isiPapan tidak kosong
F.S : papan.isiPapan kosong
*/

void tukarGiliranPertama();
/* Prosedur yang digunakan untuk menukar giliran pertama ketika bermain game tersebut dengan cara menukar nama dan poinnya juga
IS: pemain1.nama, pemain1.poin, pemain2.nama, pemain2.poin, belum ditukar
FS: pemain1.nama, pemain1.poin, pemain2.nama, pemain2.poin sudah ditukar
*/

void resetNamaPemain();
/* Prosedur yang berguna untuk mereset variabel pemain1.nama dan pemain2.nama = NULL
I.S: pemain1.nama dan pemain2.nama berisi nama
F.S: pemain1.nama dan pemain2.nama menjadi kosong
*/

void inputOpsiMenu(char *inpt);
/* Modul ini untuk memasukan nilai ke dalam variabel opsi untuk yang di tampilkan di layar
I.S : Nilai variabel opsi belum terdefinisi
F.S : Nilai variabel opsi sudah terdefinisi
*/

void gotoxy(int x, int y);
/* Prosedur untuk memindahkan posisi pointer printf di dalam cmd
I.S: Pointer printf tidak berpindah
F.S: Pointer printf berpindah
*/

void saveHighscore();
/* Prosedur untuk menyimpan highscore
I.S: Tidak menyimpan data skortertinggi
F.S: Menyimpan data skortertinggi
*/
void openHighscore();
/* Prosedur untuk mengaskses data highscore yang tersimpan
I.S : Belum mengaskes data highscore yang tersimpan
F.S : Mengakses data highscore yang tersimpan
*/

void prosesPermainan();

int main() {
	do{
		game.namaTerisi = 0;
		game.ronde = 1;
		
		do {
			tampilkanMenu();
			inputOpsiMenu(&opsi);
			system("cls");
			if(atoi(&opsi) == 0) {
				gotoxy(0, 30);printf("Mohon Pilih Opsi Menu yang Tersedia");
			}
		} while(atoi(&opsi) == 0);
		
		switch(atoi(&opsi)) {
			case 1:	//pemain masuk ke ui menu Jumlah Pemain
				menuJumlahPemain(); 
				game.skorTertinggi = 0;
				break;
			case 2: //pemain masuk ke ui menu lanjutkan bermain
				openHighscore();
				menuJumlahPemain();
				break;
			case 3: //pemain masuk ke ui panduan bermain
				menuCaraBermain();
				break; 
			case 99://pemain masuk ke ui keluar game
				menuYakinKeluar();
				break;
			default://pemain diminta masukkan lagi karena tidak sesuai dengan opsi yang ada
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
	gotoxy(40,24);printf("99. Keluar");
	//Algoritma menampilkan ui Menu awal kepada user
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
	gotoxy(40,16);printf("|||          99. Kembali                 |||");
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
	//Algoritma menampilkan ui pilihan jumlah pemain ke user
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
	gotoxy(40,18);printf("|||||          99.    Kembali          |||||");
	gotoxy(40,19);printf("||||||                               ||||||");
	gotoxy(40,20);printf("|||||||                             |||||||");
	gotoxy(40,21);printf("||||||||                           ||||||||");
	gotoxy(40,22);printf("|||||||||                         |||||||||");
	gotoxy(40,23);printf("||||||||||                       ||||||||||");
	gotoxy(40,24);printf(" ========================================= ");
	gotoxy(40,25);printf("||            Mode Permainan             ||");
	gotoxy(40,26);printf(" ========================================= ");
	//Algoritma menampilkan ui pilihan mode permainan ke user
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
	//Algoritma menampilkan ui input nama pemain ke user
}

void tampilkanPapan() {
	int i, j;
	int k, l;
	int ukuran = game.modePermainan;
	int geserKanan;
	//variabel i dan j menunjukkan baris dan kolom yang akan dibuat
	//variabel geser kanan adalah menggeser tampilan agar tidak bertabrakan
	
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
	gotoxy(46-ukuran, ukuran*3 + 7);printf("Skor: %d", pemain1.skor);
	gotoxy(40+ukuran*6 + ukuran/3, ukuran*3 + 7);printf("Skor: %d", pemain2.skor);
	gotoxy(33 + ukuran*3 + ukuran, ukuran*3 + 9);printf("Skor Tertinggi :%d", game.skorTertinggi);
}

void tampilkanOpsiCaraBermain() {
	gotoxy(40,0);printf(" ===================================================================");
	gotoxy(40,1);printf("||                         Panduan Bermain                         ||");
	gotoxy(40,2);printf(" ===================================================================");
	gotoxy(40,3);printf("||                                                                 ||");
	gotoxy(40,4);printf("|| 1.Game dimulai dengan papan kosong berukuran 3x3, 5x5, atau 7x7 ||");
	gotoxy(40,5);printf("||   (tergantung pada variasi yang dipilih).                       ||");
	gotoxy(40,6);printf("|| 2.Pemain pertama menginputkan baris dan kolom. Pemain 1 dan     ||");
	gotoxy(40,7);printf("||   pemain 2 bergantian menempatkan simbol mereka (X atau O) pada ||");
	gotoxy(40,8);printf("||   papan, satu simbol per giliran dan akan diwaktu selama 10     ||");
	gotoxy(40,9);printf("||   detik, jika melebihi maka akan diisi secara acak.             ||");
	gotoxy(40,10);printf("|| 3.Simbol ditempatkan pada kotak kosong di papan.                ||");
	gotoxy(40,11);printf("|| 4.Ketikkan angka sesuai dengan baris yang diinginkan, lalu      ||");
	gotoxy(40,12);printf("||   tekan enter                                                   ||");
	gotoxy(40,13);printf("|| 5.Ketikkan angka sesuai dengan kolom yang diinginkan, lalu      ||");
	gotoxy(40,14);printf("||   tekan enter                                                   ||");
	gotoxy(40,15);printf("|| 6.Pemain yang berhasil menempatkan simbolnya secara berurutan   ||");
	gotoxy(40,16);printf("||   pada baris, kolom, atau diagonal papan menang (Untuk 3x3      ||");
	gotoxy(40,17);printf("||   3 simbol berurutan, untuk 5x5 4 simbol berurutan dan untuk 7x7||");
	gotoxy(40,18);printf("||   5 simbol berurutan).                                          ||");
	gotoxy(40,19);printf("||                                                                 ||");
	gotoxy(40,20);printf("||                                                                 ||");
	gotoxy(40,21);printf("||                                                                 ||");
	gotoxy(40,22);printf("|| 99. Kembali                                                     ||");
	gotoxy(40,23);printf(" =================================================================== ");
	gotoxy(40,24);printf("||                         Panduan Bermain                         ||");
	gotoxy(40,25);printf(" =================================================================== ");
	//Algoritma menampilkan ui panduan bermain ke user
}

void tampilkanPemenang() {
	gotoxy(35, 2); printf(" ============================================================");
	gotoxy(57, 4); printf("%s menang", &game.pemenang);
	gotoxy(35, 6); printf(" ============================================================");
	gotoxy(54, 10); printf("Apakah ingin bermain lagi ?");
	gotoxy(62, 12); printf("1. Ya");
	gotoxy(62, 14); printf("2. Tidak");
	gotoxy(35, 18); printf(" ============================================================");
	//algoritma menampilkan apakah user ingin bermain lagi
}

void tampilkanYakinKeluar() {
	gotoxy(35, 2); printf(" ============================================================");
	gotoxy(35, 6); printf(" ============================================================");
	gotoxy(54, 10); printf("Apakah yakin ingin keluar ?");
	gotoxy(62, 12); printf("1. Ya");
	gotoxy(62, 14); printf("2. Tidak");
	gotoxy(35, 18); printf(" ============================================================");
	//algoritma menampilkan apakah user yakin ingin keluar
}

void menuModePermainan() {
	do{
		tampilkanOpsiModePermainan();
		//masuk ke ui pilihan mode permainan
		inputOpsiMenu(&opsi);
		system("cls");
		if(atoi(&opsi) == 0) {
			gotoxy(0, 30);printf("Mohon PIlih Opsi Menu yang Tersedia");
		}
	} while(atoi(&opsi) == 0);
	
	switch(atoi(&opsi)) {
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
		case 99: 
			game.jumlahPemain = 0;
			menuJumlahPemain();
		default:
			gotoxy(1, 28);printf("\nTidak Valid");
			return menuModePermainan(); 
	} 
}

void menuJumlahPemain() {
	do {
		tampilkanOpsiJumlahPemain();
		//masuk ke tampilan ui pilihan jumlah pemain
		inputOpsiMenu(&opsi);
		system("cls");
		if(atoi(&opsi) == 0) {
			gotoxy(0, 30);printf("Mohon Pilih Opsi Menu yang Tersedia");
		}
	} while (atoi(&opsi) == 0);
	
	switch(atoi(&opsi)) {
		case 1:
			game.jumlahPemain = 1;
			menuModePermainan();
			break;
		case 2:
			game.jumlahPemain = 2;
			menuModePermainan();
			break;
		case 99:
			main();
			break;
		default: 
			gotoxy(1, 28);printf("\nTidak Valid");
			menuJumlahPemain();
	}
}

void menuYakinKeluar(){
	do {
		tampilkanYakinKeluar();
		inputOpsiMenu(&opsi);
		system("cls");
		if(atoi(&opsi) == 0) {
			gotoxy(0, 30); printf("Mohon Pilih Opsi Menu yang Tersedia");
		}
	} while(atoi(&opsi) == 0);
	
	switch (atoi(&opsi))
	{
	case 1: inProgram = 0;
		break;
	
	case 2: main();
		break;
	default: 
		gotoxy(1, 26);printf("\nTidak Valid");
		menuYakinKeluar();
		break;
	}
}

void mulaiPermainan() {
	 nilaiAwal();
	//nilaiAwal() untuk mereset papan kedalam keadaan awal atau kosong
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
		prosesPermainan();	
	} while(game.menang != 1 && game.papanTerisi < game.modePermainan * game.modePermainan);
	
	Sleep(2);
	system("cls");
	
	if(game.pemainAktif == 2) game.pemenang= pemain1.nama;
	else game.pemenang = pemain2.nama;
	menuPemenang();
	//masuk ke ui Pemenang jika permainan sudah ditemukan pemenang atau seri
}

void menuPemenang() {
	do {
		tampilkanPemenang();
		inputOpsiMenu(&opsi);
		system("cls");
		if(atoi(&opsi) == 0) {
			gotoxy(0,30);printf("Mohon Pilih Opsi Menu yang Tersedia");
		}
	} while(atoi(&opsi) == 0);
	
	saveHighscore();
	//menyimpan highscore permainan
	switch(atoi(&opsi)) {
		case 1: 
			tukarGiliranPertama();
			game.ronde++;
			mulaiPermainan();
			break;
		case 2:
			resetNamaPemain();
			pemain1.skor=0;
			pemain2.skor=0;
			main();
			break;
		default:
			printf("\nTidak Valid");
			menuPemenang();
	}
}

void menuCaraBermain() {
	do {
		tampilkanOpsiCaraBermain();
		inputOpsiMenu(&opsi);
		system("cls");
		if(atoi(&opsi) == 0) {
			gotoxy(0, 30);printf("Mohon Pilih Opsi yang Tersedia");
		}
	} while(atoi(&opsi) == 0);
	
	switch(atoi(&opsi)) {
		case 99: 
			main();
			break;
		default: 
			gotoxy(1, 31);printf("Tidak valid");
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
	
	waktuHabis=0;
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
					if(papan.isiPapan[baris-1][kolom-1] == 'X' || papan.isiPapan[baris-1][kolom-1] == 'O') {
						gotoxy(0, 24 + game.modePermainan);
						printf("Kotak sudah terisi");
					} else if(baris > game.modePermainan || kolom > game.modePermainan) {
						gotoxy(0, 24 + game.modePermainan);
						printf("Berada di Luar Papan !");
					}
				}
	}while(isValid != 1);
}

void *timer(void *arg) {
  // Inisialisasi variabel
  int ukuran = game.modePermainan;
  
  while (game.batasWaktu >= 0 && stop_thread == 0) {
	gotoxy(1, ukuran*3 + 11);
    printf("Waktu Anda Tersisa[%d]: ", game.batasWaktu);
	sleep(1);
    game.batasWaktu--;	
	}
	if (stop_thread == 1){
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

void inputOpsiMenu(char *inpt) {
	printf("\n\nPilih Opsi Menu : ");
	scanf("%s", &(*inpt));
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void saveHighscore(){
	FILE *datasaveHS;
	
	datasaveHS = fopen("Highscore.dat","wb");
	fprintf(datasaveHS,"%d",game.skorTertinggi);
	fclose(datasaveHS);
}

void openHighscore(){
	FILE *dataopenHS;
	
	dataopenHS = fopen("Highscore.dat","rb");
	fscanf(dataopenHS,"%d",&game.skorTertinggi);
	fclose(dataopenHS);
}

void prosesPermainan() {
	isiPapan(game.tanda);
	gantiGiliran();	
	tampilkanPapan();
}
