/*
 * Order.h
 * Written by: Max Bernstein and Erica Schwartz
 * Fall 2016
 *
 * Defines an Order struct that holds the data for a Nozama order
 */

#ifndef ORDER_H
#define ORDER_H

struct Order {
        int id;
        int arrival_timestamp;  /* aka "arrival time" */
        int fetch_duration;     /* aka "fetch time"   */
        int pack_duration;      /* aka "pack time"    */
        int fetch_time_left;
        int pack_time_left;
        bool to_pack;
};

#endif
