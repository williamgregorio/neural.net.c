#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define inputs 2
#define hidden_nodes 2
#define outputs 1
#define training_sets 4

// 0 and 1 for weight initialization
double weights() {
  return ((double)rand()) / ((double)RAND_MAX);
}

double sigmoid_activation(double x) {
  return 1 / (1 + exp(-x));
}

double derivative_sigmoid(double x) {
  return x * (1 - x);
}

int main(void) {
  const double learning_rate =  0.1f;

  double hidden_layer[hidden_nodes];
  double hidden_layer_bias[hidden_nodes];

  double output_layer[outputs];
  double output_layer_bias[outputs];

  double hidden_weights[inputs][hidden_nodes];
  double output_weights[hidden_nodes][ouputs];

  double training_inputs[training_sets][inputs] = {{0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}};
  double training_outputs[training_sets][outputs] = {{0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}};
}
