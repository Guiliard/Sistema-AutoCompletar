#ifndef __TREES_HPP
#define __TREES_HPP

#include <bits/stdc++.h>

#define K 20

using namespace std;

typedef struct word
{
    string palavra;
    int contador;

}word;

typedef struct folha
{
    word dado;
    folha *folha_esq, *folha_dir;

}folha;

class Arvore_binaria
{
    private:
    folha* Raiz;

    public:
    Arvore_binaria();
    ~Arvore_binaria();

    void setRaiz(folha* Raiz);
    folha* getRaiz();

    bool Arvore_vazia();

    void Inserir_arvore(folha** Raiz, word keyword);

    void print_inordem(folha* Raiz, ofstream& out);
    void print_preordem(folha* Raiz, ofstream& out);
    void print_posordem(folha* Raiz, ofstream& out);

    void limpar_Arvore(folha* Raiz);

};

typedef struct folha_avl
{
    word dado_avl;
    short int fator_balanceamento;
    folha_avl* folha_esq_avl, *folha_dir_avl;

}folha_avl;

class Arvore_AVL
{
    private:
    folha_avl* Raiz_avl;

    public:
    Arvore_AVL();
    ~Arvore_AVL();

    void setRaizAVL(folha_avl* Raiz_avl);
    folha_avl* getRaizAVL();

    bool Arvore_AVL_vazia();

    void Inserir_avl(word keyword);
    void Inserir_arvore_avl(folha_avl*& Raiz_avl, word keyword, bool& brota);

    void Rotacao_simples_direita(folha_avl*& arvore);
    void Rotacao_simples_esquerda(folha_avl*& arvore);
    void Rotacao_dupla_direita_esquerda(folha_avl*& arvore);
    void Rotacao_dupla_esquerda_direita(folha_avl*& arvore);

    void Escolhe_rotação(folha_avl*& arvore);

    void print_inordem(folha_avl* Raiz_avl, ofstream& out);
    void print_preordem(folha_avl* Raiz_avl, ofstream& out);
    void print_posordem(folha_avl* Raiz_avl, ofstream& out);

    void limpar_Arvore(folha_avl* Raiz_avl);
};

typedef struct folha_huffman
{
    word dado;
    folha_huffman *folha_esq, *folha_dir;

}folha_huffman;

struct comp_huffman
{
    constexpr bool operator()(folha_huffman* const& a, folha_huffman* const& b) const noexcept
    {
    return a->dado.contador >= b->dado.contador;
    }
};

class Arvore_Huffman
{
    private:
    priority_queue <folha_huffman*, vector<folha_huffman*>, comp_huffman> minimos;
    folha_huffman* Raiz_Huffman;

    public:
    Arvore_Huffman();
    ~Arvore_Huffman();

    void setRaizHuffman(folha_huffman* Raiz_Huffman);
    folha_huffman* getRaizHuffman();

    void Inserir_arvore_huffman(folha_huffman*& Raiz_Huffman, vector <word> heap);

    void print_inordem(folha_huffman* Raiz_Huffman, ofstream& out);
    void print_preordem(folha_huffman* Raiz_Huffman, ofstream& out);
    void print_posordem(folha_huffman* Raiz_Huffman, ofstream& out);

    void limpar_Arvore(folha_huffman* Raiz_Huffman);

};
#endif