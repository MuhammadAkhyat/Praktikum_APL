#include <iostream>
#include <string>
using namespace std;

// struktur data untuk menyimpan data penduduk
struct Penduduk {
    string nama;
    string nik;
    int tanggalLahir;
    int bulanLahir;
    int tahunLahir;
};

// array untuk menyimpan data penduduk
Penduduk dataPenduduk[1000];
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
    cout << "5. Keluar " << endl;
    cout << "______________________________" << endl;
    cout << endl;
    cout << "Pilih menu: ";
}

// fungsi untuk login (fungsi rekursif)
bool login(int chance = 0) {
    if (chance >= 3) {
        cout << "Login gagal. Silakan coba lagi." << endl;
        return false;
    }

    string username;
    int passnim;

    cout << "Masukkan Nama: ";
    cin >> username;
    cout << "Masukkan NIM: ";
    cin >> passnim;

    if (username == "Akhyat" && passnim == 119) {
        return true;
    } else {
        cout << "Nama atau NIM salah!" << endl;
        return login(chance + 1);
    }
}

// fungsi untuk menambahkan data penduduk
void tambahData() {
    if (jumlahPenduduk == 1000) {
        cout << "Data penduduk sudah penuh!" << endl;
        return;
    }
    string nama, nik;
    int tanggalLahir, bulanLahir, tahunLahir;
    cout << " Masukkan Nama: ";
    cin >> nama;
    cout << " Masukkan NIK: ";
    cin >> nik;
    cout << " Masukkan Tanggal Lahir (dd): ";
    cin >> tanggalLahir;
    cout << " Masukkan Bulan Lahir (mm): ";
    cin >> bulanLahir;
    cout << " Masukkan Tahun Lahir (yyyy): ";
    cin >> tahunLahir;

    // menambahkan data penduduk ke array
    Penduduk penduduk;
    penduduk.nama = nama;
    penduduk.nik = nik;
    penduduk.tanggalLahir = tanggalLahir;
    penduduk.bulanLahir = bulanLahir;
    penduduk.tahunLahir = tahunLahir;
    dataPenduduk[jumlahPenduduk] = penduduk;
    jumlahPenduduk++;
    cout << "Data penduduk berhasil ditambahkan!" << endl;
}

// prosedur untuk lihat data 
void lihatData(int index = 0) {
    if (index == jumlahPenduduk) {
        return;
    }

    cout << "Data ke-" << index + 1 << endl;
    cout << "Nama: " << dataPenduduk[index].nama << endl;
    cout << "NIK: " << dataPenduduk[index].nik << endl;
    cout << "Tanggal Lahir: " << dataPenduduk[index].tanggalLahir 
    << "/" << dataPenduduk[index].bulanLahir << "/" << dataPenduduk[index].tahunLahir << endl;
    cout << endl;

    lihatData(index + 1);
}

// Fungsi untuk mengubah data (fungsi rekursif)
void ubahData() {
    int index;
    string nama, nik;
    int tanggalLahir, bulanLahir, tahunLahir;
    bool ubahTanggalLahir = false, ubahBulanLahir = false, ubahTahunLahir = false;

    cout << "Masukkan nomor data yang ingin diubah: ";
    cin >> index;

    // mengecek apakah index valid
    if (index < 1 || index > jumlahPenduduk) {
        cout << "Nomor data tidak valid!" << endl;
        return;
    }

    cout << "Masukkan nama baru (tekan Enter untuk tidak mengubah): ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan NIK baru (tekan Enter untuk tidak mengubah): ";
    getline(cin, nik);

    cout << "Apakah ingin mengubah Tanggal Lahir? (y/n): ";
    char ubah;
    cin >> ubah;
    if (ubah == 'y' || ubah == 'Y') {
        cout << "Masukkan Tanggal Lahir baru: ";
        cin >> tanggalLahir;
        ubahTanggalLahir = true;
    }

    cout << "Apakah ingin mengubah Bulan Lahir? (y/n): ";
    cin >> ubah;
    if (ubah == 'y' || ubah == 'Y') {
        cout << "Masukkan Bulan Lahir baru: ";
        cin >> bulanLahir;
        ubahBulanLahir = true;
    }

    cout << "Apakah ingin mengubah Tahun Lahir? (y/n): ";
    cin >> ubah;
    if (ubah == 'y' || ubah == 'Y') {
        cout << "Masukkan Tahun Lahir baru: ";
        cin >> tahunLahir;
        ubahTahunLahir = true;
    }

    // mengecek apakah ada perubahan pada data atau tidak
    if (nama.empty() && nik.empty() && !ubahTanggalLahir && !ubahBulanLahir && !ubahTahunLahir) {
        cout << "Tidak ada perubahan data." << endl;
        return;
    }

    // mengubah data penduduk di array
    if (!nama.empty() && dataPenduduk[index - 1].nama == nama) {
        cout << "Nama tidak dapat diubah karena sama dengan data sebelumnya." << endl;
    } else {
        dataPenduduk[index - 1].nama = nama;
    }
    if (!nik.empty() && dataPenduduk[index - 1].nik == nik) {
        cout << "NIK tidak dapat diubah karena sama dengan data sebelumnya." << endl;
    } else {
        dataPenduduk[index - 1].nik = nik;
    }
    if (ubahTanggalLahir) {
        dataPenduduk[index - 1].tanggalLahir = tanggalLahir;
    }
    if (ubahBulanLahir) {
        dataPenduduk[index - 1].bulanLahir = bulanLahir;
    }
    if (ubahTahunLahir) {
        dataPenduduk[index - 1].tahunLahir = tahunLahir;
    }
    if (!nama.empty() || !nik.empty() || ubahTanggalLahir || ubahBulanLahir || ubahTahunLahir) {
        cout << "Data penduduk berhasil diubah!" << endl;
    }
}

// fungsi untuk menghapus data penduduk
void hapusData() {
    int index;
    cout << "Masukkan nomor data yang ingin dihapus: ";
    cin >> index;
    // mengecek apakah index valid atau tidak
    if (index < 1 || index > jumlahPenduduk) {
        cout << "Nomor data tidak valid!" << endl;
        return;
    }
    // menghilangkan data setelah data yang dihapus
    for (int i = index - 1; i < jumlahPenduduk - 1; i++) {
        dataPenduduk[i] = dataPenduduk[i + 1];
    }
    jumlahPenduduk--;
    cout << "Data penduduk berhasil dihapus!" << endl;
}

// Main program
int main() {
    bool isLoggedIn = login();
    if (isLoggedIn) {
        int pilihan;
        do {
            tampilMenu();
            cin >> pilihan;
            switch (pilihan) {
                case 1:
                    tambahData();
                    break;
                case 2:
                    if (jumlahPenduduk == 0) {
                        cout << "Data penduduk masih kosong!" << endl;
                    } else {
                        lihatData();
                    }
                    break;
                case 3:
                    ubahData();
                    break;
                case 4:
                    hapusData();
                    break;
                case 5:
                    cout << "Terima kasih!" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    break;
            }
        } while (pilihan != 5);
    } else {
        cout << "Login gagal. Silakan coba lagi." << endl;
    }
    return 0;
}