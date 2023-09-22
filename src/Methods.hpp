#ifndef __METHODS_HPP
#define __METHODS_HPP

#include "Trees.hpp"

class Leitor
{
    private:
    word palavra;
    unordered_map <string, word> hash;
    unordered_map <string, string> hash_stop_words;
    vector <word> heap;
    vector <string> palavras_pesquisadas;

    public:
    Leitor();

    void setPalavra (word palavra);
    word getPalavra ();

    void setHash (unordered_map <string, word> hash);
    unordered_map <string, word> geTHash();

    void setHash_Stop_Words (unordered_map <string, string> hash_stop_words);
    unordered_map <string, string> getHash_Stop_Words();

    void setVector (vector <word> ordenar);
    vector <word> getVector();

    string Leitura(ifstream &arq);
    string Tratamento_para_Hash(ifstream &arq);

    void Cria_Hash(ifstream &arq); void Verifica(unordered_map <string, word> tabela, short int num_texto, ofstream& out);
    void Cria_Heap(unordered_map <string, word> tabela, short int t, ofstream& out); void Opera_Heap();
    void Limpeza();
};
#endif
