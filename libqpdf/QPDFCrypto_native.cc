#include <qpdf/QPDFCrypto_native.hh>
#include <qpdf/QUtil.hh>

void
QPDFCrypto_native::MD5_init()
{
    this->md5 = std::make_shared<MD5_native>();
}

void
QPDFCrypto_native::MD5_update(unsigned char const* data, size_t len)
{
    this->md5->update(const_cast<unsigned char*>(data), len);
}

void
QPDFCrypto_native::MD5_finalize()
{
    this->md5->finalize();
}

void
QPDFCrypto_native::MD5_digest(MD5_Digest d)
{
    this->md5->digest(d);
}

void
QPDFCrypto_native::RC4_init(unsigned char const* key_data, int key_len)
{
    this->rc4 = std::make_shared<RC4_native>(key_data, key_len);
}

void
QPDFCrypto_native::RC4_process(unsigned char* in_data, size_t len,
                               unsigned char* out_data)
{
    this->rc4->process(in_data, len, out_data);
}

void
QPDFCrypto_native::RC4_finalize()
{
}
