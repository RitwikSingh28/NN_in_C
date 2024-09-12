#include <stdio.h>
#include <stdlib.h>

float train[][2] = {
  {0, 0},
  {1, 2},
  {2, 4},
  {3, 6},
  {4, 8},
};

#define train_count sizeof(train)/sizeof(train[0])

// w -> parameter of our model

float rand_float(void) {
  return (float) rand() / (float) RAND_MAX;
}

float cost(float w, float b) {
  float result = 0.0f;

  for (size_t i = 0; i < train_count; i++) {
    float x = train[i][0];
    float y = x*w + b;

    float d = y - train[i][1];
    result += d * d; 
  }

  result /= (1.0f * train_count);
  return result;
}

int main() {
  
  srand(69);
  // y = x * w;
  
  float w = rand_float() * 10.0f;
  float b = rand_float() * 5.0f;

  // getting to convergence using finite differences
  // Not used in production 
  // Only for educational purposes
  float eps = 1e-3;
  float rate = 1e-3;

  printf("cost: %f\n", cost(w, 1.0f));
  for(size_t i = 0; i < 500; ++i) {
    float dw = (cost(w+eps, b) - cost(w, b)) / eps;
    float db = (cost(w, b+eps) - cost(w, b)) / eps;
    w -= rate*dw;
    b -= rate*db;
    printf("cost: %f; w: %f; b: %f\n", cost(w, b), w, b);
  }
  
  printf("----------------------------------\n");
  printf("w: %f\n", w);

  return 0;
}
