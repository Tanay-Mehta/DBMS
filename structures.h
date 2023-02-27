#ifndef STRUCTURES_H
#define STRUCTURES_H



typedef struct record {
    int id;
    char** data;
}record;

typedef struct field {
    char name[30];
    char data_type[20];
}field;

// typedef struct field_node{
//     char* data_type;
//     field* Field;
//     struct field_node* next;
// }field_node;

// typedef struct record_node{
//     record* Record;
//     struct record_node* next;
// }record_node;

typedef struct table {
    char name[30];
    int num_fields;
    field fields[30];
    record records[30];
}table;

typedef char* str;
table* create_table(char* table_name,int num_fields, char* field_names[], char* data_type[]);
void insert_record(table* table1, char* data[]);
int generate_id(void);
#endif