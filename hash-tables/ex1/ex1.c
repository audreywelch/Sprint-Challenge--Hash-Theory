#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"


Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // Loop through the items in `weights`
  for (int i = 0; i < length; i++) {

    // Check if the needed key is in the hash table
    // This returns the index (value) of that key in the weights array
    // limit - weights[i] e.g. 21 - 6 = 15 -> looking for a key of 15
    int index_of_needed_key = hash_table_retrieve(ht, limit - weights[i]);

    // Build the hash table
    // If the key is not yet in the hash table
    if (index_of_needed_key == -1) {

        // Create the key/value pairs that are inserted into the hash table
        hash_table_insert(ht, weights[i], i);

    // If there exists a key equal to the (limit - weight)
    } else {

      // Create an instance of the Answer struct
      Answer *a = malloc(sizeof(Answer));

      // Set the index of the weight we started with
      a->index_1 = i;

      // Store the value (index) that matches
      a->index_2 = index_of_needed_key;
      return a;

     }
   }
  return NULL;

}


void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}

#endif

/*
THOUGHTS:

- Create a hash table
- Insert key, value pairs into the hash table
  > key: weight
  > value: index (because this is what we want to enter into the Answer struct)
  
- (limit - weight) = the key we want to look for
  > retrieve()

For Loop
  int *weights = { 4: 0, 6: 1, 10: 2, 15: 3, 16: 4 }
  21 - 4 = 17
  Looks for key 17
  Doesn't find it

  21 - 6 = 15
  Looks for key 15
  value: 3

// Create the key/value pairs that are inserted into the hash table
for (int i = 0; i < length - 1; i++;

  // Save the index
  hashed_index = hash_table_retrieve(ht, limit - weights[i])

  insert(key: weights[i], value: i)

  // for each item in the hash table, if there exists a key equal to the limit - weight
  if (hash_table_retrieve(ht, (limit - weights[i]))) != -1 {

    // Store the index for the weight we are starting with into a variable
    *starting_weight = i

    // Store that value (index) into a variable
    *matching_weight = hash_table_retrieve(ht, (limit - i))
  }

  // Answer Struct implementation
  if (matching_weight < starting weight) {
    Answer->index_1 = matching_weight
    Answer->index_2 = starting_weight
  } else {
    Answer->index_1 = starting_weight
    Answer->index_2 = matching_weight
  }
  
*/
