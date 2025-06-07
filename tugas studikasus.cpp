#include <iostream>
using namespace std;

const int MAKS_MHS = 100;

class Mahasiswa {
public:
    string nama;
    string nim;
    int alpro, matdis, pweb, aljabar;

    void input(int i) {
        cout << "Masukkan Nama Mahasiswa Ke-" << i + 1 << " : ";
        getline(cin, nama);
        cout << "Masukkan NIM " << nama << " : ";
        getline(cin, nim);
        cout << "\nInput Nilai Alpro " << nama << " : ";
        cin >> alpro;
        cout << "Input Nilai Matdis " << nama << " : ";
        cin >> matdis;
        cout << "Input Nilai Pweb " << nama << " : ";
        cin >> pweb;
        cout << "Input Nilai Aljabar " << nama << " : ";
        cin >> aljabar;
        cin.ignore();
        cout << "===============================+\n";
    }

 double getRataRata() {
        return (alpro + matdis + pweb + aljabar) / 4.0;
    }

    char getHuruf() {
        double r = getRataRata();
        if (r >= 85) return 'A';
        else if (r >= 75) return 'B';
        else if (r >= 65) return 'C';
        else if (r >= 50) return 'D';
        else return 'E';
    }

    string getKelulusan() {
        char h = getHuruf();
        if (h == 'A' || h == 'B') return "LULUS";
        else return "TIDAK LULUS";
    }

    void tampil() {
        double rata = getRataRata();
        char huruf = getHuruf();
        string kelulusan = getKelulusan();

        cout << "| Nama            : " << nama << endl;
        cout << "| NIM             : " << nim << endl;
        cout << "| Nilai Akhir     : " << rata << endl;
        cout << "| Huruf Mutu      : " << huruf << endl;
        cout << "| Kelulusan       : " << kelulusan << endl;
        cout << "+==============================+\n";
    }
};

int main() {
    Mahasiswa mhs[MAKS_MHS];
    int jumlah = 0;
    int pilihan;

    cout << "Masukkan jumlah Mahasiswa : ";
    cin >> jumlah;
    cin.ignore();

    do {
        cout << "\n+==============================+\n";
        cout << "|             MENU             |\n";
        cout << "+==============================+\n";
        cout << "| 1. Input Nilai               |\n";
        cout << "| 2. Tampilkan Data Nilai      |\n";
        cout << "| 3. Keluar                    |\n";
        cout << "+==============================+\n";
        cout << "| Masukkan Pilihan : ";
        cin >> pilihan;
        cin.ignore();
        cout << "+==============================+\n";

        switch (pilihan) {
        case 1:
            cout << "\n+==============================+\n";
            cout << "|     INPUT NILAI MAHASISWA    |\n";
            cout << "+==============================+\n";
            for (int i = 0; i < jumlah; i++) {
                mhs[i].input(i);
            }
			 break;
        case 2:
            cout << "\n+==============================+\n";
            cout << "|       DATA NILAI MAHASISWA   |\n";
            cout << "+==============================+\n";
            for (int i = 0; i < jumlah; i++) {
                mhs[i].tampil();
            }
            break;
        case 3:
            cout << "Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);

    return 0;
}
