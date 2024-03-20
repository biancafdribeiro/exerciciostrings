#include <iostream>
#include <string>
#include <iomanip>
#include <locale.h>
#include <chrono>
#include <thread>

using namespace std;

void printCentered(const string& msg, int width) {
    int espacosCentralizados = (width - msg.size()) / 2;
    cout << setw(espacosCentralizados) << ' ' << msg << endl;
}

int main() {
    setlocale(LC_ALL, "");

    string msg;

    cout << "Digite uma mensagem: ";
    getline(cin, msg);

    int width = 80; 

    printCentered(msg, width);

    for (int linha = 6; linha <= 20; linha++) {
        cout << setw((width - msg.size()) / 2) << ' ';

        for (int i = 0; i < msg.size(); i++) {
            if (linha - 5 > i) {
                cout << ' ';
            } else {
                cout << msg[i]; 
            }
        }
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
