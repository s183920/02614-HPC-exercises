#include "data.h"

#ifdef ARRAY_OF_STRUCTS
double 
distcheck(particle_t *p, int n) {

    double dist = 0.0;
    /* fill in your code here
     *
     */
    for (int i = 0; i < n; i++) {
        dist = dist + p[i].dist;
    }
    return dist;
}
#else
double 
distcheck(particle_t p, int n) {

    double dist = 0.0;
    /* fill in your code here
     *
     */
    for (int i = 0; i < n; i++) {
        dist = dist + p.dist[i];
    }
    return dist;
}
#endif
