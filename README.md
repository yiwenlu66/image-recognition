# image-recognition
OOP homework

## Requirements
- `opencv` 2.4
- compiler supporting C++11

## Compile

```
cmake .
make
```

## Usage
```
Usage: ./ImageRecognition -b BIG_IMAGE_LIST -s SMALL_IMAGE_LIST -r NUM_ROW -c NUM_COLUMN
```

For example,

```
./ImageRecognition -b big.txt -s small.txt -r 3 -c 5 > output.txt
```
