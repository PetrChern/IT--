#pragma once

#include <iostream>
#include <memory>
#include <openssl/pem.h>
#include <openssl/x509.h>

class Fingerprint
{
public:
    Fingerprint(const char* file_name);

    void show();
private:
    const char* cert_file_name_ = "cert.pem";
    std::unique_ptr<BIO, decltype(&BIO_free)> cert{BIO_new_file(cert_file_name_, "rb"), &BIO_free};
    std::unique_ptr<X509, decltype(&X509_free)> x509{PEM_read_bio_X509(cert.get(), NULL, NULL, NULL), &X509_free};
};