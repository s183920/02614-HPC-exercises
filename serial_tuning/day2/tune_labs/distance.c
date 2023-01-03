#include "data.h"
#include <math.h>

#ifdef ARRAY_OF_STRUCTS
double 
distance(particle_t *p, int n) {
    
    double dist = 0.0;
    /* fill in your code here
     *
     */
    for(int i = 0; i < n; i++) {
        double d = pow(p[i].x, 2) + pow(p[i].y, 2) + pow(p[i].z, 2);
        p[i].dist = sqrt(d);
        dist += p[i].dist;
    }
    return dist;
}
#else
double 
distance(particle_t p, int n) {

    double dist = 0.0;
    /* fill in your code here
     *
     */
    for(int i = 0; i < n; i++) {
        double d = pow(p.x[i], 2) + pow(p.y[i], 2) + pow(p.z[i], 2);
        p.dist[i] = sqrt(d);
        dist += p.dist[i];
    }
    return dist;
}
#endif
