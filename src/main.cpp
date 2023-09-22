#include "Methods.hpp"

#define NUM_ARQUIVOS 6

int main()
{
    Leitor *texto = new Leitor();
    vector <unordered_map <string, word>> textos;
    ifstream arq; short int cont = 0;
    ofstream out;
    out.open("dataset/output.data");
    while(cont < NUM_ARQUIVOS)
    {
        string inicio = "dataset/input", meio = to_string(cont+1), fim = ".data";
        string nomearq = inicio + meio + fim;
        arq.open(nomearq);
        texto->Cria_Hash(arq);
        textos.push_back(texto->geTHash());
        texto->Limpeza();
        cont++;
    }
    for(unsigned long int i = 0; i < textos.size(); i++)
        texto->Verifica(textos[i], i, out);
    out.close();
    return 0;  
}