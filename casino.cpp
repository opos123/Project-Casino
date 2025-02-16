#include <iostream> // Fungsi untuk melakukan Input/Output
#include <cstdlib> // Untuk fungsi rand() dan srand()
#include <ctime>   // Untuk fungsi time()


void tampilkanMenu() {
    std::cout << "========== GAME CASINO SEDERHANA ==========\n";
    std::cout << "1. Mulai Game\n";
    std::cout << "2. Keluar\n";
    std::cout << "===========================================\n";
    std::cout << "Pilih opsi (1/2): ";
}


void inputUser(std::string &username, std::string &password) {
    std::cout << "Masukkan Username: ";
    std::cin >> username;
    std::cout << "Masukkan Password: ";
    std::cin >> password;
}


int inputSaldo() {
    int saldo;
    std::cout << "Masukkan Saldo Awal: ";
    std::cin >> saldo;
    return saldo;
}


int generateAngka() {
    return std::rand() % 10;
}


void tampilkanAngkaAcak(int &angka1, int &angka2, int &angka3) {
    std::cout << "Tekan Enter untuk menghasilkan angka pertama...\n";
    std::cin.ignore();
    std::cin.get();
    angka1 = generateAngka();
    std::cout << angka1 << " ";

    std::cout << "\nTekan Enter untuk menghasilkan angka kedua...\n";
    std::cin.get();
    angka2 = generateAngka();
    std::cout << angka1 << " " << angka2 << " ";

    std::cout << "\nTekan Enter untuk menghasilkan angka ketiga...\n";
    std::cin.get();
    angka3 = generateAngka();
    std::cout << angka1 << " " << angka2 << " " << angka3 << "\n";
}


int hitungSaldo(int saldo, int angka1, int angka2, int angka3) {
    if (angka1 == angka2 && angka2 == angka3) {
        std::cout << "Selamat! Semua angka sama. Saldo bertambah 5.\n";
        saldo += 5;
    } else if (angka1 == angka2 || angka1 == angka3 || angka2 == angka3) {
        std::cout << "Selamat! Ada 2 angka yang sama. Saldo bertambah 1.\n";
        saldo += 1;
    } else {
        std::cout << "Sayang sekali, tidak ada angka yang sama. Saldo berkurang 1.\n";
        saldo -= 1;
    }
    return saldo;
}

int main() {

    std::string username, password;
    int pilihan;
    bool gameRunning = true;


    std::srand(std::time(0));

    while (gameRunning) {

        tampilkanMenu();
        std::cin >> pilihan;


        if (pilihan == 1) {

            inputUser(username, password);


            int saldo = inputSaldo();

            bool gameOn = true;


            while (gameOn) {
                std::cout << "\nGame Dimulai! Tekan Enter untuk menghasilkan angka.\n";


                int angka1, angka2, angka3;


                tampilkanAngkaAcak(angka1, angka2, angka3);


                saldo = hitungSaldo(saldo, angka1, angka2, angka3);

                std::cout << "Saldo Akhir Anda: " << saldo << "\n";

                // Menanyakan apakah pemain ingin bermain lagi
                std::cout << "\nApakah Anda ingin bermain lagi? (1 untuk Ya, 2 untuk Keluar): ";
                int pilihanLanjut;
                std::cin >> pilihanLanjut;

                if (saldo == 0) {
                    std::cout << "Saldo Anda Habis... silahkan Isi ulang Saldo" << "\n";
                    break;
                }

                if (pilihanLanjut == 2) {
                    gameOn = false;  // Keluar dari loop permainan
                }
            }

        } else if (pilihan == 2) {
            gameRunning = false;  // Keluar dari loop utama dan program selesai
            std::cout << "Terima kasih telah bermain. Sampai jumpa!\n";
        } else {
            std::cout << "Pilihan tidak valid. Program selesai.\n";
            gameRunning = false;
        }
    }

    return 0;
}
