#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "ErrorHandler.h"

// Colors
#define WHITE "\e[0;37m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"

// Bold Colors
#define WHITE_BOLD "\e[1;37m"
#define MAGENTA_BOLD "\e[1;35m"
#define YELLOW_BOLD "\e[0;33m"
#define BLUE_BOLD "\e[1;34m"
#define CYAN_BOLD "\e[1;36m"
#define RED_BOLD "\e[1;31m"

// Buffer
#define BUFFER_SIZE 100

// Possible Constants
#define POSSIBLE_IDS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define POSSIBLE_NUM "0123456789"

// Possible Operators
#define ADDITION_OP "+"
#define PRODUCT_OP "*"
#define ASSIGNATION_OP "="

#define PARENTHESIS_OP "("
#define PARENTHESIS_CL ")"