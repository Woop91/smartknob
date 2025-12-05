// Main test entry point for PlatformIO Unity tests
// Individual test suites are in subdirectories

#include <unity.h>

void setUp(void) {
    // Set up code that runs before each test
}

void tearDown(void) {
    // Clean up code that runs after each test
}

void setup() {
    delay(2000); // Wait for serial connection
    UNITY_BEGIN();
    // Tests are defined in individual test files
    UNITY_END();
}

void loop() {
    // Tests run once in setup()
}
