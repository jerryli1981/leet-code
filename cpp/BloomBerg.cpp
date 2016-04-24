// You are given a neural network with fully-connected layers and sigmoid units
// for recognizing handwritten decimal digits with the following schematic
// architecture.
//
//              +------+   +------+   +------+
// Pixel 000 -->|      |   |      |   |      |--> Output 0
// Pixel 001 -->|      |   |      |   |      |--> Output 1
// ...          |      |   |      |   |      |--> Output 2
// ...          |      |   |      |   |      |--> Output 3
// ...          |      |   |      |   |      |--> Output 4
// ...          |      |==>|      |==>|      |--> Output 5
// ...          |      |   |      |   |      |--> Output 6
// ...          |      |   |      |   |      |--> Output 7
// ...          |      |   |      |   |      |--> Output 8
// Pixel 255 -->|      |   |      |   |      |--> Output 9
//              +------+   +------+   +------+
//               Input      Hidden     Output
//               Layer      Layer      Layer
//              n = 256                n = 10
//
// You have trained it well such that, given an input image containing a certain
// digit, the output for that digit will be very close to 1, whereas the outputs
// for all other digits will be very close to 0.
//
// You are now asked to extend the network above with one additional layer that
// will yield the output in binary digits, i.e., given an image w ith '6' written
// on it, you would like the outputs labeled 2 and 4 to have values close to 1
// and everything else values close to 0
//
//              +------+   +------+   +------+   +------+
// Pixel 000 -->|      |   |      |   |      |   |      |
// Pixel 001 -->|      |   |      |   |      |   |      |
// ...          |      |   |      |   |      |   |      |
// ...          |      |   |      |   |      |   |      |
// ...          |      |   |      |   |      |   |      |--> Output 0
// ...          |      |==>|      |==>|      |==>|      |--> Output 2
// ...          |      |   |      |   |      |   |      |--> Output 4
// ...          |      |   |      |   |      |   |      |...
// ...          |      |   |      |   |      |   |      |
// Pixel 255 -->|      |   |      |   |      |   |      |
//              +------+   +------+   +------+   +------+
//               Input      Hidden     Hidden     Output
//               Layer      Layer      Layer      Layer
//              n = 256                n = 10     n = ?
//
// QUESTION 1:
// How many output nodes will you need to encode all the decimal digits in
// binary?

#include <array>
#include <iostream>

const int BINARY_OUT_SZ = 4;
const int DECIMAL_OUT_SZ = 10;

// QUESTION 2:
//
// If the new output is computed as a simple matrix multiplication of the
// previous output vector:
//
//     W * Y_decimal = Y_binary
//
// Write a function that will yield the best weight matrix W.

typedef std::array<double, BINARY_OUT_SZ> BinaryOutput;
typedef std::array<double, DECIMAL_OUT_SZ> DecimalOutput;
typedef std::array<DecimalOutput, BINARY_OUT_SZ> WeightMatrix;

WeightMatrix get_weights()
{

}

// QUESTION 3: Write a function that computes Y_binary given Y_decimal.

BinaryOutput convert(const DecimalOutput& decimalOutput)
{


}

const int DECIMAL_OUT_SZ = 10;