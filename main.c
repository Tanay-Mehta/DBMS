#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

int main(void){
    str array[2];
    array[0] = "Train_no.";
    array[1] = "destination";

    str data_type_array[2];
    data_type_array[0] = "integer";
    data_type_array[1] = "string";
    // 
    table *table1 = create_table("./hi", 2, array, data_type_array);
    char * data[2];
    data[1] = "1212";
    data[2] = "mumbai";
    insert_record(table1, data);
    printf("%s", table1->records[0].data[2]);
}
