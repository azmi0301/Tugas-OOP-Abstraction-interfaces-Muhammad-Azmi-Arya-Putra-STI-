#include <iostream>
using namespace std;

class Penyembuhan {
public:
    virtual void sembuhkan() = 0; 
};

class Serangan {
public:
    virtual void serang() = 0; 
};

class Pertahanan {
public:
    virtual void bertahan() = 0;
};

class KarakterGame {
protected:
    string nama;
    int kesehatan;
    int kekuatan;
    int pertahanan;

public:
    KarakterGame(string nama, int kesehatan, int kekuatan, int pertahanan) {
        this->nama = nama;
        this->kesehatan = kesehatan;
        this->kekuatan = kekuatan;
        this->pertahanan = pertahanan;
    }

    void tampilkanStatus() {
        cout << "Karakter: " << nama << endl;
        cout << "Kesehatan: " << kesehatan << " HP" << endl;
        cout << "Kekuatan: " << kekuatan << " ATK" << endl;
        cout << "Pertahanan: " << pertahanan << " DEF" << endl;
        cout << "--------------------------" << endl;
    }
};

class Pemain : public KarakterGame, public Penyembuhan, public Serangan, public Pertahanan {
public:
    Pemain(string nama, int kesehatan, int kekuatan, int pertahanan)
        : KarakterGame(nama, kesehatan, kekuatan, pertahanan) {}

    void sembuhkan() override {
        cout << nama << " menggunakan ramuan penyembuhan..." << endl;
        kesehatan += 25;
        cout << "Kesehatan meningkat menjadi " << kesehatan << " HP." << endl;
    }

    void serang() override {
        cout << nama << " menyerang musuh dengan pedang, memberikan " << kekuatan << " damage!" << endl;
    }

    void bertahan() override {
        cout << nama << " mengangkat perisai, mengurangi damage sebesar " << pertahanan << "!" << endl;
    }
};

class Musuh : public KarakterGame, public Serangan, public Pertahanan {
public:
    Musuh(string nama, int kesehatan, int kekuatan, int pertahanan)
        : KarakterGame(nama, kesehatan, kekuatan, pertahanan) {}

    void serang() override {
        cout << nama << " menyerang pemain dengan cakar, memberikan " << kekuatan << " damage!" << endl;
    }

    void bertahan() override {
        cout << nama << " mencoba menghindari serangan dan mengurangi damage sebesar " << pertahanan << "!" << endl;
    }
};

class NPC : public KarakterGame {
public:
    NPC(string nama, int kesehatan) : KarakterGame(nama, kesehatan, 0, 0) {}

    void bicara() {
        cout << nama << " berkata: 'Selamat datang di desa kami, petualang!'" << endl;
    }
};

int main() {
    Pemain pemain("chip", 100, 30, 10);
    Musuh musuh("kangkungt", 80, 25, 5);
    NPC npc("tukang sayur", 50);

    pemain.tampilkanStatus();
    musuh.tampilkanStatus();
    npc.tampilkanStatus();

    pemain.serang();
    musuh.bertahan();
    pemain.sembuhkan();

    musuh.serang();
    pemain.bertahan();

    npc.bicara();

    return 0;
}