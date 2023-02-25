#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ,int num_fields, char* field_names[], str data_type

table* create_table(char* table_name,int num_fields, char* field_names[], char*data_types[]){
     FILE *fp = fopen(table_name, "w");
     int i;
     table* table1 = (table*)malloc(sizeof(table));
     memcpy(table1->name, table_name, 30);
     table1->num_fields = num_fields;

     for(i=0;i<num_fields;i++){
          fprintf(fp, "%s, ", field_names[i]);
          memcpy(table1->fields[i].name, field_names[i], 30);
          memcpy(table1->fields[i].data_type, data_types[i], 30);
     }
     fclose(fp);
     return table1;

}