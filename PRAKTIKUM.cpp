#include <iostream>
#include <string>

using namespace std;

class RekeningBank {
protected:
    string nama, nomor;
    double saldo;
public:
    RekeningBank(string n, string no, double s) : nama(n), nomor(no), saldo(s) {}
    virtual double potongAdmin() = 0;
    double getSaldo() { return saldo; }
    string getNama() { return nama; }
    void info() {
        cout << "\nNasabah: " << nama << " (" << nomor << ")" << endl;
        cout << "Saldo: Rp " << saldo;
    }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string n, string no, double s) : RekeningBank(n, no, s) {}
    double potongAdmin() {
        cout << " [Syariah] Bebas biaya admin" << endl;
        return 0;
    }
};

class RekeningKonvensional : public RekeningBank {
private:
    const double BIAYA = 15000;
public:
    RekeningKonvensional(string n, string no, double s) : RekeningBank(n, no, s) {}
    double potongAdmin() {
        cout << " [Konvensional] Potong Rp " << BIAYA << endl;
        saldo -= BIAYA;
        return BIAYA;
    }
};

class RekeningPremium : public RekeningBank {
private:
    const double BATAS = 10000000, BIAYA = 50000;
public:
    RekeningPremium(string n, string no, double s) : RekeningBank(n, no, s) {}
    double potongAdmin() {
        if (saldo > BATAS) {
            cout << " [Premium] Saldo > Rp 10jt - Bebas admin!" << endl;
            return 0;
        } else {
            cout << " [Premium] Potong Rp " << BIAYA << endl;
            saldo -= BIAYA;
            return BIAYA;
        }
    }
};

void prosesEndMonth(RekeningBank* r[], int n) {
    cout << "\n============================" << endl;
    cout << "PROSES OTOMATISASI AKHIR BULAN" << endl;
    cout << "       Bank Gibran Jaya" << endl;
    cout << "============================" << endl;
    
    double total = 0;
    for (int i = 0; i < n; i++) {
        r[i]->info();
        double potong = r[i]->potongAdmin();
        total += potong;
        cout << " => Rp " << r[i]->getSaldo() << endl;
    }
    cout << "\nTotal admin terkumpul: Rp " << total << endl;
}

int main() {
    RekeningBank* r[5];
    
    r[0] = new RekeningSyariah("Ahmad Fauzi", "RSH-001", 5000000);
    r[1] = new RekeningKonvensional("Budi Santoso", "RKV-001", 200000);
    r[2] = new RekeningPremium("Citra Dewi", "RPM-001", 15000000);
    r[3] = new RekeningPremium("Dani Kurniawan", "RPM-002", 7500000);
    r[4] = new RekeningPremium("Eko Prasetyo", "RPM-003", 10000000);
    
    prosesEndMonth(r, 5);
    
    return 0;
}