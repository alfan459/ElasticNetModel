#include "ElasticNetModel.h"

// Constructor
ElasticNetModel::ElasticNetModel(float coefVolume, float coefWaktu, float intercept, float alpha, float l1_ratio, float learningRate) {
  _coefVolume = coefVolume;
  _coefWaktu = coefWaktu;
  _intercept = intercept;
  _alpha = alpha;
  _l1_ratio = l1_ratio;
  _learningRate = learningRate;
}

// Predict waktu based on volume and target delta_tds
float ElasticNetModel::predictWaktu(float volume, float targetDeltaTDS) {
  return (targetDeltaTDS - (_coefVolume * volume + _intercept)) / _coefWaktu;
}

// Predict delta_tds based on volume and waktu
float ElasticNetModel::predictDeltaTDS(float volume, float waktu) {
  return _coefVolume * volume + _coefWaktu * waktu + _intercept;
}

// Update coefficients using feedback
void ElasticNetModel::updateCoefficients(float volume, float waktu, float actualDeltaTDS, float predictedDeltaTDS) {
  float error = predictedDeltaTDS - actualDeltaTDS;

  // ElasticNet penalty terms
  float l1_penalty = _l1_ratio * _alpha;
  float l2_penalty = (1 - _l1_ratio) * _alpha;

  // Gradient descent update rules
  _coefVolume -= _learningRate * (error * volume + l1_penalty * (_coefVolume > 0 ? 1 : -1) + 2 * l2_penalty * _coefVolume);
  _coefWaktu -= _learningRate * (error * waktu + l1_penalty * (_coefWaktu > 0 ? 1 : -1) + 2 * l2_penalty * _coefWaktu);
  _intercept -= _learningRate * error;
}

// Print current model coefficients
void ElasticNetModel::printCoefficients() {
  Serial.println("Current Model Coefficients:");
  Serial.print("  Coef Volume: ");
  Serial.println(_coefVolume);
  Serial.print("  Coef Waktu: ");
  Serial.println(_coefWaktu);
  Serial.print("  Intercept: ");
  Serial.println(_intercept);
}

// getFunction
float ElasticNetModel::getCoefVolume() { return _coefVolume; }
float ElasticNetModel::getCoefWaktu() { return _coefWaktu; }
float ElasticNetModel::getIntercept() { return _intercept; }
float ElasticNetModel::getAlpha() { return _alpha; }
float ElasticNetModel::getL1Ratio() { return _l1_ratio; }
float ElasticNetModel::getLearningRate() { return _learningRate; }

