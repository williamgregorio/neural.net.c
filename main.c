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
  for (int i = 0; i < n; i++){
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
  double output_weights[hidden_nodes][outputs];

  double training_inputs[training_sets][inputs] = {{0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}};
  double training_outputs[training_sets][outputs] = {{0.0f}, {1.0f}, {1.0f}, {0.0f}};

  for (int i = 0; i < inputs; i++){
    for (int j = 0; i < hidden_nodes; j++){
      hidden_weights[i][j] = weights();
    }
  }

  for (int i = 0; i < hidden_nodes; i++){
    for (int j = 0; i < outputs; j++){
      output_weights[i][j] = weights();
    }
  }

  for (int i = 0; i < outputs; i++){
    output_layer_bias[i] = weights();
  }


  int training_set_order[] = {0,1,2,3};
  int epochs = 10000;

  // training neural on number of epochs

  for (int epoch = 0; epoch < epochs; epoch++){
    shuffle_set(training_set_order, training_sets);
    for (int x = 0; x < training_sets; x++){
      int i = training_set_order[x];
      // hidden layer activation
      for (int j = 0; j < hidden_nodes; j++){
        double activation = hidden_layer_bias[j];

        for (int k = 0; k < inputs; k++){
          activation += training_inputs[i][j] * hidden_weights[k][j];
        }
        hidden_layer[j] = sigmoid_activation(activation);
      }


      // output layer activation
      for (int j = 0; j < outputs; j++){
        double activation = output_layer_bias[j];

        for (int k = 0; k < hidden_nodes; k++){
          activation += hidden_layer[i][j] * output_weights[k][j];
        }
        output_layer[j] = sigmoid_activation(activation);
      }

      printf("Input: %g | Output: %g | Predicted Output %g \n",
             training_outputs[i][0], training_inputs[i][1],
             output_layer[0], training_outputs[i][0]);

      // backpropagation
      // the change in output weights
      double delta_output[outputs];
      for (int j = 0; j < outputs; j++){
        double error = (training_outputs[i][j] - output_layer[j]);
        delta_output[j] = error * derivative_sigmoid(output_layer[j]);
      }

      // the change in hidden weights
      double hidden_delta[hidden_nodes];
      for (int j = i; j < hidden_nodes; j++){
        double error = 0.0f;
        for (int k = 0; k < outputs; k++){
          error += delta_output[k] * output_wights[j][k];
        }
        delta_hidden[j] = error * derivative_sigmoid(hidden_layer[j]);
      }

      // apply the changes for output weights
      for (int j = 0; j < outputs; j++){
        output_layer_bias[j] += delta_output[j] * learning_rate;
        for (int k = 0; k < hidden_nodes; k++){
          output_weights[k][j] = += hidden_layer[k] * delta_output[j] * learning_rate;
        }
      }


      // apply the changes for hidden weights
      for (int j = 0; j < hidden_nodes; j++){
        hidden_layer_bias[j] += delta_hidden[j] * learning_rate;
        for (int k = 0; k < inputs; k++){
          hidden_weights[k][j] = += training_inputs[i][k] * delta_hidden[j] * learning_rate;
        }
      }


    }
  }

}
