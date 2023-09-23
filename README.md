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

Em múltiplos arquivos ".data", encontram-se conjuntos de dados (textos), os quais devem ser lidos e tokenizados (separados em palavras). A partir disso, deve-se fornecer para o programa, como entrada, em um arquivo nomeado como "palavras.txt", as palavras que serão pesquisadas pelo usuário. Com tais informações, se, em um texto, existir aquela palavra pesquisada, todo o processo descrito no projeto <a href="https://github.com/Guiliard/Top-K-Elementos" target="_blank">Top-K-Elementos</a> deve ser construído. Após isso, as  as <i>K</i> palavras mais frequêntes devem ser armazedas em 3 diferentes estruturas de dados complexas: Árvore Binária, Árvore AVL e Árvore de Huffman, cada uma seguindo 

# Solução Proposta

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
