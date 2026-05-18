#include <iostream>
using namespace std;

class RekeningBank {
public:
    virtual void potongAdmin() = 0;
};

class RekeningSyariah : public RekeningBank {
private:
    string noRek;
    double saldo;

public:
    RekeningSyariah(string no, double saldoAwal) {
        noRek = no;
        saldo = saldoAwal;
    }

    void potongAdmin() {
        cout << "Rekening Syariah: Tidak ada potongan admin bulanan." << endl;
        cout << "No Rek: " << noRek << " | Saldo Akhir: Rp " << saldo << endl;
        cout << "----------------------------------------------------" << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
private:
    string noRek;
    double saldo;

public:
    RekeningKonvensional(string no, double saldoAwal) {
        noRek = no;
        saldo = saldoAwal;
    }

    void potongAdmin() {
        saldo -= 15000;
        cout << "Rekening Konvensional: Dipotong biaya admin Rp 15000" << endl;
        cout << "No Rek: " << noRek << " | Saldo Akhir: Rp " << saldo << endl;
        cout << "----------------------------------------------------" << endl;
    }
};

class RekeningPremium : public RekeningBank {
private:
    string noRek;
    double saldo;

public:
    RekeningPremium(string no, double saldoAwal) {
        noRek = no;
        saldo = saldoAwal;
    }

    void potongAdmin() {
        if (saldo > 10000000) {
            cout << "Rekening Premium: Bebas biaya admin karena saldo di atas 10JT." << endl;
        } else {
            saldo -= 50000;
            cout << "Rekening Premium: Dipotong biaya admin Rp 50000 karena saldo <= 10JT." << endl;
        }
        cout << "No Rek: " << noRek << " | Saldo Akhir: Rp " << saldo << endl;
        cout << "----------------------------------------------------" << endl;
    }
};

int main() {
    RekeningBank* akun;
    RekeningSyariah nasabah1("SYR-001", 500000);
    RekeningKonvensional nasabah2("KNV-099", 2000000); 
    RekeningPremium nasabah3("PRM-002", 15000000);

    akun = &nasabah1;
    akun->potongAdmin();

    akun = &nasabah2;
    akun->potongAdmin();
    
    akun = &nasabah3;
    akun->potongAdmin();

    return 0;
}