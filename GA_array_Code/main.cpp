// #include "src/Alg.h"
#include "src/Ga.h"
#include "src/structures.h"
#include <iostream>
#include "stdio.h"
#include <string.h>

// #include <cmath>
//#include <bits/stdc++.h> // pt timp

// int generations;// = 20;
// int population_size;// = 1;
// int chromosome_size;// = 20; //protein size
// extern std::string sequence01; // secventa in lucru
// double selection_elite_percent = 0.10;  // elitePercent
// double crossover_percent = 0.15;   // crossoverPercent
// double mutation_percent = 0.15;   // mutationPercent
genetic_algorithm GA;
// benchmark sequences for the 2D and 3D HP model
// 0 = hydrophil (P), "blue"
// 1 = hydrophob (H), "red"
// data source: Ron Unger, John Moult: Genetic Algorithms for Protein Folding Simulations,
//         Journal of Molecular Biology, Vol. 231, No. 1, May 1993

std::string SEQ6 = "110101";
std::string SEQ20 = "10100110100101100101"; //HPHPPHHPHPPHPHHPPHPH
std::string SEQ24 = "110010010010010010010011"; // HHPPHPPHPPHPPHPPHPPHPPHH
std::string SEQ25 = "0010011000011000011000011"; // PPHPPHHPPPPHHPPPPHHPPPPHH
std::string SEQ36 = "000110011000001111111001100001100100"; //PPPHHPPHHPPPPPHHHHHHHPPHHPPPPHHPPHPP
std::string SEQ48 = "001001100110000011111111110000001100110010011111"; // PPHPPHHPPHHPPPPPHHHHHHHHHHPPPPPPHHPPHHPPHPPHHHHH
// RURULLDLULLLUURRDRRRRULURRRRULLLLULDLULDLDRRRDL - 22,50,000, 200 gen
std::string SEQ50 = "11010101011110100010001000010001000101111010101011"; //HHPHPHPHPHHHHPHPPPHPPPHPPPPHPPPHPPPHPHHHHPHPHPHPHH
std::string SEQ60 = "001110111111110001111111111010001111111111110000111111011010"; // PPHHHPHHHHHHHHPPPHHHHHHHHHHPHPPPHHHHHHHHHHHHPPPPHHHHHHPHHPHP
std::string SEQ64 = "1111111111110101001100110010011001100100110011001010111111111111"; //HHHHHHHHHHHHPHPHPPHHPPHHPPHPPHHPPHHPPHPPHHPPHHPPHPHPHHHHHHHHHHHH
std::string SEQ85 = "1111000011111111111100000011111111111100011111111111100011111111111100010011001100101"; //HHHHPPPPHHHHHHHHHHHHPPPPPPHHHHHHHHHHHHPPPHHHHHHHHHHHHPPPHHHHHHHHHHHHPPPHPPHHPPHHPPHPH
std::string SEQ150 = "110101010111101000100110101010111101000100010000100010001011110101010111101010101111010001000100001000100010111101010101101000010001000101111010101011";
//HHPHPHPHPHHHHPHPPPHPPHHPHPHPHPHHHHPHPPPHPPPHPPPPHPPPHPPPHPHHHHPHPHPHPHHHHPHPHPHPHHHHPHPPPHPPPHPPPPHPPPHPPPHPHHHHPHPHPHPHHPHPPPPHPPPHPPPHPHHHHPHPHPHPHH
std::string SEQ156 = "000000000001001111111111100111111111110011111111111001111111111100111111111110011111111111001111111111100111111111110011111111111001111111111100100000000000";
//PPPPPPPPPPPHPPHHHHHHHHHHHPPHHHHHHHHHHHPPHHHHHHHHHHHPPHHHHHHHHHHHPPHHHHHHHHHHHPPHHHHHHHHHHHPPHHHHHHHHHHHPPHHHHHHHHHHHPPHHHHHHHHHHHPPHHHHHHHHHHHPPHPPPPPPPPPPP
//glucagon (PDB ID: 1BH0)
std::string SEQ29 = "00000100010011000010011011100"; //PPPPPHPPPHPPHHPPPPHPPHHPHHHPP
//insulin umana (PDB ID: 4CXL) - lantul B
std::string SEQ30 = "110001000011011111000001110000"; //HHPPPHPPPPHHPHHHHHPPPPPHHHPPPP
//aquaporin (PDB ID: 1j4n)
std::string SEQ271 = "1100100011101111011111111110100110101010000000110001010111010110110010010010100110101110001011011111110010111101110010001000010101110010000010101100101110111000000001000001110101110011110100001001001000110001000111110011011111111011110000010001011000010010101001000101000";
//HHPPHPPPHHHPHHHHPHHHHHHHHHHPHPPHHPHPHPHPPPPPPPHHPPPHPHPHHHPHPHHPHHPPHPPHPPHPHPPHHPHPHHHPPPHPHHPHHHHHHHPPHPHHHHPHHHPPHPPPHPPPPHPHPHHHPPHPPPPPHPHPHHPPHPHHHPHHHPPPPPPPPHPPPPPHHHPHPHHHPPHHHHPHPPPPHPPHPPHPPPHHPPPHPPPHHHHHPPHHPHHHHHHHHPHHHHPPPPPHPPPHPHHPPPPHPPHPHPHPPHPPPHPHPPP

//chromosome population[1000]; // aici: Bus error: 10
Chromosomes population[1000000];
int generations_energy[100000];
int generations_colisions[100000];
//as putea folosi siruri sau array-uri de lungime: generationss x population x protein_size (20x100x6)
//poate declarate cu pointeri si alocate dinamic
// std::string SRL_letters_s;// e posibil ca astea doua siruri sa nu fie necesare
// std::string RULD_letters;
// // char* SRL_letters = malloc(10000);
// int x_string[6]; //pt ficare coordonata
// int y_string[6];
// int z_string[6];
// //sau (de vazut care e mai rapid)
// coord coord_stirng[6];

//SAU

//aminoacid chromosome[6];
// chromosome population[100];
// population generations[20];
//aminoacid generations[20][100][6];

// void generate_init_population();
// void crossover();
// void mutation();
// void selection();

int initialization(int argc, char **argv);
void test(chromosome population[]);
void print_the_best(chromosome population[], int best);
void write_csv();


int main(int argc, char **argv){
    time_t start, end;
    std::cout<<"=== START ===\n";

    start = clock(); //time(&start);
    srand (time(NULL));
    if (initialization(argc, argv)==1)
        return 0;
    //char* SRL_letters = (char*) malloc(10000);
    //chromosome population = malloc(sizeof(chromosome) * 10);
    //Chromosomes population[10];// Segmentation fault: 11; pe stiva nu accepta valoare mai mare;  
    //Chromosomes* population = malloc(10 * sizeof (*population))

    generate_init_population(population,GA);
    // SRL_letters_s = generate_init_population(1,20);
    // SRL_letters = generate_init_population(1,20);
    //test(population);

    int pos_best = find_best(population,GA);
    // print_the_best(population, pos_best);
    for (size_t i = 1; i <= GA.generations; i++) {
        // selection(population,GA,pos_best);
        // elitism_selection(population,GA,pos_best);
        //population = tournament_selection(population,GA,pos_best);
        
        // print_the_best(population, pos_best);

        crossover(population, GA, pos_best);
        re_compute(population, GA); // recalcul dupa fiecare etapa sau doar la final?
        pos_best = find_best(population,GA);
        // std::cout<<"Dupa Crossover: "<<"\n";
        // print_the_best(population, pos_best);

        mutation(population, GA, pos_best);
        re_compute(population, GA);
        // pos_best = find_best(population,GA);

        generations_energy[i] = population[pos_best].energy;
        generations_colisions[i] = population[pos_best].colisions;
        
        tournament_selection_Jo(population,GA,pos_best);
        pos_best = find_best(population,GA);

        // std::cout<<"Generatia: "<<i<<" ";
        // std::cout<<i<<": "<<"Energy = "<<population[pos_best].energy<<"\n";
        // std::cout<<"Dupa Mutatie: "<<i<<"\n";
        // print_the_best(population, pos_best);        
    }
    print_the_best(population, pos_best);
    write_csv();

    end = clock(); //time(&end);
//    double time_taken = double(end - start);
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //std::cout << "Time taken by program is : " << std::fixed
    //     << time_taken << std::setprecision(5);
    std::cout << "Time taken by program is : " << std::fixed << time_taken;
    std::cout << " sec " << std::endl;
    return 0;
}

int initialization(int argc, char **argv){
    if (argc != 4){
        //std::cout<<"There need 4 parameters: SEQ, Generations, Population, lattice_type\n";
        std::cout<<"4 parameters are required: SEQ, Generations, Population\n";
        return 1;
    }    
    // std::cout<<"Sequence: "<<argv[1]<<"\n";
    // std::cout<<"Generations: "<<argv[2]<<"\n";
    // std::cout<<"Populations: "<<argv[3]<<"\n";
    //std::cout<<"Lattice Type: "<<argv[4]<<"\n";

    std::string arg(argv[1]); // convert array char to string pt a-l putea compara
    if (arg=="seq6") GA.sequence01 = SEQ6;
    else if (arg=="seq20") GA.sequence01 = SEQ20;
    else if (arg=="seq24") GA.sequence01 = SEQ24;
    else if (arg=="seq25") GA.sequence01 = SEQ25;
    else if (arg=="seq36") GA.sequence01 = SEQ36;
    else if (arg=="seq48") GA.sequence01 = SEQ48;
    else if (arg=="seq50") GA.sequence01 = SEQ50;
    else if (arg=="seq60") GA.sequence01 = SEQ60;
    else if (arg=="seq64") GA.sequence01 = SEQ64;
    else if (arg=="seq85") GA.sequence01 = SEQ85;
    else if (arg=="seq150") GA.sequence01 = SEQ150;
    else if (arg=="seq156") GA.sequence01 = SEQ156;

    GA.chromosome_size = GA.sequence01.size();
    GA.generations = std::atoi(argv[2]);
    GA.population_size = std::atoi(argv[3]);

    std::cout<<"Sequence: "<<argv[1]<<": ";
    std::cout<<"Sequence: "<<GA.sequence01<<"\n";
    std::cout<<"Generations: "<<GA.generations<<"\n";
    std::cout<<"Populations: "<<GA.population_size<<"\n";
    //std::cout<<"Lattice Type: "<<argv[4]<<"\n";
    std::cout<<"Chromo length: "<<GA.chromosome_size<<"\n\n";

    GA.crossover_percent = 0.5;
    GA.mutation_percent = 0.3;
    GA.selection_elite_percent = 0.35;

    //GA.latticeType = "2D";
    //GA.latticeType = "3D";
    GA.nr_litere = 4; // pt 2D
    //GA.nr_litere = 6; // pt 3D

    return 0;
}

void print_the_best(chromosome population[], int best){
    //for (size_t i = 0; i < population_size; i++) {
        // for (size_t j = 0; j < GA.chromosome_size; j++) { 

        // }
    //}
    std::cout<<"\n\nID Best: "<<best<<std::endl;
    std::cout<<"Colisions: "<<population[best].colisions<<std::endl;
    std::cout<<"Energy: "<<population[best].energy<<std::endl;
    std::cout<<"Fitness: "<<population[best].fitness<<std::endl; 

    for (size_t j = 1; j < GA.chromosome_size; j++) {
        // std::cout<<population[i].SRL_letters[j];
        std::cout<<population[best].RULD_letters[j];
    }
    std::cout<<std::endl;
}

void test(chromosome population[]){
    for (size_t i = 0; i < GA.population_size; i++)
    {
        for (size_t j = 1; j < GA.chromosome_size; j++)
        {
            // std::cout<<population[i].SRL_letters_int[j];            
            std::cout<<population[i].RULD_letters_int[j];            
        }
        std::cout<<std::endl;       
    }
    std::cout<<std::endl;

    for (size_t i = 0; i < GA.population_size; i++)
    {
        for (size_t j = 1; j < GA.chromosome_size; j++)
        {
            // std::cout<<population[i].SRL_letters[j];
            std::cout<<population[i].RULD_letters[j];
        }   
        std::cout<<std::endl;     
    }
    std::cout<<std::endl;

    // for (size_t i = 0; i < GA.population_size; i++)
    // {
    //     for (size_t j = 0; j < GA.chromosome_size; j++)
    //     {
    //         std::cout<<population[i].x_string[j]<<","<<population[i].y_string[j]<<","<<population[i].z_string[j]<<std::endl;
    //     }        
    // }
    // std::cout<<std::endl;

    for (size_t i = 0; i < GA.population_size; i++)    {
        std::cout<<"ID = "<<i<<std::endl;
        std::cout<<"Colisions = "<<population[i].colisions<<std::endl;
        std::cout<<"Energy = "<<population[i].energy<<std::endl;
        std::cout<<"Fitness = "<<population[i].fitness<<std::endl;
        std::cout<<std::endl;               
    }
    std::cout<<std::endl;
}

void write_csv(){
    for (size_t i = 1; i <= GA.generations; i++) {
        //de scris in csv
        std::cout<<generations_energy[i]<<",";
    }
    std::cout<<"\n";
    for (size_t i = 1; i <= GA.generations; i++) {
        //de scris in csv
        std::cout<<generations_colisions[i]<<",";
    }
    std::cout<<"\n";
}

