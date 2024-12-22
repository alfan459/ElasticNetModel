#include <ElasticNetModel.h>

// Initialize the model with initial coefficients and parameters
ElasticNetModel model(0.5, 0.3, 1.0, 0.1, 0.5, 0.01);

void setup() {
  Serial.begin(9600);
  Serial.println("=== ElasticNet Model Example ===");

  // Example input
  float volume = 12.0;
  float targetDeltaTDS = 15.0;

  // Predict waktu
  float waktu = model.predictWaktu(volume, targetDeltaTDS);
  if (waktu < 0) waktu = 0.1; // Prevent negative waktu
  Serial.print("Predicted Waktu: ");
  Serial.println(waktu);

  // Predict delta_tds
  float predictedDeltaTDS = model.predictDeltaTDS(volume, waktu);
  Serial.print("Predicted DeltaTDS: ");
  Serial.println(predictedDeltaTDS);

  // Simulated feedback (actual delta_tds)
  float actualDeltaTDS = 14.8; // Replace with actual feedback
  Serial.print("Actual DeltaTDS: ");
  Serial.println(actualDeltaTDS);

  // Update model coefficients based on feedback
  model.updateCoefficients(volume, waktu, actualDeltaTDS, predictedDeltaTDS);
  model.printCoefficients();
}

void loop() {
  // Nothing to do in the loop
}
