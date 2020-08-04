//////////////////////////////////////////////////////////////////////////////////////////
//                                      resource.h                                      //
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef __RESOURCE_H__
#define __RESOURCE_H__

typedef struct resource resource_t;

/*
 * The following structure represents a resource we are interested
 * in allocating. Problem: there is only a limited number of such
 * a resource! We only have 100 of them, all in the bank array
 * defined in allocation.c. Since we only have so few of them, we
 * will create an allocation and de-allocation function pair to
 * manage these resources and make sure none of them are getting
 * wasted!
 */
struct resource {
    int id;
    int flag;
    double weight;
};

#endif
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////