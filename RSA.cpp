#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menghitung GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Fungsi untuk menghitung invers modulo
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

// Fungsi untuk mengenkripsi pesan
string encrypt(string msg, int e, int n) {
    string encrypted_msg = "";
    for (int i = 0; i < msg.length(); i++) {
        // Ubah setiap karakter pesan menjadi nilai numerik
        int num = msg[i];
git init
        // Enkripsi nilai numerik menggunakan algoritma RSA
        int encrypted_num = 1;
        for (int j = 0; j < e; j++) {
            encrypted_num = (encrypted_num * num) % n;
        }

        // Tambahkan nilai numerik terenkripsi ke dalam string
        encrypted_msg += to_string(encrypted_num) + " ";
    }
    return encrypted_msg;
}

// Fungsi untuk mendekripsi pesan
string decrypt(string msg, int d, int n) {
    string decrypted_msg = "";
    string num_str = "";
    for (int i = 0; i < msg.length(); i++) {
        // Ambil nilai numerik terenkripsi dari string
        if (msg[i] != ' ') {
            num_str += msg[i];
        } else {
            // Konversi nilai numerik kembali ke dalam bentuk integer
            int encrypted_num = stoi(num_str);

            // Dekripsi nilai numerik menggunakan algoritma RSA
            int decrypted_num = 1;
            for (int j = 0; j < d; j++) {
                decrypted_num = (decrypted_num * encrypted_num) % n;
            }

            // Tambahkan karakter terdekripsi ke dalam string
            decrypted_msg += char(decrypted_num);

            // Reset num_str untuk nilai numerik berikutnya
            num_str = "";
        }
    }
    return decrypted_msg;
}

int main() {
    int p = 61, q = 53; // Contoh bilangan prima
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);

    // Pilih e yang saling prima dengan phi_n
    int e = 17;
    // Pastikan e relatif prima dengan phi_n
    while (gcd(e, phi_n) != 1) {
        e++;
    }

    // Hitung kunci privat (d)
    int d = modInverse(e, phi_n);

    // Tampilkan kunci publik dan privat
    cout << "Kunci publik (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Kunci privat (d, n): (" << d << ", " << n << ")" << endl;

    // Masukkan teks yang akan dienkripsi
    string plaintext;
    cout << "Masukkan teks yang akan dienkripsi: ";
    getline(cin, plaintext);

    // Enkripsi teks
    string encrypted_text = encrypt(plaintext, e, n);
    cout << "Teks terenkripsi: " << encrypted_text << endl;

    // Dekripsi teks
    string decrypted_text = decrypt(encrypted_text, d, n);
    cout << "Teks terdekripsi: " << decrypted_text << endl;

    return 0;
}
