#include <iostream>
#include <stdexcept>
#include "MinhaInformacao.h"
#include "ArvoreNaria.h"

using namespace std;
int main()
{
    try
    {
        ArvoreNaria ar(3);

        MinhaInformacao* mi1 = new MinhaInformacao(8);
        MinhaInformacao* mi2 = new MinhaInformacao(10);
        MinhaInformacao* mi3 = new MinhaInformacao(11);
        MinhaInformacao* mi4 = new MinhaInformacao(14);
        MinhaInformacao* mi5 = new MinhaInformacao(12);
        MinhaInformacao* mi6 = new MinhaInformacao(13);

        cout << ar << "\n";

        ar.inserir(mi6);
        ar.inserir(mi5);
        ar.inserir(mi4);
        ar.inserir(mi3);
        ar.inserir(mi2);
        ar.inserir(mi1);
        cout << ar << "\n";

        ar.excluir(mi6);
        cout << ar << "\n";

        ar.excluir(mi5);
        cout << ar << "\n";

        ar.excluir(mi1);
        ar.excluir(mi2);
        cout << ar << "\n";

    }
    catch(invalid_argument e)
    {
        cerr << e.what();
    }

    return 0;
}
