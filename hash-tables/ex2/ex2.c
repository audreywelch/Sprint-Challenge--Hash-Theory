#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

// PLAN:
  // If hash_table_retrieve(ht, "NONE") {
  //    append to route array    
  // }

  // for each item (i) in the hash table
  //    if the item's key (i->key) == first item's value (i-1)->value
  //      append to route array

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(length);
  char **route = malloc(length * sizeof(char *));

  // Create the key/value pairs to insert into the hash table
  for (int i = 0; i < length; i++) {

    // Insert Tickets to the hash table
    // Key: Location, Value: Destination
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  // First item to be inserted in the array should have a source/key of NONE
  char *current_destination = hash_table_retrieve(ht, "NONE");

  // for each item (i) in the hash table
  for (int i = 0; i < length; i++) {

    // Set each index of the route array to the 
    route[i] = current_destination;

    // Retrieve the ticket that has its source/key that matches the current ticket's destination
    // This returns the value/destination of that ticket
    current_destination = hash_table_retrieve(ht, current_destination);
  }
  
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}



#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  for (int i = 0; i < 3; i++) {
    free(tickets[i]);
  }

  free(tickets);

  return 0;
}
#endif
