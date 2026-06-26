BUILD_DIR := c/build

.PHONY: all build test check clean

all: build test check

build:
	cmake -S c -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)
	pip install -q -e python/

test:
	cd $(BUILD_DIR) && ctest --output-on-failure
	cd python && pytest tests/ -v

check:
	cppcheck --enable=all --error-exitcode=1 --suppress=unusedFunction -I c/include/ c/src/ c/include/
	cd python && ruff check src/

clean:
	rm -rf $(BUILD_DIR)
