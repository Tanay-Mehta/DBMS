#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
     