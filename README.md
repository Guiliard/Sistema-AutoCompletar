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

Em múltiplos arquivos ".data", encontram-se conjuntos de dados (textos), os quais devem ser lidos e tokenizados (separados em palavras). A partir disso, deve-se fornecer para o programa, como entrada, em um arquivo nomeado como "palavras.txt", as palavras que serão pesquisadas pelo usuário. Com tais informações, se, em um texto, existir aquela palavra pesquisada, todo o processo descrito no projeto <a href="https://github.com/Guiliard/Top-K-Elementos" target="_blank">Top-K-Elementos</a> deve ser construído. Após isso, as  as <i>K</i> palavras mais valiosas (frequêntes) devem ser armazedas em 3 diferentes estruturas de dados complexas: Árvore Binária, Árvore AVL e Árvore de <i>Huffman</i>, com cada uma possuindo suas peculariedades. Por fim, espera-se, como saída, um arquivo "output.data", contendo o resultado de todo esse procedimento.

Para o processo de leitura, considera-se as mesmas regras descritas no projeto <a href="https://github.com/Guiliard/Top-K-Elementos" target="_blank">Top-K-Elementos</a>. 

Para o processo de saída, vale-se das mesmas regras, contudo, acrescidas de tais informações:
- Construção lógica das três Árvores (as quais serão explicadas posteriormente).
- Especificação da palavra pesquisada no arquivo "output.data".

# Solução Proposta

<p>Para esse tipo de problema, foi proposto um código que contém cinco arquivos principais: Trees.hpp, Trees.cpp, Methods.hpp, Methods.cpp e main.cpp.<br>

- ```Trees.hpp``` : Classes que possuem a declaração de variáveis e funções envolvidas no processo de construção das Árvores (Binária, AVL e <i>Huffman</i>). <br>
- ```Trees.cpp``` : Arquivo que contém a estruturação das funções envolvidas nas classes correspondentes. <br>
- ```Methods.hpp``` : Classe que possui a declaração dos atributos (características) e métodos (funções) envolvidas no processo de armazenamento e contagem de palavras. É importante ressaltar que é nesse arquivo que se encontra a declaração do valor assumido por <i>K</i>. <br>
- ```Methods.cpp``` : Arquivo que contém a estruturação das funções envolvidas na classe correspondente. <br>
- ```main.cpp``` : Arquivo fonte, responsável por chamar as funções contidas nas classes , realizar o processo de seleção das <i>K</i> palavras mais valiosas e armazenar tais itens nas estruturas de dados complexas.<br>

Em primeiro lugar, expõe-se as classes utilizadas para a elaboração das estruturas de dados (Árvores) em questão, as quais se localizam no arquivo ```Trees.hpp```.

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
Ademais, vale ressaltar que as estruturas em questão são instanciadas na classe ```Leitor```, a qual é declarada no arquivo ```Methods.hpp```, para que, dessa forma, os <i>K</i> elementos escolhidos previamente nessa classe fossem devidamente armazenados. Tendo evidenciado tal ponto, volta-se para a explicação do funcionamento das árvores que compõe a solução proposta:

<strong><h4>Explicação - Árvore Binaria :</h4></strong>

Uma árvore binária é uma estrutura de dados hierárquica baseada em divisão e conquista utilizada para armazenamento e pesquisa de dados, onde cada nó(dado) pode ter, no máximo, dois filhos: um à esquerda e um à direita, sendo os filhos da esquerda menores do que o nó pai e os filhos da direita maiores do que o nó pai. É importante ressaltar que o nó inicial é chamado de raiz, e os nós sem filhos são chamados de nós folhas. Tal estrutura, assim como todas as árvores, pode ser percorrida em diferentes ordens: in-ordem, pré-ordem e pós-ordem. Vale ressaltar que todos os caminhamentos estão presentes no arquivo "output.data".
- Função principal: ```void Inserir_arvore(folha** Raiz, word keyword)```.
- Custo: <i>O(log * n)</i>, onde <i>n</i> é o número de nós (itens) inseridos na estrutura em árvore, ou seja, <i>K</i>.

<strong><h4>Explicação - Árvore AVL :</h4></strong>

Uma Árvore AVL é uma estrutura de dados de árvore binária balanceada, projetada para manter o equilíbrio da árvore, garantindo que a diferença de altura entre as subárvores da esquerda e da direita de qualquer nó (chamada de fator de balanceamento) seja no máximo 1 ou -1. Tal fato contribuí para o desempenho de operações de busca, inserção e remoção em tempo logarítmico. É importante salientar que quando um nó é inserido, a árvore é reequilibrada automaticamente para manter o fator de balanceamento. Sua característica principal (uso de rotações) é responsável por reduzir a probabilidade de degeneração da árvore em uma lista vinculada, mantendo-a balanceada.
- Função principal: ```void Inserir_arvore_avl(folha_avl*& Raiz_avl, word keyword, bool& brota)```.

<strong>Rotações</strong>

Caso o fator de balanceamento de um nó exceder o limite (de 1 até -1), a árvore não será mais uma AVL, e rotações serão usadas para restaurar o equilíbrio. Existem quatro tipos principais de rotações em uma árvore AVL:

<strong> - Rotação simples à esquerda: </strong>
Essa rotação é usada quando o fator de balanceamento de um nó se torna menor que -1 devido a uma inserção à esquerda do nó desequilibrado. A rotação à esquerda reequilibra a árvore movendo o nó desequilibrado para a esquerda.

- Função: ```void Rotacao_simples_esquerda(folha_avl*& arvore)```.
    
```cpp
                                               A                        
                                                \                       B  
                                                 B         ->         /   \   
                                                  \                  A     C
                                                   C                  
```

<strong> - Rotação simples à direita: </strong>
<p>Esta rotação é usada quando o fator de balanceamento de um nó se torna maior que 1 devido a uma inserção à direita do nó desequilibrado. A rotação à direita reequilibra a árvore movendo o nó desequilibrado para a direita.
    
- Função: ```void Rotacao_simples_direita(folha_avl*& arvore)```.

```cpp
                                                C
                                               /                        B
                                              B           ->          /   \
                                             /                       A     C
                                            A
```

<strong> - Rotação dupla direita_esquerda: </strong>
Esta rotação é usada quando o fator de balanceamento de um nó se torna maior que 1 devido a uma inserção à direita do filho esquerdo do nó desequilibrado. A rotação direita-esquerda reequilibra a árvore realizando uma rotação simples à direita seguida de uma rotação simples à esquerda.

- Função: ```void Rotacao_dupla_esquerda_direita(folha_avl*& arvore)```.

```cpp
                                             A   
                                              \                          B
                                               C           ->          /   \
                                              /                       A     C
                                             B
```

<strong> - Rotação dupla esquerda_direira: </strong>
Esta rotação é usada quando o fator de balanceamento de um nó se torna menor que -1 devido a uma inserção à esquerda do filho direito do nó desequilibrado. A rotação esquerda-direita reequilibra a árvore realizando uma rotação simples à esquerda seguida de uma rotação simples à direita.

- Função: ```void Rotacao_dupla_direita_esquerda(folha_avl*& arvore)```.

```cpp
                                             C   
                                            /                          B
                                           A             ->          /   \
                                            \                       A     C
                                             B
```

- Custo (garantido): <i>O(log * n)</i>, onde <i>n</i> é o número de nós (itens) inseridos na estrutura em árvore, ou seja, <i>K</i>.

<strong><h4>Explicação - Árvore <i>Huffman</i> :</h4></strong>

A Árvore de <i>Huffman</i>, sendo desenvolvida por David A. Huffman em 1952 é uma técnica de compressão de dados amplamente utilizada para reduzir o tamanho de dados. Sua construção inicia-se a contagem da frequência de cada elemento (palavras) no conjunto de dados a ser comprimido. Após isso, os elementos são organizados em nós de uma árvore binária, onde os itens com menor frequência estão nas folhas e os nós internos representam somas de frequências. Desse modo, atribui-se códigos binários únicos para cada símbolo, percorrendo a árvore de <i>Huffman</i> da raiz até as folhas. Os códigos são atribuídos de tal forma que nenhum código seja um prefixo de outro. Por fim, substitui-se os símbolos originais pelos códigos Huffman correspondentes. O resultado é uma representação compacta dos dados originais.

- Custo: <i>O(log * n)</i>, onde <i>n</i> é o número de nós (itens) inseridos na estrutura em árvore, ou seja, <i>K</i>.

<div align=center>
<img src="https://github.com/Guiliard/Sistema-AutoCompletar/assets/127882640/ec22cf5a-b293-41ce-b903-44272f66db97.png" width="420px"/>
</div>
<p  align="center">
Exemplo da uma árvore binária genérica.
</p>

Dado as estruturas principais do programa, evidencia-se que as funções contidas na classe ```Methods.cpp``` são as mesmas declaradas no projeto <a href="https://github.com/Guiliard/Top-K-Elementos" target="_blank">Top-K-Elementos</a>. Contudo, uma foi adicionada: 

- ```Verifica```: verificação se a palavra pesquisada pelo usuário existe ou não no texto. Caso exista, o código continua sua execução.

Com a interconexão de todas essas funções, estruturas e classes, a seleção, armazenamento e classificação dos <i>K</i> itens mais valiosos do conjunto de dados se torna possível.

# Casos Especiais

<strong><h4>Minimos (priority_queue) :</h4></strong>
Conforme a explicação dada na árvore <i>Huffman</i>, é necessário encontrar os itens com menor frequência, para que esses possam ser armazenados nas folhas que possuem nós internos dados pelas somas de tais frequências. Logo, para se obter esses elementos, necessitou-se escolher um método de ordenação eficiente. Por isso, foi-se utilizada uma fila de prioridades (priority_queue), a qual recebe os dados (itens) de forma desordenada e retorna as palavras em ordem crescente, orientando-se pela frequência de cada uma por meio de um <i>operator</i>. Com isso, o processo de seleção das menores recorrências para a construção da árvore <i>Huffman</i> foi construído.
- Sintaxe: ```priority_queue <folha_huffman*, vector<folha_huffman*>, comp_huffman> minimos```.
- Custo médio: <i>O(log * n)</i>, onde <i>n</i> é o número de elementos inseridos na estrutura, ou seja, <i>K</i>.

```cpp
  struct comp_huffman
{
    constexpr bool operator()(folha_huffman* const& a, folha_huffman* const& b) const noexcept
    {
    return a->dado.contador >= b->dado.contador;
    }
};
```
- <i>Operator</i> utlizado na fila de prioridades que compara as frequências das palavras inseridas.

Além disso, caso a palavra pesquisada esteja na lista das <i>K</i> palavras mais importantes do texto, ela será substituída pela (<i>K</i>+1)º palavra mais frequênte do texto e, assim, a lógica do programa se segue normalmente.

# Casos Sem Tratamento e Possíveis Erros

Os limites do programa elaborado nessa prática são os mesmos evidenciados no trabalho  <a href="https://github.com/Guiliard/Top-K-Elementos" target="_blank">Top-K-Elementos</a>. Além disso, a árvore <i>Huffman</i> implementada nesse trabalho, apesar de seguir, veemente, a teoria e o conceito de tal estrutura, não evidencia os códigos de compactação dos elementos inseridos, apesar de que, segundo a lógica de David A. Huffman, o primeiro elemento terá código 0000, o segundo 0001, o terceiro 0010, e assim por diante seguindo uma sequência crescente em binário. Logo, tal característica, apesar de não estar evidenciada no arquivo de saída "output.data", não significa um erro exorbitande, já que tal processo pode ser dado de maneira trivial.   

- Primeira palavra da árvore de <i>Huffman</i>: É -- Frequência: 96 -- Código: 0000.

# Implementação

Considere os seguintes exemplos de entrada para o programa: 

|   Entrada     |    Conteúdo                      | Quantidade de linhas |
|---------------|----------------------------------|----------------------|
| input1.data   |  Texto_sobre_Filosofia.txt       | 1039                 |
| input2.data   |  Texto_sobre_Filosofia_2.txt     | 1025                 |
| input3.data   |  Texto_sobre_Globalização.txt    | 1029                 |
| input4.data   |  Texto_sobre_Política.txt        | 1017                 |
| input5.data   |  Texto_sobre_Tecnologia.txt      | 1027                 |
| input6.data   |  Texto_sobre_Tecnologia_2.txt    | 1020                 |
| stopwords.txt |  Artigos_e_Adjuntos.txt          | 207                  |
| palavras.txt  |  Palavras_Pesquisadas.txt        | 5                    |

<strong><h4>Palavras.txt :</h4></strong>
```
teoria
mundo
software
tecnologia
empreendedorismo
```

<strong><h4>input1.data (parcial) :</h4></strong>
```
Caros amigos, a infinita diversidade da realidade única nos obriga à análise do demônio de Laplace. Por outro lado, a complexidade dos estudos efetuados cumpre um papel essencial na formulação da fundamentação metafísica das representações. Assim mesmo, a forma geral da proposição significativa deverá confirmar as consequências decorrentes do sistema de conhecimento geral.

Neste sentido, o novo modelo estruturalista aqui preconizado auxilia a preparação e a composição das posturas dos filósofos divergentes com relação às atribuições conceituais. Baseando-se nos ensinamentos de Dewey, a canalizaçao do Ser do Ente garante a contribuição de um grupo importante na determinação das novas teorias propostas. A prática cotidiana prova que a consolidação das estruturas psico-lógicas não sistematiza essa relação, de tal modo que a pulsão funciona funciona como significado da determinação do Ser enquanto Ser.

Nunca é demais lembrar o peso e o significado destes problemas, uma vez que o conceito de diáthesis e os princípios fundamentais de rhytmos e arrythmiston facilita a criação do sistema de formação de quadros que corresponde às necessidades lógico-estruturais. Como Deleuze eloquentemente mostrou, o início da atividade geral de formação de conceitos obstaculiza a apreciação da importância dos paradigmas filosóficos. Acabei de provar que o desafiador cenário globalizado não oferece uma interessante oportunidade para verificação dos relacionamentos verticais entre as hierarquias conceituais. Se estivesse vivo, Foucault diria que o Übermensch de Nietzsche, ou seja, o Super-Homem, acarreta um processo de reformulação e modernização da substancialidade e causalidade entendidos como certezas fundamentais. Pretendo demonstrar que a expansão dos mercados mundiais pode nos levar a considerar a reestruturação das ciências discursivas.

Neste sentido, existem duas tendências que coexistem de modo heterogêneo, revelando a hegemonia do ambiente político representa uma abertura para a melhoria da fórmula da ressonância racionalista. Segundo Heidegger, o fenômeno da Internet se apresenta como experiência metapsicológica, devido à impermeabilização de um mundo povoado por objetos intencionais e transcendentes, interiores ao imanente infinito. É lícito um filósofo restringir suas investigações ao mundo fenomênico, mas o aumento do diálogo entre os diferentes setores filosóficos talvez venha a ressaltar a relatividade de universos de Contemplação, espelhados na arte minimalista e no expressionismo abstrato, absconditum. Este pensamento está vinculado à desconstrução da metafísica, pois a crescente influência da mídia consistiria na origem epistemológica de todos os recursos funcionais envolvidos.

Todas estas questões, devidamente ponderadas, levantam dúvidas sobre se o surgimento de impulsos psicossociais individualizantes reduziria a importância da corrente inovadora da qual fazemos parte. A ruptura definitiva com Kant é consumada quando o não-ser que não é nada é condição necessária das considerações acima? Nada se pode dizer, pois sobre o que não se pode falar, deve-se calar. Acima de tudo, o uno-múltiplo, repouso-movimento, finito indeterminado, agrega valor ao estabelecimento do fluxo de informações. Sob a perspectiva de Schopenhauer, a instauração do modo aporético do Uno é uma das consequências dos elementos envolvidos de maneira conclusiva? Nada se pode dizer a respeito.

Segundo Nietzsche, a indeterminação contínua de distintas formas de fenômeno promove a alavancagem das diversas correntes de pensamento. As experiências acumuladas demonstram que a geração de sistemas de coordenadas heterogêneas irredutíveis não pode mais se dissociar das regras de conduta normativas. Seguindo o fluxo da corrente analítica anglo-saxônica, o surgimento do comércio virtual possibilita uma melhor visão global da conjuntura histórico-social. O que temos que ter sempre em mente é que a universalidade eidética do puro-devir obstaculiza a admissão de uma ontologia do retorno esperado a longo prazo.

O movimento inverso da proaíresis, que avança -pro-, como a pro-lépsis, demonstra que o acompanhamento das preferências de consumo desafia a capacidade de equalização das coisas e o melhor dos mundos possíveis. Acima de tudo, é fundamental ressaltar que o comprometimento entre as ontologias faz parte de um processo de agenciamento das condições epistemológicas e cognitivas exigidas. O incentivo ao avanço tecnológico, assim como a determinação clara de objetivos não causa impacto indireto na reavaliação dos métodos utilizados na busca da verdade. Não obstante, uma adoção de metodologias descentralizadoras tem como componentes elementos indiscerníveis dos meios de comunicação, The Media, o fator condicionante da interdependência virtual.

Pensando mais a longo prazo, a valorização de fatores subjetivos estende o alcance e a importância da sensibilia dos não-sentidos. Em um dos seus momentos mais iluminados Heidegger afirmou que a percepção das dificuldades deve passar por modificações independentemente dos sinais peirceanos percebidos pelo sujeito imerso nos fenômenos sociais. O filósofo francês Ricoeur, defende que a abordagem de Zeit und Sein afeta positivamente a correta previsão da doxa, da opinião e da razão pura do espírito transcendente. Gostaria de enfatizar que a consequência da interpretação substitucional dos quantificadores recorre à experiência efetiva do levantamento das variáveis envolvidas. Todavia, a coerência das idéias contratualistas não parece corresponder a uma análise distributiva de conhecimentos empíricos provindos das afecções.

Ora, a univocidade da substância imanente constitui uma propriedade inalienável dos prospectos condicionalizantes e necessários a todo juízo empírico. O empenho em analisar a forma de uma transcendência imanente ou primordialefetua a conexão habitual das três instâncias de oposição centrais. Percebemos, cada vez mais, que o personagem conceitual imanente ao caos parece compendiar nossas conclusões experimentais a respeito das direções preferenciais no sentido do progresso filosófico. No mundo atual, o tríptico movimento de pensamento não sistematiza a estrutura da afirmação que o Ser é e o Não ser não é. É importante questionar o quanto o su-jeito de que fala Kant nos arrasta ao labirinto de sofismas obscuros da esfera do virtual, a saber, do pensamento em potência.

No entanto, não podemos esquecer que a revolução copernicana, entendida como ruptura, nos leva ao caminho impenetrável das múltiplas direções do ponto de transcendência do sentido enunciativo. Tendo em vista a extrema limitação dos meios empregados (como Husserl advertiu), o uso metafórico da linguagem, a respeito do significante e significado, estimula a padronização das retroações, proliferações, conexões e fractalizações do território desterritorializado. Podemos já vislumbrar o modo pelo qual a relevância da terceira antinomia da Antitética da Razão demonstra a irrefutabilidade das vantagens dos modos de análise convencionais.
```
<strong><h4>output.data (parcial) :</h4></strong>
```
----------INPUT 1----------

Palavra a ser pesquisada no texto: teoria
A palavra teoria foi encontrada 176 vezes!

--> Árvore Binária: 

In-Ordem:
Palavra: princípio ---  frequência: 91
Palavra: virtual ---  frequência: 93
Palavra: assim ---  frequência: 94
Palavra: maneira ---  frequência: 95
Palavra: quanto ---  frequência: 95
Palavra: pode ---  frequência: 95
Palavra: wittgenstein ---  frequência: 95
Palavra: É ---  frequência: 96
Palavra: vista ---  frequência: 96
Palavra: imanente ---  frequência: 104
Palavra: sentido ---  frequência: 110
Palavra: segundo ---  frequência: 114
Palavra: sobre ---  frequência: 114
Palavra: sistema ---  frequência: 115
Palavra: pensamento ---  frequência: 115
Palavra: priori ---  frequência: 125
Palavra: modo ---  frequência: 129
Palavra: condição ---  frequência: 134
Palavra: mundo ---  frequência: 134
Palavra: sujeito ---  frequência: 145

Pre-Ordem:
Palavra: virtual ---  frequência: 93
Palavra: princípio ---  frequência: 91
Palavra: imanente ---  frequência: 104
Palavra: assim ---  frequência: 94
Palavra: wittgenstein ---  frequência: 95
Palavra: pode ---  frequência: 95
Palavra: quanto ---  frequência: 95
Palavra: maneira ---  frequência: 95
Palavra: vista ---  frequência: 96
Palavra: É ---  frequência: 96
Palavra: pensamento ---  frequência: 115
Palavra: sentido ---  frequência: 110
Palavra: sobre ---  frequência: 114
Palavra: segundo ---  frequência: 114
Palavra: sistema ---  frequência: 115
Palavra: mundo ---  frequência: 134
Palavra: priori ---  frequência: 125
Palavra: condição ---  frequência: 134
Palavra: modo ---  frequência: 129
Palavra: sujeito ---  frequência: 145

Pos-Ordem:
Palavra: princípio ---  frequência: 91
Palavra: maneira ---  frequência: 95
Palavra: quanto ---  frequência: 95
Palavra: pode ---  frequência: 95
Palavra: É ---  frequência: 96
Palavra: vista ---  frequência: 96
Palavra: wittgenstein ---  frequência: 95
Palavra: assim ---  frequência: 94
Palavra: segundo ---  frequência: 114
Palavra: sistema ---  frequência: 115
Palavra: sobre ---  frequência: 114
Palavra: sentido ---  frequência: 110
Palavra: modo ---  frequência: 129
Palavra: condição ---  frequência: 134
Palavra: priori ---  frequência: 125
Palavra: sujeito ---  frequência: 145
Palavra: mundo ---  frequência: 134
Palavra: pensamento ---  frequência: 115
Palavra: imanente ---  frequência: 104
Palavra: virtual ---  frequência: 93


--> Árvore AVL: 

In-Ordem:
Palavra: princípio ---  frequência: 91
Palavra: virtual ---  frequência: 93
Palavra: assim ---  frequência: 94
Palavra: maneira ---  frequência: 95
Palavra: quanto ---  frequência: 95
Palavra: pode ---  frequência: 95
Palavra: wittgenstein ---  frequência: 95
Palavra: É ---  frequência: 96
Palavra: vista ---  frequência: 96
Palavra: imanente ---  frequência: 104
Palavra: sentido ---  frequência: 110
Palavra: segundo ---  frequência: 114
Palavra: sobre ---  frequência: 114
Palavra: sistema ---  frequência: 115
Palavra: pensamento ---  frequência: 115
Palavra: priori ---  frequência: 125
Palavra: modo ---  frequência: 129
Palavra: condição ---  frequência: 134
Palavra: mundo ---  frequência: 134
Palavra: sujeito ---  frequência: 145

Pre-Ordem:
Palavra: imanente ---  frequência: 104
Palavra: wittgenstein ---  frequência: 95
Palavra: assim ---  frequência: 94
Palavra: virtual ---  frequência: 93
Palavra: princípio ---  frequência: 91
Palavra: quanto ---  frequência: 95
Palavra: maneira ---  frequência: 95
Palavra: pode ---  frequência: 95
Palavra: vista ---  frequência: 96
Palavra: É ---  frequência: 96
Palavra: pensamento ---  frequência: 115
Palavra: segundo ---  frequência: 114
Palavra: sentido ---  frequência: 110
Palavra: sobre ---  frequência: 114
Palavra: sistema ---  frequência: 115
Palavra: mundo ---  frequência: 134
Palavra: modo ---  frequência: 129
Palavra: priori ---  frequência: 125
Palavra: condição ---  frequência: 134
Palavra: sujeito ---  frequência: 145

Pos-Ordem:
Palavra: princípio ---  frequência: 91
Palavra: virtual ---  frequência: 93
Palavra: maneira ---  frequência: 95
Palavra: pode ---  frequência: 95
Palavra: quanto ---  frequência: 95
Palavra: assim ---  frequência: 94
Palavra: É ---  frequência: 96
Palavra: vista ---  frequência: 96
Palavra: wittgenstein ---  frequência: 95
Palavra: sentido ---  frequência: 110
Palavra: sistema ---  frequência: 115
Palavra: sobre ---  frequência: 114
Palavra: segundo ---  frequência: 114
Palavra: priori ---  frequência: 125
Palavra: condição ---  frequência: 134
Palavra: modo ---  frequência: 129
Palavra: sujeito ---  frequência: 145
Palavra: mundo ---  frequência: 134
Palavra: pensamento ---  frequência: 115
Palavra: imanente ---  frequência: 104


--> Ávore de Huffman: 

In-Ordem:
Palavra: É ---  frequência: 96
Palavra: imanente ---  frequência: 104
Palavra: sentido ---  frequência: 110
Palavra: sobre ---  frequência: 114
Palavra: segundo ---  frequência: 114
Palavra: sistema ---  frequência: 115
Palavra: pensamento ---  frequência: 115
Palavra: priori ---  frequência: 125
Palavra: modo ---  frequência: 129
Palavra: mundo ---  frequência: 134
Palavra: condição ---  frequência: 134
Palavra: sujeito ---  frequência: 145
Palavra: princípio ---  frequência: 91
Palavra: virtual ---  frequência: 93
Palavra: assim ---  frequência: 94
Palavra: wittgenstein ---  frequência: 95
Palavra: maneira ---  frequência: 95
Palavra: pode ---  frequência: 95
Palavra: quanto ---  frequência: 95
Palavra: vista ---  frequência: 96

Pre-Ordem:
Palavra: É ---  frequência: 96
Palavra: imanente ---  frequência: 104
Palavra: sentido ---  frequência: 110
Palavra: sobre ---  frequência: 114
Palavra: segundo ---  frequência: 114
Palavra: sistema ---  frequência: 115
Palavra: pensamento ---  frequência: 115
Palavra: priori ---  frequência: 125
Palavra: modo ---  frequência: 129
Palavra: mundo ---  frequência: 134
Palavra: condição ---  frequência: 134
Palavra: sujeito ---  frequência: 145
Palavra: princípio ---  frequência: 91
Palavra: virtual ---  frequência: 93
Palavra: assim ---  frequência: 94
Palavra: wittgenstein ---  frequência: 95
Palavra: maneira ---  frequência: 95
Palavra: pode ---  frequência: 95
Palavra: quanto ---  frequência: 95
Palavra: vista ---  frequência: 96

Pos-Ordem:
Palavra: É ---  frequência: 96
Palavra: imanente ---  frequência: 104
Palavra: sentido ---  frequência: 110
Palavra: sobre ---  frequência: 114
Palavra: segundo ---  frequência: 114
Palavra: sistema ---  frequência: 115
Palavra: pensamento ---  frequência: 115
Palavra: priori ---  frequência: 125
Palavra: modo ---  frequência: 129
Palavra: mundo ---  frequência: 134
Palavra: condição ---  frequência: 134
Palavra: sujeito ---  frequência: 145
Palavra: princípio ---  frequência: 91
Palavra: virtual ---  frequência: 93
Palavra: assim ---  frequência: 94
Palavra: wittgenstein ---  frequência: 95
Palavra: maneira ---  frequência: 95
Palavra: pode ---  frequência: 95
Palavra: quanto ---  frequência: 95
Palavra: vista ---  frequência: 96
```

# Conclusão

De forma geral, o programa, orientado à objeto, se mostra eficiente para encontrar os <i>K</i> itens mais valiosos de uma coleção de dados e armazená-los nas 3 estruturas (árvores) escolhidas. Em se tratando de custo computacional, vale ressaltar que as árvores selecionadas (Binária - AVL - <i>Huffman</i>) possuem seu custo computacional geral dado por <i> O(log n)</i>. Contudo, a árvore binária padrão, em seu pior caso, apresenta custo <i>O(n)</i>, já que, por ela não apresentar nenhuma ferramenta que garante seu balanceamento, pode-se ocorrer a degeneração da árvore em uma lista vinculada, conforme a explicação dada na seção anterior. Em se tratando da AVL e <i>Huffman</i>, ambas apresentam uma melhoria em comparação com a Binária, tendo em vista que a AVL mantém o seu custo próximo de <i>O(log *n)</i>, em virtude das rotações, e a <i>Huffman</i> compacta seus dados, contribuindo para um menor gasto de memória. <br>
Por fim, afirma-se que o objetivo do trabalho foi cumprido com excelência, porém, o código é passivo de melhorias e otimizações, tais como aquelas discutidas na seção "Casos Sem Tratamento e Possíveis Erros".

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
|  `make clean`          | Apaga a última compilação realizada contida na pasta build e o último "output.data"               |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Referências

[1] MAIOLI, DOUGLAS - Repositório GitHub, @professordouglasmaioli: Árvore AVL - Disponível em: https://github.com/professordouglasmaioli. Acessado em 19 de Setembro de 2023.

[2] CORMEN, T. H. et al. Introduction to Algorithms, third edition. [s.l.] MIT Press, 2012. Acessado em 01 de Março de 2023.

[3] PIRES, MICHEL - Repositório GitHub, @mpiress: Basic_Tree - Disponível em: https://github.com/mpiress/basic_tree. Acessado em 19 de Setembro de 2023.

[3] PIRES, MICHEL - Repositório GitHub, @mpiress: HeapSort - Disponível em: https://github.com/mpiress/HeapSort. Acessado em 20 de Agosto de 2023.
