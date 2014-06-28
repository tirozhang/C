#include<stdio.h>

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
};

void catelog(struct fish f){
    printf("%s is a %s with %i teeth. he is  %i\n",f.name,f.species,f.teeth,f.age);

}

int main(){
    struct fish snappy = { "Snappy", "Piranha", 69, 4};
    catelog( snappy );
    return 0;
}
