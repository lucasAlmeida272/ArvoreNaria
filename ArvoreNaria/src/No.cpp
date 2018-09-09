#include "No.h"
#include <iostream>

No::No(int n) throw(char*)
{
    if(n <= 1)
        throw("A ordem deve ser no m�nimo 2!");

    this->ordem = n;
    this->vetInfo = new Informacao*[n - 1];
    this->vetPtr  = new No*[n];
    this->qtsInformacoes = 0;

    for(int i = 0; i < n; i++)
    {
        this->vetInfo[i] = NULL;
        this->vetPtr[i]  = NULL;
    }

    this->vetPtr[n] = NULL;
}

No::~No()
{
}

Informacao* No::getInfo(int pos) throw(char*)
{
    if(pos >= this->ordem)
        throw("Posi��o inv�lida!");
    return vetInfo[pos];
}

No* No::getPtr(int pos) throw(char*)
{
    if(pos > this->ordem)
        throw("Posi��o inv�lida!");
    return vetPtr[pos];
}

void No::setPtr(int pos, No* no) throw(char*)
{
    if(pos > this->ordem)
        throw("Posi��o inv�lida!");
    this->vetPtr[pos] = no;
}

int No::getOrdem()
{
    return this->ordem;
}

bool No::temEspaco()
{
    return this->qtsInformacoes != (this->getOrdem()-1);
}

void No::inserirInfo(Informacao* in) throw(char*)
{
    if(in == NULL)
        throw("A informa��o n�o pode ser nula");
    if(!this->temEspaco())
        throw("O n� est� cheio");

    if(this->qtsInformacoes == 0)
        this->inserir(0, in);
    else
    {
        int i;
        for(i = 0; i < this->ordem; i++)
        {
            if(vetInfo[i] == NULL)
            {
                this->inserir(i, in);
                break;
            }
            int c = in->compareTo(vetInfo[i]);
            if(c < 0)
            {
                this->inserir(i, in);
                break;
            }
        }
        if(i == this->ordem)
            this->inserir(i, in);
    }
}

void No::inserir(int pos, Informacao* in)
{
    Informacao* aux;
    if(this->qtsInformacoes == 0)
        vetInfo[pos] = in;
    else
    {
        for(int i = this->ordem; i > pos; i--)
        {
            aux = vetInfo[i];
            vetInfo[i] = vetInfo[i - 1];
            vetInfo[i - 1] = aux;
        }

        vetInfo[pos] = in;
    }

    this->qtsInformacoes++;
}

void No::printar(ostream& os)
{
    os << "( ";

    for(int i = 0; i < this->ordem; i++)
    {
        if(this->getPtr(i) != NULL)
            this->getPtr(i)->printar(os);
        if(this->getInfo(i) != NULL)
            os << this->getInfo(i)->getCodigo() << " ";
    }

    if(this->getPtr(this->ordem) != NULL)
        this->getPtr(this->ordem)->printar(os);

    os << ")";
}