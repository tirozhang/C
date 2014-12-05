#include<stdio.h>
#include<string.h>

void find_tracks(char list[][80] , char search_for[]){
    int i;
    for( i = 0; i < 5; i++ ){
        if(strstr(list[i],search_for)){
            printf("track %i:%s\n", i , list[i] );
            break;
        }
    }
}

int main(){
    char tracks[][80] = {
        "I left my heart",
        "newarks",
        "dancing",
        "form here to there",
        "the girl",
    };
    char search_for[] = "girl";
    find_tracks(tracks,search_for);
    return 0;

}
