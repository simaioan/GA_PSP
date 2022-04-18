#include "Ga.h"
#include "structures.h"
#include <iostream>
#include <random>
// #include <bits/stdc++.h> // e doar in gcc nu si clang

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 3); // define the range

    // for(int n=0; n<40; ++n)
        // std::cout << distr(gen) << ' '; // generate numbers

// std::string generate_init_population(int population_size, int chromosome_size){
void generate_init_population(struct chromosome init_population[], genetic_algorithm GA_param){
    std::cout<<"Generate Init Population\n";
    //std::string SRL_letters_s;// e posibil ca astea doua siruri sa nu fie necesare
    // std::string RULD_letters;
    //char SRL_letters[10000];
    //int SRL_letters_int[10000];
    
    // std::cout<<"Populatie: " << GA_param.population_size<<"\n";
    // std::cout<<"Protein Length:" << GA_param.chromosome_size<<"\n";
    //generate_init_SRL(init_population,population_size,chromosome_size);
    generate_init_RULD(init_population,GA_param);
    transform_int_to_RULD(init_population,GA_param);
    transform_RULD_to_xyz(init_population,GA_param);
    compute_fitness(init_population,GA_param);

    // for (size_t i = 0; i < GA_param.population_size; i++)  { 
    //     init_population[i].changed = true;
    // }
    // std::cout<<"\n";
};


// void generate_init_population(){
//     char litera;
//     aminoacid a;
//     for (size_t i = 0; i < population_size; i++)
//     {
//         for (size_t j = 0; i < chromosome_size; i++)
//         {
//             generations[0][i][j] = a;

            
//         }
        
//     }
    
// }


// void generate_init_SRL(struct chromosome init_population[],
//                         int population_size,
//                         int chromosome_size){

//     for (size_t i = 0; i < population_size; i++)  {
//         init_population[i].SRL_letters_int[0] = 0;//First AA
//         init_population[i].SRL_letters[0] = 'S';
//         //init_population[i].SRL_letters_int[1] = 0;//Second AA = S (R)
//         //init_population[i].SRL_letters[1] = 'S';
//         for (size_t j = 1; j < chromosome_size; j++)   {
            
//             init_population[i].SRL_letters_int[j] = distr(gen) - 1;
//             switch (init_population[i].SRL_letters_int[j])  {
//             case -1:
//                 init_population[i].SRL_letters[j] = 'L';
//                 break;
//             case 0:
//                 init_population[i].SRL_letters[j] = 'S';
//                 break;
//             case 1:
//                 init_population[i].SRL_letters[j] = 'R';
//                 break;
//             case 2:
//                 init_population[i].SRL_letters[j] = 'F';
//                 break;
//             case 3:
//                 init_population[i].SRL_letters[j] = 'B';
//                 break;            
//             default:
//                 std::cout<<"Litera SRL inexistenta!";
//                 break;
//             }
//         }
//     }  
// }

// void transform_SRL_RULD(struct chromosome init_population[],int population_size,int chromosome_size){

//     for (size_t i = 0; i < population_size; i++)  {
//         init_population[i].RULD_letters[0] = 'C';
//         init_population[i].x_string[0] = 0; //First AA
//         init_population[i].y_string[0] = 0;
//         init_population[i].z_string[0] = 0;

//         for (size_t j = 1; j < chromosome_size; j++)   {
//             switch (init_population[i].SRL_letters_int[j-1])  {
//             case -1:
//                 switch (init_population[i].SRL_letters_int[j])  {
//                 case -1:
//                     init_population[i].RULD_letters[0] = '';
//                     break;
//                 case 0:
                    
//                     break;
//                 case 1:
                    
//                     break;
//                 case 2:
                    
//                     break;
//                 case 3:
                    
//                     break;                           
//                 default:
//                     std::cout<<"Litera SRL inexistenta!";
//                     break;
//                 }
//                 break;

//             case 0:
                
//                 break;
//             case 1:
                
//                 break;
//             case 2:
                
//                 break;
//             case 3:
                
//                 break;                           
//             default:
//                 std::cout<<"Litera SRL inexistenta!";
//                 break;
//             }



//             switch (init_population[i].SRL_letters_int[j])  {
//             case -1:
//                 init_population[i].x_string = 
//                 init_population[i].SRL_letters[j] = 'L';
//                 break;
//             case 0:
//                 init_population[i].SRL_letters[j] = 'S';
//                 break;
//             case 1:
//                 init_population[i].SRL_letters[j] = 'R';
//                 break;
//             case 2:
//                 init_population[i].SRL_letters[j] = 'F';
//                 break;
//             case 3:
//                 init_population[i].SRL_letters[j] = 'B';
//                 break;            
//             default:
//                 std::cout<<"Litera SRL inexistenta!";
//                 break;
//             }
//         }
//     }  
// };

void generate_init_RULD(struct chromosome init_population[], genetic_algorithm GA_param){
    // std::cout<<"Pop size: "<<GA_param.population_size<<"\n";
    for (size_t i = 0; i < GA_param.population_size; i++)  {
        init_population[i].changed = true;       
        init_population[i].RULD_letters_int[0] = 0;//First AA
        init_population[i].RULD_letters[0] = 'R';
        //init_population[i].RULD_letters_int[1] = 0;//Second AA = R
        //init_population[i].RULD_letters[1] = 'R';
        for (size_t j = 1; j < GA_param.chromosome_size; j++)   {
            //std::cout<<"UNU "<<j<<" ";
            init_population[i].RULD_letters_int[j] = distr(gen);
            // std::cout<<"litera "<<init_population[i].RULD_letters_int[j]<<" \n";
            // init_population[i].RULD_letters_int[j] = rand() % GA_param.nr_litere;
            //remove imposible: RL,LR,UD,DU,FB,BF
            if (init_population[i].RULD_letters_int[j-1]==0 && init_population[i].RULD_letters_int[j]==2) j--;
            if (init_population[i].RULD_letters_int[j-1]==2 && init_population[i].RULD_letters_int[j]==0) j--;
            if (init_population[i].RULD_letters_int[j-1]==1 && init_population[i].RULD_letters_int[j]==3) j--;
            if (init_population[i].RULD_letters_int[j-1]==3 && init_population[i].RULD_letters_int[j]==1) j--;
            if (init_population[i].RULD_letters_int[j-1]==4 && init_population[i].RULD_letters_int[j]==5) j--;
            if (init_population[i].RULD_letters_int[j-1]==5 && init_population[i].RULD_letters_int[j]==4) j--;

        }
        // for (size_t k = 0; k < GA_param.chromosome_size; k++) {
        //     std::cout<<init_population[i].RULD_letters_int[k]<<" ";
        // }
        // std::cout<<"\n";        
    }                                   
}

void transform_int_to_RULD(struct chromosome population[], genetic_algorithm GA_param){
    for (size_t i = 0; i < GA_param.population_size; i++)  {
        // std::cout<<population[i].changed;
        if(population[i].changed){
            // std::cout<<"DA\n";
            for (size_t j = 1; j < GA_param.chromosome_size; j++)   {
                // std::cout<<"DA 2 \n";
                switch (population[i].RULD_letters_int[j])  {
                case 0:
                    population[i].RULD_letters[j] = 'R';
                    break;
                case 1:
                    population[i].RULD_letters[j] = 'U';
                    break;
                case 2:
                    population[i].RULD_letters[j] = 'L';
                    break;
                case 3:
                    population[i].RULD_letters[j] = 'D';
                    break;
                case 4:
                    population[i].RULD_letters[j] = 'F';
                    break;
                case 5:
                    population[i].RULD_letters[j] = 'B';
                    break;        
                default:
                    std::cout<<"Litera RULD inexistenta!";
                    break;
                }
            }
        }
    }
    // for (size_t i = 0; i < GA_param.population_size; i++)  {
    //     for (size_t j = 0; j < GA_param.chromosome_size; j++) {
    //         std::cout<<population[i].RULD_letters[j]<<" ";
    //     }
    //     std::cout<<"\n";
    // }    
}

void transform_RULD_to_xyz(struct chromosome population[], genetic_algorithm GA_param){
    for (size_t i = 0; i < GA_param.population_size; i++)  {
        if(population[i].changed){
            population[i].x_string[0] = 0;
            population[i].y_string[0] = 0;
            population[i].z_string[0] = 0;
            for (size_t j = 1; j < GA_param.chromosome_size; j++)   {
                switch (population[i].RULD_letters_int[j])  {
                case 0: //R
                    population[i].x_string[j] = population[i].x_string[j-1] + 1;
                    population[i].y_string[j] = population[i].y_string[j-1];
                    population[i].z_string[j] = population[i].z_string[j-1];
                    break;
                case 1: //U
                    population[i].y_string[j] = population[i].y_string[j-1] + 1;
                    population[i].x_string[j] = population[i].x_string[j-1];
                    population[i].z_string[j] = population[i].z_string[j-1];
                    break;
                case 2: //L
                    population[i].x_string[j] = population[i].x_string[j-1] - 1;
                    population[i].y_string[j] = population[i].y_string[j-1];
                    population[i].z_string[j] = population[i].z_string[j-1];
                    break;
                case 3: //D
                    population[i].y_string[j] = population[i].y_string[j-1] - 1;
                    population[i].x_string[j] = population[i].x_string[j-1];
                    population[i].z_string[j] = population[i].z_string[j-1];
                    break;
                case 4: //F
                    population[i].z_string[j] = population[i].z_string[j-1] - 1;
                    population[i].y_string[j] = population[i].y_string[j-1];
                    population[i].x_string[j] = population[i].x_string[j-1];
                    break;
                case 5: //B
                    population[i].z_string[j] = population[i].z_string[j-1] + 1;
                    population[i].y_string[j] = population[i].y_string[j-1];
                    population[i].x_string[j] = population[i].x_string[j-1];
                    break;        
                default:
                    std::cout<<"Litera RULDFB inexistenta!";
                    break;
                }
            }
        }
    }                                   
}

void compute_fitness(struct chromosome population[], genetic_algorithm GA_param) {
    int energy, colisions;//, fitness;
    for (size_t i = 0; i < GA_param.population_size; i++)  {
        if (population[i].changed){

            energy=0, colisions=0;//, fitness=0;
            for (size_t j = 0; j < GA_param.chromosome_size-2; j++)   {
                for (size_t k = j+2; k < GA_param.chromosome_size; k++)
                {
                    if((population[i].x_string[j] == population[i].x_string[k]) && 
                        (population[i].y_string[j] == population[i].y_string[k]) && 
                        (population[i].z_string[j] == population[i].z_string[k])){
                            colisions++;
                        }   
                    
                    if (GA_param.sequence01[j] == '1' && GA_param.sequence01[k] == '1'){
                        if (abs(population[i].x_string[j] - population[i].x_string[k]) + 
                            abs(population[i].y_string[j] - population[i].y_string[k]) + 
                            abs(population[i].z_string[j] - population[i].z_string[k]) == 1) {
                                energy++;
                        }
                    }
                }   
            }
            // fitness = 100 * energy / colisions / colisions;
            population[i].colisions = colisions;
            population[i].energy = energy;
            population[i].fitness = 100 * energy;
            if (colisions > 0 ){
                if (colisions == 1){
                    colisions = 2;
                }
                population[i].fitness = 100 * energy / colisions / colisions;
            }
            // population[i].changed = false;//seteaza false pt mutatie si crossover           
        }        
    }                                   
}

// bool compare( index_fitness a, index_fitness b){ // asta e pt sort din bits
// 	return a.fitness <= b.fitness ? 1: 0;
//     // if(a.fitness <= b.fitness)
// 	// 	return 1;
// 	// else 
// 	// 	return 0;
// };

int compare(const void *s1, const void *s2){ // asta e pt sort din bits
    struct index_fitness *e1 = (struct index_fitness *)s1;
    struct index_fitness *e2 = (struct index_fitness *)s2;
    if (e1->fitness < e2->fitness)
        return 1;
    if (e1->fitness > e2->fitness)
        return -1;
    if (e1->fitness == e2->fitness)
        return 0;
	// return e1->fitness < e2->fitness ? 1: 0;
    // if(a.fitness <= b.fitness)
	// 	return 1;
	// else 
	// 	return 0;
    return 0;
};

void elitism_selection(chromosome population[], genetic_algorithm GA_param, int best){
    std::cout<<"==== Elitism Selection ====\n";
    //conservare the best
    index_fitness temp[100000];
    for (size_t i = 0; i < GA_param.population_size; i++) {
        temp[i].index = i;
        temp[i].fitness = population[i].fitness;
    }
    for (int i = 0; i < GA_param.population_size; i++)
        std::cout << temp[i].fitness << " " << temp[i].index << "\n";

    // int n = sizeof(temp) / sizeof(temp[0]);
    // std::sort(temp, temp+n, compare);//cat timp ia aici?
    // std::sort(temp, temp + GA_param.population_size, compare);//cat timp ia aici?

    //Nu sorteaza bine
    std::qsort(temp, GA_param.population_size, sizeof(struct index_fitness), compare);//cat timp ia aici?

    for (int i = 0; i < GA_param.population_size; i++)
        std::cout << temp[i].fitness << " " << temp[i].index << "\n";



};

// Chromosomes tournament_selection(chromosome population[], genetic_algorithm GA_param, int best){
//     // K-Way tournament selection with the best conservation
//     int chr1, chr2, temp; //temp_RULD_letters_int[1000];;
//     //int count = (int)GA_param.population_size * GA_param.selection_elite_percent;
//     int count = GA_param.population_size;
//     Chromosomes new_population[1000000];

//     std::cout<<"==== 2-way Tournament Selection ====";
//     new_population[0] = population[best]; // conservare best
//     int i = 1;
//     while(count){
//         chr1 = rand() % GA_param.population_size;
//         chr2 = rand() % GA_param.population_size;
//         if (chr1 != chr2){            
//             if (population[chr1].fitness >= population[chr2].fitness)
//                 new_population[i] = population[chr1];
//             else
//                 new_population[i] = population[chr2];
//             i++;
//             count--;            
//         }
//     }
//     return new_population[1000000];
// };

void tournament_selection_Jo(chromosome population[], genetic_algorithm GA_param, int best){
    // K-Way tournament selection in popuatia initiala (with the best conservation)
    //In pozitia celui mai slab este copiat winner-ul
    //Dezavantaj: pot fi eliminati din populatie chromo cu energie buna daca sunt comparati cu altii si mai buni 
    int chr1, chr2, count;
    // count = GA_param.population_size / 2;
    // std::cout<<count<<"\n";
    count = GA_param.population_size * GA_param.selection_elite_percent;
    // std::cout<<count<<"\n";
    // std::cout<<"==== 2-way Tournament Selection John method ====";
     // conservare best este implicita
    while(count){
        chr1 = rand() % GA_param.population_size;
        while ((chr2 = (rand() % GA_param.population_size)) == chr1){}// cicleaza pana obtine 2 chromo diferiti        
        //if (chr1 != chr2){            
        if (population[chr1].fitness > population[chr2].fitness)
            population[chr2] = population[chr1];
        else if (population[chr1].fitness < population[chr2].fitness)
            population[chr1] = population[chr2];
        count--;            
        //}
    }
};


void crossover(chromosome population[], genetic_algorithm GA_param, int best){
    //std::cout<<"==== Crossover ====\n";
    int chr1, chr2, position, temp; //temp_RULD_letters_int[1000];;
    int count = (int)GA_param.population_size * GA_param.crossover_percent;
    
    // int c = 0;
    while(count){
        //Aici poate ca nu trebuie sa tin cont de count - marti, 12 apr 2021
        //min + rand() % (( max + 1 ) - min);
        // chr1 = c + rand() % (GA_param.population_size - c);
        // chr2 = c + rand() % (GA_param.population_size - c);
        chr1 = rand() % GA_param.population_size;
        chr2 = rand() % GA_param.population_size;
        if (chr1 != chr2){   
            position = 1 + (rand() % (GA_param.chromosome_size - 1));
            // std::cout<<"chr 1: "<<chr1<<std::endl;
            // std::cout<<"chr 2: "<<chr2<<std::endl;
            // std::cout<<"position: "<<position<<std::endl;
            
            // for (size_t i = 0; i < GA_param.chromosome_size; i++)            {
            //     std::cout<<population[chr1].RULD_letters_int[i]<< " ";
            // } 
            // std::cout<<"\n";
            // for (size_t i = 0; i < GA_param.chromosome_size; i++)            {
            //     std::cout<<population[chr2].RULD_letters_int[i]<< " ";
            // }
            // std::cout<<"\n";

            // Este protejat The Best (conservat de la o generatie la alta)
            if (chr1 == best){
                // std::cout<<"BEST chr1 "<<chr1<<" - "<<best;
                for (size_t i = position; i < GA_param.chromosome_size; i++) {
                    population[chr2].RULD_letters_int[i] = population[chr1].RULD_letters_int[i];;
                }
            } else if (chr2 == best) {
                // std::cout<<"BEST chr2 "<<chr2<<" - "<<best;
                for (size_t i = position; i < GA_param.chromosome_size; i++) {
                    population[chr1].RULD_letters_int[i] = population[chr2].RULD_letters_int[i];
                }
            } else {
                for (size_t i = position; i < GA_param.chromosome_size; i++) {
                    //temp_RULD_letters_int[i] = 
                    temp = population[chr1].RULD_letters_int[i];
                    population[chr1].RULD_letters_int[i] = population[chr2].RULD_letters_int[i];
                    population[chr2].RULD_letters_int[i] = temp;
                }
            }
            // for (size_t i = 0; i < GA_param.chromosome_size; i++)            {
            //     std::cout<<population[chr1].RULD_letters_int[i]<< " ";
            // } 
            // std::cout<<"\n";
            // for (size_t i = 0; i < GA_param.chromosome_size; i++)            {
            //     std::cout<<population[chr2].RULD_letters_int[i]<< " ";
            // }
            // std::cout<<"\n";
            population[chr1].changed = true;
            population[chr2].changed = true;
            count--;
        }
    }
};

void mutation(chromosome population[], genetic_algorithm GA_param, int best){
    // std::cout<<"==== Mutation ====\n";
    int chr, position, prev_letter, old_letter, new_letter; //chr - chromo ales, pozitia, litera mutata
    int count = (int)GA_param.population_size * GA_param.mutation_percent;
    // std::cout<<"count: "<<count<<std::endl;
    while(count){
        // Protejam The Best de mutatie
        chr = rand() % GA_param.population_size;
        // std::cout<<"chr : "<<chr<<std::endl;
        // std::cout<<"best : "<<best<<std::endl;
        if (chr == best) { //se accepta mutatie in chromo nou, dar unde il pun?
            // std::cout<<"chr Best: "<<chr<<std::endl;

        } else {
            position = 1 + (rand() % (GA_param.chromosome_size - 1));            
            // std::cout<<"position: "<<position<<std::endl;          
            // for (size_t i = 0; i < GA_param.chromosome_size; i++) {
            //     std::cout<<population[chr].RULD_letters_int[i]<< " ";
            // }
            // std::cout<<"\n";
            // for (size_t i = 0; i < GA_param.chromosome_size; i++) {
            //     std::cout<<population[chr].RULD_letters[i]<< "";
            // } 
            // std::cout<<"\n";

            new_letter = rand() % GA_param.nr_litere; // functie de latice, nr litere difera
            old_letter = population[chr].RULD_letters_int[position];
            
            // std::cout << "Litera 1: " << old_letter << " Litera 2: "<<new_letter<<std::endl;
            // Recalcurile
            //pt acceasi litera nu are sens mutatia
            if(old_letter != new_letter){
                prev_letter = population[chr].RULD_letters_int[position-1];
                //eliminare cele 6 variante imposibile, care nu apar la relative 
                //in loc de 4 si daca as avea 7 si 9 cred ca ar merge abs(old_letter-new_letter)==2
                // si as putea aici nega la if             
                if ((prev_letter == 0 && new_letter == 2) ||
                    (prev_letter == 2 && new_letter == 0) ||
                    (prev_letter == 1 && new_letter == 3) ||
                    (prev_letter == 3 && new_letter == 1) ||
                    (prev_letter == 4 && new_letter == 5) ||
                    (prev_letter == 5 && new_letter == 4)) {
                 } else {
                    population[chr].RULD_letters_int[position] = new_letter;  
                    population[chr].changed = true;
                    count--;                                
                    // f2();
                    // std::cout<<"Afisare dupa mutatie:\n";
                    // for (size_t i = 0; i < GA_param.chromosome_size; i++) {
                    //     std::cout<<population[chr].RULD_letters_int[i]<< " ";
                    // }
                    // std::cout<<"\n";
                    // for (size_t i = 0; i < GA_param.chromosome_size; i++) {
                    //     std::cout<<population[chr].RULD_letters[i]<< " ";
                    // } 
                    // std::cout<<"\n";
                }                 
            }
            // f1();
        }
    }
};

// void inline mutattie(){

// }

// void f1(){
    // if (letter == 1){
            //     // if litera urmat = 0...3
            //     //litera urmat noua = (litera urmatoare + (letter - init_population[i].RULD_letters_int[position-1]))%4
            //     //(0+1) % 4

            //     //1-0 = 1
            //     //toate literele se aduna cu 1, iar 3 devine 0
            //     //else
            //     //init_population[i].RULD_letters_int[position-1] nu se schimba
            //     // 4 si 5 raman la fel
            // }
            // if (letter == 3) {//D
            //     // if litera urmat = 0...3
            //     //litera urmat noua = (litera urmatoare + (letter - init_population[i].RULD_letters_int[position-1]))%4
            //     //(0+3) % 4
            //     //3-0 = 3 adica 3-4=-1
            //     //toate literele se aduna cu -1, iar -1 devine 3
            //     // 0->3 (0+3 % 4= 3)
            //     // 3->2 (3+3 % 4)
            //     // 2->1 (2+3 % 4)
            //     // 1->0 (1+3 % 4)
            //     //else
            //     //init_population[i].RULD_letters_int[position-1] nu se schimba
            //     // 4 si 5 raman la fel
            // }
            // if (letter == 4) {//F - e inspre spate
            //     //0->4 (R devine F)
            //     //4->2 (F devine L)
            //     //2->5(L->B)
            //     //5->0 (B->R)
            //     //1 si 3 (U si D) raman neschimbate
            // }
            // if (letter == 5) {//B - e inspre fata
            //     //0->5 (R devine B)
            //     //5->2 (B devine L)
            //     //2->4 (L devine F)
            //     //4->0 (F devine R)
            //     //1 si 3 (U si D) raman neschimbate
            // }                    
// }

// void f2(){
    // for (size_t i = position+1; i < GA_param.chromosome_size; i++) {
                    //     if (old_letter == 0){
                    //         if (new_letter == 1 or new_letter == 3) { //U, D  , F si B raman neschimbate  
                    //             if(init_population[chr].RULD_letters_int[i]==0,1,2,3)
                    //                 init_population[chr].RULD_letters_int[i] = (init_population[chr].RULD_letters_int[i] + (new_letter - old_letter)) % 4
                    //         } else if (new_letter == 4) {
                    //             if(init_population[chr].RULD_letters_int[i]==0) init_population[chr].RULD_letters_int[i]=4;
                    //             if(init_population[chr].RULD_letters_int[i]==4) init_population[chr].RULD_letters_int[i]=2;
                    //             if(init_population[chr].RULD_letters_int[i]==2) init_population[chr].RULD_letters_int[i]=5;
                    //             if(init_population[chr].RULD_letters_int[i]==5) init_population[chr].RULD_letters_int[i]=0;
                    //             //0->4 (R devine F)
                    //             //4->2 (F devine L)
                    //             //2->5(L->B)
                    //             //5->0 (B->R)
                    //         } else if (new_letter == 5) {
                    //             if(init_population[chr].RULD_letters_int[i]==0) init_population[chr].RULD_letters_int[i]=5;
                    //             if(init_population[chr].RULD_letters_int[i]==5) init_population[chr].RULD_letters_int[i]=2;
                    //             if(init_population[chr].RULD_letters_int[i]==2) init_population[chr].RULD_letters_int[i]=4;
                    //             if(init_population[chr].RULD_letters_int[i]==4) init_population[chr].RULD_letters_int[i]=0;
                    //             //0->5 (R devine B)
                    //             //5->2 (B devine L)
                    //             //2->4 (L devine F)
                    //             //4->0 (F devine R)
                    //             //1 si 3 (U si D) raman neschimbate
                    //         }
                    //     }
                    //     if (old_letter == 1){ //primul if e la fel ca sus
                    //         if (new_letter == 0 or new_letter == 2) { //R, L  , F si B raman neschimbate  
                    //             init_population[chr].RULD_letters_int[i] = (init_population[chr].RULD_letters_int[i] + (new_letter - old_letter)) % 4
                    //         } else if (new_letter == 4) {
                    //             if(init_population[chr].RULD_letters_int[i]==0) init_population[chr].RULD_letters_int[i]=4;
                    //             if(init_population[chr].RULD_letters_int[i]==4) init_population[chr].RULD_letters_int[i]=2;
                    //             if(init_population[chr].RULD_letters_int[i]==2) init_population[chr].RULD_letters_int[i]=5;
                    //             if(init_population[chr].RULD_letters_int[i]==5) init_population[chr].RULD_letters_int[i]=0;
                    //             //0->4 (R devine F)
                    //             //4->2 (F devine L)
                    //             //2->5(L->B)
                    //             //5->0 (B->R)
                    //         } else if (new_letter == 5) {
                    //             if(init_population[chr].RULD_letters_int[i]==0) init_population[chr].RULD_letters_int[i]=5;
                    //             if(init_population[chr].RULD_letters_int[i]==5) init_population[chr].RULD_letters_int[i]=2;
                    //             if(init_population[chr].RULD_letters_int[i]==2) init_population[chr].RULD_letters_int[i]=4;
                    //             if(init_population[chr].RULD_letters_int[i]==4) init_population[chr].RULD_letters_int[i]=0;
                    //             //0->5 (R devine B)
                    //             //5->2 (B devine L)
                    //             //2->4 (L devine F)
                    //             //4->0 (F devine R)
                    //             //1 si 3 (L si R) raman neschimbate
                    //         }
                    //     }
// }

void re_compute(chromosome population[], genetic_algorithm GA_param){
    //std::cout<<"==== Re Compute ====";
    transform_int_to_RULD(population,GA_param);
    transform_RULD_to_xyz(population,GA_param);
    compute_fitness(population,GA_param);
};

int find_best(chromosome population[], genetic_algorithm GA_param){
    int position, max_fitness = 0;
    for (size_t i = 0; i < GA_param.population_size; i++)  {
        if (population[i].fitness > max_fitness){
            max_fitness = population[i].fitness;
            position = i;
        }
    }
    return position;
}

