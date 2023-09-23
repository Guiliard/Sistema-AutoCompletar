<h1 align="center"> Sistema-AutoCompletar </h1>
<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Compilation-Make-orange.svg"/>
</div>
<br><div align=center>
<img src="https://github.com/Guiliard/Sistema-AutoCompletar/assets/127882640/81df55e3-31a0-4662-a292-30669decaa6f.png" width="850px">
</div>

# Introdução

Foi proposto um problema de sugestão de dados em base aos <i>K</i> itens mais valiosos de um conjunto de informações. Nessa situação, os grupos de dados são arquivos que contém textos sem formatação (Arquivos ASCII), e os itens são palavras. A partir dessa busca, tais elementos são utilizados para criar um sistema autocompletar, permitindo que o usuário busque palavras específicas, e tenha as <i>K</i> palavras mais frequêntes como retorno. A partir disso, pressupoê-se que estruturas de dados complexas sejam devidamente operadas, bem como as estruturas auxiliares e variáveis que contribuem para a resolução do problema.
<p>Vale ressaltar que esse trabalho é uma continuação do projeto <a href="https://github.com/Guiliard/Top-K-Elementos" target="_blank">Top-K-Elementos</a>, seguindo as regras e diretrizes especificadas nele.

# Descrição do Problema

Em múltiplos arquivos ".data", encontram-se conjuntos de dados (textos), os quais devem ser lidos e tokenizados (separados em palavras). A partir disso, deve-se fornecer para o programa, como entrada, em um arquivo nomeado como "palavras.txt", as palavras que serão pesquisadas pelo usuário. Com tais informações, se, em um texto, existir aquela palavra pesquisada, todo o processo descrito no projeto <a href="https://github.com/Guiliard/Top-K-Elementos" target="_blank">Top-K-Elementos</a> deve ser construído. Após isso, as  as <i>K</i> palavras mais valiosas(frequêntes) devem ser armazedas em 3 diferentes estruturas de dados complexas: Árvore Binária, Árvore AVL e Árvore de <i>Huffman</i>, com cada uma possuindo suas peculariedades. Por fim, espera-se, como saída, um arquivo "output.data", contendo o resultado de todo esse procedimento.

Para o processo de leitura, considera-se as mesmas regras descritas no projeto <a href="https://github.com/Guiliard/Top-K-Elementos" target="_blank">Top-K-Elementos</a>. 

Para o processo de saída, vale-se das mesmas regras, contudo, acrescidas de tais informações:
- Construção lógica das 3 Árvores (as quais serão explicadas posteriormente).
- Especificação da palavra pesquisada no arquivo "output.data".

# Solução Proposta

<p>Para esse tipo de problema, foi proposto um código que contém 5 arquivos principais: Trees.hpp, Trees.cpp, Methods.hpp, Methods.cpp e main.cpp.<br>

- ```Trees.hpp``` : Classes que possuem a declaração de variáveis e funções envolvidas no processo de construção das Árvores (Binária, AVL e <i>Huffman</i>). <br>
- ```Trees.cpp``` : Arquivo que contém a estruturação das funções envolvidas nas classes correspondente. <br>
- ```Methods.hpp``` : Classe que possui a declaração dos atributos (características) e métodos (funções) envolvidas no processo de armazenamento e contagem de palavras. É importante ressaltar que é nesse arquivo que se encontra a declaração do valor assumido por <i>K</i>. <br>
- ```Methods.cpp``` : Arquivo que contém a estruturação das funções envolvidas na classe correspondente. <br>
- ```main.cpp``` : Arquivo fonte, responsável por chamar as funções contidas nas classes , realizar o processo de seleção das <i>K</i> palavras mais valiosas e armazenar tais itens nas estruturas de dados complexas.<br>

Em primeiro lugar, vale ressaltar as classes utilizadas para a elaboração das estruturas de dados (Árvores) em questão, as quais se localizam no arquivo ```Trees.hpp```.

<strong><h4>Árvore Binaria :</h4></strong>
```cpp
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
```

<strong><h4>Árvore AVL :</h4></strong>
```cpp
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
```

<strong><h4>Árvore <i>Huffman</i> :</h4></strong>
```cpp
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
```
Ademais, vale ressaltar que todas as árvores em questão são instanciadas na classe ```Leitor```, a qual é declarada no arquivo ```Methods.hpp```, para que, dessa forma, os <i>K</i> elementos escolhidos previamente nessa classe fossem devidamente armazenados. Vale ressaltar que a classe ```Leitor``` possui apenas uma alteração quando comparada ao do trabalho <a href="https://github.com/Guiliard/Top-K-Elementos" target="_blank">Top-K-Elementos</a>. Essa alteração, a qual consiste na adição de um método, foi necessária para realizar a verificação se a palavra escolhida pelo usuário estava contida ou não naquele conjunto de dados e, caso estivesse, o processo de seleção e armazenamento seria iniciado.
```cpp
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
```
- Detalhamento da função ```Verifica```.

Tendo evidenciado as classes e os códigos adicionados nesse trabalho, volta-se para a explicação de como funciona as 3 estruturas de dados selecionadas: Árvore Binária, Árvore AVL e Árvore <i>Huffman</i>.

<strong><h4>Explicação - Árvore Binaria :</h4></strong>

Uma árvore binária é uma estrutura de dados hierárquica baseada em divisão e conquista utilizada para armazenamento e pesquisa de dados, onde cada nó(dado) pode ter, no máximo, dois filhos: um à esquerda e um à direita, sendo os filhos da esquerda menores do que o nó pai e os filhos da direita maiores do que o nó pai. É importante ressaltar que o nó inicial é chamado de raiz, e os nós sem filhos são chamados de nós folha. Tal estrutura, assim como todas as árvores, pode ser percorrida em diferentes ordens: in-ordem, pre-ordem e pos-ordem. Vale ressaltar que todos os caminhamentos estão presentes no arquivo "output.data".
- Custo: <i>O(log * n)</i>, onde <i>n</i> é o número de nós (itens) inseridos na estrutura em árvore, ou seja, <i>K</i>.




# Casos Especiais

# Casos Sem Tratamento e Possíveis Erros

# Implementação

# Conclusão

# Especificações do Dispositivo Utilizado

| Componentes            | Detalhes                                                                                         |
| -----------------------| -----------------------------------------------------------------------------------------------  |
|  `Processador`         | Intel(R) Core(TM) i7-1065G7 CPU @ 1.30GHz   1.50 GHz                                             |
|  `RAM Instalada`       | 8.0 GB (Utilizável: 7.8 GB)                                                                      |
|  `Tipo de Sistema`     | Sistema Operacional de 64 bits, processador baseado em x64                                       |
|  `Sistema Operacional` | Edição Windows 11 Home Single Language, versão 22H2                                              |

# Compilação e Execução

Um arquivo Makefile que realiza todo o procedimento de compilação e execução está disponível no código. Para utilizá-lo, siga as diretrizes de execução no terminal:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Referências

[1] MAIOLI, DOUGLAS - Repositório GitHub, @professordouglasmaioli: Árvore AVL - Disponível em: https://github.com/professordouglasmaioli. Acessado em 19 de Setembro de 2023.

[2] CORMEN, T. H. et al. Introduction to Algorithms, third edition. [s.l.] MIT Press, 2012. Acessado em 01 de Março de 2023.

[3] PIRES, MICHEL - Repositório GitHub, @mpiress: Basic_Tree - Disponível em: https://github.com/mpiress/basic_tree. Acessado em 19 de Setembro de 2023.

[3] PIRES, MICHEL - Repositório GitHub, @mpiress: HeapSort - Disponível em: https://github.com/mpiress/HeapSort. Acessado em 20 de Agosto de 2023.
