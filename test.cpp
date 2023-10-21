#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define INF 99
using namespace std;

int nmr, total, input[10]; // variable umum

struct node // struct linked-list
{
    int nomorpem;
    int hargatotal;
    int hrgaaks;
    int hrgamdl;
    int hrgamrk;
    string merk;
    string model;
    string warna;
    string ukuran;
    string nama;
    string aksesoris;
    string alamat;
    string statusbyar;
    struct node *next;

} *front = NULL, *rear, *temp;

struct admin // struk untuk admin
{
    string username = "admin";
    string password = "admin";
};
admin adm;

struct user // struk untuk user
{
    string username = "user";
    string password = "user";
};
user usr;

void gotoxy(int x, int y) // fungsi go to x,y
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void headerMenu() // header menu
{
    system("CLS");
    cout << endl;
    cout << "                        ========================" << endl;
    cout << "                 ==========================================" << endl;
    cout << "      ==============================================================" << endl;
    cout << "=========================== DURIAN RUNTUH HELMET ========================= " << endl;
    cout << "             Jl. Indah Pada Waktunya No.2 Telp.(088)88899999" << endl;
    cout << "                Antapani, Karawang Barat, Jawa Barat 11530" << endl;
    cout << "===============================================================================" << endl;
    cout << "===============================================================================" << endl;
    cout << endl;
}

int menu() // menu user
{

    int input;

    headerMenu();
    cout << "                 =====================================" << endl;
    cout << "                               DAFTAR MENU            " << endl;
    cout << "                 =====================================" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "|1.|   Input Data Pembelian                                              |" << endl;
    cout << "|2.|   Hapus Data Pembelian                                              |" << endl;
    cout << "|3.|   Transaksi                                                         |" << endl;
    cout << "|4.|   Petunjuk / Panduan Rute                                           |" << endl;
    cout << "|5.|   Exit                                                              |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    cout << endl;
    do
    {
        cout << "> Masukan Pilihan : ";
        cin >> input;
        if (input <= 0 || input > 6)
        {
            cout << "Masukan Pilihan 1 - 6 " << endl;
        }
    } while (input <= 0 || input > 6);

    return input;
}

int menuAdmin() // menu admin
{

    system("cls");
    int input;
    cout << "                  =====================================" << endl;
    cout << "                              DAFTAR MENU ADMIN        " << endl;
    cout << "                  =====================================" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "|1.|   Tampil Daftar Pembelian                                           |" << endl;
    cout << "|2.|   Mencari Data pembelian                                            |" << endl;
    cout << "|3.|   Exit                                                              |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    cout << endl;

    cout << "> Input Pilihan \t: ";
    cin >> input;

    return input;
}

int login() // fungsi login
{

    string username, password;

    system("cls");

    cout << "=============================[ LOGIN ]=============================\n\n";
    cout << "\t\t\tUsername : ";
    cin >> username;
    cout << endl;
    cout << "\t\t\tPassword : ";
    cin >> password;

    if (username == adm.username && password == adm.password)
    {
        return 1;
    }
    else if (username == usr.username && password == usr.password)
    {
        return 2;
    }
    else
    {
        cout << "Username Atau Password Salah!" << endl;
        return 0;
    }
}

void insert() // menu pembelian - input barang oleh user
{
    system("cls");
    temp = new node;
    string mrk;
    string mdl;
    string wrn;
    string ukr;
    string nm;
    string aks;
    string alamat;

    // untuk membuat tampilan table agar lebih rapih
    gotoxy(20, 1);
    cout << "               <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n";
    gotoxy(35, 2);
    cout << "                                              DURIAH RUNTUH HELMET\n";
    gotoxy(50, 3);
    cout << "               Jl. Indah Pada Waktunya, No.2, Telp. (088)88899999\n";
    gotoxy(20, 4);
    cout << "               <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
    gotoxy(35, 6);
    cout << "                                               | PEMBELIAN HELM |";
    gotoxy(25, 8);
    cout << "        > Masukkan kode Pembelian\n";
    gotoxy(25, 9);
    cout << "        > Contoh : 01\n";
    gotoxy(25, 10);
    cout << "        > Masukkan Nama Barang sesuai dengan Display Barang !";
    gotoxy(20, 11);
    cout << "============================================================================================================================================================\n";
    gotoxy(20, 12);
    cout << "|Kode | Merk Helm         || Harga Merk       ||  Model Helm      ||   Harga Model   || Warna        || Ukuran     || Aksesoris Helm    || Harga Aksesoris |\n";
    gotoxy(20, 13);
    cout << "============================================================================================================================================================\n";
    gotoxy(20, 14);
    cout << "|  1  | KYT               || Rp.100.000,00    || FULL FACE        || RP. 50.000,00   || Merah        || S          || Visor             || Rp.300.000,00   |\n";
    gotoxy(20, 15);
    cout << "|  2  | TRX               || Rp.150.000,00    || OPEN FACE        || RP. 40.000,00   || Hijau        || M          || Balaclava         || Rp.60.000,00    |\n";
    gotoxy(20, 16);
    cout << "|  3  | SHARK             || Rp.170.000,00    || HALF FACE        || RP. 45.000,00   || Kuning       || L          || Spoiler           || Rp.50.000,00    |\n";
    gotoxy(20, 17);
    cout << "|  4  | INK               || Rp.155.000,00    || FLIP UP          || RP. 70.000,00   || Biru         || XL         || Intercom          || Rp.500.000,00   |\n";
    gotoxy(20, 18);
    cout << "|  5  | SHOEI             || Rp.200.000,00    || OFFROAD          || RP. 65.000,00   || Hitam        ||            || Go Pro            || Rp.3.000.000,00 |\n";
    gotoxy(20, 19);
    cout << "|  6  | NOLAN             || Rp.200.000,00    || DUAL SPORT       || RP. 55.000,00   || Abu-Abu      ||            || Antifog           || Rp.100.000,00   |\n";
    gotoxy(20, 20);
    cout << "|  7  | CARGLOSS          || Rp.135.000,00    ||                  ||                 ||              ||            || Tear Off          || Rp.55.000,00    |\n";
    gotoxy(20, 21);
    cout << "|  8  | KBC               || Rp.120.000,00    ||                  ||                 ||              ||            || Stiker            || Rp.10.000,00    |\n";
    gotoxy(20, 22);
    cout << "|  9  | ARAI              || Rp.500.000,00    ||                  ||                 ||              ||            ||                                      |\n";
    gotoxy(20, 23);
    cout << "============================================================================================================================================================\n";
    gotoxy(1, 24);

    cout << endl;

    // Inputan pembelian User
    cout << "== INPUT PEMBELIAN ==\n\n";
    cout << "Input No. Pesanan\t: "; // ex. 01
    cin >> nmr;
    cin.ignore(1, '\n');
    cout << "Input Merk\t\t: ";
    getline(cin, mrk);
    cout << "Input Model\t\t: ";
    getline(cin, mdl);
    cout << "Input Warna\t\t: ";
    getline(cin, wrn);
    cout << "Input Ukuran\t\t: ";
    getline(cin, ukr);
    cout << "Input Nama\t\t: ";
    getline(cin, nm);
    cout << "Input Alamat\t\t: ";
    getline(cin, alamat);
    cout << "Input Aksesoris\t\t: ";
    getline(cin, aks);
    cout << endl;
    system("pause");

    // alokasi memori
    temp->nomorpem = nmr;
    temp->merk = mrk;
    temp->model = mdl;
    temp->warna = wrn;
    temp->ukuran = ukr;
    temp->nama = nm;
    temp->aksesoris = aks;

    temp->next = NULL;

    if (front == NULL)
        front = rear = temp;

    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void del() // fungsi untuk menghapus data
{
    if (front == NULL)
    {
        cout << "Belum ada Pesanan!\n";
        getch();
    }
    else
    {
        temp = front;
        front = front->next;
        cout << "No. Pembelian " << temp->nomorpem << " Telah DIhapus beserta Datanya\n";
        delete (temp);
        cout << endl;
        system("pause");
    }
}

int displayAdmin() // fungsi untuk menampilkan data yang sudah di inputkan sebelumnya
{
    system("cls");

    int total, hrgaaks, hrgamdl, hrgamrk;
    char yn;
    if (front == NULL)
    {
        cout << "Belum ada data Pembelian!\n";
        getch;
    }

    else
    {
        temp = front;
        while (temp != NULL)
        {
            cout << endl;
            cout << "\t\t DATA PEMBELIAN \t\t" << endl;
            cout << endl;
            cout << "No. Pembelian\t: " << temp->nomorpem << endl;
            cout << "Nama\t\t: " << temp->nama << endl;
            cout << "Merk Helm\t: " << temp->merk << endl;

            // kondisi untuk menentukan harga pada merk helm
            if ((temp->merk == "KYT") || (temp->merk == "kyt"))
            {

                hrgamrk = 100000;
            }
            else if ((temp->merk == "TRX") || (temp->merk == "trx"))
            {

                hrgamrk = 150000;
            }
            else if ((temp->merk == "SHARK") || (temp->merk == "shark"))
            {

                hrgamrk = 170000;
            }
            else if ((temp->merk == "INK") || (temp->merk == "ink"))
            {

                hrgamrk = 155000;
            }
            else if ((temp->merk == "SHOEI") || (temp->merk == "shoei"))
            {

                hrgamrk = 200000;
            }
            else if ((temp->merk == "NOLAN") || (temp->merk == "nolan"))
            {

                hrgamrk = 200000;
            }
            else if ((temp->merk == "CARGLOSS") || (temp->merk == "cargloss"))
            {

                hrgamrk = 135000;
            }
            else if ((temp->merk == "KBC") || (temp->merk == "kbc"))
            {

                hrgamrk = 120000;
            }
            else if ((temp->merk == "ARAI") || (temp->merk == "arai"))
            {

                hrgamrk = 500000;
            }

            cout << "Model Helm\t: " << temp->model << endl;

            // kondisi untuk menentukan harga model helm
            if ((temp->model == "FULL FACE") || (temp->model == "full face"))
            {
                hrgamdl = 50000;
            }
            else if ((temp->model == "OPEN FACE") || (temp->model == "open face"))
            {
                hrgamdl = 40000;
            }
            else if ((temp->model == "HALF FACE") || (temp->model == "half face"))
            {
                hrgamdl = 45000;
            }
            else if ((temp->model == "FLIP UP") || (temp->model == "flip up"))
            {
                hrgamdl = 70000;
            }
            else if ((temp->model == "OFFROAD") || (temp->model == "offroad"))
            {
                hrgamdl = 65000;
            }
            else if ((temp->model == "DUAL SPORT") || (temp->model == "dual sport"))
            {
                hrgamdl = 55000;
            }

            cout << "Warna Helm\t: " << temp->warna << endl;
            cout << "Ukuran Helm\t: " << temp->ukuran << endl;
            cout << "Aksesoris\t: " << temp->aksesoris << endl;
            // kondisi untuk menentukan harga aksesoris helm
            if ((temp->aksesoris == "VISOR") || (temp->aksesoris == "visor"))
            {
                hrgaaks = 300000;
            }
            else if ((temp->aksesoris == "BALACLAVA") || (temp->aksesoris == "balaclava"))
            {
                hrgaaks = 60000;
            }
            else if ((temp->aksesoris == "SPOILER") || (temp->aksesoris == "spoiler"))
            {
                hrgaaks = 50000;
            }
            else if ((temp->aksesoris == "INTERCOM") || (temp->aksesoris == "intercom"))
            {
                hrgaaks = 500000;
            }
            else if ((temp->aksesoris == "GO PRO") || (temp->aksesoris == "go pro"))
            {
                hrgaaks = 3000000;
            }
            else if ((temp->aksesoris == "ANTIFOG") || (temp->aksesoris == "antifog"))
            {
                hrgaaks = 100000;
            }
            else if ((temp->aksesoris == "TEAR OFF") || (temp->aksesoris == "tear off"))
            {
                hrgaaks = 55000;
            }
            else if ((temp->aksesoris == "STIKER") || (temp->aksesoris == "sticker"))
            {
                hrgaaks = 10000;
            }
            else if ((temp->aksesoris == "NULL") || (temp->aksesoris == "-"))
            {
                hrgaaks = 0;
            }

            cout << "------------------------------------------" << endl;

            total = hrgamrk + hrgamdl + hrgaaks; // deklasri fungsi untuk menghitung total harga dari model, merk dan aksesoris

            temp->hargatotal = total;

            cout << "Total Harga : Rp. " << total << endl;
            cout << endl;
            cout << temp->statusbyar << endl;

            temp = temp->next;
        }
    }
    cout << endl;
    system("pause");
}

int display() // fungsi untuk menampilkan data yang sudah di inputkan sebelumnya
{
    system("cls");

    int total, hrgaaks, hrgamdl, hrgamrk;
    char yn;
    if (front == NULL)
    {
        cout << "Belum ada data Pembelian!\n";
        getch;
    }

    else
    {
        temp = front;
        while (temp != NULL)
        {
            cout << endl;
            cout << "\t\t DATA PEMBELIAN \t\t" << endl;
            cout << endl;
            cout << "No. Pembelian\t: " << temp->nomorpem << endl;
            cout << "Nama\t\t: " << temp->nama << endl;
            cout << "Merk Helm\t: " << temp->merk << endl;

            // kondisi untuk menentukan harga pada merk helm
            if ((temp->merk == "KYT") || (temp->merk == "kyt"))
            {

                hrgamrk = 100000;
            }
            else if ((temp->merk == "TRX") || (temp->merk == "trx"))
            {

                hrgamrk = 150000;
            }
            else if ((temp->merk == "SHARK") || (temp->merk == "shark"))
            {

                hrgamrk = 170000;
            }
            else if ((temp->merk == "INK") || (temp->merk == "ink"))
            {

                hrgamrk = 155000;
            }
            else if ((temp->merk == "SHOEI") || (temp->merk == "shoei"))
            {

                hrgamrk = 200000;
            }
            else if ((temp->merk == "NOLAN") || (temp->merk == "nolan"))
            {

                hrgamrk = 200000;
            }
            else if ((temp->merk == "CARGLOSS") || (temp->merk == "cargloss"))
            {

                hrgamrk = 135000;
            }
            else if ((temp->merk == "KBC") || (temp->merk == "kbc"))
            {

                hrgamrk = 120000;
            }
            else if ((temp->merk == "ARAI") || (temp->merk == "arai"))
            {

                hrgamrk = 500000;
            }

            cout << "Model Helm\t: " << temp->model << endl;

            // kondisi untuk menentukan harga model helm
            if ((temp->model == "FULL FACE") || (temp->model == "full face"))
            {
                hrgamdl = 50000;
            }
            else if ((temp->model == "OPEN FACE") || (temp->model == "open face"))
            {
                hrgamdl = 40000;
            }
            else if ((temp->model == "HALF FACE") || (temp->model == "half face"))
            {
                hrgamdl = 45000;
            }
            else if ((temp->model == "FLIP UP") || (temp->model == "flip up"))
            {
                hrgamdl = 70000;
            }
            else if ((temp->model == "OFFROAD") || (temp->model == "offroad"))
            {
                hrgamdl = 65000;
            }
            else if ((temp->model == "DUAL SPORT") || (temp->model == "dual sport"))
            {
                hrgamdl = 55000;
            }

            cout << "Warna Helm\t: " << temp->warna << endl;
            cout << "Ukuran Helm\t: " << temp->ukuran << endl;
            cout << "Aksesoris\t: " << temp->aksesoris << endl;
            // kondisi untuk menentukan harga aksesoris helm
            if ((temp->aksesoris == "VISOR") || (temp->aksesoris == "visor"))
            {
                hrgaaks = 300000;
            }
            else if ((temp->aksesoris == "BALACLAVA") || (temp->aksesoris == "balaclava"))
            {
                hrgaaks = 60000;
            }
            else if ((temp->aksesoris == "SPOILER") || (temp->aksesoris == "spoiler"))
            {
                hrgaaks = 50000;
            }
            else if ((temp->aksesoris == "INTERCOM") || (temp->aksesoris == "intercom"))
            {
                hrgaaks = 500000;
            }
            else if ((temp->aksesoris == "GO PRO") || (temp->aksesoris == "go pro"))
            {
                hrgaaks = 3000000;
            }
            else if ((temp->aksesoris == "ANTIFOG") || (temp->aksesoris == "antifog"))
            {
                hrgaaks = 100000;
            }
            else if ((temp->aksesoris == "TEAR OFF") || (temp->aksesoris == "tear off"))
            {
                hrgaaks = 55000;
            }
            else if ((temp->aksesoris == "STIKER") || (temp->aksesoris == "sticker"))
            {
                hrgaaks = 10000;
            }
            else if ((temp->aksesoris == "NULL") || (temp->aksesoris == "-"))
            {
                hrgaaks = 0;
            }

            cout << "------------------------------------------" << endl;

            total = hrgamrk + hrgamdl + hrgaaks; // deklasri fungsi untuk menghitung total harga dari model, merk dan aksesoris

            temp->hargatotal = total;

            cout << "Total Harga : Rp. " << total << endl;

            temp = temp->next;
        }

        getch();
    }
    cout << endl;
    cout << "Ingin melanjutkan ke pembayaran (y/n) ? ";
    cin >> yn;
    cout << endl;
    return yn;
}

int transaksi() // fungsi transaksi
{

    system("cls");

    int bayar, kembalian;
    string status;
    char lanjutTransaksi;
    if (front == NULL)
    {
        cout << "Belum ada data Pembelian!\n";
        getch;
    }

    else
    {
        lanjutTransaksi = display();
        cout << endl;

        if (lanjutTransaksi == 'Y' || lanjutTransaksi == 'y')
        {
        BAYAR:
            temp = front;
            while (temp != NULL)
            {
                cout << endl;
                cout << "\t\t TRANSAKSI PEMBAYARAN \t\t" << endl;
                cout << endl;
                cout << "No. Pembelian\t: " << temp->nomorpem << endl;
                cout << "Nama\t\t: " << temp->nama << endl;
                cout << "------------------------------------------" << endl;
                cout << "Harga Total\t: Rp. " << temp->hargatotal << endl;
                cout << "Pembayaran\t: Rp. ";
                cin >> bayar;
                cout << "------------------------------------------" << endl;
                kembalian = bayar - temp->hargatotal;
                if (bayar < temp->hargatotal)
                {
                    cout << "Silahkan Masukan Nominal Pembayaran Sesuai dengan Total Harga" << endl;
                    cout << "Pembayaran kurang : Rp. " << temp->hargatotal - bayar << endl;
                    getch();
                    system("cls");
                    goto BAYAR;
                }
                else if (kembalian != 0)
                {
                    cout << "Kembalian      : Rp. " << kembalian;
                }
                else if (kembalian == 0)
                {
                    cout << "Kembalian      : Rp. 0";
                    cout << endl;
                }

                status = "Sudah di Bayar";
                temp->statusbyar = status;
                temp = temp->next;
            }
        }
        else if (lanjutTransaksi == 'n' || lanjutTransaksi == 'N')
        {
            return 2;
            status = "Belum di Bayar";
            temp->statusbyar = status;
        }
    }
    cout << endl;
    system("pause");
}

void search() // fungsi untuk mencari data
{
    system("cls");
    node *temp;
    temp = front;
    int cari;
    int ketemu = 0;
    if (front != NULL)
    {
        cout << "\n Input No. Pembelian yang dicari\t: ";
        cin >> cari;

        while (temp != NULL)
        {
            temp->nomorpem;
            if (cari == temp->nomorpem)
            {
                cout << "\n\n == Data Ditemukan ==\n\n";
                cout << "Merk Helm\t: " << temp->merk << endl;
                cout << "Model Helm\t: " << temp->model << endl;
                cout << "Warna Helm\t: " << temp->warna << endl;
                cout << "Ukuran Helm\t: " << temp->ukuran << endl;
                cout << "Aksesoris\t: " << temp->aksesoris << endl;
                cout << "Nama\t\t: " << temp->nama << endl;
                cout << "-------------------------------------" << endl;
                cout << endl;
                cout << temp->statusbyar;
                cout << "\n\n";
                ketemu = 1;
            }
            temp = temp->next;
        }

        if (ketemu == 0)
        {
            cout << "Data tidak Ditemukan";
        }
    }
    else
        cout << "Belum ada Pesanan!";
    cout << endl;
    system("pause");
}

void headerMap()
{
    system("cls");

    headerMenu();
    cout << endl;
    cout << "==============================================================================" << endl;
    cout << "                          Peta Panduan Khusus Daerah Bandung" << endl;
    cout << "            Mencari Rute Tercepat Menuju Perpustakaan Duriah Runtuh" << endl;
    cout << "==============================================================================" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|1. Antapni" << endl;
    cout << "|2. Trans Studi Mall" << endl;
    cout << "|3. Bandung Indah Plaza" << endl;
    cout << "|4. Paskal" << endl;
    cout << "|5. Dago" << endl;
    cout << "|6. Margahayu" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
}

int jarakMinimum(int jarak[], bool set[])
{
    int kecil = INF;
    int index;

    for (int i = 0; i < 7; i++)
    {
        if (set[i] == false && jarak[i] <= kecil)
        {
            kecil = jarak[i];
            index = i;
        }
    }
    return index;
}

void cetakRute(int simpan[], int j, int awal)
{
    string keteranganDaerah;
    if (j == 1)
    {
        keteranganDaerah = "Antapani";
    }
    else if (j == 2)
    {
        keteranganDaerah = "Trans Studi Mall";
    }
    else if (j == 3)
    {
        keteranganDaerah = "Bandung Indah Plaza";
    }
    else if (j == 4)
    {
        keteranganDaerah = "Paskal";
    }
    else if (j == 5)
    {
        keteranganDaerah = "Dago";
    }
    else if (j == 6)
    {
        keteranganDaerah = "Margahayu";
    }

    if (simpan[j] == -1)
    {
        return;
    }
    else
    {
        cetakRute(simpan, simpan[j], awal);
        if (j == 0)
        {
            cout << "Kemudian lanjutkan menuju Cibiru" << endl;
            cout << "Lalu lanjutkan perjalanan hingga sampai di Durian Runtuh Helmet" << endl;
        }
        else
        {
            cout << "Lanjutkan Perjalanan menuju " << keteranganDaerah << endl;
        }
    }
}

int tampilkanRute(int jarak[], int n, int simpan[], int awal)
{
    string keterangan;
    for (int i = 0; i < 7; i++)
    {
        if (i == 0)
        {
            cout << endl;
            if (awal == 1)
            {
                keterangan = "Antapani";
            }
            else if (awal == 2)
            {
                keterangan = "Trans Studi Mall";
            }
            else if (awal == 3)
            {
                keterangan = "Bandung Indah Plaza";
            }
            else if (awal == 4)
            {
                keterangan = "Paskal";
            }
            else if (awal == 5)
            {
                keterangan = "Dago";
            }
            else if (awal == 6)
            {
                keterangan = "Margahayu";
            }

            cout << "Mulai Dari " << keterangan << endl;
            cetakRute(simpan, i, awal);
            cout << endl;
            cout << "\"Stay Safe, Stay healty and Stay With Me\" " << endl;
            cout << endl;

            cout << "---------------------------------" << endl;
            cout << "Total Jarak yang ditempuh : " << jarak[i] << "km" << endl;
            cout << "---------------------------------" << endl;
            cout << endl;
        }
    }
}

int dijkstra(int graf[7][7], int awal)
{
    int jarak[7];
    bool set[7];
    int simpan[7];

    for (int i = 0; i < 7; i++)
    {
        jarak[i] = INF;
        set[i] = false;
        simpan[i] = -1;
    }

    jarak[awal] = 0;

    for (int i = 0; i < 7; i++)
    {
        int m = jarakMinimum(jarak, set);
        set[m] = true;

        for (int i = 0; i < 7; i++)
        {
            if (!set[i] && graf[m][i] && jarak[m] + graf[m][i] < jarak[i])
            {
                simpan[i] = m;
                jarak[i] = jarak[m] + graf[m][i];
            }
        }
    }
    tampilkanRute(jarak, 7, simpan, awal);
}

int main() // fungsi utama
{
    while (true)
    {
        string username, password;
        int nmr, rolePengguna;

        int graf[7][7] = {
            // nilai 0
            // matriks G = [v,e]
            {0, 4, 0, 5, 0, 0, 0}, // Durian Runtuh Helmet
            {4, 0, 1, 0, 4, 5, 0}, // Antapani
            {0, 1, 0, 2, 6, 0, 0}, // Trans Studi Mall
            {5, 0, 2, 0, 5, 0, 8}, // Bandung indah Plaza
            {0, 4, 6, 5, 0, 2, 7}, // Paskal
            {0, 5, 0, 0, 2, 0, 0}, // Dago
            {0, 0, 0, 8, 7, 0, 0}, // Margahayu

        };
        int asalDaerah;

        rolePengguna = login();
        if (rolePengguna == 0)
        {
            continue;
        }

        else if (rolePengguna == 1)
        {
            while (true)
            {
                int pilihanAdmin;
                pilihanAdmin = menuAdmin();

                if (pilihanAdmin == 1)
                {
                    displayAdmin();
                }
                else if (pilihanAdmin == 2)
                {
                    search();
                }
                else if (pilihanAdmin == 3)
                {
                    break;
                }
                else
                {
                    cout << "Pilihan Tidak Valid! " << endl;
                    continue;
                }
            }
        }
        else if (rolePengguna == 2)
        {
            while (true)
            {
                int pilihanUser;
                pilihanUser = menu();

                if (pilihanUser == 1)
                {
                    insert();
                }
                else if (pilihanUser == 2)
                {
                    del();
                }
                else if (pilihanUser == 3)
                {
                    transaksi();
                }
                else if (pilihanUser == 4)
                {
                    headerMap();
                    cout << "Tentukan titik Awal (1-6): ";
                    cin >> asalDaerah;
                    while (asalDaerah > 6)
                    {
                        cout << endl;
                        cout << "Maaf, daerah tidak tersedia!" << endl;
                        cout << "Tentukan titik awal anda berada!  (1-6): ";
                        cin >> asalDaerah;
                    }
                    cout << endl;
                    cout << "Loading..." << endl;
                    cout << "Mencari Rute tercepat" << endl;
                    Sleep(3000);
                    system("cls");

                    cout << "Rute tercepat Ditemukan : ";
                    cout << endl;
                    dijkstra(graf, asalDaerah);
                    getch();
                }
                else if (pilihanUser == 5)
                {
                    break;
                }
            }
        }
    }

    return 0;
}