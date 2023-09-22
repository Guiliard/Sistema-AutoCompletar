#include "Methods.hpp"

Leitor :: Leitor()
{
}

void Leitor :: setPalavra (word palavra) {this->palavra=palavra;}
word Leitor :: getPalavra () {return this->palavra;}
void Leitor :: setHash (unordered_map <string, word> hash) {this->hash=hash;}
unordered_map <string, word> Leitor :: geTHash() {return this->hash;}
void Leitor :: setHash_Stop_Words (unordered_map <string, string> hash_stop_words) {this->hash_stop_words=hash_stop_words;}
unordered_map <string, string> Leitor :: getHash_Stop_Words() {return this->hash_stop_words;}

string Leitor :: Leitura (ifstream &arq)
{
    string texto, linha;
    while (!arq.eof())
    {
        getline(arq, linha);
        if(!linha.empty())
            linha = linha + " ";
        texto = texto + linha;
    }
    arq.close();

    palavras_pesquisadas.clear();
    ifstream arq3; arq3.open("dataset/palavras.txt");
    string palavra_pesquisada;
    while (!arq3.eof())
    {
        getline(arq3, palavra_pesquisada);
        palavras_pesquisadas.push_back(palavra_pesquisada);
    }
    arq3.close();

    ifstream arq2; 
    arq2.open("dataset/stopwords.txt");
    string palavra;
    while (!arq2.eof())
    {
        getline(arq2, palavra);
        hash_stop_words[palavra] = palavra;
    }
    arq2.close(); return texto;
}

string Leitor :: Tratamento_para_Hash (ifstream &arq)
{
    string texto_para_tratar = Leitura (arq);
    
    for (char &letra : texto_para_tratar) 
    {
        letra = tolower(letra);
    }

    char ponto1 = '.', ponto2 = ',', ponto3 = ':', ponto4 = ';', ponto5 = '/', ponto6 = '"', ponto7 = '!', ponto8 = '?';
    char ponto9 = '(', ponto10 = ')';
    for (char &c : texto_para_tratar) 
    {
        if (c == ponto1 || c == ponto2 || c == ponto3 || c == ponto4 || c == ponto5 || c == ponto6 || c == ponto7 || c == ponto8 || c == ponto9 || c == ponto10) 
        {
            c = ' ';
        }
    }

    string travs = "--";
    size_t position;
    while(1)
    {
        position = texto_para_tratar.find(travs);
        if (position != std::string::npos) 
        {
            texto_para_tratar[position] = ' '; texto_para_tratar[position+1] = ' ';
        }
        else
            break;
    }
    return texto_para_tratar;
}

void Leitor :: Cria_Hash(ifstream &arq)
{
    string texto = Tratamento_para_Hash (arq);
    istringstream tok(texto);
    string palavra_separada;

    while (tok >> palavra_separada) 
    {
        auto stop = hash_stop_words.find(palavra_separada);
        if(palavra_separada != "-" && stop == hash_stop_words.end() && palavra_separada != "—")
        {
            auto verifica = hash.find(palavra_separada);
            if (verifica != hash.end()) 
                hash [palavra_separada].contador++;
            else
            {
                hash [palavra_separada].palavra = palavra_separada;
                hash [palavra_separada].contador = 1;
            }
        }
    }
}

void Leitor :: Verifica (unordered_map <string, word> tabela, short int num_texto, ofstream& out)
{
    out << "\n----------INPUT " << to_string(num_texto+1) << "----------" << "\n"; 
    for(unsigned long int i = 0; i < palavras_pesquisadas.size(); i++)
    {
        out << "\nPalavra a ser pesquisada no texto: " << palavras_pesquisadas[i];
        if(tabela.count(palavras_pesquisadas[i])==1)
        {
            out << "\nA palavra " << palavras_pesquisadas[i] << " foi encontrada " << tabela[palavras_pesquisadas[i]].contador << " vezes!";
            Cria_Heap(tabela, i, out);
            if(i+1 == palavras_pesquisadas.size())
                break;
        }
        else 
            out << "\nA palavra " << palavras_pesquisadas[i] << " não foi encontrada no texto...\n";
    }
}

void Leitor :: Cria_Heap (unordered_map <string, word> tabela, short int t, ofstream& out)
{
    Arvore_binaria* arvore = new Arvore_binaria(); folha* B_Tree = NULL;
    Arvore_AVL* arvore_avl = new Arvore_AVL();
    Arvore_Huffman* arvore_huffman = new Arvore_Huffman(); folha_huffman* H_Tree = NULL;
    short int j = 0; word k_mais_um;
	for (const auto& pair : tabela) 
    {
        if(j < K) { heap.push_back(pair.second); j++; }
        else { Opera_Heap(); if(heap[0].contador < pair.second.contador){ k_mais_um = heap[0]; heap[0] = pair.second;}}
    }
    for(short int i = 0; i < K; i++)
    {
        if(heap[i].palavra == palavras_pesquisadas[t])
            heap[i] = k_mais_um;
    }
    for(short int i = 0; i < K; i++)
    {
        arvore->Inserir_arvore(&B_Tree, heap[i]);
        arvore_avl->Inserir_avl(heap[i]);

    }
    arvore_huffman->Inserir_arvore_huffman(H_Tree, heap);
    heap.clear();
    out << "\n\n--> Árvore Binária: \n";
    out << "\nIn-Ordem:\n";
    arvore->print_inordem(B_Tree, out);
    out << "\nPre-Ordem:\n";
    arvore->print_preordem(B_Tree, out);
    out << "\nPos-Ordem:\n";
    arvore->print_posordem(B_Tree, out);
    out << "\n\n--> Árvore AVL: \n";
    out << "\nIn-Ordem:\n";
    arvore_avl->print_inordem(arvore_avl->getRaizAVL(), out);
    out << "\nPre-Ordem:\n";
    arvore_avl->print_preordem(arvore_avl->getRaizAVL(), out);
    out << "\nPos-Ordem:\n";
    arvore_avl->print_posordem(arvore_avl->getRaizAVL(), out);
    out << "\n\n--> Ávore de Huffman: \n";
    out << "\nIn-Ordem:\n";
    arvore_huffman->print_inordem(H_Tree, out);
    out << "\nPre-Ordem:\n";
    arvore_huffman->print_preordem(H_Tree, out);
    out << "\nPos-Ordem:\n";
    arvore_huffman->print_posordem(H_Tree, out);
    arvore->limpar_Arvore(B_Tree);
    arvore_avl->limpar_Arvore(arvore_avl->getRaizAVL());
    arvore_huffman->limpar_Arvore(H_Tree);
    Limpeza();
}

void Leitor :: Opera_Heap()
{
    short int inicio = (K/2)-1;
    for(short int i = inicio; i > -1 ; i--)
    {
        if(heap[i].contador > heap[i+i].contador)
        {
            word aux;
            aux = heap [i];
            heap[i] = heap [i+i];
            heap[i+i] = aux;
        }
        if(heap[i].contador > heap[i+i+1].contador)
        {
            word aux;
            aux = heap [i];
            heap[i] = heap [i+i+1];
            heap[i+i+1] = aux;
        }
    }
}

void Leitor :: Limpeza()
{
    hash.clear();
    hash_stop_words.clear();
}