#ifndef CONFEDERATIONS_H_
#define CONFEDERATIONS_H_

typedef struct {
	int id;
	char name[50];
	char region[50];
	int creationYear;
	int isEmpty;
} sConfederation;

void hardcodeConfederations(sConfederation confederations[]);

void showConfederation(sConfederation confederations);

int listConfederations(sConfederation confederations[], int len_cf);

int loadConfederationsName(sConfederation confederations[], int len, int idConfederation, char name[]);

#endif /* CONFEDERATIONS_H_ */
