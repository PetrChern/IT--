#include "Fingerprint.hpp"

Fingerprint::Fingerprint(const char* file_name) : cert_file_name_(file_name)
{
    if (BIO_new_file(cert_file_name_, "rb") == NULL)
    {
        std::cout << "Unable to open the certificate" << std::endl;
        exit(0);
    }
}

void Fingerprint::show()
{
    std::cout << "Fingerprint (digest) of certificate: ";

    static const char hexbytes[] = "0123456789ABCDEF";
    unsigned int n;
    unsigned char md[EVP_MAX_MD_SIZE];
    X509_digest(x509.get(), EVP_sha256(), md, &n);

    for (int i = 0; i < n; ++i) {
        std::cout << hexbytes[(md[i] & 0xf0) >> 4] << hexbytes[(md[i] & 0x0f) >> 0];
        if (i != n - 1)
            std::cout << ":";
    }
    std::cout << std::endl;
}