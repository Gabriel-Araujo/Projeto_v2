#include <iostream>
#include <string>

#include "include/Vacina.h"

using namespace std;

int main()
{
    Vacina *vacina = new Vacina("a de amor", 10, 5, "10/10/1000", "meu coracao", "minha casa", "1010", "injeção", 10, 5);

    string nome = "Gabriel";
    cout << "Hello world!" << nome << endl;
    return 0;
}
