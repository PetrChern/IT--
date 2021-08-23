#include "send.hpp"

void error_message(std::string mes)
{
    std::cout << "Error occured:" << std::endl << "> " << mes << std::endl;
}

int main(int argc, char* argv[]) 
{
    if (3 > argc) 
    {
        error_message("wrong input, try <write MESSAGE>");
        return -1;
    }

    uint16_t len = 0;
    if (!strcmp(argv[1], "write"))
    {
        len = strlen(argv[2]);
        len = (SHR_MAX_LEN >= len) ? len : SHR_MAX_LEN;
    } else 
    {
        error_message("wrong input, try <write MESSAGE>");
        return -1;
    }

    int shm = 0;
    if (-1 == (shm = shm_open(SHR_OBJECT_NAME, O_CREAT | O_RDWR, 0777)))
    {
        error_message("shm_open failed");
        return -1;
    }

    if (-1 == ftruncate(shm, SHR_MAX_LEN + 1))
    {
        error_message("truncation failed");
        return -1;
    }

    char *addr = static_cast<char *>(mmap(0, SHR_MAX_LEN + 1, PROT_WRITE | PROT_READ, MAP_SHARED, shm, 0));
    if (((char*)-1) == addr) 
    {
        error_message("mmap failed");
        return -1;
    }

    std::cout << "Your message: " << argv[2] << std::endl;

    memcpy(addr, argv[2], len);
    addr[len] = '\0';
    munmap(addr, SHR_MAX_LEN);
    close(shm);

    std::cout << "Programm for sending message worked successfully, try <read> to recieve it or <close> to close shared memory" << std::endl;
    return 0;
}