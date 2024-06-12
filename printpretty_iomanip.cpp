#include <iostream>
#include <iomanip> // look for this.
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;


        // A
        // noshowpos = Will reset flag for showpos. If showpos is setted then numbers will be printed with their + or - signs.
        // left = the output is padded to the field width appending fill characters at the end.
        // hex = read/write integer values using hexadecimal base format
        // showbase = adds base prefix for the str. For example 0x for hexas.
        cout << noshowpos << left << hex << showbase << nouppercase;
        cout << static_cast<long long>(A) << endl;

        // B
        // showpos = every non negative value will have + sign prefix.
        // dec = decimal format
        // setw = Sets the field width to be used on output operations.
        // setfill = fills the outputwidth with given character
        // right = the output is padded to the field width by inserting fill characters at the beginning.
        // fixed = for the float number precisions.
        // setprecision = for show how many numbers will be shown after dot.
        cout << showpos << dec << setw(15) << setfill('_') << right << fixed << setprecision(2);
        cout << B << endl;

        // C
        // scientific = write floating-point values in scientific notation. (like 3.14159e+000)
        // uppercase = make uppercase the chars.
        cout << noshowpos << left << scientific << setprecision(9) << uppercase;
        cout << C << endl;

    }
    return 0;

}