#ifndef ARVORENARIA_H
#define ARVORENARIA_H
#include "Informacao.h"
#include "No.h"
#include <iostream>

class ArvoreNaria
{
    public:
        ArvoreNaria(int) throw(char*);
        virtual ~ArvoreNaria();
        void inserir(Informacao*) throw(char*);
        bool tem(Informacao*) throw(char*);
        friend ostream& operator<<(ostream&, const ArvoreNaria&);
    private:
        int ordem;
        No* inserir(No*, Informacao*);
        bool tem(No*, Informacao*);
        No* raiz;
};

#endif // ARVORENARIA_H