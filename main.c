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

void shuffle_set(int *array, size_t n) {
  size_t i;
  for (i = 0; i < n; i++){
    size_t j = i + rand() / (RAND_MAX / (n - 1) + 1);
    int t = array[j];
    array[j] = array[i];
    array[i] = t;
  }
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
  double training_outputs[training_sets][outputs] = {{0.0f}, {1.0f}, {1.0f}, {0.0f}};

  for (i = 0; i < inputs; i++){
    for (j = 0; i < hidden_nodes; j++){
      hidden_weights[i][j] = weights();
    }
  }

  for (i = 0; i < hidden_nodes; i++){
    for (j = 0; i < outputs; j++){
      output_weights[i][j] = weights();
    }
  }
  
  for (i = 0; i < outputs; i++){
    output_layer_bias[i] = weights();
  }


}
