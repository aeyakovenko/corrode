#include <stdio.h>
#include <string.h>
void fake_memmove(void * a, void *b, unsigned long t) {
    memmove(a,b,t);
}
int main() {
    int num_clusters = 12;
    unsigned int best_index = 3;
    unsigned int clusters[12] = {0,1,2,3,4,5,6,5,4,3,2,1};
    for (int i = 0;i < num_clusters;++i) {
        if (clusters[i] == best_index) {
            fake_memmove(&clusters[i],
                    &clusters[i+1],
                    (num_clusters - i- 1)* sizeof(clusters[0]));
            break;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d %d %d\n",
           clusters[0],
                      clusters[1],
                      clusters[2],
                      clusters[3],
                      clusters[4],
                      clusters[5],
                      clusters[6],
                      clusters[7],
                      clusters[8],
                      clusters[9],
                      clusters[10],
           clusters[11]);
    return clusters[0];
}
