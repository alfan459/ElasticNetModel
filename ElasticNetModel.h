#ifndef ElasticNetModel_h
#define ElasticNetModel_h

#include "Arduino.h"

class ElasticNetModel {
  public:
    // Constructor
    ElasticNetModel(float coefVolume, float coefWaktu, float intercept, float alpha, float l1_ratio, float learningRate);

    // Predict waktu based on volume and target delta_tds
    float predictWaktu(float volume, float targetDeltaTDS);

    // Predict delta_tds based on volume and waktu
    float predictDeltaTDS(float volume, float waktu);

    // Update coefficients using feedback
    void updateCoefficients(float volume, float waktu, float actualDeltaTDS, float predictedDeltaTDS);

    // Print current model coefficients
    void printCoefficients();

    // Getter methods
    float getCoefVolume();  // Get coefficient for volume
    float getCoefWaktu();   // Get coefficient for waktu
    float getIntercept();   // Get intercept
    float getAlpha();   	// Get Alpha
    float getL1Ratio();   	// Get L1 Ratio
    float getLearningRate(); // Get learning rate



  private:
    float _coefVolume;   // Coefficient for volume
    float _coefWaktu;    // Coefficient for waktu
    float _intercept;    // Intercept of the model
    float _alpha;        // Regularization parameter for ElasticNet
    float _l1_ratio;     // L1/L2 ratio for ElasticNet
    float _learningRate; // Learning rate for coefficient updates
};

#endif
