//
//  main.c
//  exe1
//
//  Created by НУРИЯ on 10/14/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
// Nuriya Umirbekova
#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *file_1 = fopen("exe1.txt", "r");
    int num, number_of_misses=0, number_of_hits=0;
       
    printf("enter the number of pages:\n");
    scanf("%d", &num);
    int cnt[num], page_table[num];
    
    for(int i=0; i<num; i++){
        page_table[i] = -1;
        cnt[i] = 0; }
   
    for (int j=0; j<100; j++){
        int reference;
        fscanf(file_1, "%d", &reference);
        int page_id=-1;
        int f=0;
        
        for (int i=0; i<num; i++){
            if(page_table[i]==reference){
                number_of_hits++;
                f=1;
                page_id=i;
                break;
            }
        }
        if (!f){
            number_of_misses++;
            for (int i=0; i<num; i++){
                if (page_table[i]==-1){
                    page_id=i;
                    break;
                }
            }
            if (page_id==-1){
                int minimal=cnt[0];
                page_id=0;
                for (int i=1; i<num; i++){
                    if (cnt[i]<minimal){
                        minimal=cnt[i];
                        page_id=i;
                    }
                }
            }
            page_table[page_id]=reference;
        }
        for (int i=0; i<num; i++){
            cnt[i]=cnt[i] >> 1;
        }
        cnt[page_id]=cnt[page_id] |(1<<64);
    }
     printf("Hits: %d, misses: %d, hit/miss ratio: %f\n", number_of_hits, number_of_misses,(double)number_of_hits/ (double)(number_of_misses));
    exit(0);
}
