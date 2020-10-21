#include "../include/bst.hpp"

// Func para auxiliar nos testes de busca.
// ------------------------------------------------------------------------
void auxBusca( ABB tr, int _valor_ )
{
    if( tr.buscar( tr.raiz_, _valor_ ) == nullptr )
    {
        std::cout << "O valor " << _valor_ << " não está na árvore!\n";

        return; 
    }

    if( tr.buscar( tr.raiz_, _valor_ )->chave == _valor_ )
    {
        std::cout << "O valor " << _valor_ << " está na árvore!\n"; 
    }
}
// ------------------------------------------------------------------------


// Func para gerar os 2 tipo de vetores para os testes.
// ----------------------------------------------------------------------------------------------------------------
void geraVetores( std::vector<long int> * arr_ordenado, std::vector<long int> * arr_random, long int MAX )
{
    for( long int i = 1; i <= MAX; i++ )
    {
        arr_ordenado->push_back(i);
        arr_random->push_back(i);
    } 

    std::shuffle( arr_random->begin(), arr_random->end(), std::default_random_engine(23) ); 

}
// ----------------------------------------------------------------------------------------------------------------



// Func para controlar o crescimento das amostras baseado na quantidade total.
// ----------------------------------------------------------------------------------------------------------------
long int sample_control( long int MAX, long int samples, long int init_sample, long int index )
{
    // Método linear

    long int reason = ( MAX - init_sample ) / samples;

    return init_sample + ( (index - 1) * reason );
}
// ----------------------------------------------------------------------------------------------------------------




int main( int argc, char *argv[] ) 
{

    if( argc != 4 )
    {
        std::cout << "\x1b[93mPor favor entre com 3 argumentos!\x1b[0m\n\t\t"
                  << "<número_de_amostras> <tamanho_amostra_inicial> <tamanho_amostra_final>\n";

       return EXIT_FAILURE; 
    }

    if( atoi(argv[1]) < 5 )
    {
        std::cout << "\x1b[93mNúmero mínimo de amostras: 5\x1b[0m\n";

        return EXIT_FAILURE;
    }

    //else

    // Menor amostra, maior amostra, numero de amostras.
    long int SAMPLES, MIN_SAMPLE, MAX_SAMPLE;
    
    SAMPLES = atol(argv[1]);
    MIN_SAMPLE = atol(argv[2]);
    MAX_SAMPLE = atol(argv[3]);

    // -----------------------------------------------------------------------------------------------
    
    // Vetor que guardará as amostras de tempo
    std::vector< std::pair< double, double > > order_data_time(SAMPLES);
    std::vector< std::pair< double, double > > random_data_time(SAMPLES);

    // Vetores de arvores.
    std::vector< ABB > floresta_ordenada(SAMPLES*5);
    std::vector< ABB > floresta_random(SAMPLES*5);


    // iteradores para controle do loop
    int idx_order = 0;
    int idx_random = 0;

    // Vetores para a insercao
    std::vector< long int > ord;
    std::vector< long int > rdm;

    // Gerando os valores e preenchendo.
    geraVetores( &ord, &rdm, MAX_SAMPLE );

    // loop para percorrer todos os tamanhos de amostra.
    
    // Variaveis para controle da média aritmética.
    double media_ord = 0.0;
    double media_rdm = 0.0;

    // Medindo tempo de exec e calculando a média.    
    for( int iter_samples = 0; iter_samples < SAMPLES; iter_samples++ )     
    {
        // controle do crescimento da amostra.        
        long int samplectrl = sample_control( MAX_SAMPLE, SAMPLES, MIN_SAMPLE, iter_samples + 1 );

        media_ord = 0.0; // resetando.
        media_rdm = 0.0; // resetando.


        for( int timer = 0; timer < 5; timer++ )        
        {

            // -- INICIO CONTAGEM --
            std::chrono::steady_clock::time_point START1 = std::chrono::steady_clock::now();
            for( int i = 0; i < samplectrl; i++ )
            {  
                floresta_ordenada[idx_order].inserir( ord[i] );
            }
            std::chrono::steady_clock::time_point STOP1 = std::chrono::steady_clock::now();
            // -- FIM CONTAGEM --
            
            media_ord = media_ord + (  
                    ( std::chrono::duration< double > (STOP1 - START1).count() - media_ord )/ ( timer + 1 ) );


            // -- INICIO CONTAGEM 2--
            std::chrono::steady_clock::time_point START2 = std::chrono::steady_clock::now();
            for( int i = 0; i < samplectrl; i++ )
            {  
                floresta_random[idx_random].inserir( rdm[i] );
            }
            std::chrono::steady_clock::time_point STOP2 = std::chrono::steady_clock::now();
            // -- FIM CONTAGEM --
            
            media_rdm = media_rdm + (  
                    ( std::chrono::duration< double > (STOP2 - START2).count() - media_rdm )/ ( timer + 1 ) );

            idx_order++;
            idx_random++;
        }


        order_data_time[iter_samples] = std::make_pair( media_ord, samplectrl );
        random_data_time[iter_samples] = std::make_pair( media_rdm, samplectrl );
            
    } 
    // --------------------------------------------------------------------------------------------------------------

    int data_size = order_data_time.size();


    std::cout << "Ordem\n";

    for( int i = 0; i < data_size; i++ )
    {
        std::cout << order_data_time[i].first << " " << order_data_time[i].second << std::endl;
    }

    std::cout << "\n\nRandom\n";

    for( int i = 0; i < data_size; i++ )
    {
        std::cout << random_data_time[i].first << " " << random_data_time[i].second << std::endl;
    }

 
    return EXIT_SUCCESS;
}
