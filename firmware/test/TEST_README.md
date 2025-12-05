# SmartKnob Firmware Tests

This directory contains unit tests for the SmartKnob firmware using PlatformIO's Unity test framework.

## Overview

The test suite includes comprehensive unit tests for core utility functions and components:

### Test Files

- **test_util/** - Tests for core utility functions (`util.h`/`util.cpp`)
  - `CLAMP()` template function - boundary clamping with various data types
  - `lerp()` function - linear interpolation and value mapping
  - `sgn()` function - sign determination for numeric values
  - `COUNT_OF()` macro - array size calculation

## Running Tests

### Prerequisites

- PlatformIO Core or PlatformIO IDE installed
- ESP32 development board (for hardware tests)

### Run Tests

```bash
# Run all tests on hardware
pio test -e test

# Run specific test
pio test -e test -f test_util

# Run tests in verbose mode
pio test -e test -v
```

### Test Environment

The `test` environment in `platformio.ini` is configured for running unit tests:

```ini
[env:test]
extends = base_config
board = esp32doit-devkit-v1
test_framework = unity
test_build_src = yes
```

## Test Coverage

### Currently Tested

- ✅ Utility functions (CLAMP, lerp, sgn, COUNT_OF)
  - Edge cases and boundary conditions
  - Multiple data types
  - Negative values and ranges
  - Zero values

### Future Test Additions

- Motor control algorithms
- Sensor reading validation
- Configuration serialization/deserialization
- Display rendering functions
- Interface state management

## Writing New Tests

1. Create a new directory under `firmware/test/` for your test suite (e.g., `test_motor/`)
2. Create a test file with descriptive test functions
3. Use Unity assertion macros:
   - `TEST_ASSERT_EQUAL(expected, actual)`
   - `TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual)`
   - `TEST_ASSERT_TRUE(condition)`
   - `TEST_ASSERT_NULL(pointer)`

### Example Test Structure

```cpp
#include <unity.h>
#include "your_module.h"

void test_function_basic_case() {
    TEST_ASSERT_EQUAL(expected_value, function_call());
}

void test_function_edge_case() {
    TEST_ASSERT_TRUE(function_call() > 0);
}

void setup() {
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(test_function_basic_case);
    RUN_TEST(test_function_edge_case);

    UNITY_END();
}

void loop() {}
```

## Continuous Integration

These tests can be integrated into CI/CD pipelines to ensure code quality:

```yaml
# Example GitHub Actions workflow
- name: Run PlatformIO Tests
  run: pio test -e test
```

## Resources

- [PlatformIO Unit Testing](https://docs.platformio.org/page/plus/unit-testing.html)
- [Unity Test Framework](http://www.throwtheswitch.org/unity)
- [SmartKnob Documentation](https://github.com/scottbez1/smartknob)
