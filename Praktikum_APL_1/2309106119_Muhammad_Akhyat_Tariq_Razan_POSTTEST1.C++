#include <iostream>
#include <limits>

using namespace std;

bool login() {
    string nama_id, nim_password;
    int attempts = 3;

while (attempts > 0) {
    cout << "Masukkan Nama: ";
    getline(cin, nama_id);
    cout << "Masukkan NIM: ";
    getline(cin, nim_password);

    if (nama_id == "Akhyat" && nim_password == "2309106119") {
        return true;
    } else {
        cout << "Nama atau Nim salah! Sisa percobaan: " << attempts << endl;
        attempts--;
    }
    }

    cout << "Login gagal setelah 3 percobaan." << endl;
    return false;
}

int menu() {
    cout << endl;
    cout << "Pilih menu konversi:" << endl;
    cout << endl;
    cout << "1. Celcius ke (Reamur, Fahrenheit, Kelvin)" << endl;
    cout << "2. Reamur ke (Celcius, Fahrenheit, Kelvin)" << endl;
    cout << "3. Fahrenheit ke (Celcius, Reamur, Kelvin)" << endl;
    cout << "4. Kelvin ke (Celcius, Reamur, Fahrenheit)" << endl;
    cout << endl;
    cout << "Pilihan: ";

int pilihan;
    while (!(cin >> pilihan) || pilihan < 1 || pilihan > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Masukkan pilihan (1-4): ";
    }

    return pilihan;
}

    // Konversi Celcius ke Reamur, Fahrenheit, Kelvin    
void konversi(int pilihan, float suhu) {
    if (pilihan == 1) {

        float reamur = 4.0f / 5.0f * suhu;
        float fahrenheit = 9.0f / 5.0f * suhu + 32.0f;
        float kelvin = suhu + 273.15f;
            cout << "Reamur: " << reamur << endl;
            cout << "Fahrenheit: " << fahrenheit << endl;
            cout << "Kelvin: " << kelvin << endl;

    // Konversi Reamur ke Celcius, Fahrenheit, Kelvin
    } else if (pilihan == 2) {
        float celcius = 5.0f / 4.0f * suhu;
        float fahrenheit = 9.0f / 4.0f * suhu + 32.0f;
        float kelvin = 5.0f / 4.0f * suhu + 273.15f;
            cout << "Celcius: " << celcius << endl;
            cout << "Fahrenheit: " << fahrenheit << endl;
            cout << "Kelvin: " << kelvin << endl;

    // Konversi Fahrenheit ke Celcius, Reamur, Kelvin
    } else if (pilihan == 3) {
        float celcius = (suhu - 32.0f) * 5.0f / 9.0f;
        float reamur = (suhu - 32.0f) * 4.0f / 9.0f;
        float kelvin = (suhu + 459.67f) * 5.0f / 9.0f;
            cout << "Celcius: " << celcius << endl;
            cout << "Reamur: " << reamur << endl;
            cout << "Kelvin: " << kelvin << endl;

    // Konversi Kelvin ke Celcius, Reamur, Fahrenheit
    } else if (pilihan == 4) {
        float celcius = suhu - 273.15f;
        float reamur = (suhu - 273.15f) * 4.0f / 5.0f;
        float fahrenheit = (suhu - 273.15f) * 9.0f / 5.0f + 32.0f;
            cout << "Celcius: " << celcius << endl;
            cout << "Reamur: " << reamur << endl;
            cout << "Fahrenheit: " << fahrenheit << endl;
    }
}

int main() {
    login();
    while (true) {
        int pilihan = menu();
        float suhu;
        cout << "Masukkan suhu: ";
        cin >> suhu;
        konversi(pilihan, suhu);
        cout << endl;
        cout << "Apakah ingin melanjutkan (Y/N)? ";
        char c;
        cin >> c;
            if (c == 'N' || c == 'n') {
                break;
                cout << "Terima Kasih !" << endl;
            }
    }

}
