CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
SRC_DIR = src
TEST_DATA = test_data
libr = library
all_targets = max multiply square

all: $(all_targets)

$(all_targets):
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o ./$(BUILD_DIR)/$(@) $(SRC_DIR)/$(@).c
  $(CC) -o ./$(BUILD_DIR)/$(@).o $(BUILD_DIR)/$(@) $(BUILD_DIR)/library

library:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o ./$(BUILD_DIR)/$(libr) $(SRC_DIR)/$(libr).c

clean:
	rm -f -r $(BUILD_DIR)
