#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define inputs 2
#define hidden_nodes 2
#define outputs 1
#define training_sets 6

int main(void) {
  const double learning_rate =  0.1f;

  double hidden_layer[hidden_nodes];
  double hidden_layer_bias[hidden_nodes];

  double output_layer[outputs];
  double output_layer_bias[outputs];

  double hidden_weights[inputs][hidden_nodes];
  double output_weights[hidden_nodes][ouputs];

}
