#include <iostream>
#include <string>
using namespace std;

// struktur data untuk menyimpan tanggal lahir
struct TanggalLahir {    
    int tanggal;
    int bulan;
    int tahun;
};

// nested struktur data untuk menyimpan data penduduk
struct Penduduk {
    string nama;
    string nik;
    TanggalLahir lahir;
};

// array of struct untuk menyimpan data penduduk
Penduduk* dataPenduduk = new Penduduk[1000];
int jumlahPenduduk = 0;

// prosedur untuk menampilkan menu
void tampilMenu() {
    cout << "______________________________" << endl;
    cout << "Sistem Informasi Kependudukan" << endl;
    cout << "______________________________" << endl;
    cout << endl;
    cout << "1. Tambah Data Penduduk " << endl;
    cout << "2. Lihat Data Penduduk " << endl;
    cout << "3. Ubah Data Penduduk " << endl;
    cout << "4. Hapus Data Penduduk " << endl;
    cout << "5. Urutkan Data Penduduk" << endl;
    cout << "6. Cari Data Penduduk (Binary Search)" << endl;
    cout << "7. Cari Data Penduduk (Interpolation Search)" << endl;
    cout << "8. Keluar " << endl;
    cout << "______________________________" << endl;
    cout << endl;
    cout << "Pilih menu: ";
}

// fungsi untuk login (fungsi rekursif)
bool login() {
    int chance = 0;
    const int maxChance = 3;
    string username;
    int passnim;

    while (chance < maxChance) {
        cout << "Masukkan Nama: ";
        cin >> username;
        cout << "Masukkan NIM: ";
        cin >> passnim;

        if (username == "Akhyat" && passnim == 119) {
            return true;
        } else {
            cout << "Nama atau NIM salah!" << endl;
            chance++;
        }
    }

    cout << "Login gagal. Silakan coba lagi." << endl;
    return false;
}

// fungsi untuk menambahkan data penduduk
void tambahData(Penduduk* dataPenduduk, int* jumlahPenduduk) {
    if (*jumlahPenduduk == 1000) {
        cout << "Data penduduk sudah penuh!" << endl;
        return;
    }
    string nama, nik;
    int tanggal, bulan, tahun;
    cout << " Masukkan Nama: ";
    cin >> nama;
    cout << " Masukkan NIK: ";
    cin >> nik;
    cout << " Masukkan Tanggal Lahir: ";
    cin >> tanggal;
    cout << " Masukkan Bulan Lahir: ";
    cin >> bulan;
    cout << " Masukkan Tahun Lahir: ";
    cin >> tahun;

    // validasi tanggal lahir
    if (tanggal < 1 || tanggal > 31 || bulan < 1 || bulan > 12 || tahun < 1900 || tahun > 2023) {
        cout << "Tanggal lahir tidak valid!" << endl;
        return;
    }

    // menambahkan data penduduk ke array
    Penduduk penduduk;
    penduduk.nama = nama;
    penduduk.nik = nik;
    penduduk.lahir.tanggal = tanggal;
    penduduk.lahir.bulan = bulan;
    penduduk.lahir.tahun = tahun;
    dataPenduduk[*jumlahPenduduk] = penduduk;
    (*jumlahPenduduk)++; // mengubah nilai jumlahPenduduk dengan menggunakan operator *
    cout << "Data penduduk berhasil ditambahkan!" << endl;
}

// prosedur untuk lihat data 
void lihatData(Penduduk* dataPenduduk, int jumlahPenduduk, int index = 0) {
    if (index == jumlahPenduduk) {
        return;
    }

    cout << "Data ke-" << index + 1 << endl;
    cout << "Nama: " << dataPenduduk[index].nama << endl;
    cout << "NIK: " << dataPenduduk[index].nik << endl;
    cout << "Tanggal Lahir: " << dataPenduduk[index].lahir.tanggal 
    << "/" << dataPenduduk[index].lahir.bulan << "/" << dataPenduduk[index].lahir.tahun << endl;
    cout << endl;

    lihatData(dataPenduduk, jumlahPenduduk, index + 1);
}

// Fungsi untuk mengubah data
void ubahData(Penduduk* dataPenduduk, int jumlahPenduduk) {
    int index;
    string nama, nik;
    int tanggal, bulan, tahun;
    bool ubahTanggal = false, ubahBulan = false, ubahTahun = false;

    cout << "Masukkan nomor data yang ingin diubah: ";
    cin >> index;

    // mengecek apakah index valid
    if (index < 1 || index > jumlahPenduduk) {
        cout << "Nomor data tidak valid!" << endl;
        return;
    }

    cout << "Masukkan nama baru (Enter untuk tidak mengubah): ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan NIK baru (Enter untuk tidak mengubah): ";
    getline(cin, nik);

    cout << "Apakah ingin mengubah Tanggal Lahir? (y/n): ";
    char ubah;
    cin >> ubah;
    if (ubah == 'y' || ubah == 'Y') {
        cout << "Masukkan Tanggal Lahir baru: ";
        cin >> tanggal;
        ubahTanggal = true;
    }

    cout << "Apakah ingin mengubah Bulan Lahir? (y/n): ";
    cin >> ubah;
    if (ubah == 'y' || ubah == 'Y') {
        cout << "Masukkan Bulan Lahir baru: ";
        cin >> bulan;
        ubahBulan = true;
    }

    cout << "Apakah ingin mengubah Tahun Lahir? (y/n): ";
    cin >> ubah;
    if (ubah == 'y' || ubah == 'Y') {
        cout << "Masukkan Tahun Lahir baru: ";
        cin >> tahun;
        ubahTahun = true;
    }

    // validasi tanggal lahir
    if ((ubahTanggal && (tanggal < 1 || tanggal > 31)) || 
        (ubahBulan && (bulan < 1 || bulan > 12)) ||
        (ubahTahun && (tahun < 1900 || tahun > 2023))) {
        cout << "Tanggal lahir tidak valid!" << endl;
        return;
    }

    // mengecek apakah ada perubahan pada data atau tidak
    if (nama.empty() && nik.empty() && !ubahTanggal && !ubahBulan && !ubahTahun) {
        cout << "Tidak ada perubahan data." << endl;
        return;
    }

    // mengubah data penduduk di array
    if (!nama.empty() && (dataPenduduk + (index - 1))->nama == nama) {
        cout << "Nama tidak dapat diubah karena sama dengan data sebelumnya." << endl;
    } else {
        (dataPenduduk + (index - 1))->nama = nama; // mengubah nilai nama dengan menggunakan operator -
    }
    if (!nik.empty() && (dataPenduduk + (index - 1))->nik == nik) {
        cout << "NIK tidak dapat diubah karena sama dengan data sebelumnya." << endl;
    } else {
        (dataPenduduk + (index - 1))->nik = nik;
    }
    if (ubahTanggal) {
        (dataPenduduk + (index - 1))->lahir.tanggal = tanggal;
    }
    if (ubahBulan) {
        (dataPenduduk + (index - 1))->lahir.bulan = bulan;
    }
    if (ubahTahun) {
        (dataPenduduk + (index - 1))->lahir.tahun = tahun;
    }
    if (!nama.empty() || !nik.empty() || ubahTanggal || ubahBulan || ubahTahun) {
        cout << "Data penduduk berhasil diubah!" << endl;
    }
}

// fungsi untuk menghapus data penduduk
void hapusData(Penduduk* dataPenduduk, int* jumlahPenduduk) {
    int index;
    cout << "Masukkan nomor data yang ingin dihapus: ";
    cin >> index;
    // mengecek apakah index valid atau tidak
    if (index < 1 || index > *jumlahPenduduk) {
        cout << "Nomor data tidak valid!" << endl;
        return;
    }
    // menghilangkan data setelah data yang dihapus
    for (int i = index - 1; i < *jumlahPenduduk - 1; i++) {
        dataPenduduk[i] = dataPenduduk[i + 1];
    }
    (*jumlahPenduduk)--;
    cout << "Data penduduk berhasil dihapus!" << endl;
}

// Fungsi untuk melakukan sorting data penduduk sesuai dengan ketentuan NIM ganjil
void sortData(Penduduk* dataPenduduk, int jumlahPenduduk, int nim) {
    if (nim % 2 == 1) { // NIM ganjil
        // Bubble Sort untuk mengurutkan nama secara ascending
        for (int i = 0; i < jumlahPenduduk - 1; i++) {
            for (int j = 0; j < jumlahPenduduk - i - 1; j++) {
                if (dataPenduduk[j].nama > dataPenduduk[j + 1].nama) {
                    Penduduk temp = dataPenduduk[j];
                    dataPenduduk[j] = dataPenduduk[j + 1];
                    dataPenduduk[j + 1] = temp;
                }
            }
        }

        // Selection Sort untuk mengurutkan tanggal lahir secara descending
        for (int i = 0; i < jumlahPenduduk - 1; i++) {
            int maxIndex = i;
            for (int j = i + 1; j < jumlahPenduduk; j++) {
                if (dataPenduduk[j].lahir.tahun > dataPenduduk[maxIndex].lahir.tahun ||
                    (dataPenduduk[j].lahir.tahun == dataPenduduk[maxIndex].lahir.tahun 
                    && dataPenduduk[j].lahir.bulan > dataPenduduk[maxIndex].lahir.bulan) ||
                    (dataPenduduk[j].lahir.tahun == dataPenduduk[maxIndex].lahir.tahun 
                    && dataPenduduk[j].lahir.bulan == dataPenduduk[maxIndex].lahir.bulan 
                    && dataPenduduk[j].lahir.tanggal > dataPenduduk[maxIndex].lahir.tanggal)) {
                    maxIndex = j;
                }
            }
            Penduduk temp = dataPenduduk[i];
            dataPenduduk[i] = dataPenduduk[maxIndex];
            dataPenduduk[maxIndex] = temp;
        }

        // Insertion Sort untuk mengurutkan NIK secara ascending
        for (int i = 1; i < jumlahPenduduk; i++) {
            string key = dataPenduduk[i].nik;
            int j = i - 1;
            while (j >= 0 && dataPenduduk[j].nik > key) {
                dataPenduduk[j + 1] = dataPenduduk[j];
                j--;
            }
            dataPenduduk[j + 1].nik = key;
        }
    }

    cout << "Data penduduk berhasil diurutkan!" << endl;
    cout << "Data penduduk setelah diurutkan:" << endl;
    lihatData(dataPenduduk, jumlahPenduduk);
}

// Fungsi untuk melakukan pencarian data penduduk berdasarkan NIK menggunakan Binary Search (data terurut ascending)
void cariDataByNIKBinarySearch(Penduduk* dataPenduduk, int jumlahPenduduk) {
    string nik;
    cout << "Masukkan NIK yang ingin dicari: ";
    cin >> nik;

    int left = 0, right = jumlahPenduduk - 1, mid;
    bool found = false;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (dataPenduduk[mid].nik == nik) {
            found = true;
            break;
        } else if (dataPenduduk[mid].nik < nik) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "Data penduduk ditemukan:" << endl;
        cout << "Nama: " << dataPenduduk[mid].nama << endl;
        cout << "NIK: " << dataPenduduk[mid].nik << endl;
        cout << "Tanggal Lahir: " << dataPenduduk[mid].lahir.tanggal 
        << "/" << dataPenduduk[mid].lahir.bulan << "/" << dataPenduduk[mid].lahir.tahun << endl;
    } else {
        cout << "Data penduduk dengan NIK " << nik << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk melakukan pencarian data penduduk berdasarkan NIK menggunakan Interpolation Search (data terurut descending)
void cariDataByNIKInterpolationSearch(Penduduk* dataPenduduk, int jumlahPenduduk) {
    string nikStr;
    cout << "Masukkan NIK yang ingin dicari: ";
    cin >> nikStr;
    int nik = stoi(nikStr);
    int left = 0, right = jumlahPenduduk - 1, mid;
    bool found = false;
    while (left <= right) {
        try {
            int leftNIK = stoi(dataPenduduk[left].nik);
            int rightNIK = stoi(dataPenduduk[right].nik);
            if (nik >= leftNIK && nik <= rightNIK) {
                int diff = rightNIK - leftNIK;
                if (diff == 0) {
                    mid = left;
                } else {
                    mid = left + ((nik - leftNIK) * (right - left)) / diff;
                }
                if (stoi(dataPenduduk[mid].nik) == nik) {
                    found = true;
                    break;
                } else if (stoi(dataPenduduk[mid].nik) < nik) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                break; // nik berada di luar rentang
            }
        } catch (const std::exception& e) {
            cout << "Terjadi kesalahan: " << e.what() << endl;
            break;
        }
    }
    if (found) {
        cout << "Data penduduk ditemukan:" << endl;
        cout << "Nama: " << dataPenduduk[mid].nama << endl;
        cout << "NIK: " << dataPenduduk[mid].nik << endl;
        cout << "Tanggal Lahir: " << dataPenduduk[mid].lahir.tanggal << "/" 
        << dataPenduduk[mid].lahir.bulan << "/" << dataPenduduk[mid].lahir.tahun << endl;
    } else {
        cout << "Data penduduk dengan NIK " << nikStr << " tidak ditemukan." << endl;
    }
}

// Main program
int main() {
    bool isLoggedIn = login();
    if (isLoggedIn) {
        int pilihan;
        int nim;
        
        do {
            tampilMenu();
            cin >> pilihan;
            switch (pilihan) {
                case 1:
                    tambahData(dataPenduduk, &jumlahPenduduk);
                    break;
                case 2:
                    if (jumlahPenduduk == 0) {
                        cout << "Data penduduk masih kosong!" << endl;
                    } else {
                        lihatData(dataPenduduk, jumlahPenduduk);
                    }
                    break;
                case 3:
                    ubahData(dataPenduduk, jumlahPenduduk);
                    break;
                case 4:
                    hapusData(dataPenduduk, &jumlahPenduduk);
                    break;
                case 5:
                    sortData(dataPenduduk, jumlahPenduduk, nim);
                    break;
                case 6:
                    cariDataByNIKBinarySearch(dataPenduduk, jumlahPenduduk);
                    break;
                case 7:
                    cariDataByNIKInterpolationSearch(dataPenduduk, jumlahPenduduk);
                    break;
                case 8:
                    cout << "Terima kasih!" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    break;
            }
        } while (pilihan != 8);
    } else {
        cout << "Login gagal. Silakan coba lagi." << endl;
    }
    delete[] dataPenduduk; // menghapus array
    return 0;
}