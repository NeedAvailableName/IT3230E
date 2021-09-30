struct MonHocNode {
    char id[10];
    int so_tin_chi;
    int hoc_ky;
    struct MonHocNode *next;
};
typedef struct MonHocNode *MonHocDB;

struct DangKyNode {
    char id[10];
    MonHocDB dsmh;
    struct DangKyNode *next;
};
typedef struct DangKyNode *DangKyDB;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count1, count2;
MonHocDB read_mh(char *filename) {
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL) {
        printf("cannot open file\n");
        return;
    }
    fscanf(fptr, "%d", &count1);
    while(!feof(fptr)) {
        MonHocDB s = (MonHocDB)malloc(sizeof(MonHocDB));
        fscanf(fptr, "%s\t%d\t%d", s->id, &s->so_tin_chi, &s->hoc_ky);
        free(s);
    }
    fclose(fptr);
}
DangKyDB read_dk(char *filename, MonHocDB monhocDB) {
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL) {
        printf("cannot open file\n");
        return;
    }
    fscanf(fptr, "%d", &count2);
    while(!feof(fptr)) {
        DangKyDB s = (DangKyDB)malloc(sizeof(DangKyDB));
        fscanf(fptr, "%s %d\t%s\t%s\t%s", s->id, s->dsmh->hoc_ky, s->dsmh->)
    }
}