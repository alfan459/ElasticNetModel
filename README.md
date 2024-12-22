# ElasticNetModel

An Arduino library for ElasticNet regression modeling with adaptive coefficient updates based on feedback.

## Features
- Predict `waktu` based on `volume` and `target delta_tds`.
- Update model coefficients using ElasticNet penalty (L1 and L2 regularization).
- Easily adaptable for Arduino projects.

## Installation
1. Download this repository as a ZIP file.
2. Open Arduino IDE.
3. Go to `Sketch > Include Library > Add .ZIP Library`.
4. Select the downloaded ZIP file.

## Usage
Here’s an example of how to use this library:

```cpp
#include <ElasticNetModel.h>

// Initialize the model
ElasticNetModel model(0.5, 0.3, 1.0, 0.1, 0.5, 0.01);

void setup() {
  Serial.begin(9600);

  float volume = 12.0;
  float targetDeltaTDS = 15.0;
  float waktu = model.predictWaktu(volume, targetDeltaTDS);

  Serial.print("Predicted waktu: ");
  Serial.println(waktu);
}

void loop() {}
