#pragma once

#include <sys/types.h>
#include <sys/mman.h>

#include <iostream>
#include <string>
#include <cstring>

#include <fcntl.h> 
#include <unistd.h>
#define SHR_MAX_LEN 100
#define SHR_OBJECT_NAME "SharedMemory"