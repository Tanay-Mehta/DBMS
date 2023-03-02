#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// ,int num_fields, char* field_names[], str data_type

int generate_id(void){
     char* filepath = "./id_generator";
     FILE *fpt = fopen(filepath, "r");
     int id = 0;
     fscanf (fpt, "%d", &id);
     id++;
     fclose(fpt);
     FILE *fptr = fopen(filepath, "w");
     fprintf(fptr, "%d", id);
     fclose(fptr);
     return(id);
}

table* create_table(char* table_name,int num_fields, char* field_names[], char*data_types[]){
     FILE *fp = fopen(table_name, "w");
     int i,j;
     table* table1 = (table*)malloc(sizeof(table));
     memcpy(table1->name, table_name, 30);
     table1->num_fields = num_fields;
     fprintf(fp, "id, ");
     for(i=0;i<num_fields;i++){
          fprintf(fp, "%s, ", field_names[i]);
          memcpy(table1->fields[i].name, field_names[i], 30);
          memcpy(table1->fields[i].data_type, data_types[i], 30);
     }
     for(j=0;j<30;j++){
          table1->records[j].id = 0;
     }
     fclose(fp);
     return table1;
}

void insert_record(table* table1, char** data){
     int i, j;
     int id = generate_id();
     for(i=0;i<30;i++){
          if(table1->records[i].id == 0){
               table1->records[i].id = id;
               table1->records[i].data = data;
               break;
          }
     }
     FILE* fp = fopen(table1->name, "a");
     fprintf(fp, "\n");
     fprintf(fp, "%i, ", id);
     for(j=1;j<table1->num_fields+1;j++){
          fprintf(fp, "%s, ", data[j]);
     }
     // for(j=1;j<31;j++){
     //      fprintf(fp, "%s, ", data[j]);
}

void delete_record(table* table1, int id){
     FILE *fptr1, *fptr2;
     
     char file1[50];
     char file2[50];
     strcpy(file1, table1->name);
     strcpy(file2, "file2.csv");
     // char file2[] ="file2.txt";
     char curr;
     int del, line_number = 0;
     del = id+1;
     fptr1 = fopen(file1,"r");
    fptr2 = fopen(file2, "w");
    curr = getc(fptr1);
    if(curr!=EOF) {line_number =1;}
    while(1){
      if(del != line_number)
        putc(curr, fptr2);
        curr = getc(fptr1);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }
    fclose(fptr1);
    fclose(fptr2);
    remove(table1->name);
    rename("file2.csv", table1->name);
}

void update_record(table*table1, int id, char**data){
     delete_record(table1, id);
     insert_record(table1, data);
}
int array[30];
int* query_table(table*table1, char *filter_condition, char*field_name){
     int i, j, k, t;
     
     for(i=0;i<30;i++){
          if(table1->fields[i].name == field_name){
               break;
          }
     }
     for(j=0;j<30;j++){
          if(table1->records[j].data[i] == filter_condition){
               for(k=0;k<30;k++){
                    if(array[k] == 0){
                         char* buffer;
                         FILE* fptr = fopen(table1->name, "r");
                         fgets(buffer, 1000, fptr);
                         for(t=0; t<k; t++){
                              fgets(buffer, 1000, fptr);
                         }
                         fgets(buffer, 2, fptr);
                         int id = atoi(buffer);
                         array[k] = id;
                         break;
                    }
               }
          }
     }
     return array;
}