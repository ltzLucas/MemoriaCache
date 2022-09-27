typedef struct nodo_int {
    int valido;
    int tag;
    int dado1;
    int dado2;
    int indice;
    int tempoNaCache;
    int id;
    struct nodo_int * ptr_proximo;
} LISTA_BLOCO;

LISTA_BLOCO * lst_criar(void);
LISTA_BLOCO * lst_inserir(LISTA_BLOCO * lista, int dados);
void lst_imprimir(LISTA_BLOCO * lista);
void lst_liberar(LISTA_BLOCO * lista);
int  lst_buscar(LISTA_BLOCO * lista, int indice,int tag,int dados,int dadoProximo,int leitura_escrita) ;
int ConverterToBinary (int n);
int getOffSet(int n);
int getIndice(int n);
int getTag(int n);
LISTA_BLOCO * atribuir_zero(LISTA_BLOCO * lista,int id);
int calculaTempo(int i, int x);
int numeroHitsMiss(int i);
void printHeader();



