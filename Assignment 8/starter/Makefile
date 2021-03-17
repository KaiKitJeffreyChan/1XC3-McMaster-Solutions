CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
SRC_DIR = src
TEST_DATA = test_data

all_targets = max multiply square

all: $(all_targets)

$(all_targets): 
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o ./$(BUILD_DIR)/$(@) $(SRC_DIR)/$(@).c 

clean:
	rm -f -r $(BUILD_DIR)



