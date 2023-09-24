#include "Trees.hpp"
Arvore_binaria :: Arvore_binaria()
{
    this-> Raiz = NULL;
}

Arvore_binaria :: ~Arvore_binaria()
{
    limpar_Arvore(Raiz);
}

void Arvore_binaria :: setRaiz (folha* Raiz) {this-> Raiz = Raiz;}
folha* Arvore_binaria :: getRaiz () {return this-> Raiz;}
bool Arvore_binaria :: Arvore_vazia () {return (Raiz == NULL);}

void Arvore_binaria :: Inserir_arvore (folha** Raiz, word keyword)
{
    if((*Raiz)==NULL)
    {
        *Raiz = new folha;
        (*Raiz)->dado=keyword;
        (*Raiz)->folha_esq=NULL;
        (*Raiz)->folha_dir=NULL;
    }   
    else
    {
        if(keyword.contador <= (*Raiz)->dado.contador)
            Inserir_arvore(&(*Raiz)->folha_esq, keyword);
        if(keyword.contador > (*Raiz)->dado.contador)
            Inserir_arvore(&(*Raiz)->folha_dir, keyword);   
    }
}

void Arvore_binaria :: print_inordem(folha* Raiz, ofstream& out)
{
    if(Raiz != NULL)
    {
        print_inordem(Raiz->folha_esq, out); 
        out << "Palavra: " << Raiz->dado.palavra <<" --- "<< " frequência: "<< Raiz->dado.contador << "\n";
        print_inordem(Raiz->folha_dir, out); 
    }
}

void Arvore_binaria :: print_preordem (folha* Raiz, ofstream& out)
{
    if(Raiz != NULL)
    {
        out << "Palavra: " << Raiz->dado.palavra <<" --- "<< " frequência: "<< Raiz->dado.contador << "\n";
        print_preordem(Raiz->folha_esq, out);
        print_preordem(Raiz->folha_dir, out); 
    }
}

void Arvore_binaria :: print_posordem (folha* Raiz, ofstream& out)
{
    if(Raiz != NULL)
    {
        print_posordem(Raiz->folha_esq, out); 
        print_posordem(Raiz->folha_dir, out); 
        out << "Palavra: " << Raiz->dado.palavra <<" --- "<< " frequência: "<< Raiz->dado.contador << "\n";
    }
}

void Arvore_binaria :: limpar_Arvore(folha* Raiz)
{
    if(Raiz != NULL)
    {
        limpar_Arvore(Raiz->folha_esq);
        limpar_Arvore(Raiz->folha_dir);
        delete Raiz;
    }
}

Arvore_AVL :: Arvore_AVL()
{
    this->Raiz_avl=NULL;
}

Arvore_AVL :: ~Arvore_AVL()
{
    limpar_Arvore(Raiz_avl);
}

void Arvore_AVL :: setRaizAVL (folha_avl* Raiz_avl) {this-> Raiz_avl = Raiz_avl;}
folha_avl* Arvore_AVL :: getRaizAVL () {return this-> Raiz_avl;}
bool Arvore_AVL :: Arvore_AVL_vazia () {return (Raiz_avl == NULL);}

void Arvore_AVL :: Inserir_avl (word keyword)
{
    bool brota;
    Inserir_arvore_avl(Raiz_avl, keyword, brota);
}

void Arvore_AVL :: Inserir_arvore_avl (folha_avl*& Raiz_avl, word keyword, bool& brota)
{
    if(Raiz_avl==NULL)
    {
        Raiz_avl = new folha_avl;
        Raiz_avl->dado_avl=keyword;
        Raiz_avl->folha_esq_avl=NULL;
        Raiz_avl->folha_dir_avl=NULL;
        Raiz_avl->fator_balanceamento=0;
        brota = true;
        return;
    }   
    if(keyword.contador > Raiz_avl->dado_avl.contador)
    {
        Inserir_arvore_avl(Raiz_avl->folha_dir_avl, keyword, brota);
        if(brota)
            Raiz_avl->fator_balanceamento += 1;
    }
    else
    {
        Inserir_arvore_avl(Raiz_avl->folha_esq_avl, keyword, brota);
        if(brota)
            Raiz_avl->fator_balanceamento -= 1;
    }
    Escolhe_rotacao(Raiz_avl);
    if(brota && Raiz_avl->fator_balanceamento==0)
        brota = false;
}

void Arvore_AVL :: Rotacao_simples_direita(folha_avl*& pai) 
{
    folha_avl* novopai = pai->folha_esq_avl;
    pai->folha_esq_avl = novopai->folha_dir_avl;
    novopai->folha_dir_avl = pai;
    pai = novopai;
}

void Arvore_AVL :: Rotacao_simples_esquerda(folha_avl*& pai)
{
    folha_avl* novopai = pai->folha_dir_avl;
    pai->folha_dir_avl = novopai->folha_esq_avl;
    novopai->folha_esq_avl = pai;
    pai = novopai;
}

void Arvore_AVL :: Rotacao_dupla_esquerda_direita(folha_avl*& pai)
{
    folha_avl* filho = pai->folha_esq_avl;
    Rotacao_simples_esquerda(filho);
    pai->folha_esq_avl = filho;
    Rotacao_simples_direita(pai);
}

void Arvore_AVL :: Rotacao_dupla_direita_esquerda(folha_avl*& pai)
{
    folha_avl* filho = pai->folha_dir_avl;
    Rotacao_simples_direita(filho);
    pai->folha_dir_avl = filho;
    Rotacao_simples_esquerda(pai);
}

void Arvore_AVL :: Escolhe_rotacao(folha_avl*& pai)
{
    folha_avl* filho;
    folha_avl* neto;

    if (pai->fator_balanceamento == -2)
    { 
        filho = pai->folha_esq_avl;

        if (filho->fator_balanceamento == -1)
        { 
            pai->fator_balanceamento = 0;
            filho->fator_balanceamento = 0;
            Rotacao_simples_direita(pai);
        } 
        else if (filho->fator_balanceamento == 0)
        { 
            pai->fator_balanceamento = -1;
            filho->fator_balanceamento = 1;
            Rotacao_simples_direita(pai);
        } 
        else if (filho->fator_balanceamento == 1)
        { 
            neto = filho->folha_dir_avl;
            if (neto->fator_balanceamento == -1)
            {
                pai->fator_balanceamento = 1;
                filho->fator_balanceamento = 0;
            } 
            else if (neto->fator_balanceamento == 0)
            {
                pai->fator_balanceamento = 0;
                filho->fator_balanceamento = 0;                
            } 
            else if (neto->fator_balanceamento == 1)
            {
                pai->fator_balanceamento = 0;
                filho->fator_balanceamento = -1;                
            }
            neto->fator_balanceamento = 0; 
            Rotacao_dupla_esquerda_direita(pai);            
        }
    } 
    else if(pai->fator_balanceamento == 2)
    { 
        filho = pai->folha_dir_avl;
        if (filho->fator_balanceamento == 1) 
        {
            pai->fator_balanceamento = 0;
            filho->fator_balanceamento = 0;
            Rotacao_simples_esquerda(pai);
        } 
        else if (filho->fator_balanceamento == 0)
        {         
            pai->fator_balanceamento = 1;
            filho->fator_balanceamento = -1;
            Rotacao_simples_esquerda(pai);
        } 
        else if (filho->fator_balanceamento == -1)
        {
            neto = filho->folha_esq_avl;
            if (neto->fator_balanceamento == -1)
            {
                pai->fator_balanceamento =  0;
                filho->fator_balanceamento = 1; 
            } 
            else if (neto->fator_balanceamento == 0)
            {
                pai->fator_balanceamento =  0;
                filho->fator_balanceamento = 0; 
            } 
            else if (neto->fator_balanceamento == 1)
            {
                pai->fator_balanceamento =  -1;
                filho->fator_balanceamento = 0; 
            }
            neto->fator_balanceamento = 0;
            Rotacao_dupla_direita_esquerda(pai);
        }
    }
}                  

void Arvore_AVL :: print_inordem(folha_avl* Raiz_avl, ofstream& out)
{
    if(Raiz_avl != NULL)
    {
        print_inordem(Raiz_avl->folha_esq_avl, out); 
        out << "Palavra: " << Raiz_avl->dado_avl.palavra <<" --- "<< " frequência: "<< Raiz_avl->dado_avl.contador << "\n";
        print_inordem(Raiz_avl->folha_dir_avl, out); 
    }
}

void Arvore_AVL :: print_preordem (folha_avl* Raiz_avl, ofstream& out)
{
    if(Raiz_avl != NULL)
    {
        out << "Palavra: " << Raiz_avl->dado_avl.palavra <<" --- "<< " frequência: "<< Raiz_avl->dado_avl.contador << "\n";
        print_preordem(Raiz_avl->folha_esq_avl, out);
        print_preordem(Raiz_avl->folha_dir_avl, out); 
    }
}

void Arvore_AVL :: print_posordem (folha_avl* Raiz_avl, ofstream& out)
{
    if(Raiz_avl != NULL)
    {
        print_posordem(Raiz_avl->folha_esq_avl, out); 
        print_posordem(Raiz_avl->folha_dir_avl, out); 
        out << "Palavra: " << Raiz_avl->dado_avl.palavra <<" --- "<< " frequência: "<< Raiz_avl->dado_avl.contador << "\n";
    }
}

void Arvore_AVL :: limpar_Arvore(folha_avl* Raiz_avl)
{
    if(Raiz_avl != NULL)
    {
        limpar_Arvore(Raiz_avl->folha_esq_avl);
        limpar_Arvore(Raiz_avl->folha_dir_avl);
        delete Raiz_avl;
    }
}

Arvore_Huffman :: Arvore_Huffman ()
{
    this->Raiz_Huffman = NULL;
}

Arvore_Huffman :: ~Arvore_Huffman ()
{
    //limpar arvore
}

void Arvore_Huffman :: setRaizHuffman (folha_huffman* Raiz_Huffman) {this-> Raiz_Huffman = Raiz_Huffman;}
folha_huffman* Arvore_Huffman :: getRaizHuffman () {return this-> Raiz_Huffman;}

void Arvore_Huffman :: Inserir_arvore_huffman(folha_huffman*& Raiz_Huffman, vector <word> heap)
{
    for(short int i = 0; i < K; i++)
    {
        folha_huffman* aux = new folha_huffman;
        word data_string;
        data_string.contador = heap[i].contador;
        data_string.palavra = heap[i].palavra;

        aux->dado.contador = heap[i].contador;
        aux->dado = data_string;

        aux->folha_dir = NULL;
        aux->folha_esq = NULL;

        minimos.push(aux);
    } 
    while (minimos.size() > 1)
    {
        folha_huffman* esq = minimos.top();
        minimos.pop();

        folha_huffman* dir = minimos.top();
        minimos.pop();

        folha_huffman* aux1 = new folha_huffman;
        aux1->dado.palavra = "#";
        aux1->dado.contador = esq->dado.contador + dir->dado.contador;
        aux1->folha_esq = esq;
        aux1->folha_dir = dir;

        minimos.push(aux1);
    }
    Raiz_Huffman = minimos.top(); 
}

void Arvore_Huffman :: limpar_Arvore (folha_huffman* Raiz_Huffman)
{
    if (Raiz_Huffman == nullptr)
        return;

    limpar_Arvore(Raiz_Huffman->folha_esq);
    limpar_Arvore(Raiz_Huffman->folha_dir);

    delete Raiz_Huffman;
}

void Arvore_Huffman :: print_posordem(folha_huffman* Raiz_Huffman, ofstream& out)
{
    if (Raiz_Huffman == NULL)
        return;
    print_posordem(Raiz_Huffman->folha_esq, out);
    print_posordem(Raiz_Huffman->folha_dir, out);
    if (Raiz_Huffman->dado.palavra != "#")
        out << "Palavra: " << Raiz_Huffman->dado.palavra <<" --- "<< " frequência: "<< Raiz_Huffman->dado.contador << "\n";
}

void Arvore_Huffman :: print_preordem (folha_huffman* Raiz_Huffman, ofstream& out)
{
    if (Raiz_Huffman == NULL)
        return;

    if (Raiz_Huffman->dado.palavra != "#")
        out << "Palavra: " << Raiz_Huffman->dado.palavra <<" --- "<< " frequência: "<< Raiz_Huffman->dado.contador << "\n";
    print_preordem(Raiz_Huffman->folha_esq, out);
    print_preordem(Raiz_Huffman->folha_dir, out);
}

void Arvore_Huffman :: print_inordem(folha_huffman* Raiz_Huffman, ofstream& out)
{
    if (Raiz_Huffman == NULL)
        return;

    print_inordem(Raiz_Huffman->folha_esq, out);
    if (Raiz_Huffman->dado.palavra != "#")
        out << "Palavra: " << Raiz_Huffman->dado.palavra <<" --- "<< " frequência: "<< Raiz_Huffman->dado.contador << "\n";
    print_inordem(Raiz_Huffman->folha_dir, out);
}
