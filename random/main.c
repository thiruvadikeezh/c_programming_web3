#include <stdio.h>


typedef struct data
{
	int id;
}data;

int main()
{
	data obj;

	data *id_1 = &obj;

	id_1->id = 5;

	printf("The Data Inside The Struct Before %d\n", id_1->id );

	id_1->id = 10;

	printf("The Data After Modification is %d\n", id_1->id);
	return 0;

}
