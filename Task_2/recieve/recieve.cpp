#include "recieve.hpp"

void error_message(std::string mes)
{
    std::cout << "Error occured:" << std::endl << "> " << mes << std::endl;
}

int main(int argc, char* argv[])
{
    if (2 > argc) 
    {
        error_message("wrong input, try <read>");
        return -1;
    }

    int shm = 0;
    if (!strcmp(argv[1], "read"))
    {
        if (-1 == (shm = shm_open(SHR_OBJECT_NAME, O_RDWR, 0777)))
        {
            error_message("shm_open failed");
            return -1;
        }

        std::cout << "Recieving message" << std::endl;

        char *addr = static_cast<char *>(mmap(0, SHR_MAX_LEN + 1, PROT_WRITE | PROT_READ, MAP_SHARED, shm, 0));
        if ((char*)-1 == addr) 
        {
            error_message("mmap failed");
            return -1;
        }

        std::cout << "Your message is " << addr << std::endl;

        munmap(addr, SHR_MAX_LEN);
        close(shm);
    } else if (!strcmp(argv[1], "close"))
    {
        shm_unlink(SHR_OBJECT_NAME);
        std::cout << "Shared Memory closed successfully!" << std::endl;
    }
    else 
    {
        error_message("wrong input, try <read> or <close>");
        return -1;
    }
    return 0;
}